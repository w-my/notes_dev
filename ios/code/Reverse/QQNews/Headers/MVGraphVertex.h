//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class NSArray, NSMutableArray, NSString;

@interface MVGraphVertex : NSObject
{
    id _object;
    NSString *_key;
    long long _depth;
    long long _inoutType;
    NSMutableArray *_inEdges;
    NSMutableArray *_outEdges;
}

+ (id)vertexWithObject:(id)arg1;
+ (id)keyForObject:(id)arg1;
@property(retain, nonatomic) NSMutableArray *outEdges; // @synthesize outEdges=_outEdges;
@property(retain, nonatomic) NSMutableArray *inEdges; // @synthesize inEdges=_inEdges;
@property(nonatomic) long long inoutType; // @synthesize inoutType=_inoutType;
@property(nonatomic) long long depth; // @synthesize depth=_depth;
@property(retain, nonatomic) NSString *key; // @synthesize key=_key;
@property(retain, nonatomic) id object; // @synthesize object=_object;
- (void).cxx_destruct;
- (id)description;
- (void)recurseOutputsWithBlock:(CDUnknownBlockType)arg1;
- (void)recurseInputsWithBlock:(CDUnknownBlockType)arg1;
- (id)edgeWithVertex:(id)arg1;
@property(readonly, nonatomic) NSArray *objectsOfOutputs;
@property(readonly, nonatomic) NSArray *objectsOfInputs;
@property(readonly, nonatomic) NSArray *outputs;
@property(readonly, nonatomic) NSArray *inputs;
- (id)init;

@end
