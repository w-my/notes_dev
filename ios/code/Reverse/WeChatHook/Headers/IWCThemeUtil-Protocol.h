//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class NSArray, NSDictionary, NSMutableDictionary, NSString, UIColor, UIFont, UIImage;

@protocol IWCThemeUtil <NSObject>
+ (void)parseColorDeclarations:(NSDictionary *)arg1 toValues:(NSMutableDictionary *)arg2;
+ (UIFont *)parseFontFromValues:(NSArray *)arg1;
+ (double)parseFontSizeFromValues:(NSArray *)arg1;
+ (NSString *)parseStringFromValues:(NSArray *)arg1;
+ (double)parseFloatFromValues:(NSArray *)arg1;
+ (long long)parseIntegerFromValues:(NSArray *)arg1;
+ (_Bool)parseBOOLFromValues:(NSArray *)arg1;
+ (struct UIEdgeInsets)parseEdgeInsetsFromValues:(NSArray *)arg1;
+ (struct CGRect)parseRectFromValues:(NSArray *)arg1;
+ (struct CGSize)parseSizeFromValues:(NSArray *)arg1;
+ (struct CGPoint)parsePointFromValues:(NSArray *)arg1;
+ (UIImage *)parseStrechedImageFromValues:(NSArray *)arg1;
+ (UIColor *)parseColorFromValues:(NSArray *)arg1;
@end

