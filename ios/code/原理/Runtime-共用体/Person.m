//
//  Person.m
//  位运算-取值和设值
//
//  Created by WTW on 2019/4/24.
//  Copyright © 2019 rocedar. All rights reserved.
//

#import "Person.h"

#define TallMask (1<<0)
#define RichMask (1<<1)
#define HandSomeMask (1<<2)

@interface Person ()
{
    union {
        char bits;
        struct { //此结构体仅仅是提高可读性
            char tall : 1;
            char rich : 1;
            char handSome : 1 ;
        };
    } _tallRichHandSome;
}

@end

@implementation Person

- (BOOL)isTall {
    return !!(_tallRichHandSome.bits & TallMask);
}

- (BOOL)isRich {
    return !!(_tallRichHandSome.bits & RichMask );
}

- (BOOL)isHandSome {
    return !!(_tallRichHandSome.bits & HandSomeMask);
}

- (void)setTall:(BOOL)tall {
    if (tall) {
        _tallRichHandSome.bits |= TallMask;
    }else {
        _tallRichHandSome.bits &= ~TallMask; // ~ 按位取反
    }
}

- (void)setRich:(BOOL)rich {
    if (rich) {
        _tallRichHandSome.bits |= RichMask;
    }else {
        _tallRichHandSome.bits &= ~RichMask;
    }
}

- (void)setHandSome:(BOOL)handsome {
    if (handsome) {
        _tallRichHandSome.bits |= HandSomeMask;
    }else {
        _tallRichHandSome.bits &= ~HandSomeMask;
    }
}

@end
