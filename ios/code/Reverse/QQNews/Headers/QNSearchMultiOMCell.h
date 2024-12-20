//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNThemableTableViewCell.h"

@class NSArray, NSIndexPath, QNOMItem, UIImageView;

@interface QNSearchMultiOMCell : QNThemableTableViewCell
{
    CDUnknownBlockType _omBlock;
    NSIndexPath *_indexPath;
    NSArray *_omButtonList;
    long long _omListCount;
    QNOMItem *_omItem;
    UIImageView *_bottomLine;
}

+ (double)cellHeight;
+ (id)identifier;
@property(retain, nonatomic) UIImageView *bottomLine; // @synthesize bottomLine=_bottomLine;
@property(retain, nonatomic) QNOMItem *omItem; // @synthesize omItem=_omItem;
@property(nonatomic) long long omListCount; // @synthesize omListCount=_omListCount;
@property(copy, nonatomic) NSArray *omButtonList; // @synthesize omButtonList=_omButtonList;
@property(retain, nonatomic) NSIndexPath *indexPath; // @synthesize indexPath=_indexPath;
@property(copy, nonatomic) CDUnknownBlockType omBlock; // @synthesize omBlock=_omBlock;
- (void).cxx_destruct;
- (void)searchUnitOMButtonClicked:(id)arg1;
- (void)layoutSubviews;
- (void)layoutWithOMItem:(id)arg1;
- (id)initWithStyle:(long long)arg1 reuseIdentifier:(id)arg2;

@end

