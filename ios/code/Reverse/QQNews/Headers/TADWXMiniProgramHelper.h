//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@interface TADWXMiniProgramHelper : NSObject
{
    id <TCCWXSDKInjector> _wxInjector;
    id <TCCKVStoreInjector> _storeInjector;
}

+ (id)sharedInstance;
@property(nonatomic) __weak id <TCCKVStoreInjector> storeInjector; // @synthesize storeInjector=_storeInjector;
@property(nonatomic) __weak id <TCCWXSDKInjector> wxInjector; // @synthesize wxInjector=_wxInjector;
- (void).cxx_destruct;
- (void)openMiniProgram:(id)arg1 path:(id)arg2 inViewContorller:(id)arg3 completion:(CDUnknownBlockType)arg4;
- (_Bool)openMiniProgram:(id)arg1 path:(id)arg2;
- (_Bool)isAllowed;
- (id)init;

@end
