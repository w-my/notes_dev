//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "MMObject.h"

@class FavoritesItem, NSMutableArray, NSString, WNContentStorage;

@interface WNHtmlStringBuilder : MMObject
{
    FavoritesItem *m_favItem;
    WNContentStorage *m_content;
    NSMutableArray *m_fontAttributes;
    _Bool m_bInList;
    NSString *m_remainHTML;
    _Bool m_bStop;
}

- (void).cxx_destruct;
- (void)stopBuildHtmlString;
- (id)buildSpanElementWithRange:(struct _NSRange)arg1 plainText:(id)arg2;
- (id)tryBuildListEndTagAtLocation:(unsigned long long)arg1 WithPreListAttribute:(id)arg2 withCurrentListAttribute:(id)arg3;
- (id)tryBuildListStartTagWithPreListAttribute:(id)arg1 withCurrentListAttribute:(id)arg2;
- (void)asyncBuildHtmlString;
- (void)startBuildHtmlString;
- (id)initWithWNItem:(id)arg1 withContent:(id)arg2 withRemainHTML:(id)arg3 bInList:(_Bool)arg4;

@end

