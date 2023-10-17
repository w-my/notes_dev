//
//  Mark.h
//  TouchPainter
//
//  Created by WTW on 2019/12/16.
//  Copyright © 2019 WTW. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "MarkVisitor.h"

NS_ASSUME_NONNULL_BEGIN

@protocol Mark <NSObject>

@property (nonatomic, strong) UIColor *color;
@property (nonatomic, assign) CGFloat size;
@property (nonatomic, assign) CGPoint location;
@property (nonatomic, readonly) NSUInteger count;
@property (nonatomic, readonly) id <Mark> lastChild;

- (void) addMark:(id <Mark>) mark;
- (void) removeMark:(id <Mark>) mark;
- (id <Mark>) childMarkAtIndex:(NSUInteger) index;

// for the Visitor pattern  用于访问者模式
- (void) acceptMarkVisitor:(id <MarkVisitor>) visitor;

// for the Iterator pattern 用于迭代器模式
- (NSEnumerator *) enumerator;

// for internal iterator implementation  用于内部迭代器实现
- (void) enumerateMarksUsingBlock:(void (^)(id <Mark> item, BOOL *stop)) block;

// for a bad example
- (void) drawWithContext:(CGContextRef) context;

@end

NS_ASSUME_NONNULL_END
