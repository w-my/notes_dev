//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNThemableView.h"

#import "QNDetailContentElementProtocol.h"

@class NSString, QNBaseLabel, QNDetailContentContainer;

@interface QNQAHotCommentNumberView : QNThemableView <QNDetailContentElementProtocol>
{
    QNDetailContentContainer *_contentContainer;
    QNBaseLabel *_textLabel;
}

@property(retain, nonatomic) QNBaseLabel *textLabel; // @synthesize textLabel=_textLabel;
@property(nonatomic) __weak QNDetailContentContainer *contentContainer; // @synthesize contentContainer=_contentContainer;
- (void).cxx_destruct;
- (double)heightOfElementView;
- (void)updateCommentNumber:(long long)arg1;
- (void)layoutSubviews;
- (id)initWithFrame:(struct CGRect)arg1;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

