# Promise

## Promise

`JavaScript` 中存在很多异步操作, `Promise` 将异步操作队列化，按照期望的顺序执行，返回符合预期的结果。可以通过链式调用多个 `Promise` 达到我们的目的。



## 异步状态

Promise 可以理解为承诺，就像我们去KFC点餐服务员给我们一引取餐票，这就是承诺。如果餐做好了叫我们这就是成功，如果没有办法给我们做出食物这就是拒绝。

- 一个 `promise` 必须有一个 `then` 方法用于处理状态改变

#### 状态说明

Promise 包含 `pending`、`fulfilled`、`rejected`三种状态

- `pending` 指初始等待状态，初始化 `promise` 时的状态
- `resolve` 指已经解决，将 `promise` 状态设置为`fulfilled`
- `reject` 指拒绝处理，将 `promise` 状态设置为`rejected`
- `promise` 是生产者，通过 `resolve` 与 `reject` 函数告之结果
- `promise` 非常适合需要一定执行时间的异步任务
- 状态一旦改变将不可更改

`promise` 是队列状态，就像体育中的接力赛，或多米诺骨牌游戏，状态一直向后传递，当然其中的任何一个`promise` 也可以改变状态。

`promise` 创建时即立即执行即同步任务，`then` 会放在异步微任务中执行，需要等同步任务执行后才执行。

```js
let promise = new Promise((resolve, reject) => {
  resolve("fulfilled");
  console.log("aaa");
});
promise.then(msg => {
  console.log(msg);
});
console.log("bbb.com");
```

下例在三秒后将 `Promise` 状态设置为 `fulfilled` ，然后执行 `then` 方法

```js
new Promise((resolve, reject) => {
  setTimeout(() => {
    resolve("fulfilled");
  }, 3000);
}).then(
  msg => {
    console.log(msg);
  },
  error => {
    console.log(error);
  }
);
```



#### 动态改变

下例中p2 返回了p1 所以此时p2的状态已经无意义了，后面的then是对p1状态的处理。

```js
const p1 = new Promise((resolve, reject) => {
  // resolve("fulfilled");
  reject("rejected");
});
const p2 = new Promise(resolve => {
  resolve(p1);
}).then(
  value => {
    console.log(value);
  },
  reason => {
    console.log(reason);
  }
);
```

下例中 `p1` 的状态将被改变为 `p2` 的状态

```js
const p1 = new Promise((resolve, reject) => {
  resolve(
  	//p2
    new Promise((s, e) => {
      s("成功");
    })
  );
}).then(msg => {
  console.log(msg);
});
```



## then

一个 `promise` 需要提供一个 `then` 方法访问 `promise` 结果，`then` 用于定义当 `promise` 状态发生改变时的处理，即 `promise` 处理异步操作，`then` 用于结果。

- then 方法必须返回 promise，用户返回或系统自动返回
- 第一个函数在 `resolved` 状态时执行，即执行 `resolve` 时执行 `then` 第一个函数处理成功状态
- 第二个函数在 `rejected` 状态时执行，即执行 `reject` 时执行第二个函数处理失败状态，该函数是可选的
- 两个函数都接收 `promise` 传出的值做为参数
- 也可以使用 `catch` 来处理失败的状态
- 如果 `then` 返回 `promise` ，下一个 `then` 会在当前 `promise`  状态改变后执行



#### 语法说明

`then` 的语法如下，`onFulfilled` 函数处理 `fulfilled` 状态， `onRejected` 函数处理 `rejected` 状态

- onFulfilled 或 onRejected 不是函数将被忽略
- 两个函数只会被调用一次
- onFulfilled 在 promise 执行成功时调用
- onRejected 在 promise 执行拒绝时调用

```js
promise.then(onFulfilled, onRejected);
```



#### 链式调用

每次的 `then` 都是一个全新的 `promise`，默认 `then` 返回的 `promise` 状态是 `fulfilled`

```js
let promise = new Promise((resolve, reject) => {
  resolve("fulfilled");
}).then(resolve => {
  console.log(resolve);
})
.then(resolve => {
  console.log(resolve);
});
```

