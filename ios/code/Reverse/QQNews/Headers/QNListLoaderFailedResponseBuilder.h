//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNAbstractModelBuilder.h"

@interface QNListLoaderFailedResponseBuilder : QNAbstractModelBuilder
{
}

+ (id)builderWithModelCopy:(id)arg1;
+ (id)builder;
+ (id)fromDictionary:(id)arg1;
- (id)setIsCacheData:(_Bool)arg1;
- (_Bool)isCacheData;
- (id)setDirection:(unsigned long long)arg1;
- (unsigned long long)direction;
- (id)setError:(id)arg1;
- (id)error;
- (id)build;
- (id)do_createModelObject;
- (id)initWithModelCopy:(id)arg1;
- (id)init;
- (void)do_customMapping:(id)arg1;

@end
