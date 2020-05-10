## SceneDelegate

- @ 设置rootViewController



##### 设置rootViewController

```
if let windowScene = scene as? UIWindowScene {
    let window = UIWindow(windowScene: windowScene)
    window.rootViewController = UINavigationController(rootViewController: ViewController())
    self.window = window
    window.makeKeyAndVisible()
}
```





