//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QSModel.h"

@class NSString, QSComCircleDetailItemBindParams;

@interface QSComCircleItem : QSModel
{
    _Bool _followed;
    NSString *_cid;
    NSString *_name;
    NSString *_icon;
    NSString *_headerImg;
    long long _followCount;
    long long _topicCount;
    NSString *_desc;
    NSString *_group;
    NSString *_groupdId;
    NSString *_leaderTitle;
    QSComCircleDetailItemBindParams *_bindParams;
}

+ (id)propertyNameFromParsedKey:(id)arg1;
@property(retain, nonatomic) QSComCircleDetailItemBindParams *bindParams; // @synthesize bindParams=_bindParams;
@property(nonatomic) _Bool followed; // @synthesize followed=_followed;
@property(copy, nonatomic) NSString *leaderTitle; // @synthesize leaderTitle=_leaderTitle;
@property(copy, nonatomic) NSString *groupdId; // @synthesize groupdId=_groupdId;
@property(copy, nonatomic) NSString *group; // @synthesize group=_group;
@property(copy, nonatomic) NSString *desc; // @synthesize desc=_desc;
@property(nonatomic) long long topicCount; // @synthesize topicCount=_topicCount;
@property(nonatomic) long long followCount; // @synthesize followCount=_followCount;
@property(copy, nonatomic) NSString *headerImg; // @synthesize headerImg=_headerImg;
@property(copy, nonatomic) NSString *icon; // @synthesize icon=_icon;
@property(copy, nonatomic) NSString *name; // @synthesize name=_name;
@property(copy, nonatomic) NSString *cid; // @synthesize cid=_cid;
- (void).cxx_destruct;
- (void)HTTPRequestJoin:(_Bool)arg1 circle:(id)arg2 with:(CDUnknownBlockType)arg3;
- (void)quitCircleResult:(id)arg1 withID:(id)arg2;
- (void)quitCircle;
- (void)joinCircleResult:(id)arg1 withID:(id)arg2;
- (void)joinCircleRequest;
- (void)joinCircle;

@end

