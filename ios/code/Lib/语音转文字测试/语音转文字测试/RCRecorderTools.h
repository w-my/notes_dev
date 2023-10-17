//
//  RCRecorderTools.h
//  语音转文字测试
//
//  Created by wtw on 2018/11/8.
//  Copyright © 2018 wtw. All rights reserved.
//
// 需要info.plist添加
/* <key>NSSpeechRecognitionUsageDescription</key>  <string>请允许语音识别</string>
<key>NSMicrophoneUsageDescription</key>  <string>请打开麦克风</string>
 */

#import <Foundation/Foundation.h>
#import "RCSingleton.h"

@interface RCRecorderTools : NSObject

//单例
singleton_H(RCRecorderTools);

/**
 开始录音 语音识别

 @param block 回调权限状态 和 识别结果
 */
- (void)startRecordWithCallBack:(void(^)(BOOL availiable,NSString *formattedString))block;

/**
 结束录音 语音识别
 */
- (void)endRecord;

/**
 获取分贝值
 */
- (float)levels;

@end
