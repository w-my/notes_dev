//
//  XMGTollView.h
//  XMGEaseMob5
//
//  Created by xiaomage on 15/12/27.
//  Copyright © 2015年 xiaomage. All rights reserved.
//

typedef enum {
    XMGTollViewVoiceTypeStart,
    XMGTollViewVoiceTypeStop,
    XMGTollViewVoiceTypeCancel
}XMGTollViewVoiceType;

typedef enum {
    XMGTollViewEditTextViewTypeSend,
    XMGTollViewEditTextViewTypeBegin
}XMGTollViewEditTextViewType;
#import <UIKit/UIKit.h>



typedef void(^XMGTollViewSendTextBlock)(UITextView *text,XMGTollViewEditTextViewType);
// block方式
typedef void(^XMGTollViewVoiceBlcok)(XMGTollViewVoiceType,XMGNButton *);

typedef void(^XMGTollViewMoreBtnBlock)();

@protocol XMGTollViewVoiceDelegate <NSObject>

- (void)toolViewWithType:(XMGTollViewVoiceType)type button:(XMGNButton *)btn;

@end

@interface XMGTollView : UIView

/** 发送消息的回调 */
@property (nonatomic, copy) XMGTollViewSendTextBlock sendTextBlock;

@property (nonatomic,assign)id<XMGTollViewVoiceDelegate> delegate;

/** 点击更多按钮的回调 */
@property (nonatomic, copy) XMGTollViewMoreBtnBlock moreBtnBlock;
@end
