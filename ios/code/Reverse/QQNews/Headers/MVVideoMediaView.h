//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "MVEditableMediaView.h"

@class UIImage, UIImageView;

@interface MVVideoMediaView : MVEditableMediaView
{
    _Bool _snapshotEnabled;
    UIImageView *_coverView;
}

@property(nonatomic) _Bool snapshotEnabled; // @synthesize snapshotEnabled=_snapshotEnabled;
@property(nonatomic) __weak UIImageView *coverView; // @synthesize coverView=_coverView;
- (void).cxx_destruct;
@property(readonly, nonatomic) UIImage *currentImage;
- (void)setContentMode:(long long)arg1;
- (void)updateCoverImageAtTime:(double)arg1;
- (void)replaceModel:(id)arg1 playControl:(id)arg2;
- (void)initCoverView;
- (void)initRenderView;
- (id)initWithFrame:(struct CGRect)arg1 editable:(_Bool)arg2;
- (id)initWithFrame:(struct CGRect)arg1;

@end
