//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@interface MQQSharkData : NSObject
{
    struct ClientSashimi *_clientSashimi;
    vector_aa1d262e *_compressData;
    id <MQQSharkDataDelegate> _delegate;
    int _seqNo;
    struct ServerSashimi *_serverSashimi;
    vector_aa1d262e *_rspData;
}

@property(nonatomic) id <MQQSharkDataDelegate> delegate; // @synthesize delegate=_delegate;
@property(readonly, nonatomic) int seqNo; // @synthesize seqNo=_seqNo;
- (const vector_aa1d262e *)responseData;
- (struct ServerSashimi *)serverSashimi;
- (void)handleSS:(struct ServerSashimi *)arg1;
- (struct ClientSashimi *)clientSashimi;
- (_Bool)generateCS;
- (void)dealloc;
- (id)initWithCmdId:(int)arg1 requestData:(const vector_aa1d262e *)arg2 delegate:(id)arg3;
- (id)init;

@end