如果 `then` 返回 `promise` 时，返回的 `promise` 后面的 `then` 就是处理这个 `promise` 的

```js
new Promise((resolve, reject) => {
  resolve();
})
.then(v => {
  return new Promise((resolve, reject) => {
    resolve("第二个promise");
  });
})
.then(value => {
  console.log(value);
  return value;
})
.then(value => {
  console.log(value);
});
```



#### 其它类型

Promise 解决过程是一个抽象的操作，其需输入一个 `promise` 和一个值，我们表示为 `[[Resolve]](promise, x)`，如果 `x` 有 `then` 方法且看上去像一个 Promise ，解决程序即尝试使 `promise` 接受 `x` 的状态；否则其用 `x` 的值来执行 `promise` 。

##### 循环调用

如果 `then` 返回与 `promise` 相同将禁止执行

```js
let promise = new Promise(resolve => {
  resolve();
});
let p2 = promise.then(() => {
  return p2;
}); // TypeError: Chaining cycle detected for promise
```

##### promise

如果返加值是 `promise` 对象，则需要更新状态后，才可以继承执行后面的`promise`

```js
new Promise((resolve, reject) => {
  resolve(
    new Promise((resolve, reject) => {
      setTimeout(() => {
        resolve("解决状态");
      }, 2000);
    })
  );
})
.then(
  v => {
    console.log(`fulfilled: ${v}`);
    return new Promise((resolve, reject) => {
      setTimeout(() => {
        reject("失败状态");
      }, 2000);
    });
  },
  v => {
    console.log(`rejected: ${v}`);
  }
)
.catch(error => console.log(`rejected: ${error}`));
```

##### Thenables

包含 `then` 方法的对象就是一个 `promise` ，系统将传递 resolvePromise 与 rejectPromise 做为函数参数

下例中使用 `resolve` 或在`then` 方法中返回了具有 `then`方法的对象

- 该对象即为 `promise` 要先执行，并在方法内部更改状态
- 如果不更改状态，后面的 `then` promise都为等待状态

```js
new Promise((resolve, reject) => {
  resolve({
    then(resolve, reject) {
      resolve("解决状态");
    }
  });
})
.then(v => {
  console.log(`fulfilled: ${v}`);
  return {
    then(resolve, reject) {
      setTimeout(() => {
        reject("失败状态");
      }, 2000);
    }
  };
})
.then(null, error => {
  console.log(`rejected: ${error}`);
});
```

包含 `then` 方法的对象可以当作 promise来使用

