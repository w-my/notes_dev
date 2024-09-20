# runtime



## 什么是 runtime？

Runtime 是 Objective-C 的运行时库，负责在程序运行时动态地执行代码。它允许在运行时进行方法调用、消息传递、类和对象的动态创建等操作。



## 如何通过 runtime 添加属性和方法？

可以使用 `class_addMethod` 添加方法，使用 `class_addProperty` 添加属性。例如：

```objective-c
class_addMethod([self class], @selector(newMethod), (IMP)newMethodImplementation, "v@:");
class_addProperty([self class], "newProperty", attributes, attributeCount);
```



## runtime 如何实现 weak 属性？

runtime 通过维护一个**弱引用表（weak table）**，在对象销毁时，遍历该表并将所有指向该对象的弱引用置为 nil。



## 什么是 method swizzling？

Method swizzling 是一种在运行时交换两个方法实现的技术，常用于修改系统类的默认行为。例如：

```objective-c
Method originalMethod = class_getInstanceMethod([self class], @selector(originalMethod));
Method swizzledMethod = class_getInstanceMethod([self class], @selector(swizzledMethod));
method_exchangeImplementations(originalMethod, swizzledMethod);
```



## 如何实现消息转发机制？

当一个对象接收到一个未实现的方法时，runtime 会调用 `forwardingTargetForSelector:` 方法。如果返回 nil，则会调用 `methodSignatureForSelector:` 和 `forwardInvocation:` 方法进行消息转发。你需要详细解释这些方法的实现和调用顺序。