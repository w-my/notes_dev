//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@interface MsgHelper : NSObject
{
}

+ (_Bool)IsShowPush:(_Bool)arg1 Des:(unsigned int)arg2 Msg:(id)arg3;
+ (_Bool)AddMsg:(id)arg1 EventInfo:(id)arg2 ChatName:(id)arg3 Des:(unsigned int)arg4 DBRet:(_Bool *)arg5 DB:(id)arg6 Lock:(id)arg7 GetChangeDisplay:(_Bool *)arg8 InsertNew:(_Bool *)arg9;
+ (void)ProcessOnAddNewMsg:(id)arg1 ChatName:(id)arg2 Lock:(id)arg3;
+ (_Bool)AddMessageToWCPayMsgBizExt:(id)arg1 DB:(id)arg2;
+ (_Bool)AddMessageToNewWCPayBizExt:(id)arg1 DB:(id)arg2 type:(int)arg3;
+ (_Bool)AddMessageToChatExt:(id)arg1 MsgWrap:(id)arg2 DB:(id)arg3;
+ (void)ClearDownloadData:(id)arg1 ChatName:(id)arg2;
+ (void)HandleThumb:(id)arg1 Message:(id)arg2 Lock:(id)arg3;
+ (_Bool)IsNotifyOnNotAddDB:(id)arg1 ChatName:(id)arg2;
+ (_Bool)IsNotifyOnAddMsg:(id)arg1 ChatName:(id)arg2;
+ (_Bool)CanNotAddToDB:(id)arg1 ChatName:(id)arg2;
+ (_Bool)newXMLCannotAddToDB:(id)arg1;
+ (_Bool)InternalCanNotAddDB:(id)arg1 ChatName:(id)arg2;
+ (id)GetChatName:(id)arg1 Des:(unsigned int *)arg2;

@end

