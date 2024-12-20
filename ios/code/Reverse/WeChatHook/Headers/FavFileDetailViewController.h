//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "FileDetailViewController.h"

#import "FavClickStreamHelperDelegete.h"

@class FavClickStreamHelper, FavoritesBrowseDetailReportData, NSString;

@interface FavFileDetailViewController : FileDetailViewController <FavClickStreamHelperDelegete>
{
    unsigned int m_favId;
    _Bool _needReload;
    FavoritesBrowseDetailReportData *_reportData;
    FavClickStreamHelper *_clickHelper;
}

@property(retain, nonatomic) FavClickStreamHelper *clickHelper; // @synthesize clickHelper=_clickHelper;
@property(retain, nonatomic) FavoritesBrowseDetailReportData *reportData; // @synthesize reportData=_reportData;
@property(nonatomic) _Bool needReload; // @synthesize needReload=_needReload;
- (void).cxx_destruct;
- (id)sessionId;
- (void)viewWillAppear:(_Bool)arg1;
- (void)viewWillDisappear:(_Bool)arg1;
- (void)viewDidBePoped:(_Bool)arg1;
- (id)initWithFavDataWrap:(id)arg1;
- (id)initWithFavItem:(id)arg1 LogicController:(id)arg2;
- (id)initWithFavItem:(id)arg1;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

