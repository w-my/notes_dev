//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class NSString;

@interface TSASchemeHandler : NSObject
{
    NSString *_params;
    NSString *_cidString;
    NSString *_vidString;
    NSString *_ckURLString;
    long long _errorTimes;
}

+ (_Bool)checkIsTADSchemeWith:(id)arg1;
@property(nonatomic) long long errorTimes; // @synthesize errorTimes=_errorTimes;
@property(copy, nonatomic) NSString *ckURLString; // @synthesize ckURLString=_ckURLString;
@property(copy, nonatomic) NSString *vidString; // @synthesize vidString=_vidString;
@property(copy, nonatomic) NSString *cidString; // @synthesize cidString=_cidString;
@property(copy, nonatomic) NSString *params; // @synthesize params=_params;
- (void).cxx_destruct;
- (id)_fixUrlWithUserData:(id)arg1;
- (void)dealloc;
- (void)connection:(id)arg1 didFailWithError:(id)arg2;
- (void)connectckURL;
- (void)handle;
- (id)initWithParams:(id)arg1;

@end

