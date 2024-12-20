//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "UIButton.h"

#import "QNAnswerContentProtocol.h"

@class NSString, QNBaseLabel, QNCommonGIFImageView;

@interface QNQAAnswerThreeImageView : UIButton <QNAnswerContentProtocol>
{
    QNBaseLabel *_assistantViewHeader;
    QNCommonGIFImageView *_firstImageView;
    QNCommonGIFImageView *_secondImageView;
    QNCommonGIFImageView *_thirdImageView;
    QNBaseLabel *_assistantViewFooter;
}

@property(retain, nonatomic) QNBaseLabel *assistantViewFooter; // @synthesize assistantViewFooter=_assistantViewFooter;
@property(retain, nonatomic) QNCommonGIFImageView *thirdImageView; // @synthesize thirdImageView=_thirdImageView;
@property(retain, nonatomic) QNCommonGIFImageView *secondImageView; // @synthesize secondImageView=_secondImageView;
@property(retain, nonatomic) QNCommonGIFImageView *firstImageView; // @synthesize firstImageView=_firstImageView;
@property(retain, nonatomic) QNBaseLabel *assistantViewHeader; // @synthesize assistantViewHeader=_assistantViewHeader;
- (void).cxx_destruct;
- (id)getAnswerContentView;
- (void)layoutWithItem:(id)arg1 context:(id)arg2;
- (void)layoutSubviews;
- (double)viewHeight:(id)arg1 context:(id)arg2;
- (id)init;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

