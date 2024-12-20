//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@interface MMITransmitKvData : NSObject
{
    struct Handle<std::__1::shared_ptr<kinda::ITransmitKvData>> _cppRefHandle;
}

+ (id)create;
- (id).cxx_construct;
- (void).cxx_destruct;
- (id)getStringList:(id)arg1;
- (id)getLongList:(id)arg1;
- (id)getBoolList:(id)arg1;
- (id)getIntList:(id)arg1;
- (id)getKvData:(id)arg1;
- (id)getJSEvent:(id)arg1;
- (id)getBinary:(id)arg1;
- (id)getString:(id)arg1;
- (long long)getLong:(id)arg1;
- (_Bool)getBool:(id)arg1;
- (int)getInt:(id)arg1;
- (void)putListString:(id)arg1 val:(id)arg2;
- (void)putListLong:(id)arg1 val:(id)arg2;
- (void)putListBool:(id)arg1 val:(id)arg2;
- (void)putListInt:(id)arg1 val:(id)arg2;
- (void)putKvData:(id)arg1 val:(id)arg2;
- (void)putJSEvent:(id)arg1 val:(id)arg2;
- (void)putBinary:(id)arg1 val:(id)arg2;
- (void)putString:(id)arg1 val:(id)arg2;
- (void)putLong:(id)arg1 val:(long long)arg2;
- (void)putBool:(id)arg1 val:(_Bool)arg2;
- (void)putInt:(id)arg1 val:(int)arg2;
- (id)allKeys;
- (id)initWithCpp:(const shared_ptr_01c13d64 *)arg1;

@end

