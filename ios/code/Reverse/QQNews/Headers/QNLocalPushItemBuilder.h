//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNAbstractModelBuilder.h"

@interface QNLocalPushItemBuilder : QNAbstractModelBuilder
{
}

+ (id)builderWithModelCopy:(id)arg1;
+ (id)builder;
+ (id)fromDictionary:(id)arg1;
- (id)setIsImageDownLoaded:(_Bool)arg1;
- (_Bool)isImageDownLoaded;
- (id)setRedPacketItem:(id)arg1;
- (id)redPacketItem;
- (id)setListItem:(id)arg1;
- (id)listItem;
- (id)setOpenTime:(double)arg1;
- (double)openTime;
- (id)setType:(long long)arg1;
- (long long)type;
- (id)setIdStr:(id)arg1;
- (id)idStr;
- (id)build;
- (id)do_createModelObject;
- (id)initWithModelCopy:(id)arg1;
- (id)init;
- (id)initWithDictionaryStub:(id)arg1;
- (void)do_customMapping:(id)arg1;

@end

