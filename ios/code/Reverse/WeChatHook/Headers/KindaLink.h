//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

#import "MMKLink.h"

@class MMVoidCallback, NSString;

@interface KindaLink : NSObject <MMKLink>
{
    NSString *_m_text;
    MMVoidCallback *_m_linkCallback;
    long long _m_linkColor;
    long long _m_linkStyle;
    NSString *_fontName;
    struct _NSRange _m_range;
}

@property(copy, nonatomic) NSString *fontName; // @synthesize fontName=_fontName;
@property(nonatomic) long long m_linkStyle; // @synthesize m_linkStyle=_m_linkStyle;
@property(nonatomic) long long m_linkColor; // @synthesize m_linkColor=_m_linkColor;
@property(retain, nonatomic) MMVoidCallback *m_linkCallback; // @synthesize m_linkCallback=_m_linkCallback;
@property(retain, nonatomic) NSString *m_text; // @synthesize m_text=_m_text;
@property(nonatomic) struct _NSRange m_range; // @synthesize m_range=_m_range;
- (void).cxx_destruct;
- (id)getLinkFont;
- (long long)getLinkStyle;
- (id)getLinkCallbackImpl;
- (long long)getLinkColor;
- (id)getText;
- (void)setLinkFont:(id)arg1;
- (void)setLinkStyle:(long long)arg1;
- (void)setLinkCallbackImpl:(id)arg1;
- (void)setLinkColor:(long long)arg1;
- (void)setText:(id)arg1;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

