//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

#import "GRMustacheRendering.h"

@class GRMustacheContext, GRMustacheTemplateAST, GRMustacheTemplateRepository, NSString;

@interface GRMustacheTemplate : NSObject <GRMustacheRendering>
{
    GRMustacheTemplateRepository *_templateRepository;
    GRMustacheTemplateAST *_templateAST;
    GRMustacheContext *_baseContext;
}

+ (id)renderObject:(id)arg1 fromResource:(id)arg2 bundle:(id)arg3 error:(id *)arg4;
+ (id)renderObject:(id)arg1 fromString:(id)arg2 error:(id *)arg3;
+ (id)templateFromContentsOfURL:(id)arg1 error:(id *)arg2;
+ (id)templateFromContentsOfFile:(id)arg1 error:(id *)arg2;
+ (id)templateFromResource:(id)arg1 bundle:(id)arg2 error:(id *)arg3;
+ (id)templateFromString:(id)arg1 error:(id *)arg2;
@property(retain, nonatomic) GRMustacheContext *baseContext; // @synthesize baseContext=_baseContext;
@property(retain, nonatomic) GRMustacheTemplateAST *templateAST; // @synthesize templateAST=_templateAST;
@property(retain, nonatomic) GRMustacheTemplateRepository *templateRepository; // @synthesize templateRepository=_templateRepository;
- (id)renderForMustacheTag:(id)arg1 context:(id)arg2 HTMLSafe:(_Bool *)arg3 error:(id *)arg4;
- (id)renderContentWithContext:(id)arg1 HTMLSafe:(_Bool *)arg2 error:(id *)arg3;
- (id)renderObjectsFromArray:(id)arg1 error:(id *)arg2;
- (id)renderObject:(id)arg1 error:(id *)arg2;
- (void)extendBaseContextWithTagDelegate:(id)arg1;
- (void)extendBaseContextWithProtectedObject:(id)arg1;
- (void)extendBaseContextWithObject:(id)arg1;
- (void)dealloc;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly, nonatomic) _Bool mustacheBoolValue;
@property(readonly) Class superclass;

@end
