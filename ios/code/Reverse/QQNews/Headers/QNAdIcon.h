//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "UIView.h"

@class NSDictionary, QNBaseLabel;

@interface QNAdIcon : UIView
{
    QNBaseLabel *_adIconLabel;
    NSDictionary *_labelAttributes;
    double _labelMargin;
}

+ (id)defaultIcon;
@property(nonatomic) double labelMargin; // @synthesize labelMargin=_labelMargin;
@property(retain, nonatomic) NSDictionary *labelAttributes; // @synthesize labelAttributes=_labelAttributes;
@property(retain, nonatomic) QNBaseLabel *adIconLabel; // @synthesize adIconLabel=_adIconLabel;
- (void).cxx_destruct;
- (void)updateIcon:(id)arg1;
- (id)initWithFrame:(struct CGRect)arg1;

@end
