//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

#import "NSCoding.h"

@class NSString;

@interface QNModuleDocumentaryCellVideo : NSObject <NSCoding>
{
    NSString *_vid;
    NSString *_videoTitle;
    NSString *_pictureURL;
}

@property(copy, nonatomic) NSString *pictureURL; // @synthesize pictureURL=_pictureURL;
@property(copy, nonatomic) NSString *videoTitle; // @synthesize videoTitle=_videoTitle;
@property(copy, nonatomic) NSString *vid; // @synthesize vid=_vid;
- (void).cxx_destruct;
- (void)encodeWithCoder:(id)arg1;
- (id)initWithCoder:(id)arg1;

@end

