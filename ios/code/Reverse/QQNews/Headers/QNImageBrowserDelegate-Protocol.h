//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class QNImageBrowserItem, UIImage;

@protocol QNImageBrowserDelegate <NSObject>

@optional
- (void)imageBrowserDidScrollToImageItem:(QNImageBrowserItem *)arg1;
- (void)imageBrowserDidImageSuccessDownloaded:(QNImageBrowserItem *)arg1 image:(UIImage *)arg2;
- (struct CGRect)imageBrowserWillDismissAtImageItem:(QNImageBrowserItem *)arg1;
@end

