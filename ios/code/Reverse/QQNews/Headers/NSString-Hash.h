//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSString.h"

@interface NSString (Hash)
- (id)stringFromBytes:(char *)arg1 length:(int)arg2;
- (id)fileSHA512Hash;
- (id)fileSHA256Hash;
- (id)fileSHA1Hash;
- (id)fileMD5Hash;
- (id)hmacSHA512StringWithKey:(id)arg1;
- (id)hmacSHA256StringWithKey:(id)arg1;
- (id)hmacSHA1StringWithKey:(id)arg1;
- (id)hmacMD5StringWithKey:(id)arg1;
- (id)sha512String;
- (id)sha384String;
- (id)sha256String;
- (id)sha224String;
- (id)sha1String;
- (id)md5String;
@end

