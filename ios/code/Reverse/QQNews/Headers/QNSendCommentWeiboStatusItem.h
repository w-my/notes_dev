//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class NSString, QNEditorWeiboModel;

@interface QNSendCommentWeiboStatusItem : NSObject
{
    long long _commentStatus;
    long long _weiboStatus;
    NSString *_commentRequestID;
    QNEditorWeiboModel *_weiboModel;
}

@property(retain, nonatomic) QNEditorWeiboModel *weiboModel; // @synthesize weiboModel=_weiboModel;
@property(copy, nonatomic) NSString *commentRequestID; // @synthesize commentRequestID=_commentRequestID;
@property(nonatomic) long long weiboStatus; // @synthesize weiboStatus=_weiboStatus;
@property(nonatomic) long long commentStatus; // @synthesize commentStatus=_commentStatus;
- (void).cxx_destruct;
- (_Bool)isValid;

@end
