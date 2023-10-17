//
//  CoordinatingController.h
//  TouchPainter
//
//  Created by WTW on 2019/12/13.
//  Copyright © 2019 WTW. All rights reserved.
//

/**
 * 使用中介者协调视图迁移
 * 避免对象间显式的相互引用来增进不同对象间的松耦合
 * 集中处理，对象间的依存会减少
 */

#import <Foundation/Foundation.h>
#import "CanvasViewController.h"
#import "PaletteViewController.h"
#import "ThumbnailViewController.h"

NS_ASSUME_NONNULL_BEGIN

typedef enum
{
  kButtonTagDone,
  kButtonTagOpenPaletteView,
  kButtonTagOpenThumbnailView
} ButtonTag;

@interface CoordinatingController : NSObject

@property (nonatomic, readonly) UIViewController *activeViewController;
@property (nonatomic, readonly) CanvasViewController *canvasViewController;

+ (CoordinatingController *) sharedInstance;

@end

NS_ASSUME_NONNULL_END
