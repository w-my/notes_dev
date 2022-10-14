

# FFmpeg（Fast Forward Mpeg）

FFmpeg是一个多平台多媒体处理工具，所以也可以在Mac下运行，先说一下Mac下如何安装FFmpeg。

- FFmpeg 官网 : http://ffmpeg.org/download.html

- FFmpeg 源码 : https://github.com/FFmpeg/FFmpeg

- FFmpeg doc : http://www.ffmpeg.org/documentation.html

- FFmpeg wiki : https://trac.ffmpeg.org/wiki

- Homebrew 安装网站 : http://brew.sh/index_zh-cn.html

- FFmpeg官方安装教程 : https://trac.ffmpeg.org/wiki/CompilationGuide/MacOSX

  

## 编译 iOS 下的 FFmpeg

### 下载编译脚本

地址：https://github.com/kewlbear/FFmpeg-iOS-build-script

### 下载安装 gas-preprocessor

地址：https://github.com/kewlbear/FFmpeg-iOS-build-script

后面运行 FFmpeg-iOS-build-script 这个自动编译脚本需要 gas-preprocessor。

依次执行如下命令安装：

```sh
sudo git clone https://github.com/bigsen/gas-preprocessor.git  /usr/local/bin/gas
sudo cp /usr/local/bin/gas/gas-preprocessor.pl /usr/local/bin/gas-preprocessor.pl
sudo chmod 777 /usr/local/bin/gas-preprocessor.pl
sudo rm -rf /usr/local/bin/gas/
```

### 安装 yams

yasm是汇编编译器，因为ffmpeg中为了提高效率用到了汇编指令，所以编译时需要安装

依次执行如下命令安装：

```sh
curl http://www.tortall.net/projects/yasm/releases/yasm-1.3.0.tar.gz -o yasm-1.3.0.gz
tar -zxvf yasm-1.3.0.gz
cd yasm-1.3.0
./configure && make -j 4 && sudo make install
```

### 配置 FFmpeg 编译脚本

编译FFmpeg可使用一个脚本：FFmpeg-iOS-build-script.sh。

FFmpeg-iOS-build-script 是一个外国人写的自动编译的脚本，脚本则会自动从github中把ffmpeg源码下到本地并开始编译出iOS可用的库，支持各种架构。

脚本地址：`git clone https://github.com/kewlbear/FFmpeg-iOS-build-script.git`

下载完成后可以指定编译 FFmpeg 版本，修改 `build-ffmpeg.sh` 文件下 `FF_VERSION` 后面的参数就可以了。例如：FF_VERSION="4.4.1"。

配置裁剪（可选）：

```sh
CONFIGURE_FLAGS="--enable-cross-compile \
								 --enable-pic \
								 --disable-audiotoolbox \
								 --disable-ffplay \
								 --disable-ffprobe \
								 --disable-programs \
								 --disable-debug \
                 --disable-doc"
```



FFmpeg库是一个非常庞大的库，包括编码，解码以及流媒体的支持等，如果不做裁剪全部编译进来的话，最后生成的静态库会很大。并且有很多不需要的东西，都可以禁止掉。

配置裁剪方法：修改配置 build-ffmpeg.sh 脚本里面 CONFIGURE_FLAGS 后面的内容即可。

配置选项参数：

```sh

--disable-static ：// 不构建静态库[默认：关闭]
--enable-shared ：// 构建共享库
--enable-gpl ：  // 允许使用GPL代码。
--enable-nonfree ：// 允许使用非免费代码。
--disable-doc ：  // 不构造文档
--disable-avfilter  ：// 禁止视频过滤器支持
--enable-small  ：   // 启用优化文件尺寸大小（牺牲速度）
--cross-compile  ： // 使用交叉编译
--disable-hwaccels  ：// 禁用所有硬件加速(本机不存在硬件加速器，所有不需要)
--disable-network  ：//  禁用网络

--disable-ffmpeg  --disable-ffplay  --disable-ffprobe  --disable-ffserver
// 禁止ffmpeg、ffplay、ffprobe、ffserver 
 
--disable-avdevice --disable-avcodec --disable-avcore
// 禁止libavdevice、libavcodec、libavcore


--list-decoders ： // 显示所有可用的解码器
--list-encoders ： // 显示所有可用的编码器
--list-hwaccels ： // 显示所有可用的硬件加速器            
--list-protocols ： // 显示所有可用的协议                                  
--list-indevs ：   // 显示所有可用的输入设备
--list-outdevs ： // 显示所有可用的输出设备
--list-filters ：// 显示所有可用的过滤器
--list-parsers ：// 显示所有的解析器
--list-bsfs ：  // 显示所有可用的数据过滤器


--disable-encoder=NAME ： // 禁用XX编码器 | disables encoder NAME
--enable-encoder=NAME ： // 用XX编码器 | enables encoder NAME
--disable-decoders ：   // 禁用所有解码器 | disables all decoders
 
--disable-decoder=NAME ： // 禁用XX解码器 | disables decoder NAME
--enable-decoder=NAME ： // 启用XX解码器 | enables decoder NAME
--disable-encoders ：   // 禁用所有编码器 | disables all encoders
 
--disable-muxer=NAME ： // 禁用XX混音器 | disables muxer NAME
--enable-muxer=NAME ： // 启用XX混音器 | enables muxer NAME
--disable-muxers ：   // 禁用所有混音器 | disables all muxers
 
--disable-demuxer=NAME ： // 禁用XX解轨器 | disables demuxer NAME
--enable-demuxer=NAME ： // 启用XX解轨器 | enables demuxer NAME
--disable-demuxers ：   // 禁用所有解轨器 | disables all demuxers
 
--enable-parser=NAME ：  // 启用XX剖析器 | enables parser NAME
--disable-parser=NAME ： // 禁用XX剖析器 | disables parser NAME
--disable-parsers ：    // 禁用所有剖析器 | disa
```

