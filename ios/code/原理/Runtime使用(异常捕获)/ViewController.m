//
//  ViewController.m
//  Runtime使用(异常捕获)
//
//  Created by WTW on 2020/3/8.
//  Copyright © 2020 wtw. All rights reserved.
//

#import "ViewController.h"
#import "Person.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
}

- (void)touchesBegan:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event {
    
    Person *person = [[Person alloc] init];
    
    [person test1];
    [person test2];
    [person test3];
    
}

@end
