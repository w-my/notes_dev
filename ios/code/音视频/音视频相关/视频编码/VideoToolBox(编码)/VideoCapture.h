//
//  VideoCapture.h
//  视频编码
//
//  Created by WTW on 2020/3/19.
//  Copyright © 2020 WTW. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface VideoCapture : NSObject

- (void)startCapture:(UIView *)preview;

- (void)stopCapture;

@end
