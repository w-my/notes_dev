//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "UIView.h"

@class CABasicAnimation, UILabel;

@interface QNVideoRecordTitleView : UIView
{
    UIView *_spot;
    UILabel *_title;
    CABasicAnimation *_flashAnimation;
    unsigned long long _status;
}

@property(readonly, nonatomic) unsigned long long status; // @synthesize status=_status;
- (void).cxx_destruct;
- (void)updateWithRecordStatus:(unsigned long long)arg1;
- (id)initWithFrame:(struct CGRect)arg1;

@end
