//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSArray.h"

@interface NSArray (BlocksKit)
- (_Bool)bk_corresponds:(id)arg1 withBlock:(CDUnknownBlockType)arg2;
- (_Bool)bk_all:(CDUnknownBlockType)arg1;
- (_Bool)bk_none:(CDUnknownBlockType)arg1;
- (_Bool)bk_any:(CDUnknownBlockType)arg1;
- (double)bk_reduceFloat:(double)arg1 withBlock:(CDUnknownBlockType)arg2;
- (long long)bk_reduceInteger:(long long)arg1 withBlock:(CDUnknownBlockType)arg2;
- (id)bk_reduce:(id)arg1 withBlock:(CDUnknownBlockType)arg2;
- (id)bk_flatMap:(CDUnknownBlockType)arg1;
- (id)bk_map:(CDUnknownBlockType)arg1;
- (id)bk_reject:(CDUnknownBlockType)arg1;
- (id)bk_select:(CDUnknownBlockType)arg1;
- (id)bk_match:(CDUnknownBlockType)arg1;
- (void)bk_apply:(CDUnknownBlockType)arg1;
- (void)bk_each:(CDUnknownBlockType)arg1;
@end

