//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "CArticleContentNodeType.h"

#import "NSCoding.h"

@class NSMutableArray;

@interface CArticleContentMusicNodeType : CArticleContentNodeType <NSCoding>
{
    NSMutableArray *_musicInfoArray;
}

@property(retain, nonatomic) NSMutableArray *musicInfoArray; // @synthesize musicInfoArray=_musicInfoArray;
- (void).cxx_destruct;
- (void)encodeWithCoder:(id)arg1;
- (id)initWithCoder:(id)arg1;
- (id)initWithInfo:(id)arg1;
- (id)init;

@end

