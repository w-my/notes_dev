//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@interface MMFavComponentFactory : NSObject
{
}

+ (id)getFavNoteTitle:(id)arg1;
+ (id)getDataThumbPath:(id)arg1 largeImage:(_Bool)arg2;
+ (id)convertVoiceDurationToStrInDigits:(int)arg1;
+ (id)convertVoiceDurationToStr:(unsigned int)arg1;
+ (int)dataEnumToItemEnum:(int)arg1;
+ (double)heightForItemDataField:(id)arg1 inItem:(id)arg2;
+ (id)createComponentByItemDataField:(id)arg1 inItem:(id)arg2;
+ (id)tryNeedConvertToItemWithData:(id)arg1 inItem:(id)arg2;
+ (id)getRecordUrlDataForItem:(id)arg1 hasThumb:(_Bool)arg2;
+ (void)configRecordComData:(id)arg1 withFavItem:(id)arg2;
+ (void)configNoteComData:(id)arg1 withFavItem:(id)arg2;
+ (void)getFavNoteCellTitleAndDesc:(id)arg1 outTitle:(id *)arg2 outDesc:(id *)arg3;
+ (id)getFavTextCellText:(id)arg1;
+ (void)configUrlStyleComData:(id)arg1 withFavItem:(id)arg2;
+ (void)configMediaStyleComData:(id)arg1 withFavItem:(id)arg2;
+ (id)createComponentByFavItem:(id)arg1 showDataSize:(_Bool)arg2;
+ (double)heightForFavItem:(id)arg1;

@end

