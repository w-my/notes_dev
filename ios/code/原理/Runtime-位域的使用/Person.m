//
//  Person.m
//  位运算-取值和设值
//
//  Created by WTW on 2019/4/24.
//  Copyright © 2019 rocedar. All rights reserved.
//

#import "Person.h"

@interface Person ()
{
    //位域  : 1 代表一位
    // 只有一个字节 只有后三位有值
    struct {
        char tall : 1;
        char rich : 1;
        char handSome : 1 ;
    } _tallRichHandSome;  //0b0000 0001 最后一位往前依次  tall rich handSome
}
@end

@implementation Person

- (BOOL)isTall {
    return !!_tallRichHandSome.tall;
}

- (BOOL)isRich {
    return !!_tallRichHandSome.rich;
}

- (BOOL)isHandSome {
    return !!_tallRichHandSome.handSome;
}

- (void)setTall:(BOOL)tall {
    _tallRichHandSome.tall = tall;
}

- (void)setRich:(BOOL)rich {
    _tallRichHandSome.rich = rich;
}

- (void)setHandSome:(BOOL)handsome {
    _tallRichHandSome.handSome = handsome;
}

@end
