//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

#import "QNQualityCourseViewModelProtocol.h"

@class NSAttributedString, NSString, NSURL, UIColor;

@interface QNQualityCourseHeaderViewModel : NSObject <QNQualityCourseViewModelProtocol>
{
    UIColor *_bgColor;
    NSURL *_imageUrl;
    UIColor *_coverViewColor;
    NSAttributedString *_title;
    NSAttributedString *_subTitle;
    NSAttributedString *_desc;
    struct CGSize _viewSize;
    struct CGRect _imageViewRect;
    struct CGRect _titleRect;
    struct CGRect _subTitleRect;
    struct CGRect _descRect;
}

@property(nonatomic) struct CGRect descRect; // @synthesize descRect=_descRect;
@property(copy, nonatomic) NSAttributedString *desc; // @synthesize desc=_desc;
@property(nonatomic) struct CGRect subTitleRect; // @synthesize subTitleRect=_subTitleRect;
@property(copy, nonatomic) NSAttributedString *subTitle; // @synthesize subTitle=_subTitle;
@property(nonatomic) struct CGRect titleRect; // @synthesize titleRect=_titleRect;
@property(copy, nonatomic) NSAttributedString *title; // @synthesize title=_title;
@property(retain, nonatomic) UIColor *coverViewColor; // @synthesize coverViewColor=_coverViewColor;
@property(nonatomic) struct CGRect imageViewRect; // @synthesize imageViewRect=_imageViewRect;
@property(retain, nonatomic) NSURL *imageUrl; // @synthesize imageUrl=_imageUrl;
@property(retain, nonatomic) UIColor *bgColor; // @synthesize bgColor=_bgColor;
@property(nonatomic) struct CGSize viewSize; // @synthesize viewSize=_viewSize;
- (void).cxx_destruct;
- (void)calculateWithCourseModel:(id)arg1;
- (_Bool)hasValidData;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

