//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class NSString, QNSubscribeRelateNewsApi;

@interface QNSubscribeRelateNewsLoader : NSObject
{
    id <QNSubscribeRelateNewsLoaderDelegate> _delegate;
    NSString *_idStr;
    QNSubscribeRelateNewsApi *_mRequest;
}

@property(retain, nonatomic) QNSubscribeRelateNewsApi *mRequest; // @synthesize mRequest=_mRequest;
@property(retain, nonatomic) NSString *idStr; // @synthesize idStr=_idStr;
@property(nonatomic) __weak id <QNSubscribeRelateNewsLoaderDelegate> delegate; // @synthesize delegate=_delegate;
- (void).cxx_destruct;
- (void)dealloc;
- (void)cancel;
- (void)beginRequest:(id)arg1;
- (id)init;

@end
