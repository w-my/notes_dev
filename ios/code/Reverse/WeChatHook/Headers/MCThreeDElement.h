//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "MCTriggerElement.h"

@class NSArray, NSDictionary, NSMutableArray, NSString;

@interface MCThreeDElement : MCTriggerElement
{
    NSString *_itemName;
    NSString *_elementID;
    NSString *_folderPath;
    NSString *_modelName;
    NSDictionary *_material;
    NSArray *_nodesList;
    long long _diffPointID;
    NSMutableArray *_serials;
    struct SCNVector3 _scale;
    struct SCNVector3 _position;
    struct SCNVector3 _eulerAngles;
    struct SCNVector3 _diffScale;
    struct SCNVector3 _diffVector;
}

@property(retain, nonatomic) NSMutableArray *serials; // @synthesize serials=_serials;
@property(nonatomic) long long diffPointID; // @synthesize diffPointID=_diffPointID;
@property(nonatomic) struct SCNVector3 diffVector; // @synthesize diffVector=_diffVector;
@property(nonatomic) struct SCNVector3 diffScale; // @synthesize diffScale=_diffScale;
@property(retain, nonatomic) NSArray *nodesList; // @synthesize nodesList=_nodesList;
@property(retain, nonatomic) NSDictionary *material; // @synthesize material=_material;
@property(nonatomic) struct SCNVector3 eulerAngles; // @synthesize eulerAngles=_eulerAngles;
@property(nonatomic) struct SCNVector3 position; // @synthesize position=_position;
@property(nonatomic) struct SCNVector3 scale; // @synthesize scale=_scale;
@property(copy, nonatomic) NSString *modelName; // @synthesize modelName=_modelName;
@property(copy, nonatomic) NSString *folderPath; // @synthesize folderPath=_folderPath;
@property(copy, nonatomic) NSString *elementID; // @synthesize elementID=_elementID;
@property(copy, nonatomic) NSString *itemName; // @synthesize itemName=_itemName;
- (void).cxx_destruct;
- (void)resetPlayedTimes;
- (void)advanceTime;
- (void)setVector4:(struct SCNVector4 *)arg1 fromArray:(id)arg2;
- (void)setVector3:(struct SCNVector3 *)arg1 fromArray:(id)arg2;
- (id)description;
- (id)debugDescription;
- (id)initWithDictionary:(id)arg1 item:(id)arg2;

@end

