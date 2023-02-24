[TOC]



# DM

## 多语言

```vue
this.$te("page_home." + this.schema.name + ".homeMenuTitle")
```



## 获取资源文件

```vue
<v-img :src="getResource('abc.png')"></v-img>

this.getResource('abc.png')
```



## 路由

**新页签打开**

```vue
goTo(pageView) {
    window.top.location.href = this.$router.resolve({
        name: "View",
        params: {
            pageView: pageView,
        },
        query: this.$route.query,
    }).href;
}
```

**方式二：**

跳转传参：

```vue
var queryObj = JSON.parse(JSON.stringify(this.$route.query));
queryObj.userid = "bf1741d5-c9cd-46e9-b9af-79247a35cc92";
window.open(
	this.$router.resolve({
   name: "Edit",
   params: {
     id: "74641d8f-20ee-4258-851b-5db8e10b5f04";
     pageView: "sealborrowingform",
     p1: "2021-11",
     p2: "2022-09",
   },
   query: queryObj,
 }).href
);
```

获取参数：

```vue
this.$route.params.pageview --- sealborrowingform
this.$route.params.id --- 74641d8f-20ee-4258-851b-5db8e10b5f04
this.$route.query.userid --- bf1741d5-c9cd-46e9-b9af-79247a35cc92
this.$route.query.env --- dev
```





## Api

```js
async getList() {
    let self = this;
    const params = {
        PageCode: "appform",
        SearchItems: [
            {
                "name": "appId",
                "value": self.appId,
                "operator": "Equal",
                "method": "And",
                "subSearchItems": []
            },
            {
                "name": "env",
                "value": self.env,
                "operator": "Equal",
                "method": "And",
                "subSearchItems": []
            },
            {
                "name": "Ng_SysIsDeleted",
                "value": false,
                "operator": "Equal",
                "method": "And",
                "subSearchItems": []
            }
        ],
        Columns: [],
        Order: {},
        Index: 0,
        Offset: 0,
        Size: 1000,
    };
    let result = await self.callApi("GetDocs", params);
    if (result && result.statusCode && result.statusCode === 200) {
        let res = [];
        if (result.data && result.data.items && result.data.items.length > 0) {
            
        }
        self.items = res;
    }
}
```



## 弹窗

```vue
<template>
  <div>
    <v-btn @click="popUpFormClick()">
      popUpForm
    </v-btn>
  </div>
</template>
<script>
export default {
  methods: {
    popUpFormClick() {
      this.popupForm.open({
        pageView: "", // 页面唯一标识
        pageMode: "", // Add、Preview、Edit
        id: "",       // 非必须 	Preview、Edit时需要
        pageType: "", // Form、Page
        title: "",    // 弹框title
        classes: "",  // 弹框class
        beforeFormLoad: function (model) {
          // 弹框渲染前，处理业务逻辑
        }.bind(this),
        afterFormLoad: function (model) {
          // 弹框渲染后，处理业务逻辑
        }.bind(this),
        beforeFormSubmit: function (model) {
          // save按钮点击之后未提交数据，处理业务逻辑
        }.bind(this),
        afterFormSubmit: function (model) {
          // save按钮点击之后提交数据，处理业务逻辑          
        }.bind(this)
      });
    },
  },
  inject: {
    popupForm: {
      default: {
        open: function () { },
        reload: function () { },
        close: function () { }
      }
    }
  }
}
</script>
```



## 内嵌

```vue
<template>
  <div>
    <pageObject :settings="settings"></pageObject>
  </div>
</template>

<script>
  export default {
    data() {
      return {
        settings: {
          pageCode: "", // 页面唯一标识
          pageType: "", // Form、Page
          pageMode: "", // Add、Preview、Edit
          docId: "", // 非必须 	Preview、Edit时需要
          objectContainerClass: "", // 内嵌class
          params: {
            usePageObjcet: true
          }
        }
      }
    }
  }
</script>
```



## 邮件

```js
SendEmailInputModel model = new SendEmailInputModel() {   
    FromTemplate = true, // 是否来自于模板
    EmailParameter = new PwC.Ng.Customization.EmailParameter(){
        TemplateCode="5f909db056a145169eded396bedb763b",
        // 模板唯一标识
        Parameter=new Dictionary<string, string>(){ // 模板参数
            {"visitlink",previewDocLink}
        }
    },
    MailFrom = "", // 发件人邮箱
    MailTo = new List<string>(), // 收件人邮箱
    MailCC = new List<string>(), // 抄送人邮箱
    MailBCC = new List<string>(),// 暗送人邮箱
    IsImmediate = true           // 是否立即发送
};

var res = await Service.SendEmailAsync(model);
```

**Webapi 示例**

```vue
<template>
  <div>
    <v-btn @click="sendEmailClick()">
      Send Email
    </v-btn>
  </div>
</template>

<script>
  export default {
    methods: {
      async sendEmailClick() {
        await self.callApi("SendEmail", {
          mailFrom: "",    // 发件人邮箱
          mailTo: [],      // 收件人邮箱
          mailCC: [],      // 抄送人邮箱
          mailBCC: [],     // 暗送人邮箱
          mailReplyTo: "", // 回复邮箱
          subject: "",     // 邮件标题
          content: "",     // 邮件内容，如果使用模板则内容为空
          EmailParameter: {// 模板                                     
            TemplateCode: "675768dd5f8b4613b7446ce774b29926",
            // 模板唯一标识
            Parameter: { // 模板参数
              taskowner: "",
              reminddetails: "",
              Ng_SystemDocLink: "",
            },
          },
          fromTemplate: true, // 是否来自于模板
          isImmediate: true,  // 是否立即发送
        });
      }
    }
  } 
</script>
```



