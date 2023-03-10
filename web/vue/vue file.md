# Vue file文件操作

如下是一个plist文件内容的string：

```js
let plistStr = '<?xml version="1.0" encoding="UTF-8"?>\
        <!DOCTYPE plist PUBLIC "-//Apple//DTD PLIST 1.0//EN" "http://www.apple.com/DTDs/PropertyList-1.0.dtd">\
        <plist version="1.0">\
          <dict>\
            <key>items</key>\
            <array>\
              <dict>\
                <key>assets</key>\
                <array>\
                  <dict>\
                    <key>kind</key>\
                    <string>software-package</string>\
                    <key>url</key>\
                    <string>https://baidu.com</string>\
                  </dict>\
                </array>\
                <key>metadata</key>\
                <dict>\
                  <key>bundle-identifier</key>\
                  <string>com.dgq.tcp</string>\
                  <key>bundle-version</key>\
                  <string>v1.0.0</string>\
                  <key>kind</key>\
                  <string>software</string>\
                  <key>title</key>\
                  <string>appname</string>\
                </dict>\
              </dict>\
            </array>\
          </dict>\
        </plist>\
      ';
```



## 保存为本地文件

```vue
downloadFile(obj, filename) {
  var blob = new Blob([obj], { type: "text/plain;charset=utf-8" });
  var url = URL.createObjectURL(blob);
  var elem = document.createElement("a");
  elem.href = url;
  elem.download = filename;
  document.body.appendChild(elem);
  elem.click();
  document.body.removeChild(elem);
},
```

```vue
this.downloadFile(plistStr, "app.plist");
```



## 转换成file，以上传服务器

```vue
// 转成file，以上传服务器
saveFile(obj, filename) {
  let blob = new Blob([obj], { type: 'text/xml;charset=utf-8' });
  let textContain = this.transToFile(blob, filename, "text/plain");
  // 转换完成后可以将file对象传给接口
  textContain.then((res) => {
    let file = res
    console.log("file: ", file)
  })
},
// 这么写是因为文件转换是异步任务
async transToFile(blob, fileName, fileType) {
  return await new window.File([blob], fileName, { type: fileType })
},
```

```vue
this.saveFile(plistStr, "app.plist");
```



## 读取plist文件并修改

`public` 资源目录有 `app.plist` 文件

```vue
this.readPlistFile('app.plist');
```

```vue
readPlistFile(filePath) {
  let xhr = null;
  if (window.XMLHttpRequest) {
    xhr = new XMLHttpRequest()
  }
  xhr.open('GET', filePath, false);
  xhr.overrideMimeType('text/html;charset=utf-8');
  xhr.send(null);
  console.log("==> xhr: ", xhr);
  let div = document.createElement("root");
  if (typeof xhr.responseText === "string") div.innerHTML = xhr.responseText.replace(/\s*/g, "");
  console.log("==> div: ", div);

  let plistNode;
  div.childNodes.forEach(item => {
    if (item.nodeName.indexOf('PLIST') >= 0) {
      plistNode = item;
    }
  })
  if (plistNode) {
    plistNode.childNodes.forEach(item => {
      if (item.nodeName === "DICT") {
        item.childNodes.forEach(item => {
          if (item.nodeName === "ARRAY") {
            item.childNodes.forEach(item => {
              if (item.nodeName === "DICT") {
                item.childNodes.forEach(item => {
                  if (item.nodeName === "ARRAY") {
                    item.childNodes.forEach(item => {
                      if (item.nodeName === "DICT") {
                        if (4 === item.childNodes.length) {
                          let url = item.childNodes[3];
                          url.innerText = "http://baidu.com";
                        }
                      }
                    })
                  }
                  if (item.nodeName === "DICT") {
                    if (8 === item.childNodes.length) {
                      let bundleID = item.childNodes[1];
                      bundleID.innerText = "bundle_id";
                      let version = item.childNodes[3];
                      version.innerText = "v1.0.0";
                      let appName = item.childNodes[7];
                      appName.innerText = "appname";
                    }
                  }
                })
              }
            })
          }
        })
      }
    })
    let plist = '<?xml version="1.0" encoding="UTF-8"?>\
    <!DOCTYPE plist PUBLIC "-//Apple//DTD PLIST 1.0//EN" "http://www.apple.com/DTDs/PropertyList-1.0.dtd">\
    <plist version="1.0">'
      + plistNode.innerHTML
      + '</plist>';

    this.plist = plist;
    this.downloadFile(this.plist, "app.plist");
    this.saveFile(this.plist, "app.plist");
  }
}
```



# 上传到华为云 OBS

前端直接上传到华为云

使用 npm 导入包

安装：

```sh
npm i esdk-obs-browserjs
```

引入：

```sh
import ObsClient from 'esdk-obs-browserjs/src/obs'
import { nanoid } from 'nanoid'
```

使用：

```vue
async upload() {
  let obj = this.getPlistStr();
  let file = await this.getFile(obj);
  this.putToObs(file);
},  

async getFile(obj) {
  let blob = new Blob([obj], { type: 'text/xml;charset=utf-8' });
  return new File([blob], 'app.plist', { type: 'text/xml' });
},

async putToObs(file) {
  const ak = 'WVV14YQUYXBCMOBMSUCT';
  const sk = 'al8tEuNCT2j9m4iuS2RHiM2bgL2WnBFSFOFAjaWr';
  const server = 'obs.cn-east-3.myhuaweicloud.com';
  const bucket = 'digiqal';
  const key = nanoid() + '.plist';

  // 创建ObsClient实例
  var obsClient = new ObsClient({
    access_key_id: ak,
    secret_access_key: sk,
    server: server
  });

  var callback = function (transferredAmount, totalAmount, totalSeconds) {
    // 获取上传平均速率（KB/S）
    console.log(transferredAmount * 1.0 / totalSeconds / 1024);
    // 获取上传进度百分比
    console.log(transferredAmount * 100.0 / totalAmount);
    // 百分比取整数
    console.log(Math.floor(transferredAmount * 100.0 / totalAmount))
  };

  obsClient.putObject({
    Bucket: bucket, // 桶名
    Key: key, // 路径 + 文件名
    SourceFile: file,
    ProgressCallback: callback
  }, function (err, result) {
    if (err) {
      console.error('Error-->' + err)
    } else {
      console.log('Status-->', result.CommonMsg.Status, 'https://' + bucket + '.' + server + '/' + key)
    }
  })
},
```

上传后的文件路径，需要自己拼接：

```sh
'https://' + bucket + '.' + server + '/' + key
```



**问题**

> Access to XMLHttpRequest at 'https://xxx.obs.cn-north-4.myhuaweicloud.com/?apiversion' from origin 'http://localhost:8080' has been blocked by CORS policy: Response to preflight request doesn't pass access control check: No 'Access-Control-Allow-Origin' header is present on the requested resource.

是跨域问题

解决办法:

去华为云官网，配置桶的CORS



# 实现 iOS 内测平台下载安装

`app.ipa` 和 `app.plist` 文件上传到服务器，通过安装器实现安装。

```js
<script type="text/javascript">
    window.location = "itms-services://?action=download-manifest&url=" + "https://digiqal.com/app.plist";
</script>
```

或

```js
<script>
  document.getElementById('button').addEventListener('click', function() {
    window.open('itms-services://?action=download-manifest&url=' + 'https://digiqal.com/app.plist', '_self')
  })
</script>
```



