//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

#import "NSURLConnectionDataDelegate.h"

@class NSData, NSString;

@interface QQStarVideoUploadRequest : NSObject <NSURLConnectionDataDelegate>
{
    CDUnknownBlockType _complitionBlock;
    unsigned int _fileSize;
    unsigned int _chunkOffset;
    NSString *_url;
    NSString *_videoId;
    NSData *_checkKey;
    NSData *_sha1;
    NSData *_chunkData;
}

@property(retain, nonatomic) NSData *chunkData; // @synthesize chunkData=_chunkData;
@property(nonatomic) unsigned int chunkOffset; // @synthesize chunkOffset=_chunkOffset;
@property(nonatomic) unsigned int fileSize; // @synthesize fileSize=_fileSize;
@property(retain, nonatomic) NSData *sha1; // @synthesize sha1=_sha1;
@property(retain, nonatomic) NSData *checkKey; // @synthesize checkKey=_checkKey;
@property(retain, nonatomic) NSString *videoId; // @synthesize videoId=_videoId;
@property(readonly, nonatomic) NSString *url; // @synthesize url=_url;
- (void).cxx_destruct;
- (void)cancel;
- (id)buildBodyData;
- (_Bool)sendWithCompletion:(CDUnknownBlockType)arg1;
- (void)dealloc;
- (id)initWithURL:(id)arg1;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

