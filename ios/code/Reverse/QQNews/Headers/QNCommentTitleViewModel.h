//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNBaseViewModel.h"

@class CCardNodeType, NSAttributedString, NSURL, QNListNewsItem, UIImage;

@interface QNCommentTitleViewModel : QNBaseViewModel
{
    _Bool _showOrigIcon;
    _Bool _isFromSensitiveNews;
    QNListNewsItem *_listItem;
    QNBaseViewModel *_titleUnit;
    QNBaseViewModel *_avatarUnit;
    QNBaseViewModel *_nameUnit;
    QNBaseViewModel *_timeUnit;
    QNBaseViewModel *_separatorUnit;
    NSAttributedString *_title;
    NSURL *_avatarURL;
    UIImage *_placeholderAvatar;
    NSAttributedString *_name;
    NSAttributedString *_time;
    CCardNodeType *_cardNode;
    UIImage *_origImage;
    unsigned long long _fromType;
    UIImage *_versionSlantLine;
    UIImage *_dateSlantLine;
    unsigned long long _from;
}

+ (id)dateFormatter;
@property(nonatomic) _Bool isFromSensitiveNews; // @synthesize isFromSensitiveNews=_isFromSensitiveNews;
@property(nonatomic) unsigned long long from; // @synthesize from=_from;
@property(retain, nonatomic) UIImage *dateSlantLine; // @synthesize dateSlantLine=_dateSlantLine;
@property(retain, nonatomic) UIImage *versionSlantLine; // @synthesize versionSlantLine=_versionSlantLine;
@property(nonatomic) unsigned long long fromType; // @synthesize fromType=_fromType;
@property(nonatomic) _Bool showOrigIcon; // @synthesize showOrigIcon=_showOrigIcon;
@property(retain, nonatomic) UIImage *origImage; // @synthesize origImage=_origImage;
@property(retain, nonatomic) CCardNodeType *cardNode; // @synthesize cardNode=_cardNode;
@property(copy, nonatomic) NSAttributedString *time; // @synthesize time=_time;
@property(copy, nonatomic) NSAttributedString *name; // @synthesize name=_name;
@property(retain, nonatomic) UIImage *placeholderAvatar; // @synthesize placeholderAvatar=_placeholderAvatar;
@property(retain, nonatomic) NSURL *avatarURL; // @synthesize avatarURL=_avatarURL;
@property(copy, nonatomic) NSAttributedString *title; // @synthesize title=_title;
@property(retain, nonatomic) QNBaseViewModel *separatorUnit; // @synthesize separatorUnit=_separatorUnit;
@property(retain, nonatomic) QNBaseViewModel *timeUnit; // @synthesize timeUnit=_timeUnit;
@property(retain, nonatomic) QNBaseViewModel *nameUnit; // @synthesize nameUnit=_nameUnit;
@property(retain, nonatomic) QNBaseViewModel *avatarUnit; // @synthesize avatarUnit=_avatarUnit;
@property(retain, nonatomic) QNBaseViewModel *titleUnit; // @synthesize titleUnit=_titleUnit;
@property(retain, nonatomic) QNListNewsItem *listItem; // @synthesize listItem=_listItem;
- (void).cxx_destruct;
- (void)setBgColor:(id)arg1;
- (void)calculateWithListItem:(id)arg1 cardNode:(id)arg2 differentBg:(_Bool)arg3;
- (void)calculateWithListItem:(id)arg1 cardNode:(id)arg2;

@end
