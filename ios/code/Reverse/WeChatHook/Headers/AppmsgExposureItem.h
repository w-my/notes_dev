//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class NSArray, NSString;

@interface AppmsgExposureItem : NSObject
{
    unsigned int _scene;
    unsigned int _createTime;
    unsigned int _currSessionID;
    NSString *_innerID;
    NSString *_chatName;
    NSArray *_urlInfoList;
    NSString *_sendUserName;
}

@property(nonatomic) unsigned int currSessionID; // @synthesize currSessionID=_currSessionID;
@property(nonatomic) unsigned int createTime; // @synthesize createTime=_createTime;
@property(retain, nonatomic) NSString *sendUserName; // @synthesize sendUserName=_sendUserName;
@property(retain, nonatomic) NSArray *urlInfoList; // @synthesize urlInfoList=_urlInfoList;
@property(retain, nonatomic) NSString *chatName; // @synthesize chatName=_chatName;
@property(retain, nonatomic) NSString *innerID; // @synthesize innerID=_innerID;
@property(nonatomic) unsigned int scene; // @synthesize scene=_scene;
- (void).cxx_destruct;

@end

