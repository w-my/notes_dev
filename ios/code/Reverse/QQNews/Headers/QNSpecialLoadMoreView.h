//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNThemableTableViewHeaderView.h"

@class QNBasicMoreFooterView;

@interface QNSpecialLoadMoreView : QNThemableTableViewHeaderView
{
    QNBasicMoreFooterView *_footerView;
}

+ (double)viewHeightForLast;
+ (double)viewHeight;
@property(retain, nonatomic) QNBasicMoreFooterView *footerView; // @synthesize footerView=_footerView;
- (void).cxx_destruct;
- (void)layoutWithWording:(id)arg1;
- (id)initWithReuseIdentifier:(id)arg1;

@end
