//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNArticleContentNativeWidgetNodeType.h"

@class QNComment;

@interface QNWidgetNodeArticleComment : QNArticleContentNativeWidgetNodeType
{
    QNComment *_comment;
}

@property(retain, nonatomic) QNComment *comment; // @synthesize comment=_comment;
- (void).cxx_destruct;
- (void)encodeWithCoder:(id)arg1;
- (id)initWithCoder:(id)arg1;
- (void)loadInfo:(id)arg1;
- (_Bool)isDataValid;
- (Class)viewClass;

@end

