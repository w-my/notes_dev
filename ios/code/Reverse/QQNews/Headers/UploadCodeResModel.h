//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class NSString;

@interface UploadCodeResModel : NSObject
{
    long long _em;
    NSString *_msg;
    NSString *_s;
    NSString *_vid;
    NSString *_fid;
}

@property(retain, nonatomic) NSString *fid; // @synthesize fid=_fid;
@property(retain, nonatomic) NSString *vid; // @synthesize vid=_vid;
@property(retain, nonatomic) NSString *s; // @synthesize s=_s;
@property(retain, nonatomic) NSString *msg; // @synthesize msg=_msg;
@property(nonatomic) long long em; // @synthesize em=_em;
- (void).cxx_destruct;
- (id)initWithDic:(id)arg1;

@end

