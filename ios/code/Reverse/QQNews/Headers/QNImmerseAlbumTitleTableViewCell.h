//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNTableViewCell.h"

@class UILabel, UIView;

@interface QNImmerseAlbumTitleTableViewCell : QNTableViewCell
{
    int _cellState;
    UILabel *_titleLable;
    UILabel *_descLable;
    UIView *_bottomLine;
    double _myHeight;
}

+ (id)createTitleLable;
+ (double)geCellHeightWithTitle:(id)arg1;
@property(nonatomic) double myHeight; // @synthesize myHeight=_myHeight;
@property(nonatomic) int cellState; // @synthesize cellState=_cellState;
@property(retain, nonatomic) UIView *bottomLine; // @synthesize bottomLine=_bottomLine;
@property(retain, nonatomic) UILabel *descLable; // @synthesize descLable=_descLable;
@property(retain, nonatomic) UILabel *titleLable; // @synthesize titleLable=_titleLable;
- (void).cxx_destruct;
- (void)switchToCellState:(int)arg1;
- (void)updataTitleView:(id)arg1 desc:(id)arg2;
- (id)initWithStyle:(long long)arg1 reuseIdentifier:(id)arg2;

@end
