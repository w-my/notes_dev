//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@interface TTMicBaseDislocationItem : NSObject
{
    struct CGPoint _offset;
    struct CGRect _location;
}

+ (id)itemWithLoc:(struct CGRect)arg1 offset:(struct CGPoint)arg2;
@property(nonatomic) struct CGPoint offset; // @synthesize offset=_offset;
@property(nonatomic) struct CGRect location; // @synthesize location=_location;
- (id)description;

@end
