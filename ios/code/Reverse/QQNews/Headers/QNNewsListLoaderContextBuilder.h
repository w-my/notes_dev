//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNAbstractModelBuilder.h"

@interface QNNewsListLoaderContextBuilder : QNAbstractModelBuilder
{
}

+ (id)builderWithModelCopy:(id)arg1;
+ (id)builder;
- (id)setQueryKeyValues:(id)arg1;
- (id)queryKeyValues;
- (id)setPostKeyValues:(id)arg1;
- (id)postKeyValues;
- (id)setLoadOption:(long long)arg1;
- (long long)loadOption;
- (id)setForcePolicy:(_Bool)arg1;
- (_Bool)forcePolicy;
- (id)setLoadPolicy:(unsigned long long)arg1;
- (unsigned long long)loadPolicy;
- (id)setUrlString:(id)arg1;
- (id)urlString;
- (id)build;
- (id)do_createModelObject;
- (id)initWithModelCopy:(id)arg1;
- (id)init;

@end

