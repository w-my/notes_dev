//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

#import "QNQualityCourseViewModelProtocol.h"

@class NSAttributedString, NSString, QNDeDaoCourseModel, QNQualityCourseCommonTitleViewModel, UIColor, UIFont;

@interface QNQualityCourseDescriptionViewModel : NSObject <QNQualityCourseViewModelProtocol>
{
    _Bool _isExpanded;
    UIColor *_bgColor;
    QNQualityCourseCommonTitleViewModel *_commonTitleViewModel;
    NSAttributedString *_desc;
    UIColor *_buttonSaperatorLineColor;
    UIColor *_buttonTopLineColor;
    UIColor *_allButtonTitleColor;
    UIFont *_allButtonTitleFont;
    UIColor *_bottomLineColor;
    QNDeDaoCourseModel *_courseModel;
    struct CGSize _viewSize;
    struct CGRect _titleViewRect;
    struct CGRect _descRect;
    struct CGRect _buttonSaperatorLineRect;
    struct CGRect _buttonTopLineRect;
    struct CGRect _allButtonRect;
    struct CGRect _bottomLineRect;
}

@property(retain, nonatomic) QNDeDaoCourseModel *courseModel; // @synthesize courseModel=_courseModel;
@property(nonatomic) _Bool isExpanded; // @synthesize isExpanded=_isExpanded;
@property(retain, nonatomic) UIColor *bottomLineColor; // @synthesize bottomLineColor=_bottomLineColor;
@property(nonatomic) struct CGRect bottomLineRect; // @synthesize bottomLineRect=_bottomLineRect;
@property(nonatomic) struct CGRect allButtonRect; // @synthesize allButtonRect=_allButtonRect;
@property(retain, nonatomic) UIFont *allButtonTitleFont; // @synthesize allButtonTitleFont=_allButtonTitleFont;
@property(retain, nonatomic) UIColor *allButtonTitleColor; // @synthesize allButtonTitleColor=_allButtonTitleColor;
@property(retain, nonatomic) UIColor *buttonTopLineColor; // @synthesize buttonTopLineColor=_buttonTopLineColor;
@property(nonatomic) struct CGRect buttonTopLineRect; // @synthesize buttonTopLineRect=_buttonTopLineRect;
@property(nonatomic) struct CGRect buttonSaperatorLineRect; // @synthesize buttonSaperatorLineRect=_buttonSaperatorLineRect;
@property(retain, nonatomic) UIColor *buttonSaperatorLineColor; // @synthesize buttonSaperatorLineColor=_buttonSaperatorLineColor;
@property(nonatomic) struct CGRect descRect; // @synthesize descRect=_descRect;
@property(copy, nonatomic) NSAttributedString *desc; // @synthesize desc=_desc;
@property(nonatomic) struct CGRect titleViewRect; // @synthesize titleViewRect=_titleViewRect;
@property(retain, nonatomic) QNQualityCourseCommonTitleViewModel *commonTitleViewModel; // @synthesize commonTitleViewModel=_commonTitleViewModel;
@property(retain, nonatomic) UIColor *bgColor; // @synthesize bgColor=_bgColor;
@property(nonatomic) struct CGSize viewSize; // @synthesize viewSize=_viewSize;
- (void).cxx_destruct;
- (void)calculateWithCourseModel:(id)arg1;
- (_Bool)hasValidData;
- (id)init;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end
