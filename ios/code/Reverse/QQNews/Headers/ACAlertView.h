//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "UIView.h"

@interface ACAlertView : UIView
{
    id _context;
    long long _viewTag;
    id <ACAlertViewDelegate> _delegate;
}

@property(nonatomic) __weak id <ACAlertViewDelegate> delegate; // @synthesize delegate=_delegate;
@property(nonatomic) long long viewTag; // @synthesize viewTag=_viewTag;
@property(retain, nonatomic) id context; // @synthesize context=_context;
- (void).cxx_destruct;
- (void)dismiss;
- (void)showInView:(id)arg1;
- (void)show;
- (void)actionButtonDidClick:(id)arg1;
- (void)dismissBtnAction:(id)arg1;
- (void)highlightDetailTextAtRange:(struct _NSRange)arg1 withColor:(id)arg2;
- (id)buttonAtIndex:(long long)arg1;
- (id)labelAtIndex:(long long)arg1;
- (id)initWithDelegate:(id)arg1 labelTitles:(id)arg2 buttonTitles:(id)arg3 orientation:(_Bool)arg4;
- (id)initWithDelegate:(id)arg1 labelTitles:(id)arg2 buttonTitles:(id)arg3;

@end
