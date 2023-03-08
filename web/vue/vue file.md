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
  var blob = new Blob([obj], { type: "application/json;charset=utf-8" });
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

资源目录有 `app.plist` 文件

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
  let data = div.childNodes[0].childNodes;
  data.forEach(item => {
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
      + div.childNodes[0].innerHTML 
      + '</plist>';

  this.plist = plist;
	// 下载
  this.downloadFile(this.plist, "app.plist");
	// 转成file，后续可保存到服务器
  this.saveFile(this.plist, "app.plist");
}
```



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