```js
class User {
  constructor(id) {
    this.id = id;
  }
  then(resolve, reject) {
    resolve(ajax(`http://localhost:8888/php/houdunren.php?id=${this.id}`));
  }
}
new Promise((resolve, reject) => {
  resolve(ajax(`http://localhost:8888/php/user.php?name=向军`));
})
.then(user => {
  return new User(user.id);
})
.then(lessons => {
  console.log(lessons);
});
```

如果对象中的 then 不是函数，则将对象做为值传递

```js
new Promise((resolve, reject) => {
  resolve();
})
.then(() => {
  return {
    then: "后盾人"
  };
})
.then(v => {
  console.log(v); //{then: "后盾人"}
});
```



## catch

使用未定义的变量同样会触发失败状态

```js
let promise = new Promise((resolve, reject) => {
  hd;
}).then(
  value => console.log(value),
  reason => console.log(reason)
);
```

如果 onFulfilled 或 onRejected 抛出异常，则 p2 拒绝执行并返回拒因

```js
let promise = new Promise((resolve, reject) => {
  throw new Error("fail");
});
let p2 = promise.then();
p2.then().then(null, resolve => {
  console.log(resolve + ",后盾人");
});
```

catch用于失败状态的处理函数，等同于 `then(null,reject){}`

- 建议使用 `catch` 处理错误
- 将 `catch` 放在最后面用于统一处理前面发生的错误

```js
const promise = new Promise((resolve, reject) => {
  reject(new Error("Notice: Promise Exception"));
}).catch(msg => {
  console.error(msg);
});
```

`catch` 可以捕获之前所有 `promise` 的错误，所以建议将 `catch` 放在最后。下例中 `catch` 也可以捕获到了第一个 `then` 返回 的 `promise` 的错误。

```js
new Promise((resolve, reject) => {
  resolve();
})
.then(() => {
  return new Promise((resolve, reject) => {
    reject(".then ");
  });
})
.then(() => {})
.catch(msg => {
  console.log(msg);
});
```

错误是冒泡的操作的，下面没有任何一个`then` 定义第二个函数，将一直冒泡到 `catch` 处理错误

```js
new Promise((resolve, reject) => {
  reject(new Error("请求失败"));
})
.then(msg => {})
.then(msg => {})
.catch(error => {
  console.log(error);
});
```

`catch` 也可以捕获对 `then` 抛出的错误处理

```js
new Promise((resolve, reject) => {
  resolve();
})
.then(msg => {
  throw new Error("这是then 抛出的错误");
})
.catch(() => {
  console.log("33");
});
```

`catch` 也可以捕获其他错误，下面在 `then` 中使用了未定义的变量，将会把错误抛出到 `catch`

```js
new Promise((resolve, reject) => {
  resolve("success");
})
.then(msg => {
  console.log(a);
})
.catch(reason => {
  console.log(reason);
});
```



#### 使用建议

建议将错误要交给 `catch` 处理而不是在 `then` 中完成，不建议使用下面的方式管理错误

```js
new Promise((resolve, reject) => {
  reject(new Error("请求失败"));
}).then(
  msg => {
    console.log(msg);
  },
  error => {
    console.log(error);
  }
);
```



#### 定制错误

可以根据不同的错误类型进行定制操作，下面将参数错误与404错误分别进行了处理

```js
class ParamError extends Error {
  constructor(msg) {
    super(msg);
    this.name = "ParamError";
  }
}
class HttpError extends Error {
  constructor(msg) {
    super(msg);
    this.name = "HttpError";
  }
}
function ajax(url) {
  return new Promise((resolve, reject) => {
    if (!/^http/.test(url)) {
      throw new ParamError("请求地址格式错误");
    }
    let xhr = new XMLHttpRequest();
    xhr.open("GET", url);
    xhr.send();
    xhr.onload = function() {
      if (this.status == 200) {
        resolve(JSON.parse(this.response));
      } else if (this.status == 404) {
        // throw new HttpError("用户不存在");
        reject(new HttpError("用户不存在"));
      } else {
        reject("加载失败");
      }
    };
    xhr.onerror = function() {
      reject(this);
    };
  });
}

ajax(`http://localhost:8888/php/user.php?name=后盾人`)
.then(value => {
  console.log(value);
})
.catch(error => {
  if (error instanceof ParamError) {
    console.log(error.message);
  }
  if (error instanceof HttpError) {
    alert(error.message);
  }
  console.log(error);
});
```



#### 事件处理

**unhandledrejection ** 事件用于捕获到未处理的Promise错误，下面的 then 产生了错误，但没有`catch`处理，这时就会触发事件。该事件有可能在以后被废除，处理方式是对没有处理的错误直接终止。

```js
window.addEventListener("unhandledrejection", function(event) {
  console.log(event.promise); // 产生错误的promise对象
  console.log(event.reason); // Promise的reason
});

new Promise((resolve, reject) => {
  resolve("success");
}).then(msg => {
  throw new Error("fail");
});
```



## finally

无论状态是 `resolve` 或 `reject` 都会执行此动作，`finally` 与状态无关。

```js
const promise = new Promise((resolve, reject) => {
  reject("hdcms");
})
.then(msg => {
  console.log("resolve");
})
.catch(msg => {
  console.log("reject");
})
.finally(() => {
  console.log("resolve/reject状态都会执行");
});
```



## 实例操作

#### 异步请求

下面是将 `ajax` 修改为 `promise` 后，代码结构清晰了很多

```js
function ajax(url) {
  return new Promise((resolve, reject) => {
    let xhr = new XMLHttpRequest();
    xhr.open("GET", url);
    xhr.send();
    xhr.onload = function() {
      if (this.status == 200) {
        resolve(JSON.parse(this.response));
      } else {
        reject(this);
      }
    };
  });
}

