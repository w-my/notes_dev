//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNThemableView.h"

@interface QNInputToolbar : QNThemableView
{
    struct NSMutableArray *_leftButtons;
    struct NSMutableArray *_rightButtons;
    CDUnknownBlockType _clickedBlock;
    double _buttonSpace;
    struct UIEdgeInsets _contentInsets;
}

@property(nonatomic) double buttonSpace; // @synthesize buttonSpace=_buttonSpace;
@property(nonatomic) struct UIEdgeInsets contentInsets; // @synthesize contentInsets=_contentInsets;
@property(copy, nonatomic) CDUnknownBlockType clickedBlock; // @synthesize clickedBlock=_clickedBlock;
- (void).cxx_destruct;
- (void)p_buttonClicked:(id)arg1;
- (void)p_reArrangeButtonsFromIndex:(long long)arg1 withButton:(id)arg2 left:(_Bool)arg3;
- (void)p_replaceButton:(id)arg1 withButton:(id)arg2 left:(_Bool)arg3;
- (unsigned long long)p_removeButton:(id)arg1 left:(_Bool)arg2;
- (void)p_insertButton:(id)arg1 atIndex:(unsigned long long)arg2 left:(_Bool)arg3;
- (void)p_addButtons:(id)arg1 left:(_Bool)arg2;
- (void)setFrame:(struct CGRect)arg1;
- (void)layoutButtonsWithEqualSpace;
- (void)layoutButtons;
- (_Bool)containsButtonWithType:(unsigned long long)arg1;
- (_Bool)containsButton:(id)arg1;
- (void)replaceRightButton:(id)arg1 withButton:(id)arg2;
- (void)replaceLeftButton:(id)arg1 withButton:(id)arg2;
- (void)removeRightButton:(id)arg1;
- (void)removeLeftButton:(id)arg1;
- (void)addRightButton:(id)arg1;
- (void)addLeftButton:(id)arg1;
- (void)addRightButtons:(id)arg1;
- (void)addLeftButtons:(id)arg1;
- (void)dealloc;
- (id)initWithFrame:(struct CGRect)arg1;

@end

