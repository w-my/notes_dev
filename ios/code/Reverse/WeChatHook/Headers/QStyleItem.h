//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@interface QStyleItem : NSObject
{
    long long _styleID;
    long long _index;
    long long _order;
}

@property(readonly, nonatomic) long long order; // @synthesize order=_order;
@property(readonly, nonatomic) long long index; // @synthesize index=_index;
@property(readonly, nonatomic) long long styleID; // @synthesize styleID=_styleID;
- (id)toJSON;
- (id)initWithJSON:(id)arg1;

@end

