//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "MMObject.h"

#import "NSCopying.h"

@class RTETextView;

@interface RTEContentSection : MMObject <NSCopying>
{
    unsigned long long _length;
    double _cellHeight;
    RTETextView *_cellView;
    unsigned long long _numOfParagraph;
}

+ (id)creatSectionArrayForString:(id)arg1;
+ (id)creatSectionForString:(id)arg1;
@property(nonatomic) unsigned long long numOfParagraph; // @synthesize numOfParagraph=_numOfParagraph;
@property(retain, nonatomic) RTETextView *cellView; // @synthesize cellView=_cellView;
@property(nonatomic) double cellHeight; // @synthesize cellHeight=_cellHeight;
@property(nonatomic) unsigned long long length; // @synthesize length=_length;
- (void).cxx_destruct;
- (void)clearCacheView;
- (_Bool)tryMergeSection:(id)arg1;
- (id)copyWithZone:(struct _NSZone *)arg1;
- (id)init;

@end

