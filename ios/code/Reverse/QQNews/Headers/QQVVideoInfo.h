//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class NSArray, NSString;

@interface QQVVideoInfo : NSObject
{
    NSString *_title;
    NSArray *_tags;
    NSString *_bid;
    NSString *_category;
    NSString *_subCategory;
}

@property(copy, nonatomic) NSString *subCategory; // @synthesize subCategory=_subCategory;
@property(copy, nonatomic) NSString *category; // @synthesize category=_category;
@property(retain, nonatomic) NSString *bid; // @synthesize bid=_bid;
@property(retain, nonatomic) NSArray *tags; // @synthesize tags=_tags;
@property(retain, nonatomic) NSString *title; // @synthesize title=_title;
- (void).cxx_destruct;
- (id)toDictionary;

@end
