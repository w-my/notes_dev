//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

#import "QNListSingleImageUnitModel.h"

@class NSAttributedString, NSString, NSURL, QNImageItem, QNImageProcessConfig, UIColor, UIImage;

@interface QNEventTimeLineCellSingleImageUnitModel : NSObject <QNListSingleImageUnitModel>
{
    _Bool _isVideo;
    _Bool _enableTapGesture;
    UIColor *_bgColor;
    NSURL *_imageURL;
    UIImage *_defaultImage;
    QNImageProcessConfig *_imageProcessConfig;
    NSAttributedString *_leftDesc;
    NSAttributedString *_rightDesc;
    UIImage *_image;
    long long _imageContentMode;
    struct CGRect _rect;
    struct CGRect _rightDescRect;
    struct CGRect _leftDescRect;
}

+ (struct CGSize)p_imageSize;
@property(readonly, nonatomic) long long imageContentMode; // @synthesize imageContentMode=_imageContentMode;
@property(readonly, nonatomic) _Bool enableTapGesture; // @synthesize enableTapGesture=_enableTapGesture;
@property(readonly, nonatomic) UIImage *image; // @synthesize image=_image;
@property(readonly, copy, nonatomic) NSAttributedString *rightDesc; // @synthesize rightDesc=_rightDesc;
@property(readonly, copy, nonatomic) NSAttributedString *leftDesc; // @synthesize leftDesc=_leftDesc;
@property(readonly, nonatomic) struct CGRect leftDescRect; // @synthesize leftDescRect=_leftDescRect;
@property(readonly, nonatomic) struct CGRect rightDescRect; // @synthesize rightDescRect=_rightDescRect;
@property(readonly, nonatomic) _Bool isVideo; // @synthesize isVideo=_isVideo;
@property(readonly, nonatomic) QNImageProcessConfig *imageProcessConfig; // @synthesize imageProcessConfig=_imageProcessConfig;
@property(readonly, nonatomic) UIImage *defaultImage; // @synthesize defaultImage=_defaultImage;
@property(readonly, nonatomic) NSURL *imageURL; // @synthesize imageURL=_imageURL;
@property(readonly, nonatomic) UIColor *bgColor; // @synthesize bgColor=_bgColor;
@property(readonly, nonatomic) struct CGRect rect; // @synthesize rect=_rect;
- (void).cxx_destruct;
- (void)updatePlayCount:(unsigned long long)arg1 hasPassed:(_Bool)arg2;
- (CDStruct_55d1109d)layoutTraitsForContext:(id)arg1;
- (id)p_attributedStringWithString:(id)arg1 icon:(id)arg2;
- (void)calculateWithData:(id)arg1 referRect:(struct CGRect)arg2 context:(id)arg3;

// Remaining properties
@property(readonly, nonatomic) _Bool autoPlayGIF;
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly, nonatomic) NSURL *gifStaticUrl;
@property(readonly) unsigned long long hash;
@property(readonly, nonatomic) QNImageItem *imageItem;
@property(readonly, nonatomic) _Bool isGIF;
@property(readonly, nonatomic) _Bool isLoading;
@property(readonly, nonatomic) _Bool isLongImage;
@property(readonly, copy, nonatomic) NSAttributedString *loadingDesc;
@property(readonly, nonatomic) struct CGRect loadingDescRect;
@property(readonly, nonatomic) struct CGRect loadingIndicatorRect;
@property(readonly) Class superclass;

@end
