//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QSModel.h"

@class NSArray, NSDictionary, QSComCircleExtraInfoItem, QSComCircleItem, QSComCircleTopRankInfo, QSComShareModel;

@interface QSComCircleDetailItem : QSModel
{
    QSComCircleItem *_module;
    QSComCircleExtraInfoItem *_info;
    QSComCircleTopRankInfo *_rank;
    QSComShareModel *_h5Share;
    NSArray *_top;
    NSArray *_bulletin;
    NSArray *_pk;
    NSDictionary *_jumpData;
}

+ (id)classNameForObjectInArrayProperty:(id)arg1;
@property(retain, nonatomic) NSDictionary *jumpData; // @synthesize jumpData=_jumpData;
@property(retain, nonatomic) NSArray *pk; // @synthesize pk=_pk;
@property(retain, nonatomic) NSArray *bulletin; // @synthesize bulletin=_bulletin;
@property(retain, nonatomic) NSArray *top; // @synthesize top=_top;
@property(retain, nonatomic) QSComShareModel *h5Share; // @synthesize h5Share=_h5Share;
@property(retain, nonatomic) QSComCircleTopRankInfo *rank; // @synthesize rank=_rank;
@property(retain, nonatomic) QSComCircleExtraInfoItem *info; // @synthesize info=_info;
@property(retain, nonatomic) QSComCircleItem *module; // @synthesize module=_module;
- (void).cxx_destruct;

@end

