//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class CModelLoader;

@protocol CModelLoaderDelegate <NSObject>

@optional
- (void)modelDidFailed:(CModelLoader *)arg1;
- (void)modelDidFinish:(CModelLoader *)arg1;
- (void)modelDidStart:(CModelLoader *)arg1;
@end

