//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

#import "NSCoding.h"

@class NSString;

@interface CArticleContentNodeType : NSObject <NSCoding>
{
    long long _type;
    NSString *_value;
    NSString *_nodeKey;
    struct CGRect _detailComponentFrame;
}

@property(nonatomic) struct CGRect detailComponentFrame; // @synthesize detailComponentFrame=_detailComponentFrame;
@property(copy, nonatomic) NSString *nodeKey; // @synthesize nodeKey=_nodeKey;
@property(copy) NSString *value; // @synthesize value=_value;
@property long long type; // @synthesize type=_type;
- (void).cxx_destruct;
- (id)description;
- (void)encodeWithCoder:(id)arg1;
- (id)initWithCoder:(id)arg1;
- (void)reset;
- (id)initWithInfo:(id)arg1;
- (id)init;

@end
