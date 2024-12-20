//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

#import "QNListUnitModelProtocol.h"

@class NSArray, NSString, UIColor;

@interface QNListCellAssistantViewModel : NSObject <QNListUnitModelProtocol>
{
    _Bool _isCheckNeedReset;
    _Bool _needReset;
    UIColor *_bgColor;
    NSArray *_flagViewModels;
    NSArray *_flagItems;
    struct CGRect _rect;
}

@property(nonatomic) _Bool needReset; // @synthesize needReset=_needReset;
@property(nonatomic) _Bool isCheckNeedReset; // @synthesize isCheckNeedReset=_isCheckNeedReset;
@property(copy, nonatomic) NSArray *flagItems; // @synthesize flagItems=_flagItems;
@property(copy, nonatomic) NSArray *flagViewModels; // @synthesize flagViewModels=_flagViewModels;
@property(retain, nonatomic) UIColor *bgColor; // @synthesize bgColor=_bgColor;
@property(nonatomic) struct CGRect rect; // @synthesize rect=_rect;
- (void).cxx_destruct;
- (id)_createJoinFlagItemIfNeed:(id)arg1;
- (id)_createPublishTimeFlagItemIfNeed:(id)arg1 context:(id)arg2;
- (id)_createFollowFlagItemIfNeed:(id)arg1;
- (id)_createCommentFlagItemIfNeed:(id)arg1 context:(id)arg2;
- (id)_createPicOrVideoStatusFlagItemInTextModeIfNeed:(id)arg1 context:(id)arg2;
- (id)_filterInvalidFlagItems:(id)arg1 listItem:(id)arg2 context:(id)arg3;
- (id)p_getTopicFlagItemsWithListItem:(id)arg1 context:(id)arg2;
- (id)p_getNormalFlagItemsWithListItem:(id)arg1 context:(id)arg2;
- (void)calculateWithData:(id)arg1 referRect:(struct CGRect)arg2 context:(id)arg3;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

