//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

@class NSNumber, NSString, WXVoiceTRJsonStreamParser;

@protocol WXVoiceTRJsonStreamParserDelegate
- (void)parser:(WXVoiceTRJsonStreamParser *)arg1 foundString:(NSString *)arg2;
- (void)parser:(WXVoiceTRJsonStreamParser *)arg1 foundNumber:(NSNumber *)arg2;
- (void)parserFoundNull:(WXVoiceTRJsonStreamParser *)arg1;
- (void)parser:(WXVoiceTRJsonStreamParser *)arg1 foundBoolean:(_Bool)arg2;
- (void)parserFoundArrayEnd:(WXVoiceTRJsonStreamParser *)arg1;
- (void)parserFoundArrayStart:(WXVoiceTRJsonStreamParser *)arg1;
- (void)parserFoundObjectEnd:(WXVoiceTRJsonStreamParser *)arg1;
- (void)parser:(WXVoiceTRJsonStreamParser *)arg1 foundObjectKey:(NSString *)arg2;
- (void)parserFoundObjectStart:(WXVoiceTRJsonStreamParser *)arg1;
@end

