//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class NSMutableArray;

@interface EJFileSystem : NSObject
{
    id <EJFileSystemDelegate> delegate;
    NSMutableArray *_noretainObejcts;
}

@property(nonatomic) __weak id <EJFileSystemDelegate> delegate; // @synthesize delegate;
- (void).cxx_destruct;
- (void)enterForeground;
- (void)addBackground:(id)arg1;
- (id)getFileData:(id)arg1;
- (_Bool)isFileExist:(id)arg1;
- (void)dealloc;

@end

