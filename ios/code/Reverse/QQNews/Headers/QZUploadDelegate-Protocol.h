//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class NSDictionary, NSError, NSString;

@protocol QZUploadDelegate <NSObject>

@optional
- (void)qzUploadChanceToModify:(long long)arg1 taskDetail:(NSDictionary *)arg2;
- (void)qzUpload:(long long)arg1 taskDetail:(NSDictionary *)arg2 syncAlbumeName:(NSString *)arg3;
- (void)qzUpload:(long long)arg1 taskDetail:(NSDictionary *)arg2 syncSrvTime:(long long)arg3;
- (void)qzUploadBegin:(long long)arg1 taskDetail:(NSDictionary *)arg2;
- (void)qzUploadCancel:(long long)arg1 taskDetail:(NSDictionary *)arg2;
- (void)qzUploadFinish:(long long)arg1 taskDetail:(NSDictionary *)arg2;
- (void)qzUpload:(long long)arg1 taskDetail:(NSDictionary *)arg2 Status:(int)arg3;
- (void)qzUpload:(long long)arg1 taskDetail:(NSDictionary *)arg2 fail:(NSError *)arg3;
- (void)qzUpload:(long long)arg1 taskDetail:(NSDictionary *)arg2 sucess:(id)arg3;
- (void)qzUpload:(long long)arg1 taskDetail:(NSDictionary *)arg2 recv:(long long)arg3 total:(long long)arg4;
@end

