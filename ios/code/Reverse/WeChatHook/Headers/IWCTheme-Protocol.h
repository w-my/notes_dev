//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class NSArray, NSDictionary, NSString, UIColor, UIImage;

@protocol IWCTheme <NSObject>
+ (void)reloadCssForMultiTaskingIfNeed;
+ (NSString *)pathOfResNamed:(NSString *)arg1;
+ (NSString *)getImageName:(UIImage *)arg1;
+ (UIImage *)svgImageDisableNamed:(NSString *)arg1 size:(struct CGSize)arg2 color:(UIColor *)arg3;
+ (UIImage *)svgImageHighlightNamed:(NSString *)arg1 size:(struct CGSize)arg2 color:(UIColor *)arg3;
+ (UIImage *)svgImageNamed:(NSString *)arg1 size:(struct CGSize)arg2 color:(UIColor *)arg3;
+ (UIImage *)svgImageNamed:(NSString *)arg1 color:(UIColor *)arg2;
+ (UIImage *)localizedImageNamed:(NSString *)arg1;
+ (UIImage *)imageFromColor:(UIColor *)arg1;
+ (UIImage *)imageDisableNamed:(NSString *)arg1;
+ (UIImage *)imageHighlightNamed:(NSString *)arg1;
+ (UIImage *)imageNamed:(NSString *)arg1 alpha:(double)arg2;
+ (UIImage *)imageNamed:(NSString *)arg1;
+ (UIColor *)getColorByName:(NSString *)arg1 withAlpha:(double)arg2;
+ (UIColor *)getColorByName:(NSString *)arg1;
+ (NSDictionary *)getRuleSetForSeletor:(NSString *)arg1;
+ (NSArray *)getValueOfProperty:(NSString *)arg1 inRuleSet:(NSString *)arg2;
@end

