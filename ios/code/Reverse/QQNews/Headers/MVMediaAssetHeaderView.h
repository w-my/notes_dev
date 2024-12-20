//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "UICollectionReusableView.h"

@class MVMediaAssetSection, UIButton, UILabel;

@interface MVMediaAssetHeaderView : UICollectionReusableView
{
    _Bool _allowsMultipleSelection;
    _Bool _canSelectAll;
    MVMediaAssetSection *_assetSection;
    CDUnknownBlockType _onSelectionButtonClicked;
    UILabel *_timeLabel;
    UILabel *_locationLabel;
    UIButton *_selectionButton;
}

+ (double)viewHeight;
@property(nonatomic) __weak UIButton *selectionButton; // @synthesize selectionButton=_selectionButton;
@property(nonatomic) __weak UILabel *locationLabel; // @synthesize locationLabel=_locationLabel;
@property(nonatomic) __weak UILabel *timeLabel; // @synthesize timeLabel=_timeLabel;
@property(copy, nonatomic) CDUnknownBlockType onSelectionButtonClicked; // @synthesize onSelectionButtonClicked=_onSelectionButtonClicked;
@property(retain, nonatomic) MVMediaAssetSection *assetSection; // @synthesize assetSection=_assetSection;
@property(nonatomic) _Bool canSelectAll; // @synthesize canSelectAll=_canSelectAll;
@property(nonatomic) _Bool allowsMultipleSelection; // @synthesize allowsMultipleSelection=_allowsMultipleSelection;
- (void).cxx_destruct;
- (void)setDate:(id)arg1 location:(id)arg2;
- (void)selectionButtonClicked:(id)arg1;
- (void)prepareForReuse;
- (void)awakeFromNib;

@end

