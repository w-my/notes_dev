//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "MMObject.h"

@class MPCommentReply, NSString;

@interface MPCommentMsg : MMObject
{
    _Bool _isLike;
    _Bool _isFromFriend;
    _Bool _isFromMe;
    _Bool _isTop;
    unsigned int _userCommentId;
    unsigned int _personalCommentId;
    unsigned int _createTime;
    unsigned int _likeCount;
    unsigned int _likeId;
    NSString *_url;
    unsigned long long _commentTopicId;
    NSString *_openId;
    NSString *_nickName;
    NSString *_headImageUrl;
    NSString *_content;
    MPCommentReply *_reply;
}

@property(retain, nonatomic) MPCommentReply *reply; // @synthesize reply=_reply;
@property(nonatomic) unsigned int likeId; // @synthesize likeId=_likeId;
@property(nonatomic) _Bool isTop; // @synthesize isTop=_isTop;
@property(nonatomic) _Bool isFromMe; // @synthesize isFromMe=_isFromMe;
@property(nonatomic) _Bool isFromFriend; // @synthesize isFromFriend=_isFromFriend;
@property(nonatomic) _Bool isLike; // @synthesize isLike=_isLike;
@property(nonatomic) unsigned int likeCount; // @synthesize likeCount=_likeCount;
@property(nonatomic) unsigned int createTime; // @synthesize createTime=_createTime;
@property(copy, nonatomic) NSString *content; // @synthesize content=_content;
@property(copy, nonatomic) NSString *headImageUrl; // @synthesize headImageUrl=_headImageUrl;
@property(copy, nonatomic) NSString *nickName; // @synthesize nickName=_nickName;
@property(copy, nonatomic) NSString *openId; // @synthesize openId=_openId;
@property(nonatomic) unsigned int personalCommentId; // @synthesize personalCommentId=_personalCommentId;
@property(nonatomic) unsigned int userCommentId; // @synthesize userCommentId=_userCommentId;
@property(nonatomic) unsigned long long commentTopicId; // @synthesize commentTopicId=_commentTopicId;
@property(copy, nonatomic) NSString *url; // @synthesize url=_url;
- (void).cxx_destruct;
- (id)description;

@end

