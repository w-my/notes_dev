//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class TADGDTClickInfoApi;

@interface TADOpenSchemeHandler : NSObject
{
    _Bool _disableOpenScheme;
    TADGDTClickInfoApi *_clickInfoApi;
}

+ (id)sharedInstance;
@property(nonatomic) _Bool disableOpenScheme; // @synthesize disableOpenScheme=_disableOpenScheme;
@property(retain, nonatomic) TADGDTClickInfoApi *clickInfoApi; // @synthesize clickInfoApi=_clickInfoApi;
- (void).cxx_destruct;
- (void)jumpUrl:(id)arg1 adItem:(id)arg2;
- (void)openLandingViewWithAdItem:(id)arg1;
- (void)p_getClickInfoForAdItem:(id)arg1;
- (_Bool)openSchemeForAdItem:(id)arg1;

@end

