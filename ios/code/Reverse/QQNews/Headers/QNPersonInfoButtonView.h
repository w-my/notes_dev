//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNThemableView.h"

@class QNBaseLabel, UIImageView;

@interface QNPersonInfoButtonView : QNThemableView
{
    UIImageView *_locationIcon;
    QNBaseLabel *_locationLabel;
    QNBaseLabel *_starSignLabel;
    QNBaseLabel *_descLabel;
    id <QNPersonInfoButtonViewDelgate> _iDelgate;
}

@property(nonatomic) __weak id <QNPersonInfoButtonViewDelgate> iDelgate; // @synthesize iDelgate=_iDelgate;
@property(retain, nonatomic) QNBaseLabel *descLabel; // @synthesize descLabel=_descLabel;
@property(retain, nonatomic) QNBaseLabel *starSignLabel; // @synthesize starSignLabel=_starSignLabel;
@property(retain, nonatomic) QNBaseLabel *locationLabel; // @synthesize locationLabel=_locationLabel;
@property(retain, nonatomic) UIImageView *locationIcon; // @synthesize locationIcon=_locationIcon;
- (void).cxx_destruct;
- (void)themeChanged:(long long)arg1;
- (void)setLocationName:(id)arg1 starSingName:(id)arg2;
- (id)initWithFrame:(struct CGRect)arg1;

@end
