//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class NSDictionary;

@interface QNSearchUtil : NSObject
{
    NSDictionary *_searchWordsAndQueryMapDic;
}

+ (id)sharedInstance;
@property(copy, nonatomic) NSDictionary *searchWordsAndQueryMapDic; // @synthesize searchWordsAndQueryMapDic=_searchWordsAndQueryMapDic;
- (void).cxx_destruct;
- (id)getSearchWordsByQuery:(id)arg1;
- (void)updateSearchWordsAndQueryMapDic:(id)arg1;
- (id)init;

@end
