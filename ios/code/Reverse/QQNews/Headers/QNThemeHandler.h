//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class NSString;

@interface QNThemeHandler : NSObject
{
    struct NSString *_themeVersion;
    long long _mode;
}

+ (struct NSString *)themeVersionWithMode:(long long)arg1;
+ (id)sharedInstance;
@property(nonatomic) long long mode; // @synthesize mode=_mode;
@property(retain, nonatomic) NSString *themeVersion; // @synthesize themeVersion=_themeVersion;
- (void).cxx_destruct;
- (void)exchangeTheme;
- (void)night;
- (void)day;
@property(readonly, nonatomic) _Bool isDayTheme;
- (id)init;

@end
