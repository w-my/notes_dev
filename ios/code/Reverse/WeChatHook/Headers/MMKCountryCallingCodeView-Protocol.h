//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "MMKView.h"

@class MMKCountryCallingCodeViewOnSelectCallback, NSArray, NSString;

@protocol MMKCountryCallingCodeView <MMKView>
- (void)setOnSelectCallback:(MMKCountryCallingCodeViewOnSelectCallback *)arg1;
- (NSString *)getPlaceHolder;
- (void)setPlaceHolder:(NSString *)arg1;
- (_Bool)getHideCode;
- (void)setHideCode:(_Bool)arg1;
- (NSString *)getNationality;
- (void)setNationality:(NSString *)arg1;
- (NSString *)getCountryCode;
- (void)setCountryCode:(NSString *)arg1;
- (_Bool)getFocus;
- (void)setFocus:(_Bool)arg1;
- (void)setNationalityExcludeArray:(NSArray *)arg1;
@end
