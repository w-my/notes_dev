//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QSModel.h"

@class NSString, QSMatchDetailBasketballPlayerItem;

@interface QSMatchDetailBasketballMaxPlayerDataItem : QSModel
{
    NSString *_leftVal;
    NSString *_rightVal;
    QSMatchDetailBasketballPlayerItem *_leftPlayer;
    QSMatchDetailBasketballPlayerItem *_rightPlayer;
    NSString *_text;
}

@property(copy, nonatomic) NSString *text; // @synthesize text=_text;
@property(retain, nonatomic) QSMatchDetailBasketballPlayerItem *rightPlayer; // @synthesize rightPlayer=_rightPlayer;
@property(retain, nonatomic) QSMatchDetailBasketballPlayerItem *leftPlayer; // @synthesize leftPlayer=_leftPlayer;
@property(copy, nonatomic) NSString *rightVal; // @synthesize rightVal=_rightVal;
@property(copy, nonatomic) NSString *leftVal; // @synthesize leftVal=_leftVal;
- (void).cxx_destruct;

@end

