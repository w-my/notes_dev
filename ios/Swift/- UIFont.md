## UIFont

- @ 使用自定义字体
- 



#### @ 使用自定义字体

1）将字体 `.ttf` 或 `.otf` 文件拖入到工程中；

2）配置 `Info.plist` - `Fonts provided by application`，然后在 `Build Phases` - `Copy Bundle Resources` 里增加字体；

3）使用 `FamilyName` 查找字体名称；

```swift
for family in UIFont.familyNames {
    for font in UIFont.fontNames(forFamilyName: family) {
        print(font)
    }
}
```

4）找到需要的字体后就可以使用了

```swift
UIFont(name: "Zapfino", size: 16)
```