ajax("http://localhost:8888/php/user.php?name=aa")
.then(user =>ajax(`http://localhost:8888/php/service.php?id=${user["id"]}`))
.then(lesson => {
  console.log(lesson);
});
```



#### 图片加载

下面是异步加载图片示例

```js
function loadImage(file) {
  return new Promise((resolve, reject) => {
    const image = new Image();
    image.src = file;
    image.onload = () => {
      resolve(image);
    };
    image.onerror = reject;
    document.body.appendChild(image);
  });
}

loadImage("images/houdunren.png").then(image => {
  image.style.border = "solid 20px black";
  console.log("宽度:" + window.getComputedStyle(image).width);
});
```



#### 定时器

下面是封装的`timeout` 函数，使用定时器操作更加方便

```js
function timeout(times) {
  return new Promise(resolve => {
    setTimeout(resolve, times);
  });
}

timeout(3000)
  .then(() => {
    console.log("3秒后执行");
    return timeout(1000);
  })
  .then(() => {
    console.log("执行上一步的promise后1秒执行");
  });
```

封闭 `setInterval` 定时器并实现动画效果

```js
<body>
  <style>
    div {
      width: 100px;
      height: 100px;
      background: yellowgreen;
      position: absolute;
    }
  </style>
  <div></div>
</body>
<script>
  function interval(delay = 1000, callback) {
    return new Promise(resolve => {
      let id = setInterval(() => {
        callback(id, resolve);
      }, delay);
    });
  }
  interval(100, (id, resolve) => {
    const div = document.querySelector("div");
    let left = parseInt(window.getComputedStyle(div).left);
    div.style.left = left + 10 + "px";
    if (left >= 200) {
      clearInterval(id);
      resolve(div);
    }
  }).then(div => {
    interval(50, (id, resolve) => {
      let width = parseInt(window.getComputedStyle(div).width);
      div.style.width = width - 10 + "px";
      if (width <= 20) {
        clearInterval(id);
      }
    });
  });
</script>
```



## 链式操作

- 第个 `then` 都是一个promise
- 如果 `then` 返回 promse，只当`promise` 结束后，才会继续执行下一个 `then`



#### 语法介绍

`promise` 中的 `then` 方法可以链接执行，`then` 方法的返回值会传递到下一个`then` 方法。

- `then` 会返回一个`promise` ，所以如果有多个`then` 时会连续执行
- `then` 返回的值会做为当前`promise` 的结果

下面是链式操作的 `then`，即始没有 `return` 也是会执行，因为每个`then` 会返回`promise`

```js
new Promise((resolve, reject) => {
  resolve("后盾人");
})
.then(hd => {
  hd += "-hdcms";
  console.log(hd); //后盾人-hdcms
  return hd;
})
.then(hd => {
  hd += "-houdunren";
  console.log(hd); //后盾人-hdcms-houdunren
});
```



#### 链式加载

使用`promise` 链式操作重构前面章节中的文件加载，使用代码会变得更清晰

```js
function load(file) {
  return new Promise((resolve, reject) => {
    const script = document.createElement("script");
    script.src = file;
    script.onload = () => resolve(script);
    script.onerror = () => reject();
    document.body.appendChild(script);
  });
}

load("js/hd.js")
.then(() => load("js/houdunren.js"))
.then(() => houdunren());
```



#### 操作元素

使用 `promise` 对元素事件进行处理

```js
<body>
  <div>
    <h2>第九章 闭包与作用域</h2>
    <button>收藏课程</button>
  </div>
</body>

