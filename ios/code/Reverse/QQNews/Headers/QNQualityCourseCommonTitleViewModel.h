//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class NSString, UIColor, UIFont;

@interface QNQualityCourseCommonTitleViewModel : NSObject
{
    unsigned long long _buttonType;
    UIColor *_bgColor;
    NSString *_title;
    UIFont *_titlefont;
    UIColor *_titleColor;
    UIColor *_allButtonTitleColor;
    UIFont *_allButtonTitleFont;
    struct CGSize _viewSize;
    struct CGRect _titleRect;
    struct CGRect _allButtonRect;
}

@property(nonatomic) struct CGRect allButtonRect; // @synthesize allButtonRect=_allButtonRect;
@property(retain, nonatomic) UIFont *allButtonTitleFont; // @synthesize allButtonTitleFont=_allButtonTitleFont;
@property(retain, nonatomic) UIColor *allButtonTitleColor; // @synthesize allButtonTitleColor=_allButtonTitleColor;
@property(retain, nonatomic) UIColor *titleColor; // @synthesize titleColor=_titleColor;
@property(retain, nonatomic) UIFont *titlefont; // @synthesize titlefont=_titlefont;
@property(nonatomic) struct CGRect titleRect; // @synthesize titleRect=_titleRect;
@property(copy, nonatomic) NSString *title; // @synthesize title=_title;
@property(retain, nonatomic) UIColor *bgColor; // @synthesize bgColor=_bgColor;
@property(nonatomic) struct CGSize viewSize; // @synthesize viewSize=_viewSize;
@property(nonatomic) unsigned long long buttonType; // @synthesize buttonType=_buttonType;
- (void).cxx_destruct;

@end

