//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class NSString;

@interface QNButtonCallbackItem : NSObject
{
    unsigned long long _controlEvents;
    CDUnknownBlockType _callback;
    NSString *_token;
}

@property(copy, nonatomic) NSString *token; // @synthesize token=_token;
@property(copy, nonatomic) CDUnknownBlockType callback; // @synthesize callback=_callback;
@property(nonatomic) unsigned long long controlEvents; // @synthesize controlEvents=_controlEvents;
- (void).cxx_destruct;
- (void)performCallback:(id)arg1;

@end