<script>
new Promise(resolve => {
  document.querySelector("button").addEventListener("click", e => {
    resolve();
  });
})
.then(() => {
  return new Promise(resolve => {
    setTimeout(() => {
      console.log("执行收藏任务");
      resolve();
    }, 2000);
  });
})
.then(() => {
  return new Promise(resolve => {
    setTimeout(() => {
      console.log("更新积分");
      resolve();
    }, 2000);
  });
})
.then(() => {
  console.log("收藏成功！奖励10积分");
})
.catch(error => console.log(errro));
```



#### 异步请求

下面是使用链式操作获取学生成绩

```js
function ajax(url) {
  return new Promise((resolve, reject) => {
    let xhr = new XMLHttpRequest();
    xhr.open("GET", url);
    xhr.send();
    xhr.onload = function() {
      if (this.status == 200) {
        resolve(JSON.parse(this.response));
      } else {
        reject(this);
      }
    };
  });
}
ajax("http://localhost:8888/php/user.php?name=aa")
.then(user => {
  return ajax(`http://localhost:8888/php/aaaaa.php?id=${user["id"]}`);
})
.then(lesson => {
  console.log(lesson);
});
```



## 扩展接口

#### resolve

使用 `promise.resolve` 方法可以快速的返回一个promise对象

下面将请求结果缓存，如果再次请求时直接返回带值的 `promise`

- 为了演示使用了定时器，也可以在后台设置延迟响应

```js
function query(name) {
  const cache = query.cache || (query.cache = new Map());
  if (cache.has(name)) {
    console.log("走缓存了");
    return Promise.resolve(cache.get(name));
  }
  return ajax(`http://localhost:8888/php/user.php?name=${name}`).then(
    response => {
      cache.set(name, response);
      console.log("没走缓存");
      return response;
    }
  );
}
query("aa").then(response => {
  console.log(response);
});
setTimeout(() => {
  query("aa").then(response => {
    console.log(response);
  });
}, 1000);
```

如果是 `thenable` 对象，会将对象包装成promise处理，这与其他promise处理方式一样的

```js
const hd = {
  then(resolve, reject) {
    resolve("aa");
  }
};
Promise.resolve(hd).then(value => {
  console.log(value);
});
```



#### reject

和 `Promise.resolve` 类似，`reject` 生成一个失败的`promise`

```js
Promise.reject("fail").catch(error => console.log(error));
```

下面使用 `Project.reject` 设置状态

```js
new Promise(resolve => {
  resolve("后盾人");
})
.then(v => {
  if (v != "houdunren.com") return Promise.reject(new Error("fail"));
})
.catch(error => {
  console.log(error);
});
```



#### all

使用`Promise.all` 方法可以同时执行多个并行异步操作，比如页面加载时同进获取课程列表与推荐课程。

- 任何一个 `Promise` 执行失败就会调用 `catch`方法
- 适用于一次发送多个异步操作
- 参数必须是可迭代类型，如Array/Set
- 成功后返回 `promise` 结果的有序数组

下例中当 `hdcms、houdunren` 两个 Promise 状态都为 `fulfilled` 时，hd状态才为`fulfilled`。

```js
const hdcms = new Promise((resolve, reject) => {
  setTimeout(() => {
    resolve("第一个Promise");
  }, 1000);
});
const houdunren = new Promise((resolve, reject) => {
  setTimeout(() => {
    resolve("第二个异步");
  }, 1000);
});
const hd = Promise.all([hdcms, houdunren])
  .then(results => {
    console.log(results);
  })
  .catch(msg => {
    console.log(msg);
  });
