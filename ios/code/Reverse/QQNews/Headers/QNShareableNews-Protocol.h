//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNShareableText.h"

@class NSString, NSURL, UIImage;

@protocol QNShareableNews <QNShareableText>
- (NSURL *)thumbnailUrlForShare;
- (NSString *)descriptionForShare;
- (NSURL *)webpageUrlForShare;

@optional
- (NSString *)miniProgramPathForShare;
- (long long)newsShareStyle:(long long)arg1;
- (UIImage *)defaultThumbnailImageForShare;
@end
