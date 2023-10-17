//
//  ViewController.m
//  FFmpegTest
//
//  Created by WTW on 2022/1/25.
//

#import "ViewController.h"
#include "Mp3Encoder.hpp"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
}


- (IBAction)startEncode {
    
    Mp3Encoder  *encoder = new Mp3Encoder();
    encoder->encode();
    delete encoder;
}

@end
