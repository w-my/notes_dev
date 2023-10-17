//
//  main.m
//  RunLoop 基本概念
//
//  Created by WTW on 2019/8/15.
//  Copyright © 2019 wtw. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "AppDelegate.h"

int main(int argc, char * argv[]) {
    @autoreleasepool {
        
//         NSRunLoop *runloop = [NSRunLoop currentRunLoop];
//         CFRunLoopRef runloop = CFRunLoopGetMain();
        
//        NSLog(@"currentRunLoop:%@ \n mainRunLoop: %@",[NSRunLoop currentRunLoop],[NSRunLoop mainRunLoop]);
//        NSLog(@"%@ \n %@",CFRunLoopGetCurrent() ,CFRunLoopGetMain());

        /*
        currentRunLoop:<CFRunLoop 0x600000264100 [0x10480eae8]>{wakeup port = 0x1103, stopped = false, ignoreWakeUps = true,
            current mode = (none),
            common modes = <CFBasicHash 0x600003027810 [0x10480eae8]>{type = mutable set, count = 1,
                entries =>
                2 : <CFString 0x104820ed8 [0x10480eae8]>{contents = "kCFRunLoopDefaultMode"}
            }
            ,
            common mode items = (null),
            modes = <CFBasicHash 0x600003027840 [0x10480eae8]>{type = mutable set, count = 1,
                entries =>
                2 : <CFRunLoopMode 0x6000005680d0 [0x10480eae8]>{name = kCFRunLoopDefaultMode, port set = 0x1003, queue = 0x600001064380, source = 0x600001064480 (not fired), timer port = 0x1503,
                    sources0 = (null),
                    sources1 = (null),
                    observers = (null),
                    timers = (null),
                    currently 587550909 (340514026177470) / soft deadline in: 1.84464036e+10 sec (@ -1) / hard deadline in: 1.84464036e+10 sec (@ -1)
                },
         
            }
        }
         
        mainRunLoop: <CFRunLoop 0x600000264100 [0x10480eae8]>{wakeup port = 0x1103, stopped = false, ignoreWakeUps = true,
            current mode = (none),
            common modes = <CFBasicHash 0x600003027810 [0x10480eae8]>{type = mutable set, count = 1,
                entries =>
                2 : <CFString 0x104820ed8 [0x10480eae8]>{contents = "kCFRunLoopDefaultMode"}
            }
            ,
            common mode items = (null),
            modes = <CFBasicHash 0x600003027840 [0x10480eae8]>{type = mutable set, count = 1,
                entries =>
                2 : <CFRunLoopMode 0x6000005680d0 [0x10480eae8]>{name = kCFRunLoopDefaultMode, port set = 0x1003, queue = 0x600001064380, source = 0x600001064480 (not fired), timer port = 0x1503,
                    sources0 = (null),
                    sources1 = (null),
                    observers = (null),
                    timers = (null),
                    currently 587550909 (340514026351264) / soft deadline in: 1.84464036e+10 sec (@ -1) / hard deadline in: 1.84464036e+10 sec (@ -1)
                },
         
            }
        }
         
            <CFRunLoop 0x600000264100 [0x10480eae8]>{wakeup port = 0x1103, stopped = false, ignoreWakeUps = true,
                current mode = (none),
                common modes = <CFBasicHash 0x600003027810 [0x10480eae8]>{type = mutable set, count = 1,
                    entries =>
                    2 : <CFString 0x104820ed8 [0x10480eae8]>{contents = "kCFRunLoopDefaultMode"}
                }
                ,
                common mode items = (null),
                modes = <CFBasicHash 0x600003027840 [0x10480eae8]>{type = mutable set, count = 1,
                    entries =>
                    2 : <CFRunLoopMode 0x6000005680d0 [0x10480eae8]>{name = kCFRunLoopDefaultMode, port set = 0x1003, queue = 0x600001064380, source = 0x600001064480 (not fired), timer port = 0x1503,
                        sources0 = (null),
                        sources1 = (null),
                        observers = (null),
                        timers = (null),
                        currently 587550909 (340514027926019) / soft deadline in: 1.84464036e+10 sec (@ -1) / hard deadline in: 1.84464036e+10 sec (@ -1)
                    },
         
                }
            }
         
            <CFRunLoop 0x600000264100 [0x10480eae8]>{wakeup port = 0x1103, stopped = false, ignoreWakeUps = true,
                current mode = (none),
                common modes = <CFBasicHash 0x600003027810 [0x10480eae8]>{type = mutable set, count = 1,
                    entries =>
                    2 : <CFString 0x104820ed8 [0x10480eae8]>{contents = "kCFRunLoopDefaultMode"}
                }
                ,
                common mode items = (null),
                modes = <CFBasicHash 0x600003027840 [0x10480eae8]>{type = mutable set, count = 1,
                    entries =>
                    2 : <CFRunLoopMode 0x6000005680d0 [0x10480eae8]>{name = kCFRunLoopDefaultMode, port set = 0x1003, queue = 0x600001064380, source = 0x600001064480 (not fired), timer port = 0x1503,
                        sources0 = (null),
                        sources1 = (null),
                        observers = (null),
                        timers = (null),
                        currently 587550909 (340514027998414) / soft deadline in: 1.84464036e+10 sec (@ -1) / hard deadline in: 1.84464036e+10 sec (@ -1)
                    },
         
                }
            }
        */
        
        return UIApplicationMain(argc, argv, nil, NSStringFromClass([AppDelegate class]));
    }
}
