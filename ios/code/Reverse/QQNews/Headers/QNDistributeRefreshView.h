//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNPullToRefreshBaseView.h"

@class QNAnimationImageView, QNDistributeData, UIImageView;

@interface QNDistributeRefreshView : QNPullToRefreshBaseView
{
    UIImageView *_beginView;
    UIImageView *_updateView;
    QNAnimationImageView *_endView;
    QNDistributeData *_distributeData;
}

@property(retain, nonatomic) QNDistributeData *distributeData; // @synthesize distributeData=_distributeData;
- (void).cxx_destruct;
- (id)_getCurrentChannel;
- (void)_reportShowAnimation;
- (void)loadImages:(_Bool)arg1;
- (void)themeChanged:(long long)arg1;
- (double)packupDelayTime:(_Bool)arg1;
- (void)packupAnimating:(_Bool)arg1;
- (void)stopAnimating;
- (void)startAnimating;
- (void)setRoundScale:(double)arg1;
- (void)dealloc;
- (id)initWithDistributeData:(id)arg1;

@end
