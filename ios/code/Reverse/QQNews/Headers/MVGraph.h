//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class NSArray, NSMutableDictionary;

@interface MVGraph : NSObject
{
    NSMutableDictionary *_vertices;
}

+ (id)graphWithObjects:(id)arg1;
+ (id)graphWithObject:(id)arg1;
+ (id)graph;
@property(retain, nonatomic) NSMutableDictionary *vertices; // @synthesize vertices=_vertices;
- (void).cxx_destruct;
- (void)removeConnectionsOfVertex:(id)arg1;
- (id)removeConnectsBetweenVertex:(id)arg1 andVertex:(id)arg2;
- (void)copyConnectionsOfVertex:(id)arg1 forVertex:(id)arg2;
@property(readonly, nonatomic) NSArray *objectsOfDepthTraversalSequence;
@property(readonly, nonatomic) NSArray *depthTraversalSequence;
@property(readonly, nonatomic) NSArray *objectsOfTerminals;
@property(readonly, nonatomic) NSArray *terminals;
@property(readonly, nonatomic) NSArray *objectsOfOrigins;
@property(readonly, nonatomic) NSArray *origins;
@property(readonly, nonatomic) NSArray *allObjects;
@property(readonly, nonatomic) NSArray *allVertices;
- (id)vertexOfObject:(id)arg1;
- (void)mergeGraph:(id)arg1;
- (void)disconnectObject:(id)arg1 withObject:(id)arg2;
- (id)connectFromObject:(id)arg1 toObject:(id)arg2;
- (_Bool)containsObject:(id)arg1;
- (void)removeAllObjects;
- (void)removeObject:(id)arg1;
- (id)replaceObject:(id)arg1 withObject:(id)arg2;
- (id)addObject:(id)arg1;
- (id)init;

@end
