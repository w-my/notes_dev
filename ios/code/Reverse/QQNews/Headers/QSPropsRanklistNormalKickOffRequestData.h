//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QSPropsRanklistKickOffRequestData.h"

@class NSString;

@interface QSPropsRanklistNormalKickOffRequestData : QSPropsRanklistKickOffRequestData
{
    NSString *_toPoints;
}

@property(copy, nonatomic) NSString *toPoints; // @synthesize toPoints=_toPoints;
- (void).cxx_destruct;
- (void)resetWithResponseModel:(id)arg1;
- (id)httpURLComponents;

@end
