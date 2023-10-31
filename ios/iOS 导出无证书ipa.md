# iOS 导出无证书 ipa

1. 在Xcode中选择你[打包ipa的实用方法](https://www.applebyme.xyz/ipa-dabao-637.html)的工程文件，打开项目。
2. 进入项目的`Build Settings`，搜索`Code Signing Identity`。将`Debug`和`Release`的`Code Signing Identity`都设置为`iOS Developer`。
3. 在同一个页面中，搜索`Provisioning Profile`，将`Debug`和`Release`的`Provisioning Profile`都设置为`Automatic`。
4. 在`Build Settings`的搜索框中搜索`Product Bundle Identifier`，确保`Bundle Identifier`和你的应用程序的`Bundle Identifier`保持一致。
5. 点击Xcode的菜单栏中的`Product -> Archive`，将应用程序打包成一个`.xcarchive`文件。
6. 打开`Finder`，在左侧导航栏中选择`Applications`。
7. 在`Applications`文件夹中找到你的应用程序（以.app为后缀），[ios打包ipa廋身](https://www.applebyme.xyz/ipa-dabao-146.html)右击应用程序，选择`Show Package Contents`。
8. 在打开的文件夹中，找到`Info.plist`文件，使用文本编辑器打开。
9. 在`Info.plist`文件中找到`ApplicationProperties`字典，修改其中的`ApplicationProperties/CFBundleIdentifier`为你的应用程序的`Bundle Identifier`。
10. 关闭`Info.plist`并退出所有的文件操作。
11. 回到Xcode，点击`Window -> Organizer`，打开`Organizer`窗口。
12. 在`Organizer`窗口的`Archives`选项卡中找到刚刚打包的`.xcarchive`文件，右击并选择`Show in Finder`。
13. 在Finder中找到`.xcarchive`文件，右击并选择`Show Package Contents`。
14. 在打开的文件夹中，找到`Products -> Applications`文件夹。
15. 将应用程序（.app文件）复制到其他地方，比如桌面。
16. 将应用程序的后缀名从`.app`修改为`.ipa`。现在你就得到了一个无签名的IPA文件。

这样，你就成功地打包了一个无签名的IPA文件。注意，无签名的IPA文件只能在越狱设备上安装和运行。在正常的非越狱iOS设备上，只有经过签名的应用程序才能被安装和运行。