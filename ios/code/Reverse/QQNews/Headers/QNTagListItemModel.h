//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNListModel.h"

@class NSString, QNTagItem;

@interface QNTagListItemModel : QNListModel
{
    NSString *_channelID;
    QNTagItem *_tagItem;
}

@property(readonly, nonatomic) QNTagItem *tagItem; // @synthesize tagItem=_tagItem;
@property(readonly, copy, nonatomic) NSString *channelID; // @synthesize channelID=_channelID;
- (void).cxx_destruct;
- (id)getIndexFromListItems;
- (id)listDataFilePath;
- (id)initWithChannelID:(id)arg1 tagItem:(id)arg2;

@end

