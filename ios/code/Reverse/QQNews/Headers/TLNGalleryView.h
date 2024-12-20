//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "TLNViewBase.h"

#import "UIScrollViewDelegate.h"

@class NSString, UIPageControl, UIScrollView;

@interface TLNGalleryView : TLNViewBase <UIScrollViewDelegate>
{
    UIScrollView *_imageScrollView;
    UIPageControl *_pageControl;
}

@property(retain, nonatomic) UIPageControl *pageControl; // @synthesize pageControl=_pageControl;
@property(retain, nonatomic) UIScrollView *imageScrollView; // @synthesize imageScrollView=_imageScrollView;
- (void).cxx_destruct;
- (void)pageAction:(id)arg1;
- (void)scrollViewDidEndDecelerating:(id)arg1;
- (void)layoutSubviews;
- (id)initWithModel:(id)arg1;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

