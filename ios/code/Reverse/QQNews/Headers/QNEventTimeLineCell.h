//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNTableViewCell.h"

#import "QNCommonListVideoCellProtocol.h"
#import "QNListCellProtocol.h"

@class NSIndexPath, NSString, QNEventTimeLineCellHeaderUnit, QNEventTimeLineCellModel, QNListNewsItem, QNListSeparatorUnit, QNListSingleImageUnit, QNListTextUnit;

@interface QNEventTimeLineCell : QNTableViewCell <QNListCellProtocol, QNCommonListVideoCellProtocol>
{
    QNEventTimeLineCellModel *_cellModel;
    QNListNewsItem *_listItem;
    NSIndexPath *_indexPath;
    CDUnknownBlockType _playVideoBlock;
    QNEventTimeLineCellHeaderUnit *_headerUnit;
    QNListTextUnit *_textUnit;
    QNListSingleImageUnit *_imageUnit;
    QNListSeparatorUnit *_separatorUnit;
}

@property(retain, nonatomic) QNListSeparatorUnit *separatorUnit; // @synthesize separatorUnit=_separatorUnit;
@property(retain, nonatomic) QNListSingleImageUnit *imageUnit; // @synthesize imageUnit=_imageUnit;
@property(retain, nonatomic) QNListTextUnit *textUnit; // @synthesize textUnit=_textUnit;
@property(retain, nonatomic) QNEventTimeLineCellHeaderUnit *headerUnit; // @synthesize headerUnit=_headerUnit;
@property(copy, nonatomic) CDUnknownBlockType playVideoBlock; // @synthesize playVideoBlock=_playVideoBlock;
@property(retain, nonatomic) NSIndexPath *indexPath; // @synthesize indexPath=_indexPath;
@property(retain, nonatomic) QNListNewsItem *listItem; // @synthesize listItem=_listItem;
@property(retain, nonatomic) QNEventTimeLineCellModel *cellModel; // @synthesize cellModel=_cellModel;
- (void).cxx_destruct;
- (void)p_closePlayer;
- (id)p_imageBroswerItem;
- (void)p_applyDefaultSelectedBackgroundView;
- (void)p_onConfigChanged;
- (void)layoutWithViewModel:(id)arg1 context:(id)arg2;
- (void)playVideo;
- (void)updateViews;
- (id)getAttachImage;
- (id)getAttachPlayerView;
- (id)getProtocolVideoContentView;
- (id)getProtocolListItem;
- (void)dealloc;
- (id)initWithStyle:(long long)arg1 reuseIdentifier:(id)arg2;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end
