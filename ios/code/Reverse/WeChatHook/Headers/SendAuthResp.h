//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "BaseResp.h"

@class NSString;

@interface SendAuthResp : BaseResp
{
    NSString *code;
    NSString *state;
    NSString *lang;
    NSString *country;
}

@property(copy, nonatomic) NSString *country; // @synthesize country;
@property(copy, nonatomic) NSString *lang; // @synthesize lang;
@property(copy, nonatomic) NSString *state; // @synthesize state;
@property(copy, nonatomic) NSString *code; // @synthesize code;
- (void).cxx_destruct;
- (void)dealloc;
- (id)init;

@end

