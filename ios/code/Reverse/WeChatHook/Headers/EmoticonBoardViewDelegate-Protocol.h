//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class MMUIViewController;

@protocol EmoticonBoardViewDelegate <NSObject>

@optional
- (_Bool)handleAddCameraEmoji;
- (void)OnEmoticonStateDidChanged:(_Bool)arg1;
- (MMUIViewController *)GetCurrentViewController;
- (void)onSendButtonClicked;
@end

