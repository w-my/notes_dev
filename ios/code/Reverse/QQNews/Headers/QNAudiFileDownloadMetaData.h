//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNAutoCodingCopyingObject.h"

@class NSString;

@interface QNAudiFileDownloadMetaData : QNAutoCodingCopyingObject
{
    NSString *_newsID;
    NSString *_urlString;
    NSString *_md5String;
}

@property(copy, nonatomic) NSString *md5String; // @synthesize md5String=_md5String;
@property(copy, nonatomic) NSString *urlString; // @synthesize urlString=_urlString;
@property(copy, nonatomic) NSString *newsID; // @synthesize newsID=_newsID;
- (void).cxx_destruct;
- (id)fileMD5;
- (id)fileName;
- (id)downloadPath;

@end

