//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSFileManager.h"

@interface NSFileManager (CheckCreateDir)
+ (void)removeFileInDirectory:(id)arg1 shouldBeRemoved:(CDUnknownBlockType)arg2;
+ (id)documentPath;
- (_Bool)createParentFolder:(id)arg1 error:(id *)arg2;
- (_Bool)createFileIfNoexist:(id)arg1 shouldBeDir:(_Bool)arg2 error:(id *)arg3;
- (_Bool)createFile:(id)arg1 isDir:(_Bool)arg2 error:(id *)arg3;
@end
