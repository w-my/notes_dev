//
//  Vertex.h
//  TouchPainter
//
//  Created by WTW on 2019/12/16.
//  Copyright © 2019 WTW. All rights reserved.
//  顶点

#import <Foundation/Foundation.h>
#import "Mark.h"

NS_ASSUME_NONNULL_BEGIN

@interface Vertex : NSObject <Mark>
{
  @protected
  CGPoint location_;
}

@property (nonatomic, retain) UIColor *color;
@property (nonatomic, assign) CGFloat size;
@property (nonatomic, assign) CGPoint locations;
@property (nonatomic, readonly) NSUInteger count;
@property (nonatomic, readonly) id <Mark> lastChild;

- (id) initWithLocation:(CGPoint) location;
- (void) addMark:(id <Mark>) mark;
- (void) removeMark:(id <Mark>) mark;
- (id <Mark>) childMarkAtIndex:(NSUInteger) index;

// for the Visitor pattern
- (void) acceptMarkVisitor:(id <MarkVisitor>) visitor;

// for the Prototype pattern
- (id) copyWithZone:(NSZone *)zone;

// for the Iterator pattern
- (NSEnumerator *) enumerator;

// for internal iterator implementation
- (void) enumerateMarksUsingBlock:(void (^)(id <Mark> item, BOOL *stop)) block;

// for the Memento pattern
- (id)initWithCoder:(NSCoder *)coder;
- (void)encodeWithCoder:(NSCoder *)coder;


NS_ASSUME_NONNULL_END