```

如果某一个`promise`没有catch 处理，将使用`promise.all` 的catch处理

```js
let p1 = new Promise((resolve, reject) => {
  resolve("fulfilled");
});
let p2 = new Promise((resolve, reject) => {
  reject("rejected");
});
Promise.all([p1, p2]).catch(reason => {
  console.log(reason);
});
```



#### allSettled

`allSettled` 用于处理多个`promise` ，只关注执行完成，不关注是否全部执行成功，`allSettled`状态只会是`fulfilled`。

下面的p2 返回状态为 `rejected` ，但`promise.allSettled` 不关心，它始终将状态设置为 `fulfilled` 。

```js
const p1 = new Promise((resolve, reject) => {
  resolve("resolved");
});
const p2 = new Promise((resolve, reject) => {
  reject("rejected");
});
Promise.allSettled([p1, p2])
.then(msg => {
  console.log(msg);
})
```



#### race

使用`Promise.race()` 处理容错异步，和`race`单词一样哪个Promise快用哪个，哪个先返回用哪个。

- 以最快返回的promise为准
- 如果最快返加的状态为`rejected` 那整个`promise`为`rejected`执行cache
- 如果参数不是promise，内部将自动转为promise

下面将第一次请求的异步时间调整为两秒，这时第二个先返回就用第二人。

```js
const hdcms = new Promise((resolve, reject) => {
  setTimeout(() => {
    resolve("第一个Promise");
  }, 2000);
});
const houdunren = new Promise((resolve, reject) => {
  setTimeout(() => {
    resolve("第二个异步");
  }, 1000);
});
Promise.race([hdcms, houdunren])
.then(results => {
  console.log(results);
})
.catch(msg => {
  console.log(msg);
});
```

获取用户资料，如果两秒内没有结果 `promise.race` 状态失败，执行`catch` 方法

```js
const api = "http://localhost:8888/php";
const promises = [
  ajax(`${api}/user.php?name=向军`),
  new Promise((a, b) =>
    setTimeout(() => b(new Error("request fail")), 2000)
  )
];
Promise.race(promises)
.then(response => {
  console.log(response);
})
.catch(error => {
  console.log(error);
});
```



## 任务队列

#### 实现原理

如果 `then` 返回`promise` 时，后面的`then` 就是对返回的 `promise` 的处理

下面使用 `map` 构建的队列，有以下几点需要说明

- `then` 内部返回的 `promise` 更改外部的 `promise` 变量
- 为了让任务继承，执行完任务需要将 `promise` 状态修改为 `fulfilled`

```js
function queue(nums) {
  let promise = Promise.resolve();
  nums.map(n => {
    promise = promise.then(v => {
      return new Promise(resolve => {
        console.log(n);
        resolve();
      });
    });
  });
}

queue([1, 2, 3, 4, 5]);
```

下面再来通过 `reduce` 来实现队列

```js
function queue(nums) {
  return nums.reduce((promise, n) => {
    return promise.then(() => {
      return new Promise(resolve => {
        console.log(n);
        resolve();
      });
    });
  }, Promise.resolve());
}

queue([1, 2, 3, 4, 5]);
```



#### 队列请求

下面是异步加载用户并渲染到视图中的队列实例

- 请在后台添加延迟脚本，以观察队列执行过程
- 也可以在任何`promise` 中添加定时器观察

```js
class User {
	//加载用户
  ajax(user) {
    let url = `http://localhost:8888/php/user.php?name=${user}`;
    return new Promise(resolve => {
      let xhr = new XMLHttpRequest();
      xhr.open("GET", url);
      xhr.send();
      xhr.onload = function() {
        if (this.status == 200) {
          resolve(JSON.parse(this.response));
        } else {
          reject(this);
        }
      };
    });
  }
  //启动
  render(users) {
    users.reduce((promise, user) => {
      return promise
        .then(() => {
          return this.ajax(user);
        })
        .then(user => {
          return this.view(user);
        });
    }, Promise.resolve());
  }
  //宣染视图
  view(user) {
    return new Promise(resolve => {
      let h1 = document.createElement("h1");
      h1.innerHTML = user.name;
      document.body.appendChild(h1);
      resolve();
    });
  }
}
new User().render(["向军", "后盾人"]);
```



#### 高可用封装

上例中处理是在队列中完成，不方便业务定制，下面将Promise处理在剥离到外部

**后台请求处理类**

```js
export default function(url) {
  return new Promise((resolve, reject) => {
    let xhr = new XMLHttpRequest()
    xhr.open('GET', url)
    xhr.send()
    xhr.onload = function() {
      if (this.status === 200) {
        resolve(this.response)
      } else {
        reject(this)
      }
    }
  })
}
```

**队列处理类**

```js
export default function(promises) {
  promises.reduce((promise, next) => promise.then(next), Promise.resolve())
}
```

**后台脚本**

```js
<?php
$users = [
    1 => "小明",
    2 => "李四",
    3 => "张三"
];
sleep(1);
echo $users[$_GET['id']];
```

**使用队列**

```js
<script type="module">
  import queue from './queue.js'
  import axios from './axios.js'
  queue(
    [1, 2, 3].map(v => () =>
      axios(`user.php?id=${v}`).then(user => console.log(user))
    )
  )
