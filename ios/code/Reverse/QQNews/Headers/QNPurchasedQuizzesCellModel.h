//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class NSAttributedString, NSString, QNPurchasedQuizzesModel, UIColor, UIFont;

@interface QNPurchasedQuizzesCellModel : NSObject
{
    _Bool _bottomLineHidden;
    QNPurchasedQuizzesModel *_quizzesModel;
    UIColor *_cellBgColor;
    double _cellHeight;
    NSAttributedString *_title;
    NSString *_name;
    UIColor *_nameColor;
    UIFont *_nameFont;
    NSString *_time;
    UIColor *_timeColor;
    UIFont *_timeFont;
    NSString *_avatorUrl;
    UIColor *_bottomLineColor;
    struct CGRect _titleRect;
    struct CGRect _nameRect;
    struct CGRect _timeRect;
    struct CGRect _avatorRect;
    struct CGRect _bottomLineRect;
}

@property(retain, nonatomic) UIColor *bottomLineColor; // @synthesize bottomLineColor=_bottomLineColor;
@property(nonatomic) struct CGRect bottomLineRect; // @synthesize bottomLineRect=_bottomLineRect;
@property(nonatomic) _Bool bottomLineHidden; // @synthesize bottomLineHidden=_bottomLineHidden;
@property(nonatomic) struct CGRect avatorRect; // @synthesize avatorRect=_avatorRect;
@property(copy, nonatomic) NSString *avatorUrl; // @synthesize avatorUrl=_avatorUrl;
@property(nonatomic) struct CGRect timeRect; // @synthesize timeRect=_timeRect;
@property(retain, nonatomic) UIFont *timeFont; // @synthesize timeFont=_timeFont;
@property(retain, nonatomic) UIColor *timeColor; // @synthesize timeColor=_timeColor;
@property(copy, nonatomic) NSString *time; // @synthesize time=_time;
@property(nonatomic) struct CGRect nameRect; // @synthesize nameRect=_nameRect;
@property(retain, nonatomic) UIFont *nameFont; // @synthesize nameFont=_nameFont;
@property(retain, nonatomic) UIColor *nameColor; // @synthesize nameColor=_nameColor;
@property(copy, nonatomic) NSString *name; // @synthesize name=_name;
@property(nonatomic) struct CGRect titleRect; // @synthesize titleRect=_titleRect;
@property(copy, nonatomic) NSAttributedString *title; // @synthesize title=_title;
@property(nonatomic) double cellHeight; // @synthesize cellHeight=_cellHeight;
@property(retain, nonatomic) UIColor *cellBgColor; // @synthesize cellBgColor=_cellBgColor;
@property(retain, nonatomic) QNPurchasedQuizzesModel *quizzesModel; // @synthesize quizzesModel=_quizzesModel;
- (void).cxx_destruct;
- (void)caculateWithModel:(id)arg1 context:(id)arg2;

@end

