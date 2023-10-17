//
//  ViewController.m
//  15-@synthesize还有哪些使用场景
//
//  Created by WTW on 2020/3/11.
//  Copyright © 2020 WTW. All rights reserved.
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
    
    person.name = @"JACK";
    
    NSLog(@"%@",person.name);
}


@end
