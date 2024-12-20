//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNScrollView.h"

#import "QNTopicSelectViewDelegate.h"

@class NSString, QNTopicSelectView, UIButton, UIView, _QNTopicInputView;

@interface QNTopicPublishView : QNScrollView <QNTopicSelectViewDelegate>
{
    id <QNTopicPublishViewDelegate> _publishDelegate;
    CDUnknownBlockType _textDidChangeBlock;
    _QNTopicInputView *_inputView;
    UIView *_separator1;
    UIView *_separator2;
    UIView *_selectViewLine;
    QNTopicSelectView *_topicSelectView;
    QNTopicSelectView *_locateSelectView;
    UIButton *_saveToAlbumBtn;
    UIButton *_publishBtn;
    double _lastTextHeight;
}

@property(nonatomic) double lastTextHeight; // @synthesize lastTextHeight=_lastTextHeight;
@property(nonatomic) __weak UIButton *publishBtn; // @synthesize publishBtn=_publishBtn;
@property(nonatomic) __weak UIButton *saveToAlbumBtn; // @synthesize saveToAlbumBtn=_saveToAlbumBtn;
@property(nonatomic) __weak QNTopicSelectView *locateSelectView; // @synthesize locateSelectView=_locateSelectView;
@property(nonatomic) __weak QNTopicSelectView *topicSelectView; // @synthesize topicSelectView=_topicSelectView;
@property(nonatomic) __weak UIView *selectViewLine; // @synthesize selectViewLine=_selectViewLine;
@property(nonatomic) __weak UIView *separator2; // @synthesize separator2=_separator2;
@property(nonatomic) __weak UIView *separator1; // @synthesize separator1=_separator1;
@property(nonatomic) __weak _QNTopicInputView *inputView; // @synthesize inputView=_inputView;
@property(copy, nonatomic) CDUnknownBlockType textDidChangeBlock; // @synthesize textDidChangeBlock=_textDidChangeBlock;
@property(nonatomic) __weak id <QNTopicPublishViewDelegate> publishDelegate; // @synthesize publishDelegate=_publishDelegate;
- (void).cxx_destruct;
- (void)injectSaveToAlbumButton:(id)arg1 publishButton:(id)arg2;
@property(readonly, copy, nonatomic) NSString *inputContent; // @dynamic inputContent;
- (void)p_textDidChangeOnTextView:(id)arg1;
- (void)p_scrollToVisibleTextView:(id)arg1;
- (void)p_keyboardWillShow:(id)arg1;
- (void)setupKeyboardNoti;
- (void)p_publishDelegateWithType:(unsigned long long)arg1;
- (void)topicSelectView:(id)arg1 didClickTextLabel:(id)arg2;
- (void)topicSelectViewDidClickDelete:(id)arg1;
- (void)layoutWithWeiboModel:(id)arg1 coverImage:(id)arg2;
- (void)layoutSubviews;
- (void)dealloc;
- (id)init;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

