//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class NSMutableArray, NSString, UIColor, UIFont;

@interface QSRichTextPartInfo : NSObject
{
    NSString *_text;
    UIFont *_font;
    UIColor *_textColor;
    NSMutableArray *_rects;
}

@property(retain, nonatomic) NSMutableArray *rects; // @synthesize rects=_rects;
@property(retain, nonatomic) UIColor *textColor; // @synthesize textColor=_textColor;
@property(retain, nonatomic) UIFont *font; // @synthesize font=_font;
@property(copy, nonatomic) NSString *text; // @synthesize text=_text;
- (void).cxx_destruct;
- (id)initWithString:(id)arg1;

@end

