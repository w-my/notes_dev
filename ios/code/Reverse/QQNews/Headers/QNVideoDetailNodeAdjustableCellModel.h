//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class NSArray, QNVideoTagItem;

@interface QNVideoDetailNodeAdjustableCellModel : NSObject
{
    _Bool _isMaxShowState;
    _Bool _isShowedWeiXinIcon;
    _Bool _showingCommentView;
    _Bool _needReCalculate;
    int _omButtonShowState;
    double _minShowStateHeight;
    double _maxShowStateHeight;
    QNVideoTagItem *_omBtnTagItem;
    NSArray *_kk_tags;
    double _descHeight;
    double _titleHeight;
}

@property(nonatomic) _Bool needReCalculate; // @synthesize needReCalculate=_needReCalculate;
@property(nonatomic) _Bool showingCommentView; // @synthesize showingCommentView=_showingCommentView;
@property(nonatomic) double titleHeight; // @synthesize titleHeight=_titleHeight;
@property(nonatomic) double descHeight; // @synthesize descHeight=_descHeight;
@property(retain, nonatomic) NSArray *kk_tags; // @synthesize kk_tags=_kk_tags;
@property(retain, nonatomic) QNVideoTagItem *omBtnTagItem; // @synthesize omBtnTagItem=_omBtnTagItem;
@property(nonatomic) int omButtonShowState; // @synthesize omButtonShowState=_omButtonShowState;
@property(nonatomic) _Bool isShowedWeiXinIcon; // @synthesize isShowedWeiXinIcon=_isShowedWeiXinIcon;
@property(nonatomic) _Bool isMaxShowState; // @synthesize isMaxShowState=_isMaxShowState;
@property(nonatomic) double maxShowStateHeight; // @synthesize maxShowStateHeight=_maxShowStateHeight;
@property(nonatomic) double minShowStateHeight; // @synthesize minShowStateHeight=_minShowStateHeight;
- (void).cxx_destruct;
- (id)init;

@end
