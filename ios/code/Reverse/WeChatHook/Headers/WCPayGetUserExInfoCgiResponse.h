//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class NSArray;

@interface WCPayGetUserExInfoCgiResponse : NSObject
{
    _Bool _needArea;
    _Bool _needProfession;
    _Bool _needNationality;
    NSArray *_professions;
    NSArray *_nationalityExcludeArray;
}

@property(retain, nonatomic) NSArray *nationalityExcludeArray; // @synthesize nationalityExcludeArray=_nationalityExcludeArray;
@property(nonatomic) _Bool needNationality; // @synthesize needNationality=_needNationality;
@property(retain, nonatomic) NSArray *professions; // @synthesize professions=_professions;
@property(nonatomic) _Bool needProfession; // @synthesize needProfession=_needProfession;
@property(nonatomic) _Bool needArea; // @synthesize needArea=_needArea;
- (void).cxx_destruct;

@end

