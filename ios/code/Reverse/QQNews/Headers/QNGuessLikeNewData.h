//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class NSArray;

@interface QNGuessLikeNewData : NSObject
{
    NSArray *_listItems;
    NSArray *_hotWordsData;
    long long _guessLikeJumpType;
    long long _type;
}

@property(nonatomic) long long type; // @synthesize type=_type;
@property(nonatomic) long long guessLikeJumpType; // @synthesize guessLikeJumpType=_guessLikeJumpType;
@property(copy, nonatomic) NSArray *hotWordsData; // @synthesize hotWordsData=_hotWordsData;
@property(copy, nonatomic) NSArray *listItems; // @synthesize listItems=_listItems;
- (void).cxx_destruct;
- (_Bool)isValid;

@end
