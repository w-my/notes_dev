//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class MMUIView<WASubscriptionMessagePageSheetContentViewProtocol>;

@protocol WASubscriptionMessagePageSheetContentViewDelegate <NSObject>
- (void)onContentViewClickInfoButton:(MMUIView<WASubscriptionMessagePageSheetContentViewProtocol> *)arg1 atIndex:(unsigned long long)arg2;
- (void)onContentViewDecline:(MMUIView<WASubscriptionMessagePageSheetContentViewProtocol> *)arg1;
- (void)onContentViewCancel:(MMUIView<WASubscriptionMessagePageSheetContentViewProtocol> *)arg1;
- (void)onContentViewConfirm:(MMUIView<WASubscriptionMessagePageSheetContentViewProtocol> *)arg1;
@end

