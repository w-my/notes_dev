//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "UIView.h"

@class UILabel;

@interface QSPlayerRanklistHeaderView : UIView
{
    UILabel *_ranklistLabel;
    UILabel *_pointLabel;
    UIView *_bottomSeperatorLineView;
}

@property(retain, nonatomic) UIView *bottomSeperatorLineView; // @synthesize bottomSeperatorLineView=_bottomSeperatorLineView;
@property(retain, nonatomic) UILabel *pointLabel; // @synthesize pointLabel=_pointLabel;
@property(retain, nonatomic) UILabel *ranklistLabel; // @synthesize ranklistLabel=_ranklistLabel;
- (void).cxx_destruct;
- (void)update;
- (id)initWithFrame:(struct CGRect)arg1;

@end

