# 常用组件



## Container



## Text





## Image

#### 使用本地图片

1. flutter 项目根目录创建 `images` 文件夹，然后创建 `2.0x` 和 `3.0x` 子目录，如下结构：

```
- images
  - 2.0x
  	- a.jpeg
  - 3.0x
  	- a.jpeg
  - a.jpeg
```

2. `pubspec.yaml` 文件中添加配置

```yaml
assets:
  - images/a.jpeg
  - images/2.0x/a.jpeg
  - images/3.0x/a.jpeg
```

3. 使用图片

```dart
class LocalImage extends StatelessWidget {
  const LocalImage({super.key});

  @override
  Widget build(BuildContext context) {
    return SizedBox(
      width: 100,
      height: 100,
      child: Image.asset(
        "images/a.jpeg",
        fit: BoxFit.cover,  
      ),
    );
  }
}
```



#### 圆角图片

```dart
class Circular extends StatelessWidget {
  const Circular({super.key});

  @override
  Widget build(BuildContext context) {
    return Container(
      height: 100,
      width: 100,
      decoration: BoxDecoration(
        color: Colors.blue,
        borderRadius: BorderRadius.circular(50), // 12
        image: const DecorationImage(
          image: NetworkImage(''),
          fit: BoxFit.cover
        )
      ),
    );
  }
}
```



#### 圆形图片

```dart
class ClipImage extends StatelessWidget {
  const ClipImage({super.key});

  @override
  Widget build(BuildContext context) {
    return ClipOval(
      child: Image.network(
        'https://www.itying.com/themes/itying/images/ionic4.png',
        width: 100,
        height: 100,
        fit: BoxFit.cover,
      ),
    );
  }
}
```



## Icon

#### flutter 自带图标

```dart
Icon(Icons.home, size: 20, color: Colors.red,)
```



#### 使用阿里 iconfont.cn 图标库的图标

1. 在项目根目录创建 `fonts` 文件夹
2. 在 `iconfont.cn`  添加自己需要的图标到购物车，然后点击下载代码，将下载的文件中的 `iconfont.json` 和 `iconfont.ttf` 两个文件拷贝到项目创建的 `fonts` 文件夹中
3. 在 `pubspec.yaml` 文件中添加配置

```
fonts:
  - family: myIcons # 指定字体名
    fonts:
      - asset: fonts/iconfont.ttf
```

4. `lib` 目录下创建项目字体文件 `MyIcons.dart`，如：

```dart
import 'package:flutter/material.dart';

class MyIcons {
  static const IconData book = IconData(
    0x3447,
    fontFamily: "myIcon",
    matchTextDirection: true
  );
  static const IconData weixin = IconData(
    0xf0106,
    fontFamily: "myIcon",
    matchTextDirection: true
  );
}
```

5. 在使用的地方引入字体

```dart
import './myIcons.dart';
...
Icon(MyIcons.book, size: 20, color: Colors.red,)
Icon(MyIcons.weixin, size: 20, color: Colors.red,)
```

6. 有新的icon的话，下载新的文件后，重命名后，在 `pubspec.yaml` 添加配置

```
fonts:
  - family: myIcons # 指定字体名
    fonts:
      - asset: fonts/iconfont.ttf
  - family: barIcons 
  	fonts:
  		- asset: fonts/bariconfont.ttf
```

在 ``MyIcons.dart` 中添加icon

```dart
import 'package:flutter/material.dart';

class MyIcons {
  static const IconData book = IconData(
    0x3447,
    fontFamily: "myIcons",
    matchTextDirection: true
  );
  static const IconData weixin = IconData(
    0xf0106,
    fontFamily: "myIcons",
    matchTextDirection: true
  );
  // bar-home
  static const IconData home = IconData(
    0x0000,
    fontFamily: "barIcons",
    matchTextDirection: true
  );
}
```

