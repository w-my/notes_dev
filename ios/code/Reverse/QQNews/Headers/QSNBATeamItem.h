//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QSModel.h"

@class NSString;

@interface QSNBATeamItem : QSModel
{
    _Bool _checked;
    NSString *_teamId;
    NSString *_name;
    NSString *_badge;
}

@property(retain, nonatomic) NSString *badge; // @synthesize badge=_badge;
@property(retain, nonatomic) NSString *name; // @synthesize name=_name;
@property(retain, nonatomic) NSString *teamId; // @synthesize teamId=_teamId;
@property(nonatomic) _Bool checked; // @synthesize checked=_checked;
- (void).cxx_destruct;

@end

