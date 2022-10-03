## Swift - 3DTouch
在 `info.plist` 中配置事件

```swift
<key>UIApplicationShortcutItems</key>
<array>
    <dict>
        <key>UIApplicationShortcutItemIconFile</key>
        <string>run</string>
        <key>UIApplicationShortcutItemTitle</key>
        <string>Begin Run</string>
        <key>UIApplicationShortcutItemType</key>
        <string>$(PRODUCT_BUNDLE_IDENTIFIER).First</string>
        <key>UIApplicationShortcutItemUserInfo</key>
        <dict>
            <key>firstShorcutKey1</key>
            <string>firstShortcutKeyValue1</string>
        </dict>
    </dict>
    <dict>
        <key>UIApplicationShortcutItemIconFile</key>
        <string>scan</string>
        <key>UIApplicationShortcutItemTitle</key>
        <string>Scan QRCode</string>
        <key>UIApplicationShortcutItemType</key>
        <string>$(PRODUCT_BUNDLE_IDENTIFIER).Second</string>
    </dict>
    <dict>
        <key>UIApplicationShortcutItemIconFile</key>
        <string>wifi</string>
        <key>UIApplicationShortcutItemTitle</key>
        <string>Switch Wi-Fi</string>
        <key>UIApplicationShortcutItemType</key>
        <string>$(PRODUCT_BUNDLE_IDENTIFIER).Third</string>
    </dict>
</array>
```

在 `SceneDelegate` 中实现事件响应

```swift
enum ShortcutIdentifier: String {
    case First
    case Second
    case Third
    
    init?(fullType: String) {
        guard let last = fullType.components(separatedBy: ".").last else {
            return nil
        }
        self.init(rawValue: last)
    }
    
    var type: String {
        return Bundle.main.bundleIdentifier! + ".\(self.rawValue)"
    }
}

func handleShortcutItem(_ shortcutItem: UIApplicationShortcutItem) -> Bool {
    guard let _ = ShortcutIdentifier(fullType: shortcutItem.type) else {
        return false
    }
    
    guard let shortCutType = shortcutItem.type as String? else {
        return false
    }
    
    var vc: UIViewController?
    
    switch shortCutType {
    case ShortcutIdentifier.First.type:
        vc = RunVC()
    case ShortcutIdentifier.Second.type:
        vc = ScanVC()
    case ShortcutIdentifier.Third.type:
        vc = WifiVC()
    default: break
    }
    
    guard let targetVC = vc else {
        return false
    }
    
    var presentedVC: UIViewController = window!.rootViewController!
    while presentedVC.presentedViewController != nil {
        presentedVC = presentedVC.presentedViewController!
    }
    if !presentedVC.isMember(of: targetVC.classForCoder) {
        presentedVC.present(targetVC, animated: true, completion: nil)
    }
    
    return true
}

func windowScene(_ windowScene: UIWindowScene, performActionFor shortcutItem: UIApplicationShortcutItem, completionHandler: @escaping (Bool) -> Void) {
    completionHandler(handleShortcutItem(shortcutItem))
}
```
