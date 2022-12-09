# RxSwift

## Rx

Rx是ReactiveX的缩写，简单来说就是基于异步Event序列的响应式编程。Rx可以简化异步编程方法，并提供更优雅的数据绑定，让我们可以时刻响应新的数据的同时，顺序地处理他们。



## RxSwift

在编程过程中，我们经常需要去检测某些值的变化（如：textfield输入变化），然后进行相应的处理。RxSwift的出现，让程序里的时间传递响应方法做到了统一，将之前常用的事件传递方法(delegate、notification、target-action等)，全部替换成Rx的“信号链”方式。

在MVVM的开发模式下，可以通过RxSwift获得更加方便的数据绑定方法，让MVVM更加灵活轻便。



## RxCocoa

RxCocoa是RxSwift的一部分，主要是UI相关的Rx封装。RxCocoa实现了很多组件的绑定，协助开发者把值和控件进行绑定，避免代码中产生大量的通知、代理、数据修改等代码。也可以监听delegate，无需把控件创建和delegate处理分开。