//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class TADGDTClickInfoApi;

@interface TADDownloadAdManager : NSObject
{
    _Bool _disableOpenAd;
    TADGDTClickInfoApi *_clickInfoApi;
}

+ (id)sharedInstance;
@property(retain, nonatomic) TADGDTClickInfoApi *clickInfoApi; // @synthesize clickInfoApi=_clickInfoApi;
@property(nonatomic) _Bool disableOpenAd; // @synthesize disableOpenAd=_disableOpenAd;
- (void).cxx_destruct;
- (void)showFailedAlert;
- (void)loadAppIdForAdItem:(id)arg1;

@end
