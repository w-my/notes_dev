//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "MVVideoEffectActionXMLItem.h"

#import "NSCoding.h"

@interface MVVideoEffectMirrorActionXMLItem : MVVideoEffectActionXMLItem <NSCoding>
{
    _Bool _horizontally;
    _Bool _vertically;
}

@property(nonatomic) _Bool vertically; // @synthesize vertically=_vertically;
@property(nonatomic) _Bool horizontally; // @synthesize horizontally=_horizontally;
- (id)initWithDictionary:(id)arg1;
- (id)initWithCoder:(id)arg1;
- (void)encodeWithCoder:(id)arg1;

@end

