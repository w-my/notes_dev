//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@interface ObjectWrapper : NSObject
{
    id <NSObject> _obj;
    Class _cls;
    unsigned long long _inQueueTime;
}

+ (id)genIDKeyForObject:(id)arg1;
@property(nonatomic) unsigned long long inQueueTime; // @synthesize inQueueTime=_inQueueTime;
@property(nonatomic) Class cls; // @synthesize cls=_cls;
@property(nonatomic) __weak id <NSObject> obj; // @synthesize obj=_obj;
- (void).cxx_destruct;

@end
