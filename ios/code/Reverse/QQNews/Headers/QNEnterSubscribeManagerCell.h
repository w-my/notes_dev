//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNThemableTableViewCell.h"

@class QNBaseLabel, UIImageView;

@interface QNEnterSubscribeManagerCell : QNThemableTableViewCell
{
    UIImageView *_icon;
    QNBaseLabel *_title;
    UIImageView *_indicatorView;
    QNBaseLabel *_topicLabel;
}

+ (id)topicAttributedStringForTopic:(id)arg1 count:(long long)arg2;
+ (double)maxContentWith;
+ (double)heightForNewTopicInfo:(id)arg1;
@property(retain, nonatomic) QNBaseLabel *topicLabel; // @synthesize topicLabel=_topicLabel;
@property(retain, nonatomic) UIImageView *indicatorView; // @synthesize indicatorView=_indicatorView;
@property(retain, nonatomic) QNBaseLabel *title; // @synthesize title=_title;
@property(retain, nonatomic) UIImageView *icon; // @synthesize icon=_icon;
- (void).cxx_destruct;
- (void)themeChanged:(long long)arg1;
- (void)updateWithNewTopicInfo:(id)arg1;
- (void)layoutSubviews;
- (id)initWithStyle:(long long)arg1 reuseIdentifier:(id)arg2;

@end

