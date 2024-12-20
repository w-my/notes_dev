//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

#import "NSCoding.h"

@class NSString;

@interface CCarAbsInfo : NSObject <NSCoding>
{
    _Bool _isGold;
    _Bool _isPromote;
    NSString *_fserialId;
    NSString *_fserialName;
    NSString *_fserialPic;
    NSString *_fprice;
    NSString *_brandId;
    NSString *_brandName;
    NSString *_level;
    NSString *_fstructure;
    NSString *_manuid;
    NSString *_fSerialPrice;
    NSString *_fSerialLevel;
    long long _viewNum;
    long long _rangeList;
    NSString *_askPriceUrl;
    NSString *_daikuanUrl;
}

@property(copy, nonatomic) NSString *daikuanUrl; // @synthesize daikuanUrl=_daikuanUrl;
@property(copy, nonatomic) NSString *askPriceUrl; // @synthesize askPriceUrl=_askPriceUrl;
@property(nonatomic) long long rangeList; // @synthesize rangeList=_rangeList;
@property(nonatomic) long long viewNum; // @synthesize viewNum=_viewNum;
@property(nonatomic) _Bool isPromote; // @synthesize isPromote=_isPromote;
@property(nonatomic) _Bool isGold; // @synthesize isGold=_isGold;
@property(copy, nonatomic) NSString *fSerialLevel; // @synthesize fSerialLevel=_fSerialLevel;
@property(copy, nonatomic) NSString *fSerialPrice; // @synthesize fSerialPrice=_fSerialPrice;
@property(copy, nonatomic) NSString *manuid; // @synthesize manuid=_manuid;
@property(copy, nonatomic) NSString *fstructure; // @synthesize fstructure=_fstructure;
@property(copy, nonatomic) NSString *level; // @synthesize level=_level;
@property(copy, nonatomic) NSString *brandName; // @synthesize brandName=_brandName;
@property(copy, nonatomic) NSString *brandId; // @synthesize brandId=_brandId;
@property(copy, nonatomic) NSString *fprice; // @synthesize fprice=_fprice;
@property(copy, nonatomic) NSString *fserialPic; // @synthesize fserialPic=_fserialPic;
@property(copy, nonatomic) NSString *fserialName; // @synthesize fserialName=_fserialName;
@property(copy, nonatomic) NSString *fserialId; // @synthesize fserialId=_fserialId;
- (void).cxx_destruct;
- (id)initWithCoder:(id)arg1;
- (void)encodeWithCoder:(id)arg1;
- (void)dealloc;
- (id)initWithInfoDic:(id)arg1;

@end

