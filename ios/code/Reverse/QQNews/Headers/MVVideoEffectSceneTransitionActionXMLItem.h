//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "MVVideoEffectActionXMLItem.h"

#import "NSCoding.h"

@class NSString;

@interface MVVideoEffectSceneTransitionActionXMLItem : MVVideoEffectActionXMLItem <NSCoding>
{
    NSString *_maskVideo;
}

@property(retain, nonatomic) NSString *maskVideo; // @synthesize maskVideo=_maskVideo;
- (void).cxx_destruct;
- (id)maskVideoFilePath;
- (id)initWithDictionary:(id)arg1;
- (id)initWithCoder:(id)arg1;
- (void)encodeWithCoder:(id)arg1;

@end
