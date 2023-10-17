//
//  VideoEncoder.h
//  视频编码
//
//  Created by WTW on 2020/3/19.
//  Copyright © 2020 WTW. All rights reserved.
//


#import <UIKit/UIKit.h>
#import <VideoToolbox/VideoToolbox.h>

@interface VideoEncoder : NSObject

- (void)encodeSampleBuffer:(CMSampleBufferRef)sampleBuffer;
- (void)endEncode;

@end
