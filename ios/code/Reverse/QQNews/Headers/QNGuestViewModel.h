//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNMyCommentViewModel.h"

@class QNUserItem;

@interface QNGuestViewModel : QNMyCommentViewModel
{
    QNUserItem *_userItem;
}

@property(retain, nonatomic) QNUserItem *userItem; // @synthesize userItem=_userItem;
- (void).cxx_destruct;
- (id)unitModelContextAtIndexPath:(id)arg1;
- (id)headerModelForSection:(long long)arg1;
- (void)loadGuestInfoWithCoralUid:(id)arg1 coralUin:(id)arg2 finishedBlock:(CDUnknownBlockType)arg3;

@end
