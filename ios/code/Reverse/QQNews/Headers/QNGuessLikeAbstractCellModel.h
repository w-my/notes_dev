//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "KBTableViewCellBaseModel.h"

@class NSAttributedString, NSString;

@interface QNGuessLikeAbstractCellModel : KBTableViewCellBaseModel
{
    _Bool _needShowPics;
    NSAttributedString *_titleStr;
    NSAttributedString *_abstract;
    NSString *_imageURL;
    struct CGRect _titleFrame;
    struct CGRect _abstractFrame;
    struct CGRect _imageViewFrame;
}

+ (double)p_maxContentWidth;
+ (id)p_guessAbstractAttributedString:(id)arg1 context:(id)arg2;
+ (id)p_guessTitleAttributedString:(id)arg1;
@property(nonatomic) struct CGRect imageViewFrame; // @synthesize imageViewFrame=_imageViewFrame;
@property(copy, nonatomic) NSString *imageURL; // @synthesize imageURL=_imageURL;
@property(nonatomic) _Bool needShowPics; // @synthesize needShowPics=_needShowPics;
@property(nonatomic) struct CGRect abstractFrame; // @synthesize abstractFrame=_abstractFrame;
@property(copy, nonatomic) NSAttributedString *abstract; // @synthesize abstract=_abstract;
@property(nonatomic) struct CGRect titleFrame; // @synthesize titleFrame=_titleFrame;
@property(copy, nonatomic) NSAttributedString *titleStr; // @synthesize titleStr=_titleStr;
- (void).cxx_destruct;
- (void)calculateViewModelWithItem:(id)arg1 context:(id)arg2;

@end
