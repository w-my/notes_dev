//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNAbstractModelBuilder.h"

@interface QNListWeiboItemBuilder : QNAbstractModelBuilder
{
}

+ (id)builderWithModelCopy:(id)arg1;
+ (id)builder;
+ (id)fromDictionary:(id)arg1;
- (id)setSelectedImages:(id)arg1;
- (id)selectedImages;
- (id)setVideoLocalUrl:(id)arg1;
- (id)videoLocalUrl;
- (id)setRequestId:(id)arg1;
- (id)requestId;
- (id)setInteraction:(_Bool)arg1;
- (_Bool)interaction;
- (id)setWeiboStatus:(long long)arg1;
- (long long)weiboStatus;
- (id)setLocationItem:(id)arg1;
- (id)locationItem;
- (id)build;
- (id)do_createModelObject;
- (id)initWithModelCopy:(id)arg1;
- (id)init;
- (id)initWithDictionaryStub:(id)arg1;
- (void)do_customMapping:(id)arg1;

@end

