//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class UILabel;

@interface TVKSubTitleController : NSObject
{
    UILabel *_chSubLabel;
    UILabel *_enSubLabel;
    unsigned long long _stretchMode;
    struct CGSize _videoViewSize;
    struct CGSize _videoSize;
}

@property(nonatomic) unsigned long long stretchMode; // @synthesize stretchMode=_stretchMode;
@property(nonatomic) struct CGSize videoSize; // @synthesize videoSize=_videoSize;
@property(nonatomic) struct CGSize videoViewSize; // @synthesize videoViewSize=_videoViewSize;
@property(retain, nonatomic) UILabel *enSubLabel; // @synthesize enSubLabel=_enSubLabel;
@property(retain, nonatomic) UILabel *chSubLabel; // @synthesize chSubLabel=_chSubLabel;
- (void).cxx_destruct;
- (void)reLayout;
- (void)destroy;
- (void)updateSubTitle:(id)arg1;
- (void)updateStretchMode:(unsigned long long)arg1;
- (void)updateVideoViewSize:(struct CGSize)arg1 videoSize:(struct CGSize)arg2;
- (void)setContainer:(id)arg1;
- (id)init;

@end
