//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "WAReportBaseItem.h"

@class NSString;

@interface WAReportWebViewPVItem : WAReportBaseItem
{
    unsigned int _publicLibVersion;
    unsigned long long _costtime;
    unsigned long long _staytime;
    NSString *_referpagepath;
    unsigned long long _targetAction;
    NSString *_targetpagepath;
    unsigned long long _clickTimestamp;
    NSString *_referAction;
}

@property(copy, nonatomic) NSString *referAction; // @synthesize referAction=_referAction;
@property(nonatomic) unsigned int publicLibVersion; // @synthesize publicLibVersion=_publicLibVersion;
@property(nonatomic) unsigned long long clickTimestamp; // @synthesize clickTimestamp=_clickTimestamp;
@property(copy, nonatomic) NSString *targetpagepath; // @synthesize targetpagepath=_targetpagepath;
@property(nonatomic) unsigned long long targetAction; // @synthesize targetAction=_targetAction;
@property(copy, nonatomic) NSString *referpagepath; // @synthesize referpagepath=_referpagepath;
@property(nonatomic) unsigned long long staytime; // @synthesize staytime=_staytime;
@property(nonatomic) unsigned long long costtime; // @synthesize costtime=_costtime;
- (void).cxx_destruct;
- (id)reportString;

@end

