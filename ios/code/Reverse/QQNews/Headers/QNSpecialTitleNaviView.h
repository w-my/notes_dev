//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNThemableScrollView.h"

@class CALayer, NSMutableArray, UIImageView, UIView;

@interface QNSpecialTitleNaviView : QNThemableScrollView
{
    _Bool _isHideAnimating;
    CDUnknownBlockType _selectedBlock;
    long long _selectedIndex;
    UIView *_backView;
    NSMutableArray *_itemViews;
    CALayer *_line;
    UIImageView *_bottomLine;
}

+ (double)viewHeight;
+ (double)p_maxContentWidth;
@property(nonatomic) _Bool isHideAnimating; // @synthesize isHideAnimating=_isHideAnimating;
@property(retain, nonatomic) UIImageView *bottomLine; // @synthesize bottomLine=_bottomLine;
@property(retain, nonatomic) CALayer *line; // @synthesize line=_line;
@property(retain, nonatomic) NSMutableArray *itemViews; // @synthesize itemViews=_itemViews;
@property(retain, nonatomic) UIView *backView; // @synthesize backView=_backView;
@property(nonatomic) long long selectedIndex; // @synthesize selectedIndex=_selectedIndex;
@property(copy, nonatomic) CDUnknownBlockType selectedBlock; // @synthesize selectedBlock=_selectedBlock;
- (void).cxx_destruct;
- (void)themeChanged:(long long)arg1;
- (void)p_itemViewOnCliked:(id)arg1;
- (void)reset;
- (void)scrollLineToItemViewAtIndex:(long long)arg1 clicked:(_Bool)arg2 upSwipe:(_Bool)arg3;
- (void)scrollToItemViewAtIndex:(long long)arg1 clicked:(_Bool)arg2 upSwipe:(_Bool)arg3;
- (void)hideAnimated:(_Bool)arg1;
- (void)showAnimated:(_Bool)arg1;
- (void)layoutWithTitles:(id)arg1;
- (void)p_resetViews;
- (id)initWithFrame:(struct CGRect)arg1;

@end

