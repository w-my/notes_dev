//
//  Dot.h
//  TouchPainter
//
//  Created by WTW on 2019/12/16.
//  Copyright © 2019 WTW. All rights reserved.
//  点

#import "Vertex.h"

NS_ASSUME_NONNULL_BEGIN

@protocol MarkVisitor;

@interface Dot : Vertex
{
  @private
  UIColor *color_;
  CGFloat size_;
}

@property (nonatomic, retain) UIColor *color;
@property (nonatomic, assign) CGFloat size;

// for the Visitor pattern
- (void) acceptMarkVisitor:(id <MarkVisitor>)visitor;

// for the Prototype pattern
- (id) copyWithZone:(NSZone *)zone;

// for the Memento pattern
- (id)initWithCoder:(NSCoder *)coder;
- (void)encodeWithCoder:(NSCoder *)coder;


@end

NS_ASSUME_NONNULL_END
