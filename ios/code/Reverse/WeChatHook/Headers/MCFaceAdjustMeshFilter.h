//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "MCBaseFilter.h"

@class GLProgram, GPUImageFramebuffer, NSMutableArray, NSMutableDictionary;

@interface MCFaceAdjustMeshFilter : MCBaseFilter
{
    GPUImageFramebuffer *faceAdjFrameBuffer[2];
    GPUImageFramebuffer *meshFrameBuffer[2];
    GLProgram *meshProgram;
    GLProgram *faceAdjustProgram;
    int meshFilterPositionAttribute;
    int meshFilterTextureCoordinateAttribute;
    int faceAdjustFilterPositionAttribute;
    int faceAdjustFilterTextureCoordinateAttribute;
    int meshInputTextureUniform;
    int faceAdjustInputTextureUniform;
    int filterInputTextureUniform2;
    int filterInputTextureUniform3;
    unsigned int u_vType;
    unsigned int u_boundFix;
    unsigned int u_srcSize;
    unsigned int u_cropSize;
    unsigned int u_bValidTexture;
    unsigned int u_texMapSize;
    unsigned int uv_meshInfo;
    unsigned int uv_meshParam;
    unsigned int u_cos_t;
    unsigned int u_sin_t;
    unsigned int uAngles;
    unsigned int uSize;
    unsigned int uv_posV;
    unsigned int uv_paramV;
    float meshVertices[16004];
    float meshTextureCoordinates[16004];
    NSMutableArray *peopleList;
    NSMutableArray *fffList;
    float meshInformation[210];
    unsigned long long _meshGlobalOpt;
    NSMutableArray *_meshGlobalItems;
    unsigned long long _boundaryFixMode;
    double _boundaryFixStrength;
    id <TTRealTimeFaceEditProtocol> _faceEditDelegate;
    NSMutableDictionary *_mParamDict;
    long long _currentBufferIndexFaceAdj;
    long long _currentBufferIndexMesh;
    struct CGSize _rawImageSize;
    struct CGRect _faceRect;
}

@property(nonatomic) struct CGRect faceRect; // @synthesize faceRect=_faceRect;
@property(nonatomic) struct CGSize rawImageSize; // @synthesize rawImageSize=_rawImageSize;
@property(nonatomic) long long currentBufferIndexMesh; // @synthesize currentBufferIndexMesh=_currentBufferIndexMesh;
@property(nonatomic) long long currentBufferIndexFaceAdj; // @synthesize currentBufferIndexFaceAdj=_currentBufferIndexFaceAdj;
@property(retain, nonatomic) NSMutableDictionary *mParamDict; // @synthesize mParamDict=_mParamDict;
@property(nonatomic) __weak id <TTRealTimeFaceEditProtocol> faceEditDelegate; // @synthesize faceEditDelegate=_faceEditDelegate;
@property(nonatomic) double boundaryFixStrength; // @synthesize boundaryFixStrength=_boundaryFixStrength;
@property(nonatomic) unsigned long long boundaryFixMode; // @synthesize boundaryFixMode=_boundaryFixMode;
@property(retain, nonatomic) NSMutableArray *meshGlobalItems; // @synthesize meshGlobalItems=_meshGlobalItems;
@property(nonatomic) unsigned long long meshGlobalOpt; // @synthesize meshGlobalOpt=_meshGlobalOpt;
- (void).cxx_destruct;
- (void)resetPeopleList;
- (int)doReceiveData:(id)arg1 withTarget:(id)arg2;
- (void)setupEnviroment:(struct CGSize)arg1;
- (void)updateMesh;
- (void)updateParams:(id)arg1;
- (id)mergeMeshItems:(id)arg1;
- (id)globalMeshItemsArray;
- (_Bool)updateUniformsWithFaceManager:(id)arg1;
- (double)boundaryFixStrengthFactorWithDistortion:(struct MeshDistortionType)arg1 feature:(id)arg2;
- (void)renderToTextureWithVertices:(const float *)arg1 textureCoordinates:(const float *)arg2;
- (void)endWithDrawWithVertices:(const float *)arg1 textureCoordinates:(const float *)arg2;
- (id)generateEmptyBufferForPass1:(struct CGSize)arg1;
- (void)outputProgramError:(id)arg1;
- (void)initAttribute:(id)arg1;
- (void)dealloc;
- (id)init;
- (id)getFormerShaderString:(id)arg1 needExt:(_Bool)arg2;

@end

