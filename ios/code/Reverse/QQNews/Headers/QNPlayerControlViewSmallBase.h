//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNPlayerControlViewBase.h"

@class QNTVKPlayerProgressBarMini;

@interface QNPlayerControlViewSmallBase : QNPlayerControlViewBase
{
    QNTVKPlayerProgressBarMini *_miniProgressBar;
}

@property(retain, nonatomic) QNTVKPlayerProgressBarMini *miniProgressBar; // @synthesize miniProgressBar=_miniProgressBar;
- (void).cxx_destruct;
- (void)updateProgress:(double)arg1 bufferTime:(double)arg2 duration:(double)arg3;
- (void)layoutSubviews;
- (void)createSubViews;

@end

