//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNSearchItemBase.h"

@class NSString, QNListNewsItem;

@interface QNSearchNewsResultItem : QNSearchItemBase
{
    QNListNewsItem *_basicInfo;
    NSString *_videoPlayCount;
    long long _inType;
}

@property(nonatomic) long long inType; // @synthesize inType=_inType;
@property(copy, nonatomic) NSString *videoPlayCount; // @synthesize videoPlayCount=_videoPlayCount;
@property(copy, nonatomic) QNListNewsItem *basicInfo; // @synthesize basicInfo=_basicInfo;
- (void).cxx_destruct;
- (Class)p_searchResultCellClass;
- (_Bool)shouldShowAnswerType;
- (_Bool)shouldShowQuestionType;
- (_Bool)shouldShowBigImageType;
- (_Bool)shouldShowThreeImagesType;
- (id)getID;
- (id)initWithDictionary:(id)arg1;
- (id)createCellWithIdentifier:(id)arg1;
- (double)calculateCellHeightWithKeyWords:(id)arg1;

@end

