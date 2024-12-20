//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "SKStoreProductViewController.h"

@class QNBaseLabel, UIActivityIndicatorView;

@interface CSKStoreProductViewController : SKStoreProductViewController
{
    _Bool _loadFinished;
    UIActivityIndicatorView *_loadingView;
    QNBaseLabel *_textLabel;
}

@property(nonatomic) _Bool loadFinished; // @synthesize loadFinished=_loadFinished;
@property(retain, nonatomic) QNBaseLabel *textLabel; // @synthesize textLabel=_textLabel;
@property(retain, nonatomic) UIActivityIndicatorView *loadingView; // @synthesize loadingView=_loadingView;
- (void).cxx_destruct;
- (void)stopLoading;
- (void)startLoading;
- (void)viewDidLoad;
- (unsigned long long)supportedInterfaceOrientations;
- (_Bool)shouldAutorotate;
- (void)viewWillDisappear:(_Bool)arg1;
- (void)viewWillAppear:(_Bool)arg1;

@end

