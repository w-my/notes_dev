//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "KBTableViewCell.h"

@class QNBaseLabel, QNSubscribeButton, QNTopicItem, UIImageView;

@interface QNTopicModuleHeaderCell : KBTableViewCell
{
    CDUnknownBlockType _subBlock;
    QNTopicItem *_topicItem;
    UIImageView *_topicIcon;
    QNBaseLabel *_nameLabel;
    QNBaseLabel *_abstractLabel;
    QNSubscribeButton *_followBtn;
    UIImageView *_lastLine;
}

+ (double)heightForData:(id)arg1 width:(double)arg2 context:(id)arg3;
@property(retain, nonatomic) UIImageView *lastLine; // @synthesize lastLine=_lastLine;
@property(retain, nonatomic) QNSubscribeButton *followBtn; // @synthesize followBtn=_followBtn;
@property(retain, nonatomic) QNBaseLabel *abstractLabel; // @synthesize abstractLabel=_abstractLabel;
@property(retain, nonatomic) QNBaseLabel *nameLabel; // @synthesize nameLabel=_nameLabel;
@property(retain, nonatomic) UIImageView *topicIcon; // @synthesize topicIcon=_topicIcon;
@property(retain, nonatomic) QNTopicItem *topicItem; // @synthesize topicItem=_topicItem;
@property(copy, nonatomic) CDUnknownBlockType subBlock; // @synthesize subBlock=_subBlock;
- (void).cxx_destruct;
- (void)p_TopicDataChangedNotification:(id)arg1;
- (void)p_reloadFollowCount:(long long)arg1;
- (void)layoutWithData:(id)arg1 context:(id)arg2;
- (void)themeChanged:(long long)arg1;
- (void)setBackgroundColor:(id)arg1;
- (void)layoutSubviews;
- (id)initWithStyle:(long long)arg1 reuseIdentifier:(id)arg2;
- (void)dealloc;

@end
