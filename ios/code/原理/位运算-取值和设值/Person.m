//
//  Person.m
//  位运算-取值和设值
//
//  Created by WTW on 2019/4/24.
//  Copyright © 2019 rocedar. All rights reserved.
//

#import "Person.h"

// & 取出特定的位

//掩码 一般用来按位与(&)运算

//#define TallMask 1
//#define RichMask 2
//#define HandSomeMask 4

//#define TallMask 0b00000001
//#define RichMask 0b00000010
//#define HandSomeMask 0b00000100

#define TallMask (1<<0)
#define RichMask (1<<1)
#define HandSomeMask (1<<2)

@interface Person ()
{
   char _tallRichHandSome;  //倒数第一位 tall 第二位 rich  第三位 handsome
}
@end

@implementation Person

- (instancetype)init {
    if (self = [super init]) {
        _tallRichHandSome = 0b00000011;
    }
    return self;
}

- (BOOL)isTall {
    return !!(_tallRichHandSome & TallMask);
}

- (BOOL)isRich {
    return !!(_tallRichHandSome & RichMask );
}

- (BOOL)isHandSome {
    return !!(_tallRichHandSome & HandSomeMask);
}

- (void)setTall:(BOOL)tall {
    if (tall) {
        _tallRichHandSome |= TallMask;
    }else {
        _tallRichHandSome &= ~TallMask; // ~ 按位取反
    }
}

- (void)setRich:(BOOL)rich {
    if (rich) {
        _tallRichHandSome |= RichMask;
    }else {
        _tallRichHandSome &= ~RichMask;
    }
}

- (void)setHandSome:(BOOL)handsome {
    if (handsome) {
        _tallRichHandSome |= HandSomeMask;
    }else {
        _tallRichHandSome &= ~HandSomeMask;
    }
}

@end
