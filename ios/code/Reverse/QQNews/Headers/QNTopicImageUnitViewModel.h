//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

#import "QNTopicImageUnitViewProtocol.h"

@class NSArray, NSString, UIColor, UIImage;

@interface QNTopicImageUnitViewModel : NSObject <QNTopicImageUnitViewProtocol>
{
    UIColor *_bgColor;
    UIImage *_placeholderImage;
    NSArray *_imageBrowserItems;
    struct CGSize _singleImageSize;
    struct CGRect _rect;
    struct CGRect _gridViewRect;
}

@property(copy, nonatomic) NSArray *imageBrowserItems; // @synthesize imageBrowserItems=_imageBrowserItems;
@property(nonatomic) struct CGRect gridViewRect; // @synthesize gridViewRect=_gridViewRect;
@property(retain, nonatomic) UIImage *placeholderImage; // @synthesize placeholderImage=_placeholderImage;
@property(nonatomic) struct CGSize singleImageSize; // @synthesize singleImageSize=_singleImageSize;
@property(retain, nonatomic) UIColor *bgColor; // @synthesize bgColor=_bgColor;
@property(nonatomic) struct CGRect rect; // @synthesize rect=_rect;
- (void).cxx_destruct;
- (void)calculateWithData:(id)arg1 referRect:(struct CGRect)arg2 context:(id)arg3;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

