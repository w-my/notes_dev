//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "MVVideoWordingRender.h"

@class UILabel;

@interface MVVideoWordingLabelRender : MVVideoWordingRender
{
    UILabel *_label;
}

@property(retain, nonatomic) UILabel *label; // @synthesize label=_label;
- (void).cxx_destruct;
- (void)renderInRect:(struct CGRect)arg1 animation:(id)arg2;
- (void)buildContent;
- (void)render;

@end

