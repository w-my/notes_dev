//
//  XMGAnyView.m
//  XMGEaseMob5
//
//  Created by xiaomage on 15/12/28.
//  Copyright © 2015年 xiaomage. All rights reserved.
//

#import "XMGAnyView.h"

#define XMGAnyViewSubviewHW (kWeChatScreenWidth - 4*kWeChatPadding)/3

@interface XMGAnyView ()

/** 图片按钮 */
@property (nonatomic, weak) XMGNButton *imgBtn;


/** 语音按钮 */
@property (nonatomic, weak) XMGNButton *talkBtn;

/** 视频按钮 */
@property (nonatomic, weak) XMGNButton *vedioBtn;

@end

@implementation XMGAnyView


- (instancetype)initImageBlock:(void (^)(void))imageBlock talkBlock:(void (^)(void))talkBlock vedioBlock:(void (^)(void))vedioBlock
{
    if (self = [super init]) {
        
        self.backgroundColor = [UIColor grayColor];
        
        // 初始化
        XMGNButton *imageBtn = [XMGNButton createXMGButton];
        [imageBtn setBackgroundColor:[UIColor redColor]];
        [imageBtn setTitle:@"图片" forState:UIControlStateNormal];
        [self addSubview:imageBtn];
        
        XMGNButton *talkChatBtn = [XMGNButton createXMGButton];
        [talkChatBtn setBackgroundColor:[UIColor greenColor]];
        [talkChatBtn setTitle:@"语音" forState:UIControlStateNormal];
        [self addSubview:talkChatBtn];
        
        XMGNButton *vedioChatBtn = [XMGNButton createXMGButton];
        [vedioChatBtn setBackgroundColor:[UIColor blueColor]];
        [vedioChatBtn setTitle:@"视频" forState:UIControlStateNormal];
        [self addSubview:vedioChatBtn];
        
        // 赋值
        self.imgBtn = imageBtn;
        self.talkBtn = talkChatBtn;
        self.vedioBtn = vedioChatBtn;
        
        // 事件处理
        imageBtn.block = ^(XMGNButton *btn){
            if (imageBlock) {
                imageBlock();
            }
        };
        talkChatBtn.block = ^(XMGNButton *btn){
            if (talkBlock) {
                talkBlock();
            }
        };
        vedioChatBtn.block = ^(XMGNButton *btn){
            if (vedioBlock) {
                vedioBlock();
            }
        };
    }
    return self;
}

- (void)layoutSubviews
{
    [super layoutSubviews];
    self.imgBtn.frame = CGRectMake(kWeChatPadding, kWeChatPadding, XMGAnyViewSubviewHW, XMGAnyViewSubviewHW);
    self.talkBtn.frame = CGRectMake(self.imgBtn.right + kWeChatPadding, self.imgBtn.top, XMGAnyViewSubviewHW, XMGAnyViewSubviewHW);
    self.vedioBtn.frame = CGRectMake(self.talkBtn.right + kWeChatPadding, self.talkBtn.top, XMGAnyViewSubviewHW, XMGAnyViewSubviewHW);
}


@end
