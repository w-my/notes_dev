//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QUIPopupView.h"

#import "UITableViewDataSource.h"
#import "UITableViewDelegate.h"

@class NSMutableArray, NSString, UIColor, UILabel, UITableView, UITextField, UIView, UIViewController, UIWindow;

@interface QUIAlertView : QUIPopupView <UITableViewDataSource, UITableViewDelegate>
{
    UIWindow *windowView;
    double titleHeight;
    double messageHeight;
    _Bool _keepTopAlignment;
    _Bool _visible;
    _Bool _buttonsShouldStack;
    _Bool _autoRotate;
    _Bool _keyboardIsVisible;
    UITextField *_textfield;
    UIColor *_tintColor;
    UIColor *_themeColor;
    UIView *_contentView;
    UIView *_buttonView;
    UIView *_topView;
    id <QUIAlertViewDelegate> _delegate;
    long long _cancelButtonIndex;
    long long _destructiveButtonIndex;
    long long _firstOtherButtonIndex;
    NSString *_message;
    long long _numberOfButtons;
    NSString *_title;
    UILabel *_titleLabel;
    UILabel *_messageLabel;
    id _userData;
    CDUnknownBlockType _completeBlock;
    long long _alertViewStyle;
    UIView *_alertContainerView;
    UIView *_backgroundView;
    UIView *_representationView;
    UITableView *_buttonTableView;
    UITableView *_otherTableView;
    UIWindow *_window;
    UIViewController *_controller;
    NSString *_cancelButtonTitle;
    NSMutableArray *_otherButtonsTitles;
    NSMutableArray *_textFields;
    long long _disabledIndex;
}

