//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNAutoCodingCopyingObject.h"

@class NSArray, NSString;

@interface QNPictureListItemExtras : QNAutoCodingCopyingObject
{
    long long _localSupportState;
    NSString *_itemID;
    NSString *_likeBtnImageURLString;
    NSString *_likeBtnNightImageURLString;
    NSString *_likeWord;
    NSString *_hasLikedBtnImageURLString;
    NSString *_hasLikedBtnNightImageURLString;
    NSString *_hasLikedWord;
    NSString *_hasLikedUserImageURLString;
    NSString *_hasLikedUserNightImageURLString;
    NSString *_flagImageURLString;
    NSString *_flagImageNightURLString;
    long long _serverSupportNum;
    long long _serverHasSupported;
    NSArray *_commentUsers;
}

@property(readonly, nonatomic) NSArray *commentUsers; // @synthesize commentUsers=_commentUsers;
@property(readonly, nonatomic) long long serverHasSupported; // @synthesize serverHasSupported=_serverHasSupported;
@property(readonly, nonatomic) long long serverSupportNum; // @synthesize serverSupportNum=_serverSupportNum;
@property(readonly, copy, nonatomic) NSString *flagImageNightURLString; // @synthesize flagImageNightURLString=_flagImageNightURLString;
@property(readonly, copy, nonatomic) NSString *flagImageURLString; // @synthesize flagImageURLString=_flagImageURLString;
@property(readonly, copy, nonatomic) NSString *hasLikedUserNightImageURLString; // @synthesize hasLikedUserNightImageURLString=_hasLikedUserNightImageURLString;
@property(readonly, copy, nonatomic) NSString *hasLikedUserImageURLString; // @synthesize hasLikedUserImageURLString=_hasLikedUserImageURLString;
@property(readonly, copy, nonatomic) NSString *hasLikedWord; // @synthesize hasLikedWord=_hasLikedWord;
@property(readonly, copy, nonatomic) NSString *hasLikedBtnNightImageURLString; // @synthesize hasLikedBtnNightImageURLString=_hasLikedBtnNightImageURLString;
@property(readonly, copy, nonatomic) NSString *hasLikedBtnImageURLString; // @synthesize hasLikedBtnImageURLString=_hasLikedBtnImageURLString;
@property(readonly, copy, nonatomic) NSString *likeWord; // @synthesize likeWord=_likeWord;
@property(readonly, copy, nonatomic) NSString *likeBtnNightImageURLString; // @synthesize likeBtnNightImageURLString=_likeBtnNightImageURLString;
@property(readonly, copy, nonatomic) NSString *likeBtnImageURLString; // @synthesize likeBtnImageURLString=_likeBtnImageURLString;
@property(copy, nonatomic) NSString *itemID; // @synthesize itemID=_itemID;
- (void).cxx_destruct;
- (void)loadLocalSupportData;
- (_Bool)hasSupported;
- (id)hasLikedUserImageURL;
- (id)hasLikedBtnImageURL;
- (id)likeBtnImageURL;
- (void)saveToDB;
- (void)switchSupported;
- (void)markSupported;
- (long long)supportNum;
- (id)initWithInfo:(id)arg1;

@end
