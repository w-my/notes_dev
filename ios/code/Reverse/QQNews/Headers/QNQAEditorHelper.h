//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@interface QNQAEditorHelper : NSObject
{
}

+ (id)p_processBoldText:(id)arg1 textRange:(struct _NSRange)arg2 inAttributedString:(id)arg3;
+ (id)parseContentNodesFromHTMLString:(id)arg1;
+ (_Bool)isBoldFont:(id)arg1;
+ (id)allRangesOfSubstring:(id)arg1 inText:(id)arg2;
+ (struct _NSRange)paragraphRangeOfIndex:(unsigned long long)arg1 inText:(id)arg2 hasNextParagraph:(_Bool *)arg3;
+ (id)filterHTMLTagWithStringforQAEditor:(id)arg1;
+ (id)filterHTMLTagWithString:(id)arg1;
+ (long long)currentImageCount:(id)arg1;
+ (id)buildHtmlContentAttributedText:(id)arg1;
+ (_Bool)shouldInsertNewLineAtRange:(struct _NSRange)arg1 withAttributedText:(id)arg2;
+ (id)pathForDraftWithFolderName:(id)arg1 fileName:(id)arg2;
+ (id)pathForDraftWithFolderName:(id)arg1;
+ (id)folderForDraft;
+ (id)generateImageName:(id)arg1;
+ (struct CGSize)resizeImage:(struct CGSize)arg1 maxWidth:(double)arg2;

@end

