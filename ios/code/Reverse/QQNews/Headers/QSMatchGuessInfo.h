//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QSModel.h"

@class NSArray, NSDictionary, NSString, QSMatchDetailIconAd;

@interface QSMatchGuessInfo : QSModel
{
    _Bool _rankAble;
    _Bool _listAble;
    _Bool _matchActive;
    NSArray *_guessList;
    NSString *_updateFreq;
    NSDictionary *_rankJump;
    NSArray *_showList;
    NSDictionary *_kbActivity;
    NSArray *_notices;
    QSMatchDetailIconAd *_iconAd;
}

+ (id)classNameForObjectInArrayProperty:(id)arg1;
@property(retain, nonatomic) QSMatchDetailIconAd *iconAd; // @synthesize iconAd=_iconAd;
@property(retain, nonatomic) NSArray *notices; // @synthesize notices=_notices;
@property(retain, nonatomic) NSDictionary *kbActivity; // @synthesize kbActivity=_kbActivity;
@property(nonatomic) _Bool matchActive; // @synthesize matchActive=_matchActive;
@property(retain, nonatomic) NSArray *showList; // @synthesize showList=_showList;
@property(retain, nonatomic) NSDictionary *rankJump; // @synthesize rankJump=_rankJump;
@property(nonatomic) _Bool listAble; // @synthesize listAble=_listAble;
@property(nonatomic) _Bool rankAble; // @synthesize rankAble=_rankAble;
@property(retain, nonatomic) NSString *updateFreq; // @synthesize updateFreq=_updateFreq;
@property(retain, nonatomic) NSArray *guessList; // @synthesize guessList=_guessList;
- (void).cxx_destruct;

@end
