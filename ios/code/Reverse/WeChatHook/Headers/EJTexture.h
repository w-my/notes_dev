//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

#import "NSCopying.h"

@class EJFileSystem, EJSharedTextureCache, EJTextureStorage, NSBlockOperation, NSMutableData, NSString;

@interface EJTexture : NSObject <NSCopying>
{
    _Bool cached;
    _Bool drawFlippedY;
    _Bool isCompressed;
    _Bool lazyLoaded;
    _Bool dimensionsKnown;
    short width;
    short height;
    NSString *fullPath;
    EJTextureStorage *textureStorage;
    unsigned int format;
    unsigned int fbo;
    int params[4];
    NSBlockOperation *loadCallback;
    EJSharedTextureCache *textureCache;
    _Bool readOnly;
    _Bool originPixel;
    EJFileSystem *fileSystem;
}

+ (void)flipPixelsY:(char *)arg1 bytesPerRow:(int)arg2 rows:(int)arg3;
+ (void)unPremultiplyPixels:(const char *)arg1 to:(char *)arg2 byteLength:(int)arg3 format:(unsigned int)arg4 scriptView:(id)arg5;
+ (void)premultiplyPixels:(const char *)arg1 to:(char *)arg2 byteLength:(int)arg3 format:(unsigned int)arg4 scriptView:(id)arg5;
+ (id)imageWithPixels:(id)arg1 width:(int)arg2 height:(int)arg3;
+ (id)cachedTextureWithPath:(id)arg1 loadOnQueue:(id)arg2 callback:(id)arg3 cache:(id)arg4 fileSystem:(id)arg5 glContext:(id)arg6;
@property(nonatomic) _Bool originPixel; // @synthesize originPixel;
@property(readonly, nonatomic) _Bool readOnly; // @synthesize readOnly;
@property(retain, nonatomic) EJSharedTextureCache *textureCache; // @synthesize textureCache;
@property(readonly, nonatomic) _Bool lazyLoaded; // @synthesize lazyLoaded;
@property(nonatomic) _Bool drawFlippedY; // @synthesize drawFlippedY;
@property(readonly, nonatomic) unsigned int format; // @synthesize format;
- (id)image;
- (void)bindToTarget:(unsigned int)arg1;
- (void)bindWithFilter:(unsigned int)arg1;
- (void)setParam:(unsigned int)arg1 param:(unsigned int)arg2;
- (int)getParam:(unsigned int)arg1;
- (id)loadPixelsFromUIImage:(id)arg1;
- (id)loadPixelsFromPath:(id)arg1;
@property(readonly, nonatomic) NSMutableData *pixels;
- (void)updateWithPixels:(id)arg1 atX:(int)arg2 y:(int)arg3 width:(int)arg4 height:(int)arg5;
- (void)uploadCompressedPixels:(id)arg1 target:(unsigned int)arg2;
- (void)createWithPixels:(id)arg1 format:(unsigned int)arg2 target:(unsigned int)arg3;
- (void)createWithPixels:(id)arg1 format:(unsigned int)arg2;
- (void)createWithTexture:(id)arg1;
- (id)copyWithZone:(struct _NSZone *)arg1;
@property(readonly, nonatomic) short height;
@property(readonly, nonatomic) short width;
@property(readonly, nonatomic) _Bool isDynamic;
@property(readonly, nonatomic) unsigned int textureId;
@property(readonly, nonatomic) double lastUsed;
- (void)ensureMutableKeepPixels:(_Bool)arg1 forTarget:(unsigned int)arg2;
- (void)maybeReleaseStorage;
- (void)dealloc;
- (id)initWithUIImage:(id)arg1;
- (id)initAsRenderTargetWithWidth:(int)arg1 height:(int)arg2 fbo:(unsigned int)arg3;
- (id)initWithWidth:(int)arg1 height:(int)arg2 pixels:(id)arg3;
- (id)initWithWidth:(int)arg1 height:(int)arg2 format:(unsigned int)arg3;
- (id)initWithWidth:(int)arg1 height:(int)arg2;
- (id)initWithPath:(id)arg1 loadOnQueue:(id)arg2 callback:(id)arg3 fileSystem:(id)arg4 glContext:(id)arg5;
- (id)initWithPath:(id)arg1;
- (id)initEmptyForWebGL;

@end

