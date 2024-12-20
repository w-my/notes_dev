//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "MMUIViewController.h"

#import "IWACommentMgrExt.h"
#import "MMTipsViewControllerDelegate.h"
#import "UIScrollViewDelegate.h"
#import "UITableViewDelegate.h"
#import "UITextViewDelegate.h"
#import "WACommentScoreViewDelegate.h"

@class MMTableViewInfo, MMTipsViewController, NSString, UIButton, UITextView, WACommentScoreView, WAContact;

@interface WACommentPostViewController : MMUIViewController <UITextViewDelegate, IWACommentMgrExt, UIScrollViewDelegate, UITableViewDelegate, WACommentScoreViewDelegate, MMTipsViewControllerDelegate>
{
    MMTipsViewController *m_postTipView;
    id <WACommentPostViewControllerDelegate> _delegate;
    MMTableViewInfo *_tableViewInfo;
    UITextView *_textView;
    WACommentScoreView *_scoreView;
    UIButton *_commitBtn;
    WAContact *_waContact;
}

@property(retain, nonatomic) WAContact *waContact; // @synthesize waContact=_waContact;
@property(retain, nonatomic) UIButton *commitBtn; // @synthesize commitBtn=_commitBtn;
@property(retain, nonatomic) WACommentScoreView *scoreView; // @synthesize scoreView=_scoreView;
@property(retain, nonatomic) UITextView *textView; // @synthesize textView=_textView;
@property(retain, nonatomic) MMTableViewInfo *tableViewInfo; // @synthesize tableViewInfo=_tableViewInfo;
@property(nonatomic) __weak id <WACommentPostViewControllerDelegate> delegate; // @synthesize delegate=_delegate;
- (void).cxx_destruct;
- (void)onClickTipsBtn:(unsigned long long)arg1;
- (id)makeCommitFooterView;
- (void)makeCommentCell:(id)arg1 cellInfo:(struct WCTableViewNormalCellManager *)arg2;
- (void)makeScoreCell:(id)arg1 cellInfo:(struct WCTableViewNormalCellManager *)arg2;
- (void)setCommitBtnEnable:(_Bool)arg1;
- (void)onClickCommit:(id)arg1;
- (void)reloadTableView;
- (void)onPostComment:(id)arg1 withRetCode:(int)arg2 withErrMsg:(id)arg3;
- (void)onClickStarButton;
- (void)textViewDidChange:(id)arg1;
- (void)dealloc;
- (_Bool)useTransparentNavibar;
- (_Bool)useBlackStatusbar;
- (void)viewDidLoad;
- (id)initWithWeAppContact:(id)arg1;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

