//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNCommentCellBaseUnitModel.h"

@class NSAttributedString, NSURL, UIImage;

@interface QNWidgetCommentCellHeaderUnitModel : QNCommentCellBaseUnitModel
{
    QNCommentCellBaseUnitModel *_avatarUnit;
    QNCommentCellBaseUnitModel *_nickUnit;
    QNCommentCellBaseUnitModel *_descUnit;
    NSURL *_avatarURL;
    UIImage *_defaultAvatarImage;
    NSAttributedString *_nickname;
    NSAttributedString *_desc;
    NSURL *_flagIconUrl;
}

@property(retain, nonatomic) NSURL *flagIconUrl; // @synthesize flagIconUrl=_flagIconUrl;
@property(copy, nonatomic) NSAttributedString *desc; // @synthesize desc=_desc;
@property(copy, nonatomic) NSAttributedString *nickname; // @synthesize nickname=_nickname;
@property(retain, nonatomic) UIImage *defaultAvatarImage; // @synthesize defaultAvatarImage=_defaultAvatarImage;
@property(retain, nonatomic) NSURL *avatarURL; // @synthesize avatarURL=_avatarURL;
@property(retain, nonatomic) QNCommentCellBaseUnitModel *descUnit; // @synthesize descUnit=_descUnit;
@property(retain, nonatomic) QNCommentCellBaseUnitModel *nickUnit; // @synthesize nickUnit=_nickUnit;
@property(retain, nonatomic) QNCommentCellBaseUnitModel *avatarUnit; // @synthesize avatarUnit=_avatarUnit;
- (void).cxx_destruct;
- (void)setBgColor:(id)arg1;
- (void)calculateWithData:(id)arg1 referRect:(struct CGRect)arg2 context:(id)arg3;

@end

