//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNDetailComponentBase.h"

@interface QNDetailComponentJumpButton : QNDetailComponentBase
{
    _Bool _hasReportJumpView;
}

@property(nonatomic) _Bool hasReportJumpView; // @synthesize hasReportJumpView=_hasReportJumpView;
- (void)onJumpButtonClicked:(id)arg1;
- (void)onJumpButtonExposure:(id)arg1;
- (void)scrollViewWillPrepareComponentView:(id)arg1 componentModel:(id)arg2;
- (void)scrollViewWillDisplayComponentView:(id)arg1 componentModel:(id)arg2;
- (_Bool)shouldResponseWithComponentView:(id)arg1 componentModel:(id)arg2;

@end