</script>
```



## async/await

使用 `async/await` 是promise 的语法糖，可以让编写 promise 更清晰易懂，也是推荐编写promise 的方式。

- `async/await` 本质还是promise，只是更简洁的语法糖书写
- `async/await` 使用更清晰的promise来替换 promise.then/catch 的方式



#### async

下面在 `hd` 函数前加上async，函数将返回promise，我们就可以像使用标准Promise一样使用了。

```js
async function hd() {
  return "houdunren.com";
}
console.log(hd());
hd().then(value => {
  console.log(value);
});
```

如果有多个await 需要排队执行完成，我们可以很方便的处理多个异步队列

```js
async function hd(message) {
  return new Promise(resolve => {
    setTimeout(() => {
      resolve(message);
    }, 2000);
  });
}
async function run() {
  let h1 = await hd("aa");
  console.log(h1);
  let h2 = await hd("houdunren.com");
  console.log(h2);
}
run();
```



#### await

使用 `await` 关键词后会等待promise 完

- `await` 后面一般是promise，如果不是直接返回
- `await` 必须放在 async 定义的函数中使用
- `await` 用于替代 `then` 使编码更优雅

下例会在 await 这行暂停执行，直到等待 promise 返回结果后才继执行。

```js
async function hd() {
  const promise = new Promise((resolve, reject) => {
    setTimeout(() => {
      resolve("houdunren.com");
    }, 2000);
  });
  let result = await promise;
  console.log(result);
}
hd()
```

一般await后面是外部其它的promise对象

```js
async function hd() {
  return new Promise(resolve => {
    setTimeout(() => {
      resolve("fulfilled");
    }, 2000);
  });
}
async function run() {
  let value = await hd();
  console.log("aa.com");
  console.log(value);
}
run();
```

下面是请求后台获取用户课程成绩的示例

```js
async function user() {
  let user = await ajax(`http://localhost:8888/php/user.php?name=aa`);
  let lessons = await ajax(
    `http://localhost:8888/php/houdunren.php?id=${user.id}`
  );
  console.log(lessons);
}
```

也可以将操作放在立即执行函数中完成

```js
(async () => {
  let user = await ajax(`http://localhost:8888/php/user.php?name=aa`);
  let lessons = await ajax(
    `http://localhost:8888/php/houdunren.php?id=${user.id}`
  );
  console.log(lessons);
})();
```

下面是使用async 设置定时器，并间隔时间来输出内容

```js
async function sleep(ms = 2000) {
  return new Promise(resolve => {
    setTimeout(resolve, ms);
  });
}
async function run() {
  for (const value of ["aa", "bb"]) {
    await sleep();
    console.log(value);
  }
}
run();
```



#### 加载进度

下面是请求后台加载用户并通过进度条展示的效果

```js
<body>
  <style>
    div {
      height: 50px;
      width: 0px;
      background: green;
    }
  </style>
  <div id="loading"></div>
</body>
<script src="js/ajax.js"></script>
<script>
  async function query(name) {
    return ajax(`http://localhost:8888/php/user.php?name=${name}`);
  }
  (async () => {
    let users = ["aa", "bb", "cc", "dd", "ff"];
    for (let i = 0; i < users.length; i++) {
      await query(users[i]);
      let progress = (i + 1) / users.length;
      loading.style.width = progress * 100 + "%";
    }
  })();