@property(nonatomic) _Bool keyboardIsVisible; // @synthesize keyboardIsVisible=_keyboardIsVisible;
@property(nonatomic) long long disabledIndex; // @synthesize disabledIndex=_disabledIndex;
@property(retain, nonatomic) NSMutableArray *textFields; // @synthesize textFields=_textFields;
@property(retain, nonatomic) NSMutableArray *otherButtonsTitles; // @synthesize otherButtonsTitles=_otherButtonsTitles;
@property(copy, nonatomic) NSString *cancelButtonTitle; // @synthesize cancelButtonTitle=_cancelButtonTitle;
@property(retain, nonatomic) UIViewController *controller; // @synthesize controller=_controller;
@property(retain, nonatomic) UIWindow *window; // @synthesize window=_window;
@property(retain, nonatomic) UITableView *otherTableView; // @synthesize otherTableView=_otherTableView;
@property(retain, nonatomic) UITableView *buttonTableView; // @synthesize buttonTableView=_buttonTableView;
@property(readonly, nonatomic) UIView *representationView; // @synthesize representationView=_representationView;
@property(readonly, nonatomic) UIView *backgroundView; // @synthesize backgroundView=_backgroundView;
@property(readonly, nonatomic) UIView *alertContainerView; // @synthesize alertContainerView=_alertContainerView;
@property(nonatomic) long long alertViewStyle; // @synthesize alertViewStyle=_alertViewStyle;
@property(copy, nonatomic) CDUnknownBlockType completeBlock; // @synthesize completeBlock=_completeBlock;
@property(retain, nonatomic) id userData; // @synthesize userData=_userData;
@property(retain, nonatomic) UILabel *messageLabel; // @synthesize messageLabel=_messageLabel;
@property(retain, nonatomic) UILabel *titleLabel; // @synthesize titleLabel=_titleLabel;
@property(nonatomic) _Bool autoRotate; // @synthesize autoRotate=_autoRotate;
@property(nonatomic) _Bool buttonsShouldStack; // @synthesize buttonsShouldStack=_buttonsShouldStack;
@property(readonly, nonatomic, getter=isVisible) _Bool visible; // @synthesize visible=_visible;
@property(copy, nonatomic) NSString *title; // @synthesize title=_title;
@property(readonly, nonatomic) long long numberOfButtons; // @synthesize numberOfButtons=_numberOfButtons;
@property(copy, nonatomic) NSString *message; // @synthesize message=_message;
@property(readonly, nonatomic) long long firstOtherButtonIndex; // @synthesize firstOtherButtonIndex=_firstOtherButtonIndex;
@property(nonatomic) long long destructiveButtonIndex; // @synthesize destructiveButtonIndex=_destructiveButtonIndex;
@property(nonatomic) long long cancelButtonIndex; // @synthesize cancelButtonIndex=_cancelButtonIndex;
@property(nonatomic) __weak id <QUIAlertViewDelegate> delegate; // @synthesize delegate=_delegate;
@property(nonatomic) _Bool keepTopAlignment; // @synthesize keepTopAlignment=_keepTopAlignment;
@property(retain, nonatomic) UIView *topView; // @synthesize topView=_topView;
@property(retain, nonatomic) UIView *buttonView; // @synthesize buttonView=_buttonView;
@property(retain, nonatomic) UIView *contentView; // @synthesize contentView=_contentView;
@property(retain, nonatomic) UIColor *themeColor; // @synthesize themeColor=_themeColor;
@property(retain, nonatomic) UIColor *tintColor; // @synthesize tintColor=_tintColor;
@property(retain, nonatomic) UITextField *textfield; // @synthesize textfield=_textfield;
- (void).cxx_destruct;
- (id)textFieldAtIndex:(long long)arg1;
- (id)addTextInputWithPlaceholder:(id)arg1 isSecure:(_Bool)arg2;
- (void)setButtonEnabledAtIndex:(long long)arg1;
- (void)setButtonDisabledAtIndex:(long long)arg1;
- (void)setButtonDestructiveAtIndex:(long long)arg1;
- (void)setButtonFocusAtIndex:(long long)arg1;
- (id)buttonTitleAtIndex:(long long)arg1;
- (long long)addCancelButtonWithTitle:(id)arg1;
- (long long)addDestructiveButtonWithTitle:(id)arg1;
- (long long)addFocusButtonWithTitle:(id)arg1;
- (long long)addButtonWithTitle:(id)arg1;
- (id)buttonCellForIndex:(long long)arg1;
- (void)tableView:(id)arg1 didSelectRowAtIndexPath:(id)arg2;
- (double)tableView:(id)arg1 heightForRowAtIndexPath:(id)arg2;
- (long long)tableView:(id)arg1 numberOfRowsInSection:(long long)arg2;
- (id)tableView:(id)arg1 cellForRowAtIndexPath:(id)arg2;
- (void)statusBarDidChangeFrame:(id)arg1;
- (_Bool)hasCancelButton;
- (void)destroyAlertView:(long long)arg1;
- (void)dismissWithClickedButtonIndex:(long long)arg1 animated:(_Bool)arg2;
- (void)showview;
- (void)showWithCompleteBlock:(CDUnknownBlockType)arg1;
- (void)show;
- (void)hold;
- (void)layoutSubviews;
- (void)setupWithSize:(struct CGSize)arg1;
- (struct CGSize)size;
- (void)resize;
- (void)setSize:(struct CGSize)arg1;
- (id)getContentViewWithTitle:(id)arg1 message:(id)arg2;
- (id)getTopView;
- (id)getButtonViewWithCancelButtonTitle:(id)arg1 otherButtonTitles:(id)arg2;
- (void)setupWithTitle:(id)arg1 message:(id)arg2 cancelButtonTitle:(id)arg3 otherButtonTitles:(id)arg4;
- (void)setup;
- (id)initWithTitle:(id)arg1 message:(id)arg2 delegate:(id)arg3 cancelButtonTitle:(id)arg4 otherButtonTitleArray:(id)arg5;
- (id)initWithTitle:(id)arg1 message:(id)arg2 delegate:(id)arg3 cancelButtonTitle:(id)arg4 otherButtonTitles:(id)arg5;
- (id)tableViewWithFrame:(struct CGRect)arg1;
- (void)keyboardWillDismiss:(id)arg1;
- (void)keyboardWillShow:(id)arg1;
- (id)initWithViewController:(id)arg1;
- (id)initWithSize:(struct CGSize)arg1;
- (void)setupAfterInit;
- (id)init;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

