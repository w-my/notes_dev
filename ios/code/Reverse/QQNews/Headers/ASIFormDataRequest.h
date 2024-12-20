//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "ASIHTTPRequest.h"

#import "NSCopying.h"

@class NSMutableArray;

@interface ASIFormDataRequest : ASIHTTPRequest <NSCopying>
{
    NSMutableArray *postData;
    NSMutableArray *fileData;
    int postFormat;
    unsigned long long stringEncoding;
}

+ (id)requestWithURL:(id)arg1;
@property unsigned long long stringEncoding; // @synthesize stringEncoding;
@property int postFormat; // @synthesize postFormat;
@property(retain) NSMutableArray *fileData; // @synthesize fileData;
@property(retain) NSMutableArray *postData; // @synthesize postData;
- (id)copyWithZone:(struct _NSZone *)arg1;
- (void)appendPostString:(id)arg1;
- (void)buildURLEncodedPostBody;
- (void)buildMultipartFormDataPostBody;
- (void)buildPostBody;
- (void)setData:(id)arg1 withFileName:(id)arg2 andContentType:(id)arg3 forKey:(id)arg4;
- (void)setData:(id)arg1 forKey:(id)arg2;
- (void)addData:(id)arg1 withFileName:(id)arg2 andContentType:(id)arg3 forKey:(id)arg4;
- (void)addData:(id)arg1 forKey:(id)arg2;
- (void)setFile:(id)arg1 withFileName:(id)arg2 andContentType:(id)arg3 forKey:(id)arg4;
- (void)setFile:(id)arg1 forKey:(id)arg2;
- (void)addFile:(id)arg1 withFileName:(id)arg2 andContentType:(id)arg3 forKey:(id)arg4;
- (void)addFile:(id)arg1 forKey:(id)arg2;
- (void)setPostValue:(id)arg1 forKey:(id)arg2;
- (void)addPostValue:(id)arg1 forKey:(id)arg2;
- (void)dealloc;
- (id)initWithURL:(id)arg1;
- (id)encodeURL:(id)arg1;
- (void)qn_safeAddPostValue:(id)arg1 forKey:(id)arg2;
- (void)qn_safeAddPostParams:(id)arg1;
- (_Bool)qn_loginInfoIfExpired;
- (_Bool)qn_clearLoginInfoIfExpired;

@end

