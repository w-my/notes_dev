//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QSStatedData.h"

@interface QSComAllCircleListData : QSStatedData
{
    _Bool _notShowFollow;
    _Bool _showOwn;
}

+ (_Bool)cleanCacheWhenUserChanged;
@property(nonatomic) _Bool showOwn; // @synthesize showOwn=_showOwn;
@property(nonatomic) _Bool notShowFollow; // @synthesize notShowFollow=_notShowFollow;
- (void)resetWithResponseModel:(id)arg1;
- (id)httpURLComponents;
- (id)identifier;

@end
