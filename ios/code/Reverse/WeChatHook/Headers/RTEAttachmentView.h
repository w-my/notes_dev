//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "UIView.h"

@class RTETextAttachment;

@interface RTEAttachmentView : UIView
{
    _Bool _bNeedLayout;
    _Bool _bLongPressHandled;
    _Bool _bLongPressCancelled;
    unsigned int _attachmentType;
    RTETextAttachment *_attachment;
    id <RTEAttachmentViewDelegate> _providerDelegate;
}

@property(nonatomic) _Bool bLongPressCancelled; // @synthesize bLongPressCancelled=_bLongPressCancelled;
@property(nonatomic) _Bool bLongPressHandled; // @synthesize bLongPressHandled=_bLongPressHandled;
@property(nonatomic) __weak id <RTEAttachmentViewDelegate> providerDelegate; // @synthesize providerDelegate=_providerDelegate;
@property(nonatomic) _Bool bNeedLayout; // @synthesize bNeedLayout=_bNeedLayout;
@property(retain, nonatomic) RTETextAttachment *attachment; // @synthesize attachment=_attachment;
@property(nonatomic) unsigned int attachmentType; // @synthesize attachmentType=_attachmentType;
- (void).cxx_destruct;
- (void)onLongPressObject;
- (void)onClickObject;
- (void)onLongPressEvents;
- (void)onTouchEnd:(id)arg1;
- (void)onTouchBegin:(id)arg1;
- (void)touchesCancelled:(id)arg1 withEvent:(id)arg2;
- (void)touchesEnded:(id)arg1 withEvent:(id)arg2;
- (void)touchesMoved:(id)arg1 withEvent:(id)arg2;
- (void)touchesBegan:(id)arg1 withEvent:(id)arg2;
- (void)dealloc;
- (void)layoutView;
- (void)removeFromSuperview;
- (id)initWithAttachment:(id)arg1;

@end

