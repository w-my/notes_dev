//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "TVDLProxyCGITask.h"

#import "NSXMLParserDelegate.h"

@class NSString;

@interface TVDLProxyCGICheckTimeTask : TVDLProxyCGITask <NSXMLParserDelegate>
{
    int _parseErrCode;
    NSString *_currentTag;
}

@property(nonatomic) int parseErrCode; // @synthesize parseErrCode=_parseErrCode;
@property(copy, nonatomic) NSString *currentTag; // @synthesize currentTag=_currentTag;
- (void).cxx_destruct;
- (void)parser:(id)arg1 parseErrorOccurred:(id)arg2;
- (void)parser:(id)arg1 didEndElement:(id)arg2 namespaceURI:(id)arg3 qualifiedName:(id)arg4;
- (void)parser:(id)arg1 foundCharacters:(id)arg2;
- (void)parser:(id)arg1 didStartElement:(id)arg2 namespaceURI:(id)arg3 qualifiedName:(id)arg4 attributes:(id)arg5;
- (void)reportWithCgiErrType:(long long)arg1 withErrCode:(long long)arg2 withTimecostMS:(long long)arg3 withRetryTime:(long long)arg4 withErrEm:(long long)arg5 withErrExem:(long long)arg6;
- (void)reportWithErrType:(long long)arg1 withErrCode:(long long)arg2 withTimecostMS:(long long)arg3 withRetrytime:(long long)arg4;
- (id)getRequestParams;
- (id)getRequestUrl;
- (void)parseResponse:(id)arg1 requestTimecost:(double)arg2 requestRetryTime:(long long)arg3;
- (id)init;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end
