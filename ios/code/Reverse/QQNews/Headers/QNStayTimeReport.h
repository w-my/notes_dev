//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class NSDate, NSString;

@interface QNStayTimeReport : NSObject
{
    NSString *_pageTagId;
    NSDate *_enterDate;
}

@property(retain, nonatomic) NSDate *enterDate; // @synthesize enterDate=_enterDate;
@property(copy, nonatomic) NSString *pageTagId; // @synthesize pageTagId=_pageTagId;
- (void).cxx_destruct;
- (void)leavePage;
- (void)enterPage;
- (id)initWithPageTagId:(id)arg1;

@end
