//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNAbstractModelBuilder.h"

@interface KBVideoAuthorResponseModuleBuilder : QNAbstractModelBuilder
{
}

+ (id)builderWithModelCopy:(id)arg1;
+ (id)builder;
+ (id)fromDictionary:(id)arg1;
- (id)setIsFromHostTransView:(_Bool)arg1;
- (_Bool)isFromHostTransView;
- (id)setVideosCount:(long long)arg1;
- (long long)videosCount;
- (id)setQuin:(id)arg1;
- (id)quin;
- (id)setDesc:(id)arg1;
- (id)desc;
- (id)setAvatarUrl:(id)arg1;
- (id)avatarUrl;
- (id)setNickName:(id)arg1;
- (id)nickName;
- (id)build;
- (id)do_createModelObject;
- (id)initWithModelCopy:(id)arg1;
- (id)init;
- (id)initWithDictionaryStub:(id)arg1;
- (void)do_customMapping:(id)arg1;

@end

