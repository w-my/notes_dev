//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class UIView;

@interface WCAnchor : NSObject
{
    UIView *_view;
    int _type;
    struct CGPoint _offset;
}

- (void).cxx_destruct;
- (struct CGPoint)point;
- (id)view;
- (CDUnknownBlockType)offsetBy;
- (id)initWithView:(id)arg1 type:(int)arg2;

@end

