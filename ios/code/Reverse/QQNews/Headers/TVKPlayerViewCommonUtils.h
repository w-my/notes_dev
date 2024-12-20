//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class NSMutableDictionary;

@interface TVKPlayerViewCommonUtils : NSObject
{
    NSMutableDictionary *_pixelFormatNames;
    NSMutableDictionary *_VRModeNames;
    NSMutableDictionary *_VRInteractiveTypeNames;
    NSMutableDictionary *_pictureTypeNames;
    NSMutableDictionary *_colorSpaceNames;
    NSMutableDictionary *_renderTypeNames;
}

+ (id)sharedInstance;
- (void).cxx_destruct;
- (id)makeRenderTypeName:(long long)arg1;
- (id)makeColorSpaceName:(long long)arg1;
- (id)makePictureTypeName:(long long)arg1;
- (id)makeVRInteractiveTypeName:(long long)arg1;
- (id)makeVRModeName:(long long)arg1;
- (id)makePixelFormatName:(long long)arg1;
- (void)dealloc;
- (id)init;

@end

