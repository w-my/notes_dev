//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@interface TADLoginUserInfoHelper : NSObject
{
    id <TADLoginUserInfoDelegate> _delegate;
}

+ (id)shareInstance;
@property(nonatomic) __weak id <TADLoginUserInfoDelegate> delegate; // @synthesize delegate=_delegate;
- (void).cxx_destruct;
- (void)wantToShowNativeLoginWithType:(id)arg1 completion:(CDUnknownBlockType)arg2;
- (void)wantToGetUserLoginStatusWithcallback:(CDUnknownBlockType)arg1;
- (void)wantToShowLoginPanelWithCallback:(CDUnknownBlockType)arg1;

@end
