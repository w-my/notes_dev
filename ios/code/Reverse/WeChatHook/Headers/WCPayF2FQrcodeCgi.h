//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "WCPayBaseCgi.h"

@interface WCPayF2FQrcodeCgi : WCPayBaseCgi
{
    id <WCPayF2FQrcodeCgiDelegate> _m_delegate;
}

@property(nonatomic) __weak id <WCPayF2FQrcodeCgiDelegate> m_delegate; // @synthesize m_delegate=_m_delegate;
- (void).cxx_destruct;
- (void)cacheResponse:(id)arg1;
- (void)didFailWithError:(id)arg1;
- (void)didGetResponse:(id)arg1;
- (void)startRequestWithLocalCache:(_Bool)arg1;
- (id)initWithDelegate:(id)arg1;

@end

