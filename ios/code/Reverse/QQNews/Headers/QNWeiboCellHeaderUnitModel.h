//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

#import "QNListUnitModelProtocol.h"

@class CSubscribeListItemNode, NSString, QNListNewsItem, QNUserItem, QNWeiboCellUserInfoUnitModel, UIColor;

@interface QNWeiboCellHeaderUnitModel : NSObject <QNListUnitModelProtocol>
{
    id <QNListModelProtocol> _data;
    UIColor *_bgColor;
    QNWeiboCellUserInfoUnitModel *_userInfoModel;
    CSubscribeListItemNode *_subNode;
    QNListNewsItem *_listItem;
    QNUserItem *_userItem;
    unsigned long long _accessoryViewType;
    struct CGRect _rect;
    struct CGRect _accessoryRect;
}

@property(readonly, nonatomic) struct CGRect accessoryRect; // @synthesize accessoryRect=_accessoryRect;
@property(readonly, nonatomic) unsigned long long accessoryViewType; // @synthesize accessoryViewType=_accessoryViewType;
@property(readonly, nonatomic) QNUserItem *userItem; // @synthesize userItem=_userItem;
@property(readonly, nonatomic) QNListNewsItem *listItem; // @synthesize listItem=_listItem;
@property(readonly, nonatomic) CSubscribeListItemNode *subNode; // @synthesize subNode=_subNode;
@property(readonly, nonatomic) QNWeiboCellUserInfoUnitModel *userInfoModel; // @synthesize userInfoModel=_userInfoModel;
@property(readonly, nonatomic) UIColor *bgColor; // @synthesize bgColor=_bgColor;
@property(readonly, nonatomic) struct CGRect rect; // @synthesize rect=_rect;
@property(readonly, nonatomic) id <QNListModelProtocol> data; // @synthesize data=_data;
- (void).cxx_destruct;
- (void)updateWithListItem:(id)arg1 context:(id)arg2;
- (void)calculateWithData:(id)arg1 referRect:(struct CGRect)arg2 context:(id)arg3;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

