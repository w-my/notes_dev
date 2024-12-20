//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "UIView.h"

#import "MVTailorMusicContentViewDelegate.h"
#import "UIScrollViewDelegate.h"

@class MVMusicItem, MVTailorMusicContentView, NSString, UILabel, UIScrollView;

@interface MVTailorMusicView : UIView <MVTailorMusicContentViewDelegate, UIScrollViewDelegate>
{
    _Bool _enableOverSelect;
    _Bool _contentHidden;
    id <MVTailorMusicViewDelegate> _tailorDelegate;
    double _targetSelectLength;
    MVTailorMusicContentView *_tailorMusicContentView;
    double _timerStartTime;
    unsigned long long _sampleCount;
    UIScrollView *_scrollView;
    UILabel *_startTime;
    UILabel *_endTime;
    double _totalLength;
    MVMusicItem *_musicItem;
    CDStruct_e83c9415 _selectRange;
}

@property(retain, nonatomic) MVMusicItem *musicItem; // @synthesize musicItem=_musicItem;
@property(nonatomic) double totalLength; // @synthesize totalLength=_totalLength;
@property(retain, nonatomic) UILabel *endTime; // @synthesize endTime=_endTime;
@property(retain, nonatomic) UILabel *startTime; // @synthesize startTime=_startTime;
@property(retain, nonatomic) UIScrollView *scrollView; // @synthesize scrollView=_scrollView;
@property(nonatomic) unsigned long long sampleCount; // @synthesize sampleCount=_sampleCount;
@property(nonatomic) double timerStartTime; // @synthesize timerStartTime=_timerStartTime;
@property(readonly, nonatomic) MVTailorMusicContentView *tailorMusicContentView; // @synthesize tailorMusicContentView=_tailorMusicContentView;
@property(nonatomic) _Bool contentHidden; // @synthesize contentHidden=_contentHidden;
@property(nonatomic) _Bool enableOverSelect; // @synthesize enableOverSelect=_enableOverSelect;
@property(nonatomic) double targetSelectLength; // @synthesize targetSelectLength=_targetSelectLength;
@property(readonly, nonatomic) CDStruct_e83c9415 selectRange; // @synthesize selectRange=_selectRange;
@property(nonatomic) __weak id <MVTailorMusicViewDelegate> tailorDelegate; // @synthesize tailorDelegate=_tailorDelegate;
- (void).cxx_destruct;
- (id)timeFormatted:(double)arg1;
- (void)scrollViewDidScroll:(id)arg1;
- (void)scrollViewDidEndDecelerating:(id)arg1;
- (void)scrollViewDidEndDragging:(id)arg1 willDecelerate:(_Bool)arg2;
- (void)onSizeChange:(struct CGSize)arg1;
- (void)loadSamplesWithCache:(id)arg1 complete:(CDUnknownBlockType)arg2;
- (void)fetchToRange;
- (_Bool)loadMaterial:(id)arg1 cache:(id)arg2 selectRange:(CDStruct_e83c9415)arg3 dowloadComplete:(CDUnknownBlockType)arg4 sampleComplete:(CDUnknownBlockType)arg5;
- (void)setPlayProgress:(float)arg1;
- (void)takeSamples:(CDUnknownBlockType)arg1;
- (void)reSelect:(_Bool)arg1;
- (id)initWithFrame:(struct CGRect)arg1;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

