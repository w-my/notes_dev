//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNBaseFollowListCellViewModel.h"

@class NSURL, UIImage;

@interface QNFollowCommonCellViewModel : QNBaseFollowListCellViewModel
{
    NSURL *_imageURL;
    UIImage *_defaulImage;
    long long _picType;
    struct CGRect _singleImageViewRect;
}

+ (double)calculateCellHeightWithItem:(id)arg1 context:(id)arg2;
@property(nonatomic) long long picType; // @synthesize picType=_picType;
@property(retain, nonatomic) UIImage *defaulImage; // @synthesize defaulImage=_defaulImage;
@property(retain, nonatomic) NSURL *imageURL; // @synthesize imageURL=_imageURL;
@property(nonatomic) struct CGRect singleImageViewRect; // @synthesize singleImageViewRect=_singleImageViewRect;
- (void).cxx_destruct;
- (void)calculateViewModelWithItem:(id)arg1 context:(id)arg2;
- (id)init;

@end
