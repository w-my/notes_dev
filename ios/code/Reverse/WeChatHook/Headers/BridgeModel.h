//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@interface BridgeModel : NSObject
{
    long long _input;
    long long _output;
    long long _index;
}

+ (id)createNoneModel;
+ (id)parseDictionnary:(id)arg1;
@property(nonatomic) long long index; // @synthesize index=_index;
@property(nonatomic) long long output; // @synthesize output=_output;
@property(nonatomic) long long input; // @synthesize input=_input;
- (void)encodeWithCoder:(id)arg1;
- (id)initWithCoder:(id)arg1;
- (void)dealloc;
- (id)init;

@end

