//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "MMUIViewController.h"

@class NSString, UIButton, UITextView;

@interface MMDiskUsageMatchInfoViewController : MMUIViewController
{
    UITextView *_infoTextView;
    NSString *_infoString;
    UIButton *_showCurrentInfoButton;
    UIButton *_compareButton;
}

@property(retain, nonatomic) UIButton *compareButton; // @synthesize compareButton=_compareButton;
@property(retain, nonatomic) UIButton *showCurrentInfoButton; // @synthesize showCurrentInfoButton=_showCurrentInfoButton;
@property(copy, nonatomic) NSString *infoString; // @synthesize infoString=_infoString;
@property(retain, nonatomic) UITextView *infoTextView; // @synthesize infoTextView=_infoTextView;
- (void).cxx_destruct;
- (id)compareTheRootNodeInfo:(id)arg1 withBasicRootNodeInfo:(id)arg2;
- (void)sendDataToFileHelper;
- (id)getStringWithStoreTimeType:(int)arg1;
- (id)getStringWithPrefixType:(int)arg1;
- (id)getStringWithFileTypeInUse:(int)arg1;
- (id)getMatchInfoString:(id)arg1 withParentText:(id)arg2;
- (id)getRootMatchInfoString:(id)arg1;
- (void)compareMathNodeWithBasic;
- (void)showCurrentMatchInfo;
- (void)viewDidLoad;

@end
