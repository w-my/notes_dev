Swift UI

## 支持多设备预览

```swift
struct ContentView_Previews: PreviewProvider {
   static var previews: some View {
      Group {
         ContentView()
            // 预览设备
            .previewDevice(PreviewDevice(rawValue: "iPhone 11"))
            // 预览设备名称
            .previewDisplayName("iPhone 11")

         ContentView()
            .previewDevice(PreviewDevice(rawValue: "iPhone 11 Pro Max"))
            .previewDisplayName("iPhone 11 Pro Max")
      }
   }
}
```

## 支持多模式预览

```swift
struct ContentView_Previews: PreviewProvider {
    static var previews: some View {
        Group {
            // 超大文本
            ContentView()
                .environment(\.sizeCategory, .accessibilityExtraExtraExtraLarge)
            // 深色模式  
            ContentView()
                .environment(\.colorScheme, .dark)
            // 导航视图      
            NavigationView {
                ContentView()
            }
        }
    }
}
```