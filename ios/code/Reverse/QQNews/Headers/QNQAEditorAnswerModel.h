//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNBaseModelObject.h"

#import "NSCoding.h"
#import "NSCopying.h"

@class NSArray, NSString;

@interface QNQAEditorAnswerModel : QNBaseModelObject <NSCopying, NSCoding>
{
    NSString *_userId;
    NSString *_questionId;
    NSString *_requestId;
    NSString *_commentId;
    NSString *_currentReplyId;
    NSString *_htmlContent;
    NSArray *_imageModels;
}

+ (id)build:(CDUnknownBlockType)arg1;
+ (_Bool)isImmutable;
@property(copy, nonatomic) NSArray *imageModels; // @synthesize imageModels=_imageModels;
@property(copy, nonatomic) NSString *htmlContent; // @synthesize htmlContent=_htmlContent;
@property(copy, nonatomic) NSString *currentReplyId; // @synthesize currentReplyId=_currentReplyId;
@property(copy, nonatomic) NSString *commentId; // @synthesize commentId=_commentId;
@property(copy, nonatomic) NSString *requestId; // @synthesize requestId=_requestId;
@property(copy, nonatomic) NSString *questionId; // @synthesize questionId=_questionId;
@property(copy, nonatomic) NSString *userId; // @synthesize userId=_userId;
- (void).cxx_destruct;
- (id)copyInstance;
- (id)copyWithZone:(struct _NSZone *)arg1;
- (void)encodeWithCoder:(id)arg1;
- (id)initWithCoder:(id)arg1;
- (id)init;
- (_Bool)hasUploadAllImages;

@end
