//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNStockBaseRequest.h"

@interface CHKMarketListDataRequest : QNStockBaseRequest
{
    id <CHKMarketListDataRequestDelegate> _hkMarketListDataRequestDelegate;
}

@property(nonatomic) __weak id <CHKMarketListDataRequestDelegate> hkMarketListDataRequestDelegate; // @synthesize hkMarketListDataRequestDelegate=_hkMarketListDataRequestDelegate;
- (void).cxx_destruct;
- (void)do_handleError:(id)arg1;
- (void)do_handleResponse:(id)arg1;
- (id)do_requestHeaders;
- (id)do_requestURL;
- (void)getHKMarketListData;
- (void)dealloc;
- (id)init;

@end

