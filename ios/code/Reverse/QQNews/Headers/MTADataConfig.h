//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class NSString;

@interface MTADataConfig : NSObject
{
    unsigned int _type;
    unsigned int _version;
    NSString *_content;
    NSString *_md5;
}

@property unsigned int version; // @synthesize version=_version;
@property(retain, nonatomic) NSString *md5; // @synthesize md5=_md5;
@property(retain, nonatomic) NSString *content; // @synthesize content=_content;
@property unsigned int type; // @synthesize type=_type;
- (void).cxx_destruct;
- (_Bool)decode:(id)arg1;
- (void)encodeWithNoContent:(id)arg1;

@end

