//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QSSportsMatchScheduleAttrView.h"

@class CSimpleImageView, UILabel;

@interface QSSportsMatchSchedulePlayerDataView : QSSportsMatchScheduleAttrView
{
    CSimpleImageView *_avatarView;
    UILabel *_nameLabel;
    UILabel *_dataLabel;
}

+ (id)textColor;
+ (double)fixedHeight;
@property(retain, nonatomic) UILabel *dataLabel; // @synthesize dataLabel=_dataLabel;
@property(retain, nonatomic) UILabel *nameLabel; // @synthesize nameLabel=_nameLabel;
@property(retain, nonatomic) CSimpleImageView *avatarView; // @synthesize avatarView=_avatarView;
- (void).cxx_destruct;
- (void)refreshWithScheduleItem:(id)arg1;
- (id)initWithFrame:(struct CGRect)arg1;

@end
