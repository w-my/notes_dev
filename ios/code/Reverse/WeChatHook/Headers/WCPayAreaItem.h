//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "WCBaseTextFieldItem.h"

#import "MMRegionPickerViewControllerDelegate.h"
#import "WCPayRegionPickerViewControllerDelegate.h"

@class MMUIViewController, NSString;

@interface WCPayAreaItem : WCBaseTextFieldItem <WCPayRegionPickerViewControllerDelegate, MMRegionPickerViewControllerDelegate>
{
    MMUIViewController *m_currentViewController;
    NSString *m_country;
    NSString *m_province;
    NSString *m_city;
    _Bool _disableLocation;
    _Bool _chinaFirst;
    _Bool _openSearch;
    id <WCPayAreaItemDelegate> m_payAreaItemDelegate;
}

@property(nonatomic) _Bool openSearch; // @synthesize openSearch=_openSearch;
@property(nonatomic) _Bool chinaFirst; // @synthesize chinaFirst=_chinaFirst;
@property(nonatomic) _Bool disableLocation; // @synthesize disableLocation=_disableLocation;
@property(nonatomic) __weak id <WCPayAreaItemDelegate> m_payAreaItemDelegate; // @synthesize m_payAreaItemDelegate;
- (void).cxx_destruct;
- (void)picker:(id)arg1 didPick:(id)arg2;
- (void)dealloc;
- (void)MMRegionPickerDidChoosRegion:(id)arg1;
- (void)setCountry:(id)arg1 province:(id)arg2 city:(id)arg3;
- (void)becomeFirstResponder;
- (id)getCity;
- (id)getProvince;
- (id)getCountry;
- (_Bool)isUSorCA;
- (void)setCurrentViewController:(id)arg1;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

