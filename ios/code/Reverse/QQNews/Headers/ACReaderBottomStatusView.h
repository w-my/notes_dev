//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "UIView.h"

@class NSDateFormatter, NSString, NSTimer, UIImageView, UILabel;

@interface ACReaderBottomStatusView : UIView
{
    NSTimer *_timerForUpdateTime;
    UIView *_contentView;
    UILabel *_infoLabel;
    UIImageView *_batteryImageView;
    UIView *_batteryLevelView;
    UIImageView *_lightningImageView;
    NSDateFormatter *_dateFormatter;
    long long _seqNo;
    NSString *_netStatusString;
}

@property(copy, nonatomic) NSString *netStatusString; // @synthesize netStatusString=_netStatusString;
@property(nonatomic) long long seqNo; // @synthesize seqNo=_seqNo;
@property(retain, nonatomic) NSDateFormatter *dateFormatter; // @synthesize dateFormatter=_dateFormatter;
@property(retain, nonatomic) UIImageView *lightningImageView; // @synthesize lightningImageView=_lightningImageView;
@property(retain, nonatomic) UIView *batteryLevelView; // @synthesize batteryLevelView=_batteryLevelView;
@property(retain, nonatomic) UIImageView *batteryImageView; // @synthesize batteryImageView=_batteryImageView;
@property(retain, nonatomic) UILabel *infoLabel; // @synthesize infoLabel=_infoLabel;
@property(retain, nonatomic) UIView *contentView; // @synthesize contentView=_contentView;
@property(retain, nonatomic) NSTimer *timerForUpdateTime; // @synthesize timerForUpdateTime=_timerForUpdateTime;
- (void).cxx_destruct;
- (void)batteryStateDidChange;
- (void)batteryLevelDidChange;
- (void)updateViewWithChapterSeqno:(long long)arg1;
- (void)updateTime;
- (id)init;
- (void)dealloc;

@end

