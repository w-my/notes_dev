//
//  XMGTollView.m
//  XMGEaseMob5
//
//  Created by xiaomage on 15/12/27.
//  Copyright © 2015年 xiaomage. All rights reserved.
//

#import "XMGTollView.h"

@interface XMGTollView ()<UITextViewDelegate>
/** 语音按钮 */
@property (nonatomic, weak) XMGNButton *my_voiceBtn;

/** 文本输入框 */
@property (nonatomic, weak) UITextView *my_inputView;

/** 录音按钮 */
@property (nonatomic, weak) XMGNButton *my_sendVoiceBtn;

/** 更多按钮 */
@property (nonatomic, weak) XMGNButton *my_moreBtn;
@end

@implementation XMGTollView

- (instancetype)initWithFrame:(CGRect)frame
{
    if (self = [super initWithFrame:frame]) {
        
        self.backgroundColor = [UIColor redColor];
        
        // 添加子控件
        // 1. 语音按钮
        XMGNButton *voiceBtn = [XMGNButton createXMGButton];
        [voiceBtn setImage:[UIImage imageNamed:@"ToolViewInputVoice"] forState:UIControlStateNormal];
        [self addSubview:voiceBtn];
        // 2. 文本输入框
        UITextView *inputView = [[UITextView alloc]init];
        inputView.backgroundColor = [UIColor whiteColor];
        inputView.returnKeyType = UIReturnKeyDone;
        inputView.delegate = self;
        [self addSubview:inputView];
        
        // 3. 录音按钮
        XMGNButton *sendVoiceBtn = [XMGNButton createXMGButton];
        [sendVoiceBtn setTitle:@"按住录音" forState:UIControlStateNormal];
        [sendVoiceBtn setTitle:@"松开发送" forState:UIControlStateHighlighted];
        [sendVoiceBtn addTarget:self action:@selector(startVoice:) forControlEvents:UIControlEventTouchDown];
        [sendVoiceBtn addTarget:self action:@selector(stopVoice:) forControlEvents:UIControlEventTouchUpInside];
        [sendVoiceBtn addTarget:self action:@selector(cancelVoice:) forControlEvents:UIControlEventTouchUpOutside];
        [self addSubview:sendVoiceBtn];
        sendVoiceBtn.hidden = YES;
        
        // 4. 更多按钮
        XMGNButton *moreBtn = [XMGNButton createXMGButton];
        [moreBtn setImage:[UIImage imageNamed:@"TypeSelectorBtn_Black"] forState:UIControlStateNormal];
        moreBtn.block = ^(XMGNButton *btn){
            if (_moreBtnBlock) {
                _moreBtnBlock();
            }
        };
        [self addSubview:moreBtn];
        
        // 赋值
        self.my_voiceBtn = voiceBtn;
        self.my_inputView = inputView;
        self.my_sendVoiceBtn = sendVoiceBtn;
        self.my_moreBtn = moreBtn;
        
        // 事件处理
        voiceBtn.block = ^(XMGNButton *btn){
            inputView.hidden = sendVoiceBtn.hidden;
            sendVoiceBtn.hidden = !inputView.hidden;
        
        };
    }
    return self;
}

// 按钮的点击事件
- (void)startVoice:(XMGNButton *)btn
{
    if (self.delegate && [self.delegate respondsToSelector:@selector(toolViewWithType:button:)]) {
        [self.delegate toolViewWithType:XMGTollViewVoiceTypeStart button:btn];
    }
}

// 停止语音
- (void)stopVoice:(XMGNButton *)btn
{
    if (self.delegate && [self.delegate respondsToSelector:@selector(toolViewWithType:button:)]) {
        [self.delegate toolViewWithType:XMGTollViewVoiceTypeStop button:btn];
    }
}

- (void)cancelVoice:(XMGNButton *)btn
{
    if (self.delegate && [self.delegate respondsToSelector:@selector(toolViewWithType:button:)]) {
        [self.delegate toolViewWithType:XMGTollViewVoiceTypeCancel button:btn];
    }
}

- (void)layoutSubviews
{
    [super layoutSubviews];
    self.my_voiceBtn.frame = CGRectMake(kWeChatPadding, kWeChatPadding/2 , self.height - kWeChatPadding , self.height - kWeChatPadding);
    
    self.my_inputView.frame = CGRectMake(self.my_voiceBtn.right + kWeChatPadding, self.my_voiceBtn.top, kWeChatScreenWidth - self.my_inputView.left*2, self.my_voiceBtn.height);
    
    self.my_sendVoiceBtn.frame = self.my_inputView.frame;
    
    self.my_moreBtn.frame = CGRectMake(self.my_inputView.right + kWeChatPadding, self.my_voiceBtn.top, self.my_voiceBtn.width, self.my_voiceBtn.height);
}


#pragma mark - UITextViewDelegate
- (void)textViewDidChange:(UITextView *)textView
{
    if (textView.text.length == 0) return;
    
    // 点击了完成按钮
    if ([textView.text hasSuffix:@"\n"]) {
        if (_sendTextBlock) {
            self.sendTextBlock(textView,XMGTollViewEditTextViewTypeSend);
        }
        [textView resignFirstResponder];
    }
}

- (BOOL)textViewShouldBeginEditing:(UITextView *)textView
{
    if (_sendTextBlock) {
        self.sendTextBlock(textView,XMGTollViewEditTextViewTypeBegin);
    }
    return YES;
}


@end
