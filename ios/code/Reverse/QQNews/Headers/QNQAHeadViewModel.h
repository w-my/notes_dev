//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNBaseViewModel.h"

@class NSMutableAttributedString, NSString, NSURL, QNComment, QNListNewsItem, QNUserItem, UIImage;

@interface QNQAHeadViewModel : QNBaseViewModel
{
    _Bool _descHiden;
    _Bool _foridEdit;
    _Bool _isSelf;
    _Bool _didAnswer;
    QNListNewsItem *_listItem;
    NSMutableAttributedString *_title;
    NSMutableAttributedString *_joinPeople;
    NSURL *_avarUrl;
    UIImage *_avarIcon;
    NSURL *_vipIconUrl;
    NSMutableAttributedString *_name;
    NSMutableAttributedString *_desc;
    long long _checkStatus;
    NSString *_mediaid;
    QNUserItem *_userItem;
    long long _allCommentsCount;
    NSMutableAttributedString *_timesStr;
    NSString *_uid;
    NSString *_openId;
    NSString *_coralUid;
    NSString *_coralUin;
    QNComment *_rootComment;
}

@property(retain, nonatomic) QNComment *rootComment; // @synthesize rootComment=_rootComment;
@property(copy, nonatomic) NSString *coralUin; // @synthesize coralUin=_coralUin;
@property(copy, nonatomic) NSString *coralUid; // @synthesize coralUid=_coralUid;
@property(copy, nonatomic) NSString *openId; // @synthesize openId=_openId;
@property(copy, nonatomic) NSString *uid; // @synthesize uid=_uid;
@property(retain, nonatomic) NSMutableAttributedString *timesStr; // @synthesize timesStr=_timesStr;
@property(nonatomic) long long allCommentsCount; // @synthesize allCommentsCount=_allCommentsCount;
@property(nonatomic) _Bool didAnswer; // @synthesize didAnswer=_didAnswer;
@property(nonatomic) _Bool isSelf; // @synthesize isSelf=_isSelf;
@property(retain, nonatomic) QNUserItem *userItem; // @synthesize userItem=_userItem;
@property(copy, nonatomic) NSString *mediaid; // @synthesize mediaid=_mediaid;
@property(nonatomic) _Bool foridEdit; // @synthesize foridEdit=_foridEdit;
@property(nonatomic) long long checkStatus; // @synthesize checkStatus=_checkStatus;
@property(nonatomic) _Bool descHiden; // @synthesize descHiden=_descHiden;
@property(retain, nonatomic) NSMutableAttributedString *desc; // @synthesize desc=_desc;
@property(retain, nonatomic) NSMutableAttributedString *name; // @synthesize name=_name;
@property(retain, nonatomic) NSURL *vipIconUrl; // @synthesize vipIconUrl=_vipIconUrl;
@property(retain, nonatomic) UIImage *avarIcon; // @synthesize avarIcon=_avarIcon;
@property(retain, nonatomic) NSURL *avarUrl; // @synthesize avarUrl=_avarUrl;
@property(retain, nonatomic) NSMutableAttributedString *joinPeople; // @synthesize joinPeople=_joinPeople;
@property(retain, nonatomic) NSMutableAttributedString *title; // @synthesize title=_title;
@property(retain, nonatomic) QNListNewsItem *listItem; // @synthesize listItem=_listItem;
- (void).cxx_destruct;
- (void)calculateWithData:(id)arg1 referRect:(struct CGRect)arg2;
- (id)init;

@end

