//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "TLNViewBase.h"

@class UILabel;

@interface TLNTextView : TLNViewBase
{
    UILabel *_titleLabel;
    UILabel *_abstractLabel;
}

@property(retain, nonatomic) UILabel *abstractLabel; // @synthesize abstractLabel=_abstractLabel;
@property(retain, nonatomic) UILabel *titleLabel; // @synthesize titleLabel=_titleLabel;
- (void).cxx_destruct;
- (void)layoutSubviews;
- (id)initWithModel:(id)arg1;

@end
