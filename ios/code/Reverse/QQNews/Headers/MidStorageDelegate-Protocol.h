//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class MidKeytrainIdentifer, MidStorageModel, NSString;

@protocol MidStorageDelegate <NSObject>
- (void)resetMidStorageModelNilProperty;
- (void)writeMidStorageModel:(MidStorageModel *)arg1;
- (MidStorageModel *)readMidStorageModel;
- (MidStorageModel *)quickReadMidStorageModel;
- (id)initWithAppInfo:(NSString *)arg1;

@optional
- (MidKeytrainIdentifer *)generateIdentifierByType:(int)arg1;
@end