### 运行脚本生成 FFmpeg

```sh
cd FFmpeg-iOS-build-script
./build-ffmpeg.sh
```

运行完毕就会生成：

- ffmpeg-4.4.1、FFmpeg-iOS 、scratch、thin 等文件夹
- lib：对应的 FFmpeg 静态库
- include：对应的 FFmpeg 头文件



## 异常处理

1. xcrun -sdk iphoneos clang is unable to create an executable file.C compiler test failed.

解决方案：

```sh
sudo xcode-select --switch /Applications/Xcode.app/Contents/Developer/
```

2. 编译错误 unknown type name 'AudioDeviceID'; did you mean 'AudioFileID'?

解决方案：

添加配置参数 --disable-audiotoolbox

参考来源：https://github.com/kewlbear/FFmpeg-iOS-build-script/issues/161



## iOS 集成 FFmpeg

1. 新建一个空项目，在Link Binary With Libraries 里添加

- libz.tbd
- libbz2.tbd
- libiconv.tbd
- AVFoundation.framework

2. 将编译好的 FFmpeg-iOS 文件夹拖入到项目
3. 添加头文件路径

Build Setting -> Search Paths -> Header Search Paths 添加 `$(SRCROOT)/$(PRODUCT_NAME)/FFmpeg-iOS/include`

4. 将 ffmpeg-4.4.1 -> fftools 文件夹中以下文件拖入项目中，在配置文件中禁用功能对应的文件除外

```
cmdutils.c
cmdutils.h
ffmpeg_filter.c
ffmpeg_hw.c
ffmpeg_opt.c
ffmpeg_videotoolbox.c
ffmpeg.c
ffmpeg.h
ffplay.c
ffprobe.c
```

5. 将 scratch 文件夹下任意一个架构文件夹中的 config.h 文件拖入项目中对应位置
6. 将 ffmpeg-4.4.1 -> libavutil -> thread.h 文件拖入项目中对应位置
7. 运行程序，注释掉缺失文件引用
8. 注释掉报错的代码
9. 修改main函数

将 ffmpeg.c 中 **int** main(**int** argc, **char** **argv) 修改为

```c
int ffmpeg_main(int argc, char **argv)
```

在 ffmpeg.h 中添加声明

```objc
int ffmpeg_main(int argc, char **argv);
```

至此就可以运行起来项目了



## 优化代码

1. 重置计数器

在 ffmpeg.c 中找到 **static** **void** ffmpeg_cleanup(**int** ret) 方法，在 term_exit() 前添加

```c
static void ffmpeg_cleanup(int ret)
{
    /* ... */
    
    progress_avio       = NULL;
    subtitle_out        = NULL;
    input_files         = NULL;
    input_streams       = NULL;
    output_files        = NULL;
    output_streams      = NULL;
    filtergraphs        = NULL;
    
    nb_input_files      = 0;
    nb_input_streams    = 0;
    nb_output_files     = 0;
    nb_output_streams   = 0;
    nb_filtergraphs     = 0;
    received_sigterm    = 0;
    received_nb_signals = 0;
    
    term_exit();
    ffmpeg_exited = 1;
}
```

2. 防止执行结束退出程序

方法1：在 ffmpeg.c 中找到 **int** ffmpeg_main(**int** argc, **char** **argv) 方法，将其中所有的 exit_program() 替换为 ffmpeg_cleanup()

方法2：在 cmdutils.c 中找到 void exit_program(int ret) ，修改为

```c
int exit_program(int ret) {
    if (program_exit)
        program_exit(ret);
    return ret;
}
```

在 cmdutils.h 找到对应的声明，修改为

```objc
int exit_program(int ret);
```



## 调用 FFmpeg tool 命令

以将m3u8转为mp4为例

```objc
- (void)action
{
    NSString *output = [[NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES) firstObject]
                        stringByAppendingPathComponent:@"output.mp4"];
    
    NSString *cmd = [NSString stringWithFormat:@"ffmpeg -i %@ -c:v copy -c:a copy %@",
                     self.url,output];
    
    [[[NSThread alloc] initWithTarget:self selector:@selector(run:) object:cmd] start];
}

- (void)run:(NSString *)cmd
{
    NSArray *argvs = [cmd componentsSeparatedByString:@" "];
    int argc = (int)argvs.count;
    char **argv = calloc(argc, sizeof(char *));
    for (int i = 0; i < argc; i++)
    {
        argv[i] = (char *)[argvs[i] UTF8String];
    }
    
    ffmpeg_main(argc, argv);
}
```

FFmpeg tool命令格式为

```sh
ffmpeg [global_options] {[input_file_options] -i input_url} ... {[output_file_options] output_url} ...
```

常用参数

-i 输入源

-r 帧率

-c:a 音频编码格式

-c:v 视频编码格式

-b:a 音频比特率

-b:v 视频比特率

详细命令可见官方文档

地址：https://ffmpeg.org/ffmpeg.html

