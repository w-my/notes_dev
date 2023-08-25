

#### page

###### add

```js
window.open(
    this.$router.resolve({
        name: "Add",
        params: {
            pageView: "contracttemplatecreation",
        },
        query: this.$route.query,
    }).href,
    "_blank"
);
```

###### edit

```js
window.open(
    this.$router.resolve({
        name: 'Edit',
        params: {
            id: item._id,
            pageView: 'contracttemplatecreation'
        },
        query: this.$route.query
    }).href,
    "_blank"
);
```

###### preview

```js
window.open(
    this.$router.resolve({
        name: "Preview",
        params: {
            id: item._id,
            pageView: "contracttemplatecreation",
        },
        query: this.$route.query,
    }).href,
    "_blank"
);
```



#### Const

###### 设备类型判断

- this.$vuetify.breakpoint.mobile







#### 正则

```js
switch (type) {
  case "en":
    regExp = /^[A-Za-z\s0-9~!@#$%^&*()_+{}|:"<>?`\-=\[\]\\;',.\/]+$/;
    errorMessage = "Only accept English, numbers and symbols";
    break;

  case "chinese":
    // regExp = new RegExp("^[\u4e00-\u9fa50-9_]+$");
    regExp = /^[\u4e00-\u9fa50-9\s0-9~!@#$%^&*()_+{}|:"<>?`\-=\[\]\\;',.\/]+$/;
    errorMessage = "Only accept Chinese, numbers and symbols";
    break;
  case "link":
    regExp = new RegExp("[a-zA-z]+://[^\s]*");
    errorMessage = "Link to Sharedrive: Internal Link that direct to DMS folder in Smart at Work";
    break;
  case "email":
    regExp = /^\w+([-+.]\w+)*@\w+([-.]\w+)*\.\w+([-.]\w+)*$/;
    errorMessage = "Incorrect Email format";
    break;
  case "number":
    regExp = new RegExp("^[0-9]*$");
    errorMessage = "Only accept Number";
    break;
  case "decimal":
    regExp = /^[0-9]+(\.[0-9]{1,})?$/;
    errorMessage = "Only accept Number with decimal places";
    break;
}
```

