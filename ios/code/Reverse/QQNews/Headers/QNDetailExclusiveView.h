//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "UIView.h"

#import "QNDetailContentElementProtocol.h"
#import "QNPageViewDataSource.h"
#import "QNPageViewDelegate.h"
#import "UIScrollViewDelegate.h"

@class NSArray, NSString, QNDetailContentContainer, QNListNewsItem, QNPageView;

@interface QNDetailExclusiveView : UIView <QNPageViewDataSource, QNPageViewDelegate, UIScrollViewDelegate, QNDetailContentElementProtocol>
{
    _Bool _exposured;
    QNListNewsItem *_listItem;
    QNDetailContentContainer *_contentContainer;
    NSArray *_items;
    QNPageView *_pageView;
    unsigned long long _exposuredNewsCount;
}

@property(nonatomic) unsigned long long exposuredNewsCount; // @synthesize exposuredNewsCount=_exposuredNewsCount;
@property(nonatomic) _Bool exposured; // @synthesize exposured=_exposured;
@property(retain, nonatomic) QNPageView *pageView; // @synthesize pageView=_pageView;
@property(copy, nonatomic) NSArray *items; // @synthesize items=_items;
@property(nonatomic) __weak QNDetailContentContainer *contentContainer; // @synthesize contentContainer=_contentContainer;
@property(retain, nonatomic) QNListNewsItem *listItem; // @synthesize listItem=_listItem;
- (void).cxx_destruct;
- (void)scrollViewWillEndDragging:(id)arg1 withVelocity:(struct CGPoint)arg2 targetContentOffset:(inout struct CGPoint *)arg3;
- (void)pageView:(id)arg1 didSelectedContentView:(id)arg2 atPage:(unsigned long long)arg3;
- (void)scrollViewDidScroll:(id)arg1;
- (id)pageView:(id)arg1 contentForPage:(unsigned long long)arg2;
- (unsigned long long)numberOfRowsInPageView:(id)arg1;
- (void)contentContainerWillDisappear;
- (void)contentContainer:(id)arg1 ScrolledToPosition:(struct CGPoint)arg2;
- (double)heightOfElementView;
- (void)layoutWithExclusiveItems:(id)arg1;
- (id)initWithFrame:(struct CGRect)arg1;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

