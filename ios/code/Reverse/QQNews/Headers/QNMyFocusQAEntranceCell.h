//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNThemableTableViewCell.h"

@class QNBaseLabel, UIImageView;

@interface QNMyFocusQAEntranceCell : QNThemableTableViewCell
{
    QNBaseLabel *_title;
    UIImageView *_indicatorView;
}

+ (double)heightForData;
@property(retain, nonatomic) UIImageView *indicatorView; // @synthesize indicatorView=_indicatorView;
@property(retain, nonatomic) QNBaseLabel *title; // @synthesize title=_title;
- (void).cxx_destruct;
- (void)themeChanged:(long long)arg1;
- (void)layoutSubviews;
- (void)layoutWithQACount:(unsigned long long)arg1;
- (id)initWithStyle:(long long)arg1 reuseIdentifier:(id)arg2;

@end
