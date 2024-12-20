//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNDetailComponentBase.h"

#import "CActionSheetDelegate.h"
#import "QNImageBrowserDelegate.h"

@class CActionSheet, NSData, NSString, UIImage;

@interface QNDetailComponentImage : QNDetailComponentBase <QNImageBrowserDelegate, CActionSheetDelegate>
{
    NSString *_clickedImageKey;
    CActionSheet *_actionSheet;
    UIImage *_longPressedImage;
    NSData *_longPressedImageData;
    NSString *_textModeClickIndex;
}

@property(copy, nonatomic) NSString *textModeClickIndex; // @synthesize textModeClickIndex=_textModeClickIndex;
@property(retain, nonatomic) NSData *longPressedImageData; // @synthesize longPressedImageData=_longPressedImageData;
@property(retain, nonatomic) UIImage *longPressedImage; // @synthesize longPressedImage=_longPressedImage;
@property(retain, nonatomic) CActionSheet *actionSheet; // @synthesize actionSheet=_actionSheet;
@property(copy, nonatomic) NSString *clickedImageKey; // @synthesize clickedImageKey=_clickedImageKey;
- (void).cxx_destruct;
- (void)imageBrowserDidScrollToImageItem:(id)arg1;
- (void)imageBrowserDidImageSuccessDownloaded:(id)arg1 image:(id)arg2;
- (struct CGRect)imageBrowserWillDismissAtImageItem:(id)arg1;
- (id)p_buildImageItemFromImageFrame:(id)arg1;
- (struct CGRect)_convertImageNodeFrame2Window:(id)arg1;
- (id)p_displayImagesWithSelectIndex:(long long *)arg1 selectNode:(id)arg2;
- (void)imageClickedWithContentNode:(id)arg1;
- (void)imageClickedInTextModeWithContentNode:(id)arg1;
- (void)p_recognizeQRCode:(id)arg1;
- (void)p_showForbiddenAlert:(id)arg1 message:(id)arg2;
- (void)imageDidFinishSavingWithError:(id)arg1;
- (void)image:(id)arg1 didFinishSavingWithError:(id)arg2 contextInfo:(void *)arg3;
- (void)p_savePhotoData:(id)arg1 image:(id)arg2;
- (void)actionSheet:(id)arg1 buttonClickedWithTitle:(id)arg2 andObject:(id)arg3;
- (void)p_showImageLongPressActionSheetWithImage:(id)arg1 imageNode:(id)arg2;
- (void)_layoutImageWithView:(id)arg1 model:(id)arg2;
- (void)_tryPlayGifWithView:(id)arg1 model:(id)arg2;
- (_Bool)shouldResponseWithComponentView:(id)arg1 componentModel:(id)arg2;
- (void)scrollViewWillPrepareComponentView:(id)arg1 componentModel:(id)arg2;
- (void)scrollViewEndPrepareComponentView:(id)arg1 componentModel:(id)arg2;
- (void)scrollViewWillDisplayComponentView:(id)arg1 componentModel:(id)arg2;
- (void)scrollViewRelayoutComponentView:(id)arg1 componentModel:(id)arg2;
- (void)controllerDidReceiveDataAndWillRenderHTML;
- (id)initWithDetailHandler:(id)arg1;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

