# flutter 基础

- widget 拥有不同的生命周期：整个生命周期内它是不可变的。一旦改变就会创建一个新的 widget 实例。
- widget 很轻量，源于不可变性。
- widget 不是视图，不能直接绘制任何内容，而作为对 UI 及其特性的一种描述，被注入到视图中去。

Flutter 包含了 [Material Components](https://material-io.cn/develop/flutter/) 库。内容都是一些遵循了 [Material Design 设计规范](https://material-io.cn/design/) 的组件。 Material Design 是一种灵活的 [支持全平台](https://material-io.cn/design/platform-guidance/cross-platform-adaptation.html#cross-platform-guidelines) 的设计体系，其中也包括了 iOS。

但是 Flutter 的灵活性和表现力使其能够适配任何的设计语言。在 iOS 中，你可以通过 [Cupertino widgets](https://flutter.cn/docs/development/ui/widgets/cupertino) 来构造类似于 [Apple iOS 设计语言](https://developer.apple.com/design/resources) 的接口。



## 视图



### Widget 

Widget 不能改变，只能通过修改 widget 的 state 来达到更新视图的目的。

#### StatelessWidgets

没有状态绑定的widget。

#### StatefulWidgets

有一个 state 对象，用来存储一些状态信息，并在整个生命周期内保持不变。

##### State



### 更新 widget

通过 StatefulWidget 实现更新



### 布局 widget

添加边距：`padding: const EdgeInsets.only(left: 10.0, right: 10.0)`



### 添加移除控件

```flutter
class _SampleAppPageState extends State<SampleAppPage> {
  
  bool toggle = true;

  void _toggle() {
    setState(() {
      toggle = !toggle;
    });
  }

  Widget _getToggleChild() {
    if (toggle) {
      return const Text('Toggle One');
    }

    return CupertinoButton(
      onPressed: () {},
      child: const Text('Toggle Two'),
    );
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: const Text('Sample App'),
      ),
      body: Center(
        child: _getToggleChild(),
      ),
      floatingActionButton: FloatingActionButton(
        onPressed: _toggle,
        tooltip: 'Update Text',
        child: const Icon(Icons.update),
      ),
    );
  }
}
```





### 添加动画

##### AnimationController

##### Ticker

##### CurvedAnimation





### 渲染

##### Canvas

##### CustomPaint

##### CustomPainter



### 设置透明度

大部分时候需要封装 widget 到 Opacity widget 中来实现这一功能。



### 构建自定义 widget

构建自定义 widget 需要通过 组合一些小的 widget （尔不是对它们进行扩展）来实现。

例如，应该如何构建一个初始方法中就包含文本标签的 `CustomButton`？需要创建一个合成一个 `RaisedButton` 和一个文本标签的 CustomButton，而不是继承 `RaisedButton`：

```dart
class CustomButton extends StatelessWidget {
  const CustomButton(this.label, {super.key});

  final String label;

  @override
  Widget build(BuildContext context) {
    return ElevatedButton(
      onPressed: () {},
      child: Text(label),
    );
  }
}
```

与其他 Flutter widget 一样的用法，下面我们使用 `CustomButton`：

```dart
@override
Widget build(BuildContext context) {
  return const Center(
    child: CustomButton('Hello'),
  );
}
```



## 导航

### 如何在两个页面之间切换

Flutter 中使用 `Navigator` 和 `Route`。一个 `Route` 是应用中屏幕或者页面的抽象概念，而一个 `Navigator` 是管多个 `Route` 的 widget。也可以理解把 `Route` 理解为 `UIViewController`。而 `Navigator` 的工作方式和 iOS 里的 `UINavigationController` 类似，当你想要进入或退出一个新页面的时候，它也可以进行 `push()` 和 `pop()` 操作。

想要在不同页面间跳转，你有两个选择：

- 构建由 route 名称组成的 `Map`；
- 直接跳转到一个路由。

下面的示例构建了一个 `Map`：

```dart
void main() {
  runApp(
    CupertinoApp(
      home: const MyAppHome(), // becomes the route named '/'
      routes: <String, WidgetBuilder>{
        '/a': (context) => const MyPage(title: 'page A'),
        '/b': (context) => const MyPage(title: 'page B'),
        '/c': (context) => const MyPage(title: 'page C'),
      },
    ),
  );
}
```

通过把 route 名称传递给 `Navigator` 来实现 `push` 效果。

```dart
Navigator.of(context).pushNamed('/b');
```

`Navigator` 类对 Flutter 中的路由事件做处理，还可以用来获取入栈之后的路由的结果。这需要通过 `push()` 返回的 `Future` 中的 `await` 来实现。

例如，要打开一个「定位」页面来让用户选择他们的位置，你需要做如下事情：

```dart
Object? coordinates = await Navigator.of(context).pushNamed('/location');
```

然后，在「定位」页面中，一旦用户选择了自己的定位，就 `pop()` 出栈并返回结果。

```dart
Navigator.of(context).pop({'lat': 43.821757, 'long': -79.226392});
```

#### 如何跳转到其他应用？

在 Flutter 里想要实现这个功能，需要创建原生平台的整合层，或者使用已经存在的 [插件](https://pub.flutter-io.cn/flutter)，例如 [`url_launcher`](https://pub.flutter-io.cn/packages/url_launcher)。

#### 如何退回到 iOS 原生的 ViewController？

在 Dart 代码中调用 `SystemNavigator.pop()` 将会调用下面的 iOS 代码：

```
UIViewController* viewController = [UIApplication sharedApplication].keyWindow.rootViewController;
if ([viewController isKindOfClass:[UINavigationController class]]) {
  [((UINavigationController*)viewController) popViewControllerAnimated:NO];
}
```

如果这不是你需要的功能，你可以创建你自己的 [平台通道](https://flutter.cn/docs/development/platform-integration/platform-channels) 来调用对应的 iOS 代码。



## 线程和异步

### 如何编写异步代码

Dart 是单线程执行模型，支持 `Isolate` （一种在其他线程运行 Dart 代码的方法）、事件循环和异步编程。除非生成了 `Isolate`，否则所有 Dart 代码将永远在主线程运行，并由事件循环驱动。 Flutter 中的事件循环类似于 iOS 中的 main loop—— 也就是主线程上的 `Looper`。

Dart 的单线程模型并不意味着你需要以阻塞 UI 的形式来执行代码，相反，你更应该使用 Dart 语言提供的异步功能，比如使用 `async`/`await` 来实现异步操作。

```dart
Future<void> loadData() async {
  final Uri dataURL = Uri.parse('https://jsonplaceholder.typicode.com/posts');
  final http.Response response = await http.get(dataURL);
  setState(() {
    data = jsonDecode(response.body);
  });
}
```

一旦 `await` 等待的网络操作结束，通过调用 `setState()` 来更新 UI，这将会触发 widget 子树的重新构建并更新数据。

下面的示例展示了如何异步加载数据，并在 `ListView` 中展示出来：

```dart
import 'dart:convert';

import 'package:flutter/material.dart';
import 'package:http/http.dart' as http;

void main() {
  runApp(const SampleApp());
}

class SampleApp extends StatelessWidget {
  const SampleApp({super.key});

  @override
  Widget build(BuildContext context) {
    return const MaterialApp(
      title: 'Sample App',
      home: SampleAppPage(),
    );
  }
}

class SampleAppPage extends StatefulWidget {
  const SampleAppPage({super.key});

  @override
  State<SampleAppPage> createState() => _SampleAppPageState();
}

class _SampleAppPageState extends State<SampleAppPage> {
  List<Map<String, dynamic>> data = <Map<String, dynamic>>[];

  @override
  void initState() {
    super.initState();
    loadData();
  }

  Future<void> loadData() async {
    final Uri dataURL = Uri.parse('https://jsonplaceholder.typicode.com/posts');
    final http.Response response = await http.get(dataURL);
    setState(() {
      data = jsonDecode(response.body);
    });
  }

  Widget getRow(int index) {
    return Padding(
      padding: const EdgeInsets.all(10.0),
      child: Text('Row ${data[index]['title']}'),
    );
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: const Text('Sample App'),
      ),
      body: ListView.builder(
        itemCount: data.length,
        itemBuilder: (context, index) {
          return getRow(index);
        },
      ),
    );
  }
}
```

更多关于在后台执行任务的信息，以及 Flutter 和 iOS 的区别，可以参考下一章节。

### 后台线程执行任务

有时候你需要处理大量的数据，从而导致 UI 挂起。当处理长期运行或者运算密集的任务时，可以使用 `Isolate` 来发挥出多核 CPU 的优势。

下面是一个完整示例：

```dart
import 'dart:async';
import 'dart:convert';
import 'dart:isolate';

import 'package:flutter/material.dart';
import 'package:http/http.dart' as http;

void main() {
  runApp(const SampleApp());
}

class SampleApp extends StatelessWidget {
  const SampleApp({super.key});

  @override
  Widget build(BuildContext context) {
    return const MaterialApp(
      title: 'Sample App',
      home: SampleAppPage(),
    );
  }
}

class SampleAppPage extends StatefulWidget {
  const SampleAppPage({super.key});

  @override
  State<SampleAppPage> createState() => _SampleAppPageState();
}

class _SampleAppPageState extends State<SampleAppPage> {
  List<Map<String, dynamic>> data = <Map<String, dynamic>>[];

  @override
  void initState() {
    super.initState();
    loadData();
  }

  bool get showLoadingDialog => data.isEmpty;

  Future<void> loadData() async {
    final ReceivePort receivePort = ReceivePort();
    await Isolate.spawn(dataLoader, receivePort.sendPort);

    // The 'echo' isolate sends its SendPort as the first message.
    final SendPort sendPort = await receivePort.first as SendPort;

    final List<Map<String, dynamic>> msg = await sendReceive(
      sendPort,
      'https://jsonplaceholder.typicode.com/posts',
    );

    setState(() {
      data = msg;
    });
  }

  // The entry point for the isolate.
  static Future<void> dataLoader(SendPort sendPort) async {
    // Open the ReceivePort for incoming messages.
    final ReceivePort port = ReceivePort();

    // Notify any other isolates what port this isolate listens to.
    sendPort.send(port.sendPort);

    await for (final dynamic msg in port) {
      final String url = msg[0] as String;
      final SendPort replyTo = msg[1] as SendPort;

      final Uri dataURL = Uri.parse(url);
      final http.Response response = await http.get(dataURL);
      // Lots of JSON to parse
      replyTo.send(jsonDecode(response.body) as List<Map<String, dynamic>>);
    }
  }

  Future<List<Map<String, dynamic>>> sendReceive(SendPort port, String msg) {
    final ReceivePort response = ReceivePort();
    port.send(<dynamic>[msg, response.sendPort]);
    return response.first as Future<List<Map<String, dynamic>>>;
  }

  Widget getBody() {
    bool showLoadingDialog = data.isEmpty;

    if (showLoadingDialog) {
      return getProgressDialog();
    } else {
      return getListView();
    }
  }

  Widget getProgressDialog() {
    return const Center(child: CircularProgressIndicator());
  }

  ListView getListView() {
    return ListView.builder(
      itemCount: data.length,
      itemBuilder: (context, position) {
        return getRow(position);
      },
    );
  }

  Widget getRow(int i) {
    return Padding(
      padding: const EdgeInsets.all(10.0),
      child: Text("Row ${data[i]["title"]}"),
    );
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: const Text('Sample App'),
      ),
      body: getBody(),
    );
  }
}
```

### 如何发起网络请求？

```dart
Future<void> loadData() async {
  final Uri dataURL = Uri.parse('https://jsonplaceholder.typicode.com/posts');
  final http.Response response = await http.get(dataURL);
  setState(() {
    data = jsonDecode(response.body);
  });
}
```



## 工程结构，本地化，依赖和资源

###  如何在 Flutter 中引入图片资源？如何处理多分辨率？

在 iOS 里，图片和其他资源会被视为不同的资源分别处理，而在 Flutter 中只有资源这一个概念。 iOS 里被放置在 `Images.xcasset` 文件夹的资源，在 Flutter 中都被放置到了 assets 文件夹中。和 iOS 一样，assets 中可以放置任意类型的文件，而不仅仅是图片。例如，你可以把一个 JSON 文件放置到 `my-assets` 文件夹中。

```
my-assets/data.json
```

在 `pubspec.yaml` 中声明 assets：

```
assets:
 - my-assets/data.json
```

然后在代码中通过 [`AssetBundle`](https://api.flutter-io.cn/flutter/services/AssetBundle-class.html) 访问资源:

```dart
import 'dart:async' show Future;
import 'package:flutter/services.dart' show rootBundle;

Future<String> loadAsset() async {
  return await rootBundle.loadString('my-assets/data.json');
}
```

对于图片，Flutter 和 iOS 一样遵循了一个简单的基于屏幕密度的格式。 Image assets 可能是 `1.0x`，`2.0x`，`3.0x` 或者其他任意的倍数。而 [`devicePixelRatio`](https://api.flutter-io.cn/flutter/dart-ui/FlutterView/devicePixelRatio.html) 则表达了物理分辨率到逻辑分辨率的对照比例。

Assets 可以放在任何属性的文件夹中—Flutter 没有任何预置的文件结构。你需要在 `pubspec.yaml` 中声明 assets （包括路径），然后 Flutter 将会识别它们。

例如，要添加一个名为 `my_icon.png` 的图片到你的 Flutter 工程中，你可以把它存储在 `images` 文件夹下。把基础的图片（一倍图）放到 `images` 文件夹下，然后把其他倍数的图片放置到对应的比例下的子文件夹中。

```
images/my_icon.png       // Base: 1.0x image
images/2.0x/my_icon.png  // 2.0x image
images/3.0x/my_icon.png  // 3.0x image
```

接着，在 `pubspec.yaml` 文件中声明这些图片：

```
assets:
 - images/my_icon.png
```

现在你可以使用 `AssetImage` 访问你的图片了：

```dart
AssetImage('images/a_dot_burr.jpeg')
```

或者直接在 `Image` widget 进行使用：

```dart
@override
Widget build(BuildContext context) {
  return Image.asset('images/my_image.png');
}
```

关于更多的细节，请参见文档 [在 Flutter 中添加资源和图片](https://flutter.cn/docs/development/ui/assets-and-images)。

### 字符串存储在哪里？如何处理本地化？

iOS 里有 `Localizable.strings` 文件，而 Flutter 则不同，目前并没有关于字符串的处理系统。目前，最佳的方案就是在静态区声明你的文本，然后进行访问。例如：

```dart
class Strings {
  static const String welcomeMessage = 'Welcome To Flutter';
}
```

你可以这样访问字符串：

```dart
Text(Strings.welcomeMessage);
```

### CocoaPods 相当于 Flutter 中的什么？如何添加依赖？

在 iOS 里，可以通过 `Podfile` 添加依赖。而 Flutter 使用 Dart 构建系统和 Pub 包管理器来处理依赖。这些工具将原生应用的打包任务分发给相应 Android 或 iOS 构建系统。

如果你的 Flutter 项目 iOS 文件夹中存在 Podfile，那么请仅在里面添加原生平台的依赖。总而言之，在 Flutter 中使用 `pubspec.yaml` 来声明外部依赖。你可以通过 [pub.dev](https://pub.flutter-io.cn/flutter/packages) 来查找一些优秀的 Flutter 第三方包。



## Widgets

### ListView

#### 基础列表

```dart
import 'package:flutter/material.dart';

void main() {
  runApp(const SampleApp());
}

class SampleApp extends StatelessWidget {
  const SampleApp({super.key});

  // This widget is the root of your application.
  @override
  Widget build(BuildContext context) {
    return const MaterialApp(
      title: 'Sample App',
      home: SampleAppPage(),
    );
  }
}

class SampleAppPage extends StatefulWidget {
  const SampleAppPage({super.key});

  @override
  State<SampleAppPage> createState() => _SampleAppPageState();
}

class _SampleAppPageState extends State<SampleAppPage> {
  List<Widget> _getListData() {
    final List<Widget> widgets = [];
    for (int i = 0; i < 100; i++) {
      widgets.add(Padding(
        padding: const EdgeInsets.all(10.0),
        child: Text('Row $i'),
      ));
    }
    return widgets;
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: const Text('Sample App'),
      ),
      body: ListView(children: _getListData()),
    );
  }
}
```

#### 点击事件

```dart
import 'dart:developer' as developer;
import 'package:flutter/material.dart';

void main() {
  runApp(const SampleApp());
}

class SampleApp extends StatelessWidget {
  const SampleApp({super.key});

  // This widget is the root of your application.
  @override
  Widget build(BuildContext context) {
    return const MaterialApp(
      title: 'Sample App',
      home: SampleAppPage(),
    );
  }
}

class SampleAppPage extends StatefulWidget {
  const SampleAppPage({super.key});

  @override
  State<SampleAppPage> createState() => _SampleAppPageState();
}

class _SampleAppPageState extends State<SampleAppPage> {
  List<Widget> _getListData() {
    List<Widget> widgets = [];
    for (int i = 0; i < 100; i++) {
      widgets.add(
        GestureDetector(
          onTap: () {
            developer.log('row tapped');
          },
          child: Padding(
            padding: const EdgeInsets.all(10.0),
            child: Text('Row $i'),
          ),
        ),
      );
    }
    return widgets;
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: const Text('Sample App'),
      ),
      body: ListView(children: _getListData()),
    );
  }
}
```

#### 更新列表

推荐的、高效且有效的方法就是使用 `ListView.Builder` 来构建列表。当你的数据量很大，且需要构建动态列表时，这个方法会非常好用。

```dart
import 'dart:developer' as developer;

import 'package:flutter/material.dart';

void main() {
  runApp(const SampleApp());
}

class SampleApp extends StatelessWidget {
  const SampleApp({super.key});
  // This widget is the root of your application.
  @override
  Widget build(BuildContext context) {
    return const MaterialApp(
      title: 'Sample App',
      home: SampleAppPage(),
    );
  }
}

class SampleAppPage extends StatefulWidget {
  const SampleAppPage({super.key});

  @override
  State<SampleAppPage> createState() => _SampleAppPageState();
}

class _SampleAppPageState extends State<SampleAppPage> {
  List<Widget> widgets = [];

  @override
  void initState() {
    super.initState();
    for (int i = 0; i < 100; i++) {
      widgets.add(getRow(i));
    }
  }

  Widget getRow(int i) {
    return GestureDetector(
      onTap: () {
        setState(() {
          widgets.add(getRow(widgets.length));
          developer.log('row $i');
        });
      },
      child: Padding(
        padding: const EdgeInsets.all(10.0),
        child: Text('Row $i'),
      ),
    );
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: const Text('Sample App'),
      ),
      body: ListView.builder(
        itemCount: widgets.length,
        itemBuilder: (context, position) {
          return getRow(position);
        },
      ),
    );
  }
}
```

和创建 `ListView` 不同，创建 `ListView.Builder` 需要两个关键参数：初始化列表长度和 `ItemBuilder` 函数。

`ItemBuilder` 函数和 iOS 里 tableView 和 collectionView 的 `cellForItemAt` 方法类似，它接收位置参数，然后返回想要在该位置渲染的 cell。

最后，也是最重要的，注意 `onTap()` 方法并没有重新创建列表，而是使用 `.add` 方法进行添加。











