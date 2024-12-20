//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "MMObject.h"

@class NSString;

@interface ScanCodeHistoryItem : MMObject
{
    _Bool _isFromAlbum;
    int _fromScene;
    int _version;
    int _networkType;
    NSString *_codeUrl;
    NSString *_timeString;
    NSString *_type;
}

@property(nonatomic) int networkType; // @synthesize networkType=_networkType;
@property(nonatomic) _Bool isFromAlbum; // @synthesize isFromAlbum=_isFromAlbum;
@property(nonatomic) int version; // @synthesize version=_version;
@property(copy, nonatomic) NSString *type; // @synthesize type=_type;
@property(nonatomic) int fromScene; // @synthesize fromScene=_fromScene;
@property(copy, nonatomic) NSString *timeString; // @synthesize timeString=_timeString;
@property(copy, nonatomic) NSString *codeUrl; // @synthesize codeUrl=_codeUrl;
- (void).cxx_destruct;
- (id)toXML;
- (_Bool)fromXML:(struct XmlReaderNode_t *)arg1;
- (id)copyWithZone:(struct _NSZone *)arg1;

@end

