//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "UIView.h"

@class MMUILabel, MMWebImageView, NSString;

@interface MMAuthorizeScopeTopView : UIView
{
    NSString *_iconUrl;
    NSString *_title;
    NSString *_scopeDesc;
    NSString *_appendDetailStr;
    MMWebImageView *_appIconImageView;
    MMUILabel *_titleLabel;
    MMUILabel *_scopeLabel;
    MMUILabel *_detailLabel;
}

@property(retain, nonatomic) MMUILabel *detailLabel; // @synthesize detailLabel=_detailLabel;
@property(retain, nonatomic) MMUILabel *scopeLabel; // @synthesize scopeLabel=_scopeLabel;
@property(retain, nonatomic) MMUILabel *titleLabel; // @synthesize titleLabel=_titleLabel;
@property(retain, nonatomic) MMWebImageView *appIconImageView; // @synthesize appIconImageView=_appIconImageView;
@property(copy, nonatomic) NSString *appendDetailStr; // @synthesize appendDetailStr=_appendDetailStr;
@property(copy, nonatomic) NSString *scopeDesc; // @synthesize scopeDesc=_scopeDesc;
@property(copy, nonatomic) NSString *title; // @synthesize title=_title;
@property(copy, nonatomic) NSString *iconUrl; // @synthesize iconUrl=_iconUrl;
- (void).cxx_destruct;
- (void)layoutSubviews;
- (void)initSubviews;
- (id)initWithIconUrl:(id)arg1 title:(id)arg2 scopeDesc:(id)arg3 appendDetailStr:(id)arg4;

@end
