//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "UIView.h"

@class CALayer, NSDate, UIActivityIndicatorView, UIImageView, UILabel;

@interface EGORefreshTableHeaderView : UIView
{
    id _delegate;
    int _state;
    UILabel *_lastUpdatedLabel;
    UILabel *_statusLabel;
    CALayer *_arrowImage;
    UIActivityIndicatorView *_activityView;
    _Bool _isTriggerByDrag;
    NSDate *_lastUpdateDate;
    UIImageView *_yinyingView;
}

@property(retain, nonatomic) UILabel *statusLabel; // @synthesize statusLabel=_statusLabel;
@property(retain, nonatomic) UILabel *lastUpdatedLabel; // @synthesize lastUpdatedLabel=_lastUpdatedLabel;
@property(retain, nonatomic) CALayer *arrowImage; // @synthesize arrowImage=_arrowImage;
@property(retain, nonatomic) UIImageView *yinyingView; // @synthesize yinyingView=_yinyingView;
@property(retain, nonatomic) NSDate *lastUpdateDate; // @synthesize lastUpdateDate=_lastUpdateDate;
@property(nonatomic) _Bool isTriggerByDrag; // @synthesize isTriggerByDrag=_isTriggerByDrag;
@property(nonatomic) id <EGORefreshTableHeaderDelegate> delegate; // @synthesize delegate=_delegate;
- (void)dealloc;
- (void)forceLoading:(id)arg1;
- (void)egoRefreshScrollViewDataSourceDidFinishedLoading:(id)arg1;
- (void)egoRefreshScrollViewDidEndDragging:(id)arg1;
- (void)egoRefreshScrollViewDidScroll:(id)arg1;
- (void)setState:(int)arg1;
- (void)refreshLastUpdatedDate;
- (id)initWithFrame:(struct CGRect)arg1;

@end
