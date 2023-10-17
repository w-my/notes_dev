//
//  Observer.m
//  KVC的本质
//
//  Created by WTW on 2019/7/18.
//  Copyright © 2019 wtw. All rights reserved.
//

#import "Observer.h"

@implementation Observer

- (void)observeValueForKeyPath:(NSString *)keyPath ofObject:(id)object change:(NSDictionary<NSKeyValueChangeKey,id> *)change context:(void *)context {
    NSLog(@"keyPath : %@ \n object: %@ \n  change: %@ ",keyPath,object,change);
}

/*
 keyPath : age
 object: <Person: 0x10050b970>
 change: {
     kind = 1;
     new = 20;
     old = 0;
 }
 */

@end
