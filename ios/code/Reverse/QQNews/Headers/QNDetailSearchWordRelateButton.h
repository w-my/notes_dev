//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNThemableButton.h"

@class QNAvatarView, QNBaseLabel;

@interface QNDetailSearchWordRelateButton : QNThemableButton
{
    QNAvatarView *_avatarView;
    QNBaseLabel *_nameLabel;
    QNBaseLabel *_relationLabel;
}

@property(retain, nonatomic) QNBaseLabel *relationLabel; // @synthesize relationLabel=_relationLabel;
@property(retain, nonatomic) QNBaseLabel *nameLabel; // @synthesize nameLabel=_nameLabel;
@property(retain, nonatomic) QNAvatarView *avatarView; // @synthesize avatarView=_avatarView;
- (void).cxx_destruct;
- (id)p_flagIconWithSubNode:(id)arg1;
- (void)setSelected:(_Bool)arg1;
- (void)setHighlighted:(_Bool)arg1;
- (void)layoutWithRelatePerson:(id)arg1;
- (id)initWithFrame:(struct CGRect)arg1;

@end
