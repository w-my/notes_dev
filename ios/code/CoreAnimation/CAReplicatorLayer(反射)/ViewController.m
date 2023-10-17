//
//  ViewController.m
//  CAReplicatorLayer(反射)
//
//  Created by wtw on 2019/1/28.
//  Copyright © 2019 wtw. All rights reserved.
//

#import "ViewController.h"
#import "ReflectionView.h"

@interface ViewController ()
@property (nonatomic,strong) ReflectionView *reflectView;

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    
    [self.view addSubview:self.reflectView];
    
    UILabel *label = [[UILabel alloc] initWithFrame:CGRectMake(0, 0, 300, 150)];
    [self.reflectView addSubview:label];
    label.textColor = [UIColor redColor];
    label.font = [UIFont systemFontOfSize:50];
    label.text = @"HELLO";
    
//    label.backgroundColor = [UIColor whiteColor];
}
- (IBAction)changeColor {
}


- (ReflectionView *)reflectView {
    if (!_reflectView) {
        _reflectView = [[ReflectionView alloc] initWithFrame:CGRectMake(100, 100, 330, 150)];
        _reflectView.backgroundColor = [UIColor lightGrayColor];
    }
    return  _reflectView;
}

@end
