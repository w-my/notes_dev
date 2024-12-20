//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "UITableViewCell.h"

#import "KBTableViewCellProtocol.h"

@class KBListSeparatorSingle, NSString, QNBaseLabel, UIView;

@interface QNGuessLikeRelateHeaderCell : UITableViewCell <KBTableViewCellProtocol>
{
    KBListSeparatorSingle *_sepLine;
    UIView *_leftSep;
    QNBaseLabel *_titleLabel;
    UIView *_rightSep;
}

+ (double)heightForData:(id)arg1 width:(double)arg2 context:(id)arg3;
@property(retain, nonatomic) UIView *rightSep; // @synthesize rightSep=_rightSep;
@property(retain, nonatomic) QNBaseLabel *titleLabel; // @synthesize titleLabel=_titleLabel;
@property(retain, nonatomic) UIView *leftSep; // @synthesize leftSep=_leftSep;
@property(retain, nonatomic) KBListSeparatorSingle *sepLine; // @synthesize sepLine=_sepLine;
- (void).cxx_destruct;
- (void)updateWithTitle:(id)arg1 context:(id)arg2;
- (void)layoutWithData:(id)arg1 context:(id)arg2;
- (id)initWithStyle:(long long)arg1 reuseIdentifier:(id)arg2;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

