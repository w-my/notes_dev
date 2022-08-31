# swagger 3.0



## springboot 项目集成 swagger 3.0

`pom.xml` 中添加依赖

```xml
<!-- swagger -->
<dependency>
    <groupId>io.springfox</groupId>
    <artifactId>springfox-boot-starter</artifactId>
    <version>3.0.0</version>
</dependency>
```

`application.properties` 中添加配置

```properties
spring.mvc.pathmatch.matching-strategy=ant_path_matcher
```

启动类添加注解 `@EnableOpenApi`

```java
@EnableOpenApi
@SpringBootApplication
public class DemoApplication {
    public static void main(String[] args) {
        SpringApplication.run(DemoApplication.class, args);
    }
}
```



## 使用

`Controller` 中使用

```java
@Api(tags="用户管理")
@RestController
public class UserController {

    @ApiOperation("创建用户")
    @PostMapping("/users")
    public User create(@RequestBody @Validated User user) {
        return user;
    }

    @ApiOperation("用户详情")
    @GetMapping("/users/{id}")
    public User findById(@PathVariable Long id) {
        return new User("bbb", 21, "上海", "aaa@bbb.com");
    }

    @ApiOperation("用户列表")
    @GetMapping("/users")
    public List<User> list(@ApiParam("查看第几页") @RequestParam int pageIndex,
                           @ApiParam("每页多少条") @RequestParam int pageSize) {
        List<User> result = new ArrayList<>();
        result.add(new User("aaa", 50, "北京", "aaa@ccc.com"));
        result.add(new User("bbb", 21, "广州", "aaa@ddd.com"));
        return result;
    }

    @ApiIgnore
    @DeleteMapping("/users/{id}")
    public String deleteById(@PathVariable Long id) {
        return "delete user : " + id;
    }
}
```

`model` 中使用

```java
@Data
@NoArgsConstructor
@AllArgsConstructor
@ApiModel("用户基本信息")
public class User {

    @ApiModelProperty("姓名")
    @Size(max = 20, message = "姓名最长20个字符")
    private String name;
    @ApiModelProperty("年龄")
	  @Max(value = 150, message = "年龄不能大于150")
    @Min(value = 1, message = "年龄不能小于1")
    private Integer age;
    @NotBlank(message = "地址不能为空")
    private String address;
    @Pattern(regexp = "^[a-zA-Z0-9_-]+@[a-zA-Z0-9_-]+(\\.[a-zA-Z0-9_-]+)+$")
    private String email;

}
```



## 访问 swagger 接口文档

默认访问地址：http://localhost:8080/swagger-ui/index.html

根据项目配置，修改访问路径：http://localhost:9101/api/swagger-ui/index.html

