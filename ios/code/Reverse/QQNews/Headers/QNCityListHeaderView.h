//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "UITableViewHeaderFooterView.h"

@class QNCityData, UIButton, _QNListCellContentView;

@interface QNCityListHeaderView : UITableViewHeaderFooterView
{
    CDUnknownBlockType _headerSelected;
    _QNListCellContentView *_customContentView;
    UIButton *_backgroundBtn;
    QNCityData *_cityData;
}

+ (id)headerViewFromTableView:(id)arg1;
@property(retain, nonatomic) QNCityData *cityData; // @synthesize cityData=_cityData;
@property(retain, nonatomic) UIButton *backgroundBtn; // @synthesize backgroundBtn=_backgroundBtn;
@property(retain, nonatomic) _QNListCellContentView *customContentView; // @synthesize customContentView=_customContentView;
@property(copy, nonatomic) CDUnknownBlockType headerSelected; // @synthesize headerSelected=_headerSelected;
- (void).cxx_destruct;
- (void)p_recoverCustomContentViewBackgroundColor:(id)arg1;
- (void)p_changeCustomContentViewBackgroundColor:(id)arg1;
- (void)p_headerViewSelected:(id)arg1;
- (void)layoutCellWithCityData:(id)arg1 cellType:(long long)arg2 cellStatus:(unsigned long long)arg3 isFirstRow:(_Bool)arg4;
- (id)initWithReuseIdentifier:(id)arg1;

@end

