//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNThemableView.h"

#import "QNListUnitProtocol.h"

@class NSString, QNGridImagesView;

@interface QNTopicImageUnitView : QNThemableView <QNListUnitProtocol>
{
    QNGridImagesView *_imagesView;
}

@property(retain, nonatomic) QNGridImagesView *imagesView; // @synthesize imagesView=_imagesView;
- (void).cxx_destruct;
- (void)layoutWithViewModel:(id)arg1 context:(id)arg2;
- (void)resetImage;
- (void)layoutSubviews;
- (id)initWithFrame:(struct CGRect)arg1;
- (id)init;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

