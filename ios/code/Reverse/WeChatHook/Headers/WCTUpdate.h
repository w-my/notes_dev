//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "WCTChainCall.h"

@class NSObject;

@interface WCTUpdate : WCTChainCall
{
    struct StatementUpdate _statement;
    SyntaxList_7f15fe8c _properties;
    unsigned long long _type;
    NSObject *_value;
}

- (id).cxx_construct;
- (void).cxx_destruct;
- (_Bool)execute;
- (id)toRow:(struct NSArray *)arg1;
- (id)toValue:(struct NSObject *)arg1;
- (id)toObject:(struct NSObject *)arg1;
- (id)offset:(const struct Expression *)arg1;
- (id)limit:(const struct Expression *)arg1;
- (id)orders:(const SyntaxList_64caf671 *)arg1;
- (id)where:(const struct Expression *)arg1;
- (id)set:(const SyntaxList_7f15fe8c *)arg1;
- (id)table:(id)arg1;
- (struct StatementUpdate *)statement;

@end

