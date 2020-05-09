## iOS 为 mobileconfig 描述文件签名



#### 使用ssl证书进行签名

> [http://www.rootmanager.com/iphone-ota-configuration/iphone-ota-setup-with-signed-mobileconfig.html](http://www.rootmanager.com/iphone-ota-configuration/iphone-ota-setup-with-signed-mobileconfig.html)



#### 使用苹果开发者证书进行签名

##### 使用命令行方式签名
- 从钥匙串(keychain)中导出证书
      实用工具->钥匙串访问->选择要导出的证书,导出生成p12文件 InnovCertificates.p12
- p12换成pem格式方法
      p12在线转换pem   https://www.sslshopper.com/ssl-converter.html
      (证书)cer.p12文件 转cer.pem文件
      openssl pkcs12 -clcerts -nokeys -out cer.pem -in cer.p12
      (私钥)key.p12文件转key.pem文件
      openssl pkcs12 -nocerts -out key.pem -inkey.p12
- 下载 Apple Root Certificate 和 Apple Intermediate Certificate
      (对于本篇文章 .mobileconfig文件的验证我使用了苹果的以下两个证书.
      Apple Root Certificate(苹果根证书)
      Apple Application Integration Certificate (苹果应用集成证书 )
      你也可以使用这些证书或者苹果提供的其他证书 地址:         http://www.apple.com/certificateauthority/
      下载的文件中包括证书(cer)和私钥(key)
      (在命令行中读取证书,参考链接 info.ssl.com/article.aspx?id=12149)
      根据这个文件我们可以解压出来证书.
> 解压 Apple Root Certificate证书. 然后解压Apple Intermediate Certificate
> openssl x509 -inform DER -outform PEM -in AppleIncRootCertificate.cer -out root.crt.pem
> openssl x509 -inform DER -outform PEM -in AppleAAICA.cer -out Intermediate.crt.pem 
> 在文本编辑器中打开两个解压出来的文件
> 复制并且粘贴Intermediate.crt.pem 到 root.crt.pem的开始位置,保存,然后你的root.crt.pem文件就是两个证书合并的结果

- 签名和验证.mobileconfig文件
上边所有文件准备号后,运行命令行工具,运行以下命令
openssl smime -sign -in Example.mobileconfig -out SignedVerifyExample.mobileconfig -signer InnovCertificates.pem -certfile root.crt.pem -outform der -nodetach
结果就是签名并且验证后的 .mobileconfig文件



##### 使用脚本签名

先从`github`上找到 [python](https://github.com/nmcspadden/ProfileSigner) 脚本，将脚本文件`profile_signer.py`和描述文件`Example.mobileconfig`放在同一目录下。
> **注：**以下命令中使用的 `"iPhone Distribution: XXXXXX Network Technology Co., Ltd (XXXXXX)"`  为证书在钥匙串中显示的全名。（ 获取方式：钥匙串 -> 选中证书 -> 显示简介 -> 常用名称 ）

- 对`Example.mobileconfig`进行签名
      ./profile_signer.py -n "iPhone Distribution: XXXXXX Network Technology Co., Ltd (XXXXXX)" sign Example.mobileconfig AcrobatProSigned.mobileconfig
- 对`Example.mobileconfig`进行加密
      ./profile_signer.py -n "iPhone Distribution: XXXXXX Network Technology Co., Ltd (XXXXXX)" encrypt Example.mobileconfig AcrobatProEnc.mobileconfig
- 对`Example.mobileconfig`进行签名并加密
      ./profile_signer.py -n "iPhone Distribution: XXXXXX Network Technology Co., Ltd (XXXXXX)" both Example.mobileconfig AcrobatProBoth.mobileconfig

![](http://upload-images.jianshu.io/upload_images/1599548-f24a5549d881c19b.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)
如果能正确读取到证书，会看到如图提示，选择`允许`即可完成签名！