//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNAbstractModelBuilder.h"

@interface QNTemplateContextBuilder : QNAbstractModelBuilder
{
}

+ (id)builderWithModelCopy:(id)arg1;
+ (id)builder;
+ (id)fromDictionary:(id)arg1;
- (id)setIsNoPicMode:(_Bool)arg1;
- (_Bool)isNoPicMode;
- (id)setIsQuoteMode:(_Bool)arg1;
- (_Bool)isQuoteMode;
- (id)setIsTimeLineMode:(_Bool)arg1;
- (_Bool)isTimeLineMode;
- (id)setIsTruthPlusMode:(_Bool)arg1;
- (_Bool)isTruthPlusMode;
- (id)setResourceBasePath:(id)arg1;
- (id)resourceBasePath;
- (id)setListItem:(id)arg1;
- (id)listItem;
- (id)setArticleContent:(id)arg1;
- (id)articleContent;
- (id)build;
- (id)do_createModelObject;
- (id)initWithModelCopy:(id)arg1;
- (id)init;
- (void)do_customMapping:(id)arg1;

@end
