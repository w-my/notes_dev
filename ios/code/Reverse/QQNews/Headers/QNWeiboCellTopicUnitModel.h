//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

#import "QNListLabelUnitModel.h"

@class NSAttributedString, NSString, UIColor;

@interface QNWeiboCellTopicUnitModel : NSObject <QNListLabelUnitModel>
{
    _Bool _enableTapGesture;
    UIColor *_bgColor;
    NSAttributedString *_attributedText;
    unsigned long long _numberOfLines;
    struct CGRect _rect;
}

@property(readonly, nonatomic) _Bool enableTapGesture; // @synthesize enableTapGesture=_enableTapGesture;
@property(readonly, nonatomic) unsigned long long numberOfLines; // @synthesize numberOfLines=_numberOfLines;
@property(readonly, copy, nonatomic) NSAttributedString *attributedText; // @synthesize attributedText=_attributedText;
@property(readonly, nonatomic) UIColor *bgColor; // @synthesize bgColor=_bgColor;
@property(readonly, nonatomic) struct CGRect rect; // @synthesize rect=_rect;
- (void).cxx_destruct;
- (void)calculateWithData:(id)arg1 referRect:(struct CGRect)arg2 context:(id)arg3;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end
