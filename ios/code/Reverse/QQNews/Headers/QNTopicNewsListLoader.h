//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNIndexListLoader.h"

#import "QNIndexListLoaderSubClassProtocol.h"

@class NSString;

@interface QNTopicNewsListLoader : QNIndexListLoader <QNIndexListLoaderSubClassProtocol>
{
}

- (id)configRemoteResponse:(id)arg1 direction:(unsigned long long)arg2;
- (void)p_configLoaderBlock;
- (id)initWithChannelID:(id)arg1 listDataManager:(id)arg2;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

