//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "UIView.h"

@class QNBaseLabel;

@interface QNMultiChangeTitleView : UIView
{
    QNBaseLabel *_broadcastName;
    QNBaseLabel *_indexLabel;
}

@property(retain, nonatomic) QNBaseLabel *indexLabel; // @synthesize indexLabel=_indexLabel;
@property(retain, nonatomic) QNBaseLabel *broadcastName; // @synthesize broadcastName=_broadcastName;
- (void).cxx_destruct;
- (void)layoutWithStreamInfo:(id)arg1 broadcastArray:(id)arg2;
- (id)initWithFrame:(struct CGRect)arg1;

@end
