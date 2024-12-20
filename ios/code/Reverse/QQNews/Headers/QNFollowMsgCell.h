//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "UITableViewCell.h"

#import "QNListCellProtocol.h"

@class CALayer, NSString, QNListUserInfoUnit, QNSubscribeButton;

@interface QNFollowMsgCell : UITableViewCell <QNListCellProtocol>
{
    QNListUserInfoUnit *_userInfoUnit;
    CALayer *_separatorLine;
    QNSubscribeButton *_subButton;
}

@property(retain, nonatomic) QNSubscribeButton *subButton; // @synthesize subButton=_subButton;
@property(retain, nonatomic) CALayer *separatorLine; // @synthesize separatorLine=_separatorLine;
@property(retain, nonatomic) QNListUserInfoUnit *userInfoUnit; // @synthesize userInfoUnit=_userInfoUnit;
- (void).cxx_destruct;
- (void)setSelected:(_Bool)arg1 animated:(_Bool)arg2;
- (void)setHighlighted:(_Bool)arg1 animated:(_Bool)arg2;
- (void)p_applyDefaultSelectedBackgroundView;
- (void)layoutWithViewModel:(id)arg1 context:(id)arg2;
- (void)dealloc;
- (id)initWithStyle:(long long)arg1 reuseIdentifier:(id)arg2;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

