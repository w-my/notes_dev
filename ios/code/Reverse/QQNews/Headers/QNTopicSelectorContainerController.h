//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNSubscribeManagerController.h"

@interface QNTopicSelectorContainerController : QNSubscribeManagerController
{
    CDUnknownBlockType _finishBlock;
    CDUnknownBlockType _cancelBlock;
}

+ (void)presentWithController:(id)arg1 finishBlock:(CDUnknownBlockType)arg2 cancelBlock:(CDUnknownBlockType)arg3;
@property(copy, nonatomic) CDUnknownBlockType cancelBlock; // @synthesize cancelBlock=_cancelBlock;
@property(copy, nonatomic) CDUnknownBlockType finishBlock; // @synthesize finishBlock=_finishBlock;
- (void).cxx_destruct;
- (void)p_notifyChildControllerWillDismiss;
- (void)p_cancel;
- (id)do_contentControllerWithCateItem:(id)arg1;
- (void)configTitleView;
- (void)configBarButtons;
- (void)viewDidLoad;

@end

