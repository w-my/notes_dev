//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNThemableView.h"

@class NSString, QNIntroduceContentView;

@interface QNIntroduceView : QNThemableView
{
    QNIntroduceContentView *_contentView;
    NSString *_introName;
    NSString *_intro;
}

@property(retain, nonatomic) NSString *intro; // @synthesize intro=_intro;
@property(retain, nonatomic) NSString *introName; // @synthesize introName=_introName;
@property(retain, nonatomic) QNIntroduceContentView *contentView; // @synthesize contentView=_contentView;
- (void).cxx_destruct;
- (void)themeChanged:(long long)arg1;
- (void)layoutViewWithIntroduceName:(id)arg1 introduce:(id)arg2;

@end

