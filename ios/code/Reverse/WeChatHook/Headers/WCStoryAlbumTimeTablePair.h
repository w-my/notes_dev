//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class NSString;

@interface WCStoryAlbumTimeTablePair : NSObject
{
    NSString *_showingStr;
    NSString *_timeStr;
}

+ (id)pairByUInt:(unsigned int)arg1;
+ (id)pairWithShowingStr:(id)arg1 timeStr:(id)arg2;
@property(readonly, copy, nonatomic) NSString *timeStr; // @synthesize timeStr=_timeStr;
@property(readonly, copy, nonatomic) NSString *showingStr; // @synthesize showingStr=_showingStr;
- (void).cxx_destruct;
- (id)initWithShowingStr:(id)arg1 timeStr:(id)arg2;

@end

