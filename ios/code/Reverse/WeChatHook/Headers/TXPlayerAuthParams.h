//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class NSString;

@interface TXPlayerAuthParams : NSObject
{
    _Bool _https;
    int _appId;
    int _exper;
    NSString *_fileId;
    NSString *_timeout;
    NSString *_us;
    NSString *_sign;
}

@property _Bool https; // @synthesize https=_https;
@property(retain) NSString *sign; // @synthesize sign=_sign;
@property(retain) NSString *us; // @synthesize us=_us;
@property int exper; // @synthesize exper=_exper;
@property(retain) NSString *timeout; // @synthesize timeout=_timeout;
@property(retain) NSString *fileId; // @synthesize fileId=_fileId;
@property int appId; // @synthesize appId=_appId;
- (void).cxx_destruct;
- (id)init;

@end

