//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class TLNComponentBase, TLNEvent;

@interface TLNEventContext : NSObject
{
    id _sender;
    TLNEvent *_event;
    TLNComponentBase *_view;
}

@property(nonatomic) __weak TLNComponentBase *view; // @synthesize view=_view;
@property(nonatomic) __weak TLNEvent *event; // @synthesize event=_event;
@property(nonatomic) __weak id sender; // @synthesize sender=_sender;
- (void).cxx_destruct;

@end
