//
//  ViewController.m
//  视频编码
//
//  Created by WTW on 2020/3/19.
//  Copyright © 2020 WTW. All rights reserved.
//

#import "ViewController.h"
#import "VideoCapture.h"

/*
 为什么可以进行压缩编码？
    存在冗余
        空间冗余：同一张图像中相邻像素之间有较强的相关性
        时间冗余：多张图片之间相邻图像之间内容相似
        视觉冗余：人的视觉系统对某些细节不敏感
压缩编码的标准：
    标准化组织(ITU、ISO)
    H.26X系列（由ITU[国际电传视讯联盟]主导） H.264(AVC)使用最广泛
    MPEG系列（由ISO[国际标准组织机构]下属的MPEG[运动图象专家组]开发）
 常见的编码流程：
    首先基于当前信号做预测信号(帧内或者帧间)
        时间上的预测：使用先前帧做预测
        空间上的预测：根据同一帧中相邻像素的信号做预测
    当前信号和预测信号相减得到残余信号，只对残余信号进行编码
        并不是直接对残余信号编码，还要做各种变换，去除空间和感知上的一些信息，在去除一些统计上的冗余，然后编码

 H.264 (AVC)
    定义了三种帧：
        I帧：完整编码的帧叫I帧 (关键帧)
        P帧：参考之前的I帧生成的只包含差异部分编码的帧叫P帧
        B帧：参考前后(I和P)的帧编码的帧叫B帧
    H.264 核心算法：
        帧内压缩：生成 I 帧的算法
        帧间压缩：生成 P帧和B帧的算法
    H.264 压缩方法：
        分组   : 把几帧图像分为一组(GOP，也就是一个序列),为防止运动变化,帧数不宜取多
        定义帧 : 将每组内各帧图像定义为三种类型,即I帧、B帧和P帧;
        预测帧 : 以I帧做为基础帧,以I帧预测P帧,再由I帧和P帧预测B帧;
        数据传输:最后将I帧数据与预测的差值信息进行存储和传输
    GOP(组):
        图像以序列为单位进行组织，一个序列是一段图像编码后的数据流
        一个序列的第一个图像叫做 IDR 图像（立即刷新图像），IDR 图像都是 I 帧图像 (删除以前的参考，从新开始)
    一个序列就是一段内容差异不太大的图像编码后生成的一串数据流：
        当运动变化比较少时，序列可以很长(一个I帧，然后一直P帧、B帧了)
        运动变化多时，序列就比较短了，比如就包含一个I帧和3、4个P帧
        视频编码序列中，GOP即Group of picture（图像组），指两个I帧之间的距离
    H.264 分层设计:
        视频编码层:(VCL：Video Coding Layer) 负责高效的视频内容表示编码
        网络提取层:(NAL：Network Abstraction Layer) 以网络所要求的恰当的方式对数据进行打包和传送
    NAL设计目的：
        根据不同的网络把数据打包成相应的格式，将VCL产生的比特字符串适配到各种各样的网络和多元环境中
    NAL的封装方式：
        NAL是将每一帧数据写入到一个NAL单元中，进行传输或存储的
        NALU分为NAL头和NAL体
        NALU头 通常为00 00 00 01，作为一个新的NALU的起始标识
        NALU体 封装着VCL编码后的信息或者其他信息
    封装过程：
        I帧、P帧、B帧都是被封装成一个或者多个NALU进行传输或者存储的
        I帧开始之前也有非VCL的NAL单元，用于保存其他信息，比如：PPS、SPS
        PPS（Picture Parameter Sets）：图像参数集
        SPS（Sequence Parameter Set）：序列参数集
        在实际的H264数据帧中，往往帧前面带有00 00 00 01 或 00 00 01分隔符，一般来说编码器编出的首帧数据为PPS与SPS，接着为I帧，后续是B帧、P帧等数据

    编码方式：
        硬编码：使用非CPU进行编码，如显卡GPU、专用的DSP、FPGA、ASIC芯片等
        软编码：使用CPU进行编码，软编码通常使用：ffmpeg+x264
 
    在iOS8之后，苹果开放了接口，并且封装了VideoToolBox&AudioToolbox两个框架，分别用于对视频&音频进行 硬编码
 */

@interface ViewController ()

/** 视频捕捉对象 */
@property (nonatomic, strong) VideoCapture *videoCapture;

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
}

- (IBAction)startCapture {
    [self.videoCapture startCapture:self.view];
}

- (IBAction)stopCapture {
    [self.videoCapture stopCapture];
}

- (VideoCapture *)videoCapture {
    if (_videoCapture == nil) {
        _videoCapture = [[VideoCapture alloc] init];
    }
    
    return _videoCapture;
}


@end
