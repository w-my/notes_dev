//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNAbstractModelBuilder.h"

@interface QNTagItemBuilder : QNAbstractModelBuilder
{
}

+ (id)builderWithModelCopy:(id)arg1;
+ (id)builder;
+ (id)fromDictionary:(id)arg1;
- (id)setKk_tagType:(id)arg1;
- (id)kk_tagType;
- (id)setKk_tagId:(id)arg1;
- (id)kk_tagId;
- (id)setStockCode:(id)arg1;
- (id)stockCode;
- (id)setSubCount:(long long)arg1;
- (long long)subCount;
- (id)setTagIcon:(id)arg1;
- (id)tagIcon;
- (id)setTagId:(id)arg1;
- (id)tagId;
- (id)setTagName:(id)arg1;
- (id)tagName;
- (id)build;
- (id)do_createModelObject;
- (id)initWithModelCopy:(id)arg1;
- (id)init;
- (id)initWithDictionaryStub:(id)arg1;
- (void)do_customMapping:(id)arg1;

@end
