//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QSStatedData.h"

@class NSString, QSPlayerRanklistModel;

@interface QSPlayerRanklistData : QSStatedData
{
    NSString *_tabType;
    NSString *_columnId;
}

@property(copy, nonatomic) NSString *columnId; // @synthesize columnId=_columnId;
@property(copy, nonatomic) NSString *tabType; // @synthesize tabType=_tabType;
- (void).cxx_destruct;
- (void)resetWithResponseModel:(id)arg1;
- (id)httpURLComponents;
@property(readonly, nonatomic) QSPlayerRanklistModel *model;
- (id)identifier;

@end

