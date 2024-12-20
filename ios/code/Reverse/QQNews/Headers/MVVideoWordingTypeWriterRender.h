//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "MVVideoWordingRender.h"

@class UIView;

@interface MVVideoWordingTypeWriterRender : MVVideoWordingRender
{
    _Bool _reloadLabels;
    UIView *_contentView;
}

@property(retain, nonatomic) UIView *contentView; // @synthesize contentView=_contentView;
@property _Bool reloadLabels; // @synthesize reloadLabels=_reloadLabels;
- (void).cxx_destruct;
- (void)calculateCharacterFrames:(id)arg1 font:(struct __CTFont *)arg2 boundRect:(struct CGRect *)arg3 characterFrames:(struct CGRect *)arg4;
- (id)attributedString:(id)arg1 fontSize:(double)arg2;
- (void)renderInRect:(struct CGRect)arg1 typewriterAnimation:(id)arg2;
- (void)buildContent;
- (id)createLabel;
- (void)render;

@end

