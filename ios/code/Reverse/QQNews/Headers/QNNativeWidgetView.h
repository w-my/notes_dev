//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNThemableView.h"

@class NSString, QNChartGroupView;

@interface QNNativeWidgetView : QNThemableView
{
    long long _widgetType;
    id _data;
    NSString *_widgetID;
    QNChartGroupView *_groupView;
    id <QNNativeWidgetViewDelegate> _delegate;
}

+ (struct CGSize)sizeForPlaceHolder;
+ (id)placeHolderView;
+ (struct CGSize)sizeForViewWithData:(id)arg1 width:(double)arg2 isNoPicMode:(_Bool)arg3;
+ (struct CGSize)sizeForViewWithData:(id)arg1;
@property(nonatomic) __weak id <QNNativeWidgetViewDelegate> delegate; // @synthesize delegate=_delegate;
@property(retain, nonatomic) QNChartGroupView *groupView; // @synthesize groupView=_groupView;
@property(readonly, nonatomic) NSString *widgetID; // @synthesize widgetID=_widgetID;
@property(retain, nonatomic) id data; // @synthesize data=_data;
@property(readonly, nonatomic) long long widgetType; // @synthesize widgetType=_widgetType;
- (void).cxx_destruct;
- (void)themeChanged:(long long)arg1;
- (_Bool)isNoPicMode;
- (id)listItem;
- (void)sizeChanged;
- (long long)widgetViewType;
- (void)layoutViewWithData:(id)arg1;
- (id)initWidget;

@end
