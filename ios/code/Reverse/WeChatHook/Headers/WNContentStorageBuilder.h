//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "MMObject.h"

#import "RTEHTMLParserDataSource.h"
#import "RTEHTMLParserDelegate.h"

@class NSArray, NSData, NSString, RTEHTMLParser, WNContentStorage, WNHTMLTagNode;

@interface WNContentStorageBuilder : MMObject <RTEHTMLParserDelegate, RTEHTMLParserDataSource>
{
    NSData *m_htmlData;
    NSArray *m_favDataList;
    WNContentStorage *m_tmpStorage;
    WNHTMLTagNode *m_rootTag;
    WNHTMLTagNode *m_currentTag;
    RTEHTMLParser *m_parser;
    _Bool m_bInList;
    _Bool m_bLastInList;
    const char *m_remainContent;
    id <WNContentStorageBuilderDelegate> _delegate;
}

@property(nonatomic) __weak id <WNContentStorageBuilderDelegate> delegate; // @synthesize delegate=_delegate;
- (void).cxx_destruct;
- (void)tryOutputContent;
- (_Bool)isBlockTag:(id)arg1;
- (void)applyCSSStyle:(id)arg1 toTag:(id)arg2;
- (void)applyAttributes:(id)arg1 toTag:(id)arg2;
- (id)parserCustomElementLoopupTable:(id)arg1;
- (void)parser:(id)arg1 parseErrorOccurred:(id)arg2;
- (void)parser:(id)arg1 foundCharacters:(id)arg2;
- (void)parser:(id)arg1 didEndElement:(id)arg2;
- (void)parser:(id)arg1 didStartElement:(id)arg2 attributes:(id)arg3;
- (void)parserDidEndDocument:(id)arg1;
- (void)parserDidStartDocument:(id)arg1;
- (_Bool)bInList;
- (id)getRemianContent;
- (void)stopGenerateContentStorage;
- (void)startGenerateContentStorage;
- (id)initWithHTMLData:(id)arg1 favDataList:(id)arg2 delegate:(id)arg3;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

