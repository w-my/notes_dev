//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class NSError, NSString;

@interface MPPageResourceDownloadCompletionParam : NSObject
{
    _Bool _isPatch;
    _Bool _hasPatchMD5;
    unsigned int _downloadedSize;
    NSString *_filePath;
    NSError *_error;
}

@property(retain, nonatomic) NSError *error; // @synthesize error=_error;
@property(nonatomic) unsigned int downloadedSize; // @synthesize downloadedSize=_downloadedSize;
@property(retain, nonatomic) NSString *filePath; // @synthesize filePath=_filePath;
@property(nonatomic) _Bool hasPatchMD5; // @synthesize hasPatchMD5=_hasPatchMD5;
@property(nonatomic) _Bool isPatch; // @synthesize isPatch=_isPatch;
- (void).cxx_destruct;

@end
