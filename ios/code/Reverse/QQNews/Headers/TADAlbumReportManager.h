//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "TADBaseStreamReportManager.h"

@class TADAlbumAdAsyncLoader;

@interface TADAlbumReportManager : TADBaseStreamReportManager
{
    TADAlbumAdAsyncLoader *_albumLoader;
}

@property(retain, nonatomic) TADAlbumAdAsyncLoader *albumLoader; // @synthesize albumLoader=_albumLoader;
- (void).cxx_destruct;
- (void)requestAlbumAdsForAlbumId:(id)arg1 mediaId:(id)arg2 range:(struct _NSRange)arg3 source:(long long)arg4 completionBlock:(CDUnknownBlockType)arg5;

@end

