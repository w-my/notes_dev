//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNDetailImageProgressView.h"

#import "QNAdProgressViewProtocol.h"

@class NSString;

@interface QNAdBarProgressView : QNDetailImageProgressView <QNAdProgressViewProtocol>
{
    id <QNAdProgressControlDelegate> _progressControlDelegate;
}

@property(nonatomic) __weak id <QNAdProgressControlDelegate> progressControlDelegate; // @synthesize progressControlDelegate=_progressControlDelegate;
- (void).cxx_destruct;
- (void)p_onCancelProgress:(id)arg1;
- (void)updateCurrent:(unsigned long long)arg1 Total:(unsigned long long)arg2;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

