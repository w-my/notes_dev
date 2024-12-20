//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNThemableView.h"

#import "QNDetailContentElementProtocol.h"

@class NSString, QNArticleContentNodeTagLinkNode, QNDetailContentContainer, QNDetailH5TagViewButton;

@interface QNDetailH5TagView : QNThemableView <QNDetailContentElementProtocol>
{
    QNDetailContentContainer *_contentContainer;
    QNArticleContentNodeTagLinkNode *_h5TagItem;
    CDUnknownBlockType _h5TagItemClickedBlock;
    QNDetailH5TagViewButton *_tagBtn;
}

@property(retain, nonatomic) QNDetailH5TagViewButton *tagBtn; // @synthesize tagBtn=_tagBtn;
@property(copy, nonatomic) CDUnknownBlockType h5TagItemClickedBlock; // @synthesize h5TagItemClickedBlock=_h5TagItemClickedBlock;
@property(retain, nonatomic) QNArticleContentNodeTagLinkNode *h5TagItem; // @synthesize h5TagItem=_h5TagItem;
@property(nonatomic) __weak QNDetailContentContainer *contentContainer; // @synthesize contentContainer=_contentContainer;
- (void).cxx_destruct;
- (void)p_tagButtonClicked:(id)arg1;
- (void)p_layoutSubviews;
- (void)themeChanged:(long long)arg1;
- (double)heightOfElementView;
- (id)initWithFrame:(struct CGRect)arg1;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

