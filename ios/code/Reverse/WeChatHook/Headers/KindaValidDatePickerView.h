//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "KindaView.h"

#import "MMKValidDatePickerView.h"
#import "UIPickerViewDataSource.h"
#import "UIPickerViewDelegate.h"
#import "UITextFieldDelegate.h"

@class MMKValidDatePickerViewOnSelectCallback, NSString, UIPickerView, WCUITextField;

@interface KindaValidDatePickerView : KindaView <MMKValidDatePickerView, UIPickerViewDelegate, UIPickerViewDataSource, UITextFieldDelegate>
{
    UIPickerView *m_pickerView;
    WCUITextField *m_textField;
    NSString *validDate;
    MMKValidDatePickerViewOnSelectCallback *m_callback;
    int m_iStartYear;
}

- (void).cxx_destruct;
- (void)UIPickerViewDidFinish;
- (void)UIPickerViewDidCancel;
- (id)pickerView:(id)arg1 viewForRow:(long long)arg2 forComponent:(long long)arg3 reusingView:(id)arg4;
- (id)pickerView:(id)arg1 titleForRow:(long long)arg2 forComponent:(long long)arg3;
- (double)pickerView:(id)arg1 widthForComponent:(long long)arg2;
- (long long)pickerView:(id)arg1 numberOfRowsInComponent:(long long)arg2;
- (long long)numberOfComponentsInPickerView:(id)arg1;
- (id)getText;
- (void)setOnSelectCallback:(id)arg1;
- (id)getView;
- (_Bool)getFocus;
- (void)setFocus:(_Bool)arg1;
- (id)init;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

