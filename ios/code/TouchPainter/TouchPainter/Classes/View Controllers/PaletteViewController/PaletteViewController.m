//
//  PaletteViewController.m
//  TouchPainter
//
//  Created by WTW on 2019/12/13.
//  Copyright © 2019 WTW. All rights reserved.
//

#import "PaletteViewController.h"

@interface PaletteViewController ()

@end

@implementation PaletteViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    self.view.backgroundColor = [UIColor whiteColor];
    self.title = NSStringFromClass([self class]);
    
    self.navigationItem.rightBarButtonItem = [[UIBarButtonItem alloc] initWithTitle:@"Done" style:UIBarButtonItemStyleDone target:self action:@selector(DoneClick)];
    
    // Do any additional setup after loading the view from its nib.
}

- (void)DoneClick {
    
}

@end
