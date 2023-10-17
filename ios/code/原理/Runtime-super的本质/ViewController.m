//
//  ViewController.m
//  Runtime-super的本质
//
//  Created by WTW on 2019/9/20.
//  Copyright © 2019 wtw. All rights reserved.
//

#import "ViewController.h"
#import "Student.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
   
    
    Student *student = [[Student alloc] init];
    [student print];
    
}


@end
