//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNBundleThemeImageResource.h"

#import "QNBundleResourcePrefetchable.h"

@class NSString;

@interface _QNBundlePDFThemeImageResource : QNBundleThemeImageResource <QNBundleResourcePrefetchable>
{
}

- (id)nightImageWithDPScale:(double)arg1 adaptType:(long long)arg2;
- (id)dayImageWithDPScale:(double)arg1 adaptType:(long long)arg2;
- (id)nightImageWithDPScale:(double)arg1;
- (id)dayImageWithDPScale:(double)arg1;
- (id)nightImage_I6;
- (id)dayImage_I6;
- (id)image_I6;
- (id)imageWithDPScale:(double)arg1;
- (void)prefetch;
- (id)nightImage;
- (id)dayImage;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end
