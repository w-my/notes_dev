//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class NSMutableDictionary;

@interface ACServiceFactory : NSObject
{
    NSMutableDictionary *_serviceStorage;
}

+ (id)sharedInstance;
@property(retain, nonatomic) NSMutableDictionary *serviceStorage; // @synthesize serviceStorage=_serviceStorage;
- (void).cxx_destruct;
- (id)newServiceWithIdentifier:(id)arg1;
- (id)serviceWithIdentifier:(id)arg1;

@end