</script>
```



#### 类中使用

和 promise 一样，await 也可以操作`thenables` 对象

```js
class User {
  constructor(name) {
    this.name = name;
  }
  then(resolve, reject) {
    let user = ajax(`http://localhost:8888/php/user.php?name=${this.name}`);
    resolve(user);
  }
}
async function get() {
  let user = await new User("aa");
  console.log(user);
}
get();
```

类方法也可以通过 `async` 与 `await` 来操作promise

```js
class User {
  constructor() {}
  async get(name) {
    let user = await ajax(
      `http://localhost:8888/php/user.php?name=${name}`
    );
    user.name += "-bb.com";
    return user;
  }
}
new User().get("aa").then(resolve => {
  console.log(resolve);
});
```



#### 其他声明

函数声明

```js
async function get(name) {
  return await ajax(`http://localhost:8888/php/user.php?name=${name}`);
}
get("aa").then(user => {
  console.log(user);
});
```

函数表达式

```js
let get = async function(name) {
  return await ajax(`http://localhost:8888/php/user.php?name=${name}`);
};
get("aa").then(user => {
  console.log(user);
});
```

对象方法声明

```js
let hd = {
  async get(name) {
    return await ajax(`http://localhost:8888/php/user.php?name=${name}`);
  }
};

hd.get("aa").then(user => {
  console.log(user);
});
```

立即执行函数

```js
(async () => {
  let user = await ajax(`http://localhost:8888/php/user.php?name=aa`);
  let lessons = await ajax( 
    `http://localhost:8888/php/houdunren.php?id=${user.id}`
  );
  console.log(lessons);
})();
```

类方法中的使用

```js
class User {
  async get(name) {
    return await ajax(`http://localhost:8888/php/user.php?name=${name}`);
  }
}
let user = new User().get("aa").then(user => {
  console.log(user);
});
```



#### 错误处理

async 内部发生的错误，会将必变promise对象为rejected 状态，所以可以使用`catch` 来处理

```js
async function hd() {
  console.log(aaaa);
}
hd().catch(error => {
  throw new Error(error);
});
```

下面是异步请求数据不存在时的错误处理

```js
async function get(name) {
  return await ajax(`http://localhost:8888/php/user.php?name=${name}`);
}

get("小哥").catch(error => {
  alert("用户不存在");
});
```

如果`promise` 被拒绝将抛出异常，可以使用 `try...catch` 处理错误

```js
async function get(name) {
  try {
    let user = await ajax(
      `http://localhost:8888/php/user.php?name=${name}`
    );
    console.log(user);
  } catch (error) {
    alert("用户不存在");
  }
}
get("aa");
```

多个 await 时当前面的出现失败，后面的将不可以执行

```js
async function hd() {
  await Promise.reject("fail");
  await Promise.resolve("success").then(value => {
    console.log(value);
  });
}
hd();
```

如果对前一个错误进行了处理，后面的 await 可以继续执行

```js
async function hd() {
  await Promise.reject("fail").catch(e => console.log(e));
  await Promise.resolve("success").then(value => {
    console.log(value);
  });
}
hd();
```

也可以使用 `try...catch` 特性忽略不必要的错误

```js
async function hd() {
  try {
    await Promise.reject("fail");
  } catch (error) {}
  await Promise.resolve("success").then(value => {
    console.log(value);
  });
}
hd();
```

也可以将多个 await 放在 try...catch 中统一处理错误

```js
async function hd(name) {
  const host = "http://localhost:8888/php";
  try {
    const user = await ajax(`${host}/user.php?name=${name}`);
    const lessons = await ajax(`${host}/user.php?id=${user.id}`);
    console.log(lessons);
  } catch (error) {
    console.log("用户不存在");
  }
}
hd("教程");
```



#### 并发执行

有时需要多个await 同时执行，有以下几种方法处理，下面多个await 将产生等待

```js
async function p1() {
  return new Promise(resolve => {
    setTimeout(() => {
      console.log("aa");
      resolve();
    }, 2000);
  });
}
async function p2() {
  return new Promise(resolve => {
    setTimeout(() => {
      console.log("bb");
      resolve();
    }, 2000);
  });
}
async function hd() {
  await p1();
  await p2();
}
hd();
```

使用 `Promise.all()` 处理多个promise并行执行

```js
async function hd() {
  await Promise.all([p1(), p2()]);
}
hd();
```

让promise先执行后再使用await处理结果

```js
async function hd() {
  let h1 = p1();
  let h2 = p2();
  await h1;
  await h2;
}
hd();
```

