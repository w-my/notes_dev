//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class NSData, NSMutableData, NSNumberFormatter;

@interface PBCoder : NSObject
{
    id <PBCoding> m_obj;
    _Bool m_isTopObject;
    NSData *m_inputData;
    struct CodedInputData *m_inputStream;
    NSNumberFormatter *m_numberFormatter;
    NSMutableData *m_outputData;
    struct CodedOutputData *m_outputStream;
    struct vector<PBEncodeItem, std::__1::allocator<PBEncodeItem>> *m_encodeItems;
}

+ (_Bool)appendDictionary:(id)arg1 toData:(id)arg2;
+ (_Bool)appendSet:(id)arg1 toData:(id)arg2;
+ (_Bool)appendArray:(id)arg1 toData:(id)arg2;
+ (_Bool)appendOneDictionaryValue:(id)arg1 forKey:(id)arg2 toData:(id)arg3;
+ (_Bool)appendOneSetValue:(id)arg1 toData:(id)arg2;
+ (_Bool)appendOneArrayValue:(id)arg1 toData:(id)arg2;
+ (_Bool)appendDictionary:(id)arg1 toFile:(id)arg2;
+ (_Bool)appendSet:(id)arg1 toFile:(id)arg2;
+ (_Bool)appendArray:(id)arg1 toFile:(id)arg2;
+ (_Bool)appendOneDictionaryValue:(id)arg1 forKey:(id)arg2 toFile:(id)arg3;
+ (_Bool)appendOneSetValue:(id)arg1 toFile:(id)arg2;
+ (_Bool)appendOneArrayValue:(id)arg1 toFile:(id)arg2;
+ (long long)getFiLeSize:(id)arg1;
+ (_Bool)appendData:(id)arg1 toPath:(id)arg2;
+ (id)decodeContainerOfClass:(Class)arg1 withValueClass:(Class)arg2 fromData:(id)arg3;
+ (id)decodeContainerOfClass:(Class)arg1 withValueClass:(Class)arg2 fromFile:(id)arg3;
+ (_Bool)decodeObject:(id)arg1 fromData:(id)arg2;
+ (_Bool)decodeObject:(id)arg1 fromFile:(id)arg2;
+ (id)decodeObjectOfClass:(Class)arg1 fromData:(id)arg2;
+ (id)decodeObjectOfClass:(Class)arg1 fromFile:(id)arg2;
+ (_Bool)encodeObject:(id)arg1 toFile:(id)arg2;
+ (id)encodeDataWithSizeForObject:(id)arg1;
+ (id)encodeDataWithObject:(id)arg1;
+ (_Bool)decodeObject:(id)arg1 fromData:(id)arg2 withProperty:(id)arg3 andTagIndexMap:(const map_f8690629 *)arg4;
+ (_Bool)encodeObject:(id)arg1 withPropertyTable:(id)arg2 toFile:(id)arg3;
+ (id)encodeObject:(id)arg1 withPropertyTable:(id)arg2;
- (void).cxx_destruct;
- (id)decodeOneObject:(id)arg1 withProperty:(id)arg2 andTagIndexMap:(const map_f8690629 *)arg3;
- (id)decodeOneObject:(id)arg1 ofClass:(Class)arg2;
- (void)decodeObject:(id)arg1 withProperty:(id)arg2 andTagIndexMap:(const map_f8690629 *)arg3;
- (void)decodeOneProperty:(id)arg1 ofObject:(id)arg2;
- (void)decodeOne_C_Property:(id)arg1 ofObject:(id)arg2;
- (id)decodeOneDictionaryOfValueClass:(Class)arg1 orValueCType:(int)arg2 ignoreSize:(_Bool)arg3;
- (id)decodeOneSetOfValueClass:(Class)arg1 orValueCType:(int)arg2 ignoreSize:(_Bool)arg3;
- (id)decodeOneArrayOfValueClass:(Class)arg1 orValueCType:(int)arg2 ignoreSize:(_Bool)arg3;
- (id)decodeOneValueOfCType:(int)arg1;
- (id)getEncodeDataWithPropertyTable:(id)arg1;
- (id)getEncodeDataWithForceWriteSize:(_Bool)arg1;
- (unsigned long long)prepareObjectForEncode:(id)arg1 withPropertyType:(id)arg2;
- (unsigned long long)preparePBObjectForEncode:(id)arg1 withPropertyTable:(id)arg2;
- (unsigned long long)prepareUnPackedContainerForEncode:(id)arg1 withPropertyIndex:(int)arg2 withSubCType:(int)arg3;
- (unsigned long long)prepareBasicObjectForEncode:(id)arg1 withPropertyType:(id)arg2;
- (unsigned long long)prepareCValueForEndcode:(int)arg1 withValue:(id)arg2 withTag:(unsigned int)arg3;
- (unsigned long long)prepareCPropertyForEndcode:(id)arg1 withTarget:(id)arg2;
- (void)writeRootObject;
- (void)dealloc;
- (id)initForWritingWithTarget:(id)arg1;
- (id)initForReadingWithData:(id)arg1;

@end

