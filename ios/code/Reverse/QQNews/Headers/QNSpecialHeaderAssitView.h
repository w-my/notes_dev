//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNThemableView.h"

@class QNBaseLabel;

@interface QNSpecialHeaderAssitView : QNThemableView
{
    QNBaseLabel *_readNumberLabel;
    QNBaseLabel *_followLabel;
}

+ (double)viewHeight;
+ (id)p_labelColor;
@property(retain, nonatomic) QNBaseLabel *followLabel; // @synthesize followLabel=_followLabel;
@property(retain, nonatomic) QNBaseLabel *readNumberLabel; // @synthesize readNumberLabel=_readNumberLabel;
- (void).cxx_destruct;
- (void)themeChanged:(long long)arg1;
- (void)layoutWithParam:(id)arg1;
- (void)p_resetViews;
- (void)p_initViews;
- (id)initWithFrame:(struct CGRect)arg1;

@end

