//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

#import "NSXMLParserDelegate.h"

@class NSMutableArray, NSMutableString, NSString;

@interface MMXMLParser : NSObject <NSXMLParserDelegate>
{
    _Bool _attributesAsStandaloneDic;
    NSMutableArray *_dictionaryStack;
    NSMutableString *_textInProgress;
    NSMutableString *_xml;
}

+ (id)xmlWithDic:(id)arg1;
+ (id)dictionaryWithXMLString:(id)arg1;
+ (id)dictionaryWithXMLData:(id)arg1;
@property(retain, nonatomic) NSMutableString *xml; // @synthesize xml=_xml;
@property(retain, nonatomic) NSMutableString *textInProgress; // @synthesize textInProgress=_textInProgress;
@property(retain, nonatomic) NSMutableArray *dictionaryStack; // @synthesize dictionaryStack=_dictionaryStack;
@property(nonatomic) _Bool attributesAsStandaloneDic; // @synthesize attributesAsStandaloneDic=_attributesAsStandaloneDic;
- (void).cxx_destruct;
- (_Bool)isArrayOrDic:(id)arg1;
- (void)dfsVisitObject:(id)arg1 key:(id)arg2;
- (id)xmlWithDic:(id)arg1;
- (void)parser:(id)arg1 parseErrorOccurred:(id)arg2;
- (void)parser:(id)arg1 foundCharacters:(id)arg2;
- (void)parser:(id)arg1 didEndElement:(id)arg2 namespaceURI:(id)arg3 qualifiedName:(id)arg4;
- (void)parser:(id)arg1 didStartElement:(id)arg2 namespaceURI:(id)arg3 qualifiedName:(id)arg4 attributes:(id)arg5;
- (id)dictionaryWithData:(id)arg1;
- (id)init;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

