//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "UIView.h"

#import "QNPageViewContentViewProtocol.h"

@class NSString, QNListNewsItem, QNVideoRecommendItemView;

@interface QNVideoRecommendPageView : UIView <QNPageViewContentViewProtocol>
{
    unsigned long long contentIndex;
    CDUnknownBlockType _playVideoBlock;
    QNVideoRecommendItemView *_itemViewFirst;
    QNVideoRecommendItemView *_itemViewSecond;
    QNListNewsItem *_listItemFirst;
    QNListNewsItem *_listItemSecond;
}

+ (struct CGSize)viewSize;
+ (id)viewReuseIdentifier;
@property(retain, nonatomic) QNListNewsItem *listItemSecond; // @synthesize listItemSecond=_listItemSecond;
@property(retain, nonatomic) QNListNewsItem *listItemFirst; // @synthesize listItemFirst=_listItemFirst;
@property(retain, nonatomic) QNVideoRecommendItemView *itemViewSecond; // @synthesize itemViewSecond=_itemViewSecond;
@property(retain, nonatomic) QNVideoRecommendItemView *itemViewFirst; // @synthesize itemViewFirst=_itemViewFirst;
@property(copy, nonatomic) CDUnknownBlockType playVideoBlock; // @synthesize playVideoBlock=_playVideoBlock;
@property(nonatomic) unsigned long long contentIndex; // @synthesize contentIndex;
- (void).cxx_destruct;
- (void)tapGestureSecond:(id)arg1;
- (void)tapGestureFirst:(id)arg1;
- (void)layoutWithListItemFirst:(id)arg1 listItemSecond:(id)arg2;
- (id)reuseIdentifier;
- (id)initWithFrame:(struct CGRect)arg1;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end
