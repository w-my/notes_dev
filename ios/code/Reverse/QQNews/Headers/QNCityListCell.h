//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "UITableViewCell.h"

@class _QNListCellContentView;

@interface QNCityListCell : UITableViewCell
{
    _QNListCellContentView *_customContentView;
}

+ (id)cellFromTableView:(id)arg1;
@property(retain, nonatomic) _QNListCellContentView *customContentView; // @synthesize customContentView=_customContentView;
- (void).cxx_destruct;
- (void)layoutCellWithCityData:(id)arg1 cellType:(long long)arg2 cellStatus:(unsigned long long)arg3 isFirstRow:(_Bool)arg4;
- (id)initWithStyle:(long long)arg1 reuseIdentifier:(id)arg2;

@end

