//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class NSString;

@interface TVDLProxyCGIThumbInfo : NSObject
{
    int _thumbC;
    int _thumbH;
    int _thumbW;
    int _thumbR;
    int _thumbFmt;
    int _thumbCd;
    NSString *_thumbFn;
    NSString *_thumbUrl;
}

+ (id)initThumbInfo:(id)arg1;
@property(copy, nonatomic) NSString *thumbUrl; // @synthesize thumbUrl=_thumbUrl;
@property(copy, nonatomic) NSString *thumbFn; // @synthesize thumbFn=_thumbFn;
@property(nonatomic) int thumbCd; // @synthesize thumbCd=_thumbCd;
@property(nonatomic) int thumbFmt; // @synthesize thumbFmt=_thumbFmt;
@property(nonatomic) int thumbR; // @synthesize thumbR=_thumbR;
@property(nonatomic) int thumbW; // @synthesize thumbW=_thumbW;
@property(nonatomic) int thumbH; // @synthesize thumbH=_thumbH;
@property(nonatomic) int thumbC; // @synthesize thumbC=_thumbC;
- (void).cxx_destruct;

@end

