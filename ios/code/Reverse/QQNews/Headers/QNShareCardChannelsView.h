//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNThemableView.h"

@class NSArray, QNBaseLabel, UIView;

@interface QNShareCardChannelsView : QNThemableView
{
    NSArray *_canSharePlatforms;
    UIView *_line;
    QNBaseLabel *_descLabel;
    NSArray *_shareButtons;
}

@property(copy, nonatomic) NSArray *shareButtons; // @synthesize shareButtons=_shareButtons;
@property(nonatomic) __weak QNBaseLabel *descLabel; // @synthesize descLabel=_descLabel;
@property(nonatomic) __weak UIView *line; // @synthesize line=_line;
@property(copy, nonatomic) NSArray *canSharePlatforms; // @synthesize canSharePlatforms=_canSharePlatforms;
- (void).cxx_destruct;
- (id)p_imageWithSharePlatform:(long long)arg1;
- (void)p_checkCanSharePlatforms;
- (void)addTarget:(id)arg1 action:(SEL)arg2 forControlEvents:(unsigned long long)arg3;
- (void)layoutSubviews;
- (id)initWithFrame:(struct CGRect)arg1;

@end
