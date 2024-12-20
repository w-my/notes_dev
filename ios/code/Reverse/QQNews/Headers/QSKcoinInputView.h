//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QSCellView.h"

@class UIColor, UIImage, UIImageView, UITextField;

@interface QSKcoinInputView : QSCellView
{
    _Bool _cntInputEditing;
    UITextField *_cntInput;
    UIColor *_txtColor;
    UIImageView *_cntInputBgImageView;
    UIImage *_cntInputBgImage;
    UIImage *_cntInputBgImageSelected;
    UIImage *_cntInputBgImageError;
}

@property(nonatomic) _Bool cntInputEditing; // @synthesize cntInputEditing=_cntInputEditing;
@property(retain, nonatomic) UIImage *cntInputBgImageError; // @synthesize cntInputBgImageError=_cntInputBgImageError;
@property(retain, nonatomic) UIImage *cntInputBgImageSelected; // @synthesize cntInputBgImageSelected=_cntInputBgImageSelected;
@property(retain, nonatomic) UIImage *cntInputBgImage; // @synthesize cntInputBgImage=_cntInputBgImage;
@property(retain, nonatomic) UIImageView *cntInputBgImageView; // @synthesize cntInputBgImageView=_cntInputBgImageView;
@property(nonatomic) UIColor *txtColor; // @synthesize txtColor=_txtColor;
@property(retain, nonatomic) UITextField *cntInput; // @synthesize cntInput=_cntInput;
- (void).cxx_destruct;
- (void)update;
- (id)initWithFrame:(struct CGRect)arg1 reuseIdentifier:(id)arg2;

@end

