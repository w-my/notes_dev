//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QSMatchLiveBasePropsMessageItem.h"

@class NSString, QSMatchLivePropsKickMessageButtonItem;

@interface QSMatchLiveKickPropsMessageItem : QSMatchLiveBasePropsMessageItem
{
    NSString *_kickUser;
    NSString *_kickUserid;
    NSString *_kickUserRank;
    NSString *_userIcon;
    NSString *_rankName;
    NSString *_targetCode;
    NSString *_rank;
    QSMatchLivePropsKickMessageButtonItem *_button;
}

@property(retain, nonatomic) QSMatchLivePropsKickMessageButtonItem *button; // @synthesize button=_button;
@property(copy, nonatomic) NSString *rank; // @synthesize rank=_rank;
@property(copy, nonatomic) NSString *targetCode; // @synthesize targetCode=_targetCode;
@property(copy, nonatomic) NSString *rankName; // @synthesize rankName=_rankName;
@property(copy, nonatomic) NSString *userIcon; // @synthesize userIcon=_userIcon;
@property(copy, nonatomic) NSString *kickUserRank; // @synthesize kickUserRank=_kickUserRank;
@property(copy, nonatomic) NSString *kickUserid; // @synthesize kickUserid=_kickUserid;
@property(copy, nonatomic) NSString *kickUser; // @synthesize kickUser=_kickUser;
- (void).cxx_destruct;

@end
