//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "MMKView.h"

@class MMKMoneyInputTextOnTextChangedCallback, MMKMoneyInputTextOnkeyBoardVisibleAnchorCallback, NSString;

@protocol MMKMoneyInputText <MMKView>
- (void)setOnkeyBoardVisibleAnchorCallback:(MMKMoneyInputTextOnkeyBoardVisibleAnchorCallback *)arg1;
- (void)setOnTextChangedCallback:(MMKMoneyInputTextOnTextChangedCallback *)arg1;
- (_Bool)getFocus;
- (void)setFocus:(_Bool)arg1;
- (NSString *)getInputText;
- (void)setInputText:(NSString *)arg1;
- (NSString *)getTitle;
- (void)setTitle:(NSString *)arg1;
@end
