//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QSModel.h"

@class NSString;

@interface QSHotMatchScheduleAttrESportsMatchItem : QSModel
{
    _Bool _isLive;
    _Bool _isOver;
    NSString *_leftName;
    NSString *_rightName;
    NSString *_leftScore;
    NSString *_rightScore;
}

+ (id)propertyNameFromParsedKey:(id)arg1;
@property(copy, nonatomic) NSString *rightScore; // @synthesize rightScore=_rightScore;
@property(copy, nonatomic) NSString *leftScore; // @synthesize leftScore=_leftScore;
@property(nonatomic) _Bool isOver; // @synthesize isOver=_isOver;
@property(nonatomic) _Bool isLive; // @synthesize isLive=_isLive;
@property(copy, nonatomic) NSString *rightName; // @synthesize rightName=_rightName;
@property(copy, nonatomic) NSString *leftName; // @synthesize leftName=_leftName;
- (void).cxx_destruct;

@end

