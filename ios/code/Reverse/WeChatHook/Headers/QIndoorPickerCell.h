//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "UITableViewCell.h"

@class QIndoorLevel, UILabel;

@interface QIndoorPickerCell : UITableViewCell
{
    QIndoorLevel *_indoorLevel;
    UILabel *_label;
}

@property(retain, nonatomic) UILabel *label; // @synthesize label=_label;
@property(retain, nonatomic) QIndoorLevel *indoorLevel; // @synthesize indoorLevel=_indoorLevel;
- (void).cxx_destruct;
- (id)initWithStyle:(long long)arg1 reuseIdentifier:(id)arg2;
- (void)setupLabel;
- (void)setupBackground;
- (void)layoutSubviews;
- (void)fillLabel;

@end

