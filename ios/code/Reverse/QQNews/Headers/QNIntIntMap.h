//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@interface QNIntIntMap : NSObject
{
    struct unordered_map<long, long, std::__1::hash<long>, std::__1::equal_to<long>, std::__1::allocator<std::__1::pair<const long, long>>> _map;
}

+ (id)map;
- (id).cxx_construct;
- (void).cxx_destruct;
- (_Bool)containsIntKey:(long long)arg1;
- (unsigned long long)count;
- (long long)intValueForIntKey:(long long)arg1;
- (long long)removeIntValueForIntKey:(long long)arg1;
- (long long)setIntValue:(long long)arg1 forIntKey:(long long)arg2;
- (id)initWithInitialCapacity:(unsigned long long)arg1;
- (id)init;

@end
