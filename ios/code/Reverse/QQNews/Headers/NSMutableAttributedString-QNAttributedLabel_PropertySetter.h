//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSMutableAttributedString.h"

@interface NSMutableAttributedString (QNAttributedLabel_PropertySetter)
- (void)qn_setImage:(id)arg1 atIndex:(unsigned long long)arg2;
- (void)qn_removeAllLinks;
- (void)qn_addLink:(id)arg1 range:(struct _NSRange)arg2;
- (void)qn_removeAllImages;
- (void)qn_insertImage:(id)arg1 atIndex:(long long)arg2 margins:(struct UIEdgeInsets)arg3 verticalTextAlignment:(long long)arg4 imageType:(long long)arg5 userInfo:(id)arg6;
- (void)qn_insertImage:(id)arg1 atIndex:(long long)arg2 margins:(struct UIEdgeInsets)arg3 verticalTextAlignment:(long long)arg4;
- (void)qn_insertImage:(id)arg1 atIndex:(long long)arg2 margins:(struct UIEdgeInsets)arg3;
- (void)qn_insertImage:(id)arg1 atIndex:(unsigned long long)arg2;
- (void)qn_setEndingIconImage:(id)arg1;
- (void)qn_setEndingIconImageLeftMargin:(double)arg1;
- (void)qn_setTruncationString:(id)arg1;
- (void)qn_setSkipLineStartWhitespaceCharacters:(_Bool)arg1;
- (void)qn_setLastLineMinimumCharacters:(unsigned long long)arg1;
- (void)qn_setTailStayCharNum:(unsigned long long)arg1;
- (void)qn_setNumberOfLines:(unsigned long long)arg1;
- (void)qn_setContentInsets:(struct UIEdgeInsets)arg1;
@end

