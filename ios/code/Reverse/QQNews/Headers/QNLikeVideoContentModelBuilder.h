//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNAbstractModelBuilder.h"

@interface QNLikeVideoContentModelBuilder : QNAbstractModelBuilder
{
}

+ (id)builderWithModelCopy:(id)arg1;
+ (id)builder;
+ (id)fromDictionary:(id)arg1;
- (id)setNewsItems:(id)arg1;
- (id)newsItems;
- (id)setTotalCount:(unsigned long long)arg1;
- (unsigned long long)totalCount;
- (id)setChannelID:(id)arg1;
- (id)channelID;
- (id)setEmptyJumpScheme:(id)arg1;
- (id)emptyJumpScheme;
- (id)setHasMore:(_Bool)arg1;
- (_Bool)hasMore;
- (id)build;
- (id)do_createModelObject;
- (id)initWithModelCopy:(id)arg1;
- (id)init;
- (void)do_customMapping:(id)arg1;

@end
