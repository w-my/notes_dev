//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class QSRoundMapThirdRound, QSStructMatchNode;

@interface QSStructThirdMatchNode : NSObject
{
    QSStructMatchNode *_structMatchNode;
    QSRoundMapThirdRound *_thirdMatchInfo;
    struct CGRect _thirdIconFrame;
}

@property(retain, nonatomic) QSRoundMapThirdRound *thirdMatchInfo; // @synthesize thirdMatchInfo=_thirdMatchInfo;
@property(retain, nonatomic) QSStructMatchNode *structMatchNode; // @synthesize structMatchNode=_structMatchNode;
@property(nonatomic) struct CGRect thirdIconFrame; // @synthesize thirdIconFrame=_thirdIconFrame;
- (void).cxx_destruct;

@end
