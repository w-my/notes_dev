//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNTableViewCell.h"

#import "QNListCellProtocol.h"

@class NSString, QNAttributedLabel, UIImageView, UIView;

@interface QNTopicProgressTextCell : QNTableViewCell <QNListCellProtocol>
{
    UIView *_containerBgView;
    UIImageView *_headerImageView;
    UIImageView *_footerImageView;
    QNAttributedLabel *_attrLabel;
}

@property(retain, nonatomic) QNAttributedLabel *attrLabel; // @synthesize attrLabel=_attrLabel;
@property(retain, nonatomic) UIImageView *footerImageView; // @synthesize footerImageView=_footerImageView;
@property(retain, nonatomic) UIImageView *headerImageView; // @synthesize headerImageView=_headerImageView;
@property(retain, nonatomic) UIView *containerBgView; // @synthesize containerBgView=_containerBgView;
- (void).cxx_destruct;
- (void)layoutWithViewModel:(id)arg1 context:(id)arg2;
- (id)initWithStyle:(long long)arg1 reuseIdentifier:(id)arg2;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end
