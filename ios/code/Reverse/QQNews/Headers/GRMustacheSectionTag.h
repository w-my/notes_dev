//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "GRMustacheTag.h"

@class GRMustacheExpression, GRMustacheTemplateAST, NSString;

@interface GRMustacheSectionTag : GRMustacheTag
{
    GRMustacheExpression *_expression;
    _Bool _inverted;
    NSString *_templateString;
    struct _NSRange _innerRange;
    GRMustacheTemplateAST *_templateAST;
}

+ (id)sectionTagWithExpression:(id)arg1 inverted:(_Bool)arg2 templateString:(id)arg3 innerRange:(struct _NSRange)arg4 templateAST:(id)arg5;
- (_Bool)isInverted;
@property(readonly, retain, nonatomic) GRMustacheTemplateAST *templateAST; // @synthesize templateAST=_templateAST;
@property(readonly, retain, nonatomic) GRMustacheExpression *expression; // @synthesize expression=_expression;
- (id)initWithExpression:(id)arg1 inverted:(_Bool)arg2 templateString:(id)arg3 innerRange:(struct _NSRange)arg4 templateAST:(id)arg5;
- (_Bool)acceptTemplateASTVisitor:(id)arg1 error:(id *)arg2;
- (id)renderContentWithContext:(id)arg1 HTMLSafe:(_Bool *)arg2 error:(id *)arg3;
- (unsigned long long)type;
- (id)innerTemplateString;
- (id)description;
- (void)dealloc;

@end
