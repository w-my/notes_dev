//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNAbstractModelBuilder.h"

@interface QNWikiItemBuilder : QNAbstractModelBuilder
{
}

+ (id)builderWithModelCopy:(id)arg1;
+ (id)builder;
+ (id)fromDictionary:(id)arg1;
- (id)setRelatePersonList:(id)arg1;
- (id)relatePersonList;
- (id)setIsFromDetailPage:(_Bool)arg1;
- (_Bool)isFromDetailPage;
- (id)setCalculatedHeight:(double)arg1;
- (double)calculatedHeight;
- (id)setTime:(double)arg1;
- (double)time;
- (id)setWikiWords:(id)arg1;
- (id)wikiWords;
- (id)setSource:(id)arg1;
- (id)source;
- (id)setDesc:(id)arg1;
- (id)desc;
- (id)setUrl:(id)arg1;
- (id)url;
- (id)setPicUrl:(id)arg1;
- (id)picUrl;
- (id)setTitle:(id)arg1;
- (id)title;
- (id)build;
- (id)do_createModelObject;
- (id)initWithModelCopy:(id)arg1;
- (id)init;
- (id)initWithDictionaryStub:(id)arg1;
- (void)do_customMapping:(id)arg1;

@end

