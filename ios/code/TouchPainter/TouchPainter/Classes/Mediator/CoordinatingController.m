//
//  CoordinatingController.m
//  TouchPainter
//
//  Created by WTW on 2019/12/13.
//  Copyright © 2019 WTW. All rights reserved.
//

#import "CoordinatingController.h"

@interface CoordinatingController ()

@property (nonatomic, readwrite) UIViewController *activeViewController;
@property (nonatomic, readwrite) CanvasViewController *canvasViewController;
@end

static CoordinatingController *sharedCoordinator = nil;

@implementation CoordinatingController

+ (CoordinatingController *)sharedInstance {
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        sharedCoordinator = [[CoordinatingController alloc] init];
    });
    return sharedCoordinator;
}

#pragma mark -
#pragma mark A method for view transitions
- (void) requestViewChangeByObject:(id)object {
    if ([object isKindOfClass:[UIBarButtonItem class]]) {
        switch ([(UIBarButtonItem *)object tag]) {
            case kButtonTagOpenPaletteView:{
                PaletteViewController *controller = [[PaletteViewController alloc] init];
                [_canvasViewController presentViewController:controller animated:YES completion:nil];
                _activeViewController = controller;
            }
                break;
            case kButtonTagOpenThumbnailView:{
               ThumbnailViewController *controller = [[ThumbnailViewController alloc] init];
               [_canvasViewController presentViewController:controller animated:YES completion:nil];
               _activeViewController = controller;
            }
                break;
            default:{
                [_canvasViewController dismissViewControllerAnimated:YES completion:nil];
                _activeViewController = _canvasViewController;
            }
                break;
        }
    }else {
        [_canvasViewController dismissViewControllerAnimated:YES completion:nil];
        _activeViewController = _canvasViewController;
    }
}

- (CanvasViewController *)canvasViewController {
    if (!_canvasViewController) {
        _canvasViewController = [[CanvasViewController alloc] init];
    }
    return _canvasViewController;
}

- (UIViewController *)activeViewController {
    if (!_activeViewController) {
        _activeViewController = [[UIViewController alloc] init];
    }
    return _activeViewController;
}

@end
