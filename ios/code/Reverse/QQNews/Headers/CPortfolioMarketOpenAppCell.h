//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNThemableTableViewCell.h"

@class QNRootViewController;

@interface CPortfolioMarketOpenAppCell : QNThemableTableViewCell
{
    id localeObserver;
    _Bool isPrtfolioData;
    _Bool _isAdImageDownload;
    QNRootViewController *_myController;
}

+ (double)height;
@property(nonatomic) QNRootViewController *myController; // @synthesize myController=_myController;
@property(nonatomic) _Bool isAdImageDownload; // @synthesize isAdImageDownload=_isAdImageDownload;
- (void).cxx_destruct;
- (void)openApp:(id)arg1;
- (void)setSelected:(_Bool)arg1 animated:(_Bool)arg2;
- (void)dealloc;
- (id)initWithStyle:(long long)arg1 reuseIdentifier:(id)arg2 dataCount:(long long)arg3 tableViewHeight:(double)arg4 bPortfolio:(_Bool)arg5 parentController:(id)arg6 isPortfolioView:(_Bool)arg7;

@end
