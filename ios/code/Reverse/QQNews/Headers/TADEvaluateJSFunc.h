//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "TADLandingViewBaseFunc.h"

@class WKWebView;

@interface TADEvaluateJSFunc : TADLandingViewBaseFunc
{
    WKWebView *_webView;
}

@property(nonatomic) __weak WKWebView *webView; // @synthesize webView=_webView;
- (void).cxx_destruct;
- (void)evaluateJavaScript:(id)arg1 withCompletionBlock:(CDUnknownBlockType)arg2;
- (id)evaluateJavaScript:(id)arg1;

@end
