# aliyun-oss



阿里云 OSS 文件存储



## OSS 存储申请

[aliyun](https://oss.console.aliyun.com/) 官网，申请注册开通 oss 存储。

创建 Bucket，填写必要信息，读写权限选择 `公共读` ，方便客户端访问保存的文件。

选择 AccessKey 管理，创建 AccessKey，保存记录，后续配置要用到。



## 引入依赖

```xml
<!-- oss -->
<dependency>
    <groupId>com.aliyun.oss</groupId>
    <artifactId>aliyun-sdk-oss</artifactId>
	  <version>3.13.0</version>
</dependency>
```



## 添加配置

创建 `application-oss.properties` 配置文件，具体值需要根据

```properties
aliyun.oss.endpoint=<#填写自己的endpoint#>
aliyun.oss.accessKeyId=<#填写自己的accessKeyId#>
aliyun.oss.accessKeySecret=<#填写自己的accessKeySecret#>
aliyun.oss.bucketName=<#填写自己的bucketName#>
aliyun.oss.urlPrefix=<#填写自己的urlPrefix#>
spring.servlet.multipart.max-file-size=100MB
spring.servlet.multipart.max-request-size=1000MB
```

创建 `AliyunConfig.java` 配置类，获取 OSS Bean 实例

```java
@Configuration
@PropertySource(value = {"classpath:application-oss.properties"})
@ConfigurationProperties(prefix = "aliyun.oss")
@Data
public class AliyunConfig {

    private String endpoint;
    private String accessKeyId;
    private String accessKeySecret;
    private String bucketName;
    private String urlPrefix;

    @Bean
    public OSS ossClient() {
        return new OSSClientBuilder().build(endpoint, accessKeyId, accessKeySecret);
    }

}
```



## 实现上传接口

`UploadController.java`

```java
@Api(tags = "文件上传")
@RestController
@RequestMapping("/upload")
public class UploadController {

    // 允许上传的格式
    private static final String[] IMAGE_TYPE = new String[]{".bmp", ".jpg", ".jpeg", ".gif", ".png"};

    @Autowired
    private OSS ossClient;
    @Autowired
    private AliyunConfig aliyunConfig;

    @PostMapping(value = "/user/image", produces = {"multipart/form-data", "application/json"})
    @ResponseBody
    public Result<String> uploadUserImage(@RequestParam("file") MultipartFile file) {
        return imageUpload("user", file);
    }

    @PostMapping(value = "/brand/image", produces = {"multipart/form-data", "application/json"})
    @ResponseBody
    public Result<String> uploadBrandImage(@RequestParam("file") MultipartFile file) {
        return imageUpload("brand", file);
    }


    /**
     * 图片上传
     * @param folder 文件夹
     * @param file   图片
     * @return 文件oss路径
     */
    private Result<String> imageUpload(String folder, MultipartFile file) {
        // 校验图片格式
        boolean isLegal = false;
        for (String type : IMAGE_TYPE) {
            if (StringUtils.endsWithIgnoreCase(file.getOriginalFilename(), type)) {
                isLegal = true;
                break;
            }
        }

        if (!isLegal) {
            return Result.error(Codes.FILE_LEGAL_ERROR);
        }

        return fileUpload(folder, file);
    }

    /**
     * 文件上传
     * @param folder 文件夹
     * @param file   文件
     * @return 文件oss路径
     */
    private Result<String> fileUpload(String folder, MultipartFile file) {
        // 文件路径
        String filePath = getFilePath(folder, file.getOriginalFilename());

        // bucketName
        String bucketName = aliyunConfig.getBucketName();

        // 上传到阿里云
        try {
            // 判断Bucket是否存在
            if (ossClient.doesBucketExist(bucketName)) {
                System.out.println("已经创建了Bucket: " + bucketName);
            } else {
                System.out.println("Bucket不存在，创建Bucket: " + bucketName);
                ossClient.createBucket(bucketName);
            }

            // 查看Bucket信息
            BucketInfo info = ossClient.getBucketInfo(bucketName);
            System.out.println("Bucket " + bucketName + "的信息如下：");
            System.out.println("\t数据中心: " + info.getBucket().getLocation());
            System.out.println("\t创建时间: " + info.getBucket().getCreationDate());
            System.out.println("\t用户标志: " + info.getBucket().getOwner());

            // 文件存入OSS
            ossClient.putObject(bucketName, filePath, file.getInputStream());
            System.out.println("OSS存入成功: " + aliyunConfig.getUrlPrefix() + filePath);

        } catch (Exception e) {
            e.printStackTrace();
            return Result.error(Codes.FILE_UPLOAD_ERROR);
        }

        return Result.success(aliyunConfig.getUrlPrefix() + filePath);
    }

    /**
     * 获取文件保存
     *
     * @param sourceFileName 原文件名
     * @return 文件目标路径
     */
    private String getFilePath(String folder, String sourceFileName) {
        return folder + "/" + DateUtils.formatDate(new Date(), "yyyyMMdd-") + UUID.randomUUID() + "-" + sourceFileName;
    }

}
```



