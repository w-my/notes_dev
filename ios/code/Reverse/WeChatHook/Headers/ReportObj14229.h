//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class NSDictionary, NSString;

@interface ReportObj14229 : NSObject
{
    _Bool _isRange;
    int _errorCode;
    int _optType;
    int _costTime;
    int _fileSize;
    NSString *_pkgId;
    NSString *_pkgVersion;
    NSDictionary *_extInfo;
    NSString *_localVersion;
}

+ (id)createFromDownloadInfo:(id)arg1;
@property(nonatomic) int fileSize; // @synthesize fileSize=_fileSize;
@property(nonatomic) int costTime; // @synthesize costTime=_costTime;
@property(nonatomic) int optType; // @synthesize optType=_optType;
@property(retain, nonatomic) NSString *localVersion; // @synthesize localVersion=_localVersion;
@property(retain, nonatomic) NSDictionary *extInfo; // @synthesize extInfo=_extInfo;
@property(nonatomic) int errorCode; // @synthesize errorCode=_errorCode;
@property(nonatomic) _Bool isRange; // @synthesize isRange=_isRange;
@property(retain, nonatomic) NSString *pkgVersion; // @synthesize pkgVersion=_pkgVersion;
@property(retain, nonatomic) NSString *pkgId; // @synthesize pkgId=_pkgId;
- (void).cxx_destruct;
- (id)toLogExt;
- (id)init;

@end
