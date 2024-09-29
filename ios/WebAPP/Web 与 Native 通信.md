# WebView 与 Native 通信

- [看完就懂的Hybrid框架设计方案](https://cloud.tencent.com/developer/article/2408020)



## e.g. Js 查询设备信息

这种场景本质是 JS 调用 Native 的一个函数，Native 收到请求后，把数据回传给 JS。整个过程分为 JS -> Native、Native -> JS 两个阶段。

Native -> JS 时，涉及到 Webview 调用 JS 的全局函数，为了避免暴露过多全局变量，设计时我们只暴露全局唯一对象，然后再将相关的方法挂载在这个对象上。核心代码如下：

```js
const invokeMap = new Map();
let invokeId = 0;

class BridgeNameSpace {
  /**
   * 调用Native功能
   * @param eventName - 事件名称
   * @param params - 通讯数据
   * @param callback - 回调函数
   */
  invoke = (eventName, params, callback) => {
    invokeId += 1;
    invokeMap.set(invokeId, callback);

    if (isAndroid) {
      window.BridgeNameSpace.invokeHandler(eventName, params, invokeId);
    } else {
      window.webkit.messageHandlers.invokeHandler.postMessage({
        event: eventName,
        params,
        callbackId: invokeId,
      });
    }
  };
  
  /**
   * 调用Native功能
   * @param eventName - 事件名称
   * @param params - 通讯数据
   * @param callback - 回调函数
   */
  invokeSync(eventName, params, callback) {
    invokeId += 1;
    invokeMap.set(invokeId, callback);

    if (isAndroid) {
      window.BridgeNameSpace.invokeHandler(eventName, params, invokeId);
    } else {      // 将消息体直接JSON字符串化，调用 Prompt(),并且可以直接拿到返回值        
      const result = prompt(JSON.stringify(params));
      return result;
    }
  }
  
  /**
   * Native将invoke结果返回给js的回调句柄
   * @param id - callbackId
   * @param params - 通讯数据
   */
  invokeCallbackHandler = (id, params) => {
    const fn = invokeMap.get(id);
    if (typeof fn === 'function') {
      fn(params);
    }
    invokeMap.delete(id);
  };
  
  getSystemInfo(callback) {
    const promsie = new Promise((resolve, reject) => {
      this.invoke('getSystemInfo', {}, (res) => {
        if (res.status === 'success') {
          resolve(res);
        } else {
          reject(res);
        }
      });
    });

    if (callback) {
      return promsie.then(callback).catch(callback);
    }

    return promsie;
  }
}

window.BridgeNameSpace = new BridgeNameSpace();
```

整个流程分为以下几个调用步骤：

1. JS 调用 invoke，生成一个唯一的 callbackId，将 callbackId 和 callback 注册到全局变量 invokeMap 中。
2. iOS 端，JS 将参数通过 MessageHandler 传递给 Native；安卓通过 Interface 注入的方式，JS 可以直接调用 Native 的方法。
3. Native 执行业务逻辑，并调用回调函数 BridgeNameSpace.invokeCallbackHandler。
4. 通过调用时生成的唯一的 callbackId， 从 invokeMap 中找到最初发起调用的 JS callback，执行并回传数据。

业务方调用支持 Promise 和 callback 两种调用风格：

```js
BridgeNameSpace.getSystemInfo()
    .then(res => {
        console.log(res);
    })
    .catch(err => {
        console.log(err);
    });

BridgeNameSpace.getSystemInfo((res) => {
    console.log(res);
});
```



## 当 Webview 可见时，JS 捕获这个时机来做相应的业务逻辑

这里只涉及 Native 单向通知到 JS，是标准的发布订阅模式。Native 和 JS 侧约定好事件名，JS 侧提前注册事件，当事件发生时，Native 主动调用 JS。核心实现如下：

```js
const publishMap = {};

class BridgeNameSpace {
  /**
   * 订阅 Native 事件
   * @param eventName - 事件名
   * @param callback - 回调函数
   */
   subscribe = (eventName, callback) => {
    if (!publishMap[eventName]) {
      publishMap[eventName] = [];
    }
    
    const oldEvents = publishMap[eventName];
    publishMap[eventName] = oldEvents.concat(callback);
  };
  /**
   * Native将publish结果返回给js的回调句柄
   * @param eventName - 事件名
   * @param params - 调用参数
   */
  subscribeCallbackHandler = (eventName, params) => {
    const cbs = publishMap[eventName] || [];
    if (cbs.length) {
      cbs.forEach((cb) => cb(params));
    }
  };
  
  /**
   * ⻚⾯可⻅通知
   */
  onPageVisible(callback) {
    this.subscribe(
      'onPageVisible',
      callback,
    );
  }
}
```

业务方订阅示例：

```js
BridgeNameSpace.onPageInvisible(() => {});
```

不同于 JS 主动调用 Native 函数，订阅不能直接拿到结果，所有没有 Promise 调用风格，只能是 callback 形式。实际在设计 API 时，可以从命名上做一些区分，比如订阅类型的函数都以 onXX 开头。同时，映射表也由单独 publishMap 来维护。



## 场景三：打开了两个 Webview 页面 A B，B 页面向 A 页面传递一些数据

对于 JS 来说，只能获取到当前 Webview 上下文，单纯通过 JS 是不能感知到其他 Webview 存在的。所以两个 Webveiw 之间要通信，需要借助 Native 做中转，其通信模型如下： （一个 App 内在使用多套框架时，不同框架之间通信也可以基于这个模型）

Webview 之间通信分为三个步骤：

1. Webview A 订阅事件，不同于场景二的订阅模式，订阅结果需要维护在 Native，所以这里需要有一次 JS -> Native 调用。
2. Webview B 发起通知，先通知到 Native，这里也有一次 JS -> Native 调用。
3. Native 收到通知后，发起一次广播，之前所有注册过的 Webview 都会收到通知，这里有一次 Native -> JS 调用。

那么如何来设计这个通信模型呢？

1. JS -> Native 订阅其实就是一次基本的 JS -> Native 函数调用，这里需要约定一个特定的事件名。
2. JS -> Native 通知同理，也需要约定一个特定的事件名。
3. Native -> JS 广播，是类似于 invokeCallbackHandler、subscribeCallbackHandler 的回调调用，我们也用一个 notifyMap 来维护这个映射关系。

```js
const notifyMap = new Map();

class BridgeNameSpace {
  /**
   * 混合式框架向Native发送通知 notify
   * @param eventName - 事件名，命名空间为当前包
   * @param params - 参数对象，由通知业务自己定义
   * @param callback - 回调函数，回调是否通知成功
   */
  notify = (eventName, params, callback) => {
    this.invoke('notify', { event: eventName, params }, callback);
  };

  /**
   * webview 事件处理函数，可与notify配合使用
   * 事件订阅方法，可对本应用及跨应用事件进行订阅
   * @param {String} eventName
   * @param {Function} callback
   */
  subscribeNotify = (eventName, callback) => {
    this.invoke('subscribeNotification', { event: eventName }, (res) => {
      if (res.status === 'success') {
        notifyMap.set(eventName, callback);
      } else {
        callback(res);
      }
    });
  };

  /**
   * Native将notify结果返回给js的回调句柄
   * @param eventName - 事件名
   * @param params - 调用参数
   */
  notifyCallbackHandler = (eventName, params) => {
    const fn = notifyMap.get(eventName);
    if ('function' === typeof fn) {
      fn(params);
    } else {
      notifyMap.delete(eventName);
    }
  };
}
```

业务代码调用示例：

```js
// Webview A 订阅
BridgeNameSpace.subscribeNotify(
  'QSOverlayPlayerBackClick', 
  (res) => {
    console.log(res);
  }
);

// Webview B 通知
BridgeNameSpace.notify(
  'QSOverlayPlayerBackClick',
  { test: 'a' },
  (res) => {
    if (res.status === 'success') {      console.log('通知成功');
     }
  }
);
```

