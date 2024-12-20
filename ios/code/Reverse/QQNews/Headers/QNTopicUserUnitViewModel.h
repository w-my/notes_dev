//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

#import "QNTopicUserUnitViewProtocol.h"

@class NSString, NSURL, QNListNewsItem, UIColor, UIFont, UIImage;

@interface QNTopicUserUnitViewModel : NSObject <QNTopicUserUnitViewProtocol>
{
    UIColor *_bgColor;
    QNListNewsItem *_listItem;
    NSURL *_avatarUrl;
    UIImage *_defaultImage;
    NSURL *_flagIconUrl;
    NSString *_name;
    UIFont *_nameFont;
    UIColor *_nameColor;
    NSString *_desc;
    UIFont *_descFont;
    UIColor *_descColor;
    struct CGSize _flagIconSize;
    struct CGPoint _subButtonOrigin;
    struct CGRect _rect;
    struct CGRect _avatarRect;
    struct CGRect _nameRect;
    struct CGRect _descRect;
}

@property(nonatomic) struct CGPoint subButtonOrigin; // @synthesize subButtonOrigin=_subButtonOrigin;
@property(retain, nonatomic) UIColor *descColor; // @synthesize descColor=_descColor;
@property(retain, nonatomic) UIFont *descFont; // @synthesize descFont=_descFont;
@property(nonatomic) struct CGRect descRect; // @synthesize descRect=_descRect;
@property(copy, nonatomic) NSString *desc; // @synthesize desc=_desc;
@property(retain, nonatomic) UIColor *nameColor; // @synthesize nameColor=_nameColor;
@property(retain, nonatomic) UIFont *nameFont; // @synthesize nameFont=_nameFont;
@property(nonatomic) struct CGRect nameRect; // @synthesize nameRect=_nameRect;
@property(copy, nonatomic) NSString *name; // @synthesize name=_name;
@property(nonatomic) struct CGSize flagIconSize; // @synthesize flagIconSize=_flagIconSize;
@property(retain, nonatomic) NSURL *flagIconUrl; // @synthesize flagIconUrl=_flagIconUrl;
@property(retain, nonatomic) UIImage *defaultImage; // @synthesize defaultImage=_defaultImage;
@property(nonatomic) struct CGRect avatarRect; // @synthesize avatarRect=_avatarRect;
@property(retain, nonatomic) NSURL *avatarUrl; // @synthesize avatarUrl=_avatarUrl;
@property(retain, nonatomic) QNListNewsItem *listItem; // @synthesize listItem=_listItem;
@property(retain, nonatomic) UIColor *bgColor; // @synthesize bgColor=_bgColor;
@property(nonatomic) struct CGRect rect; // @synthesize rect=_rect;
- (void).cxx_destruct;
- (void)calculateWithData:(id)arg1 referRect:(struct CGRect)arg2 context:(id)arg3;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

