//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class NSString;

@interface NowLiveInitParam : NSObject
{
    unsigned int _roomId;
    int _openType;
    NSString *_listName;
    NSString *_from;
    NSString *_ext;
}

@property(copy, nonatomic) NSString *ext; // @synthesize ext=_ext;
@property(copy, nonatomic) NSString *from; // @synthesize from=_from;
@property(nonatomic) int openType; // @synthesize openType=_openType;
@property(copy, nonatomic) NSString *listName; // @synthesize listName=_listName;
@property(nonatomic) unsigned int roomId; // @synthesize roomId=_roomId;
- (void).cxx_destruct;

@end

