//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class TADNewGameUnionInfoModel;

@interface TADQNNewGameUnionConfig : NSObject
{
    TADNewGameUnionInfoModel *_info;
}

+ (id)sharedInstance;
@property(retain, nonatomic) TADNewGameUnionInfoModel *info; // @synthesize info=_info;
- (void).cxx_destruct;
- (id)dataPath;
- (void)appWillResignActiveNotification:(id)arg1;
- (_Bool)hasValidGameUnionInfo;
- (_Bool)showRedDot;
- (void)requestGameConfig;
- (void)dealloc;
- (id)init;

@end

