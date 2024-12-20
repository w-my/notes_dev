//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@interface FBSDKCodelessIndexer : NSObject
{
}

+ (id)dimensionOf:(id)arg1;
+ (id)screenshot;
+ (id)recursiveCaptureTree:(id)arg1;
+ (id)currentViewTree;
+ (void)uploadIndexing:(id)arg1;
+ (void)uploadIndexing;
+ (void)startIndexing;
+ (id)extInfo;
+ (id)currentSessionDeviceID;
+ (void)checkCodelessIndexingSession;
+ (void)setupGesture;
+ (_Bool)_codelessSetupTimestampIsValid:(id)arg1;
+ (id)requestToLoadCodelessSetup:(id)arg1;
+ (void)loadCodelessSettingWithCompletionBlock:(CDUnknownBlockType)arg1;
+ (void)enable;

@end

