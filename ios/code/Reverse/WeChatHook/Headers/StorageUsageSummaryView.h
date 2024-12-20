//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "UIView.h"

@class MMUILabel, StorageUsageSummaryModel;

@interface StorageUsageSummaryView : UIView
{
    MMUILabel *m_titleLabel;
    MMUILabel *m_sizeLabel;
    MMUILabel *m_subTitleLabel;
    UIView *m_percentView;
    StorageUsageSummaryModel *m_model;
}

@property(retain, nonatomic) StorageUsageSummaryModel *model; // @synthesize model=m_model;
- (void).cxx_destruct;
- (void)updateLayoutWithAnimation;
- (struct CGSize)sizeThatFits:(struct CGSize)arg1;
- (void)layout:(_Bool)arg1;
- (void)layoutSubviews;
- (void)initPercentView;
- (void)initSubTitleLabel;
- (void)initSizeLabel;
- (void)initTitleLabel;
- (void)initSubview;
- (id)initWithFrame:(struct CGRect)arg1;

@end

