//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class GRMustacheFilteredExpression, GRMustacheIdentifierExpression, GRMustacheImplicitIteratorExpression, GRMustacheScopedExpression;

@protocol GRMustacheExpressionVisitor <NSObject>
- (_Bool)visitScopedExpression:(GRMustacheScopedExpression *)arg1 error:(id *)arg2;
- (_Bool)visitImplicitIteratorExpression:(GRMustacheImplicitIteratorExpression *)arg1 error:(id *)arg2;
- (_Bool)visitIdentifierExpression:(GRMustacheIdentifierExpression *)arg1 error:(id *)arg2;
- (_Bool)visitFilteredExpression:(GRMustacheFilteredExpression *)arg1 error:(id *)arg2;
@end
