//
//  XMGChatController.m
//  XMGEaseMob5
//
//  Created by xiaomage on 15/12/27.
//  Copyright © 2015年 xiaomage. All rights reserved.
//

#import "XMGChatController.h"
#import "XMGTollView.h"
#import "XMGChatCell.h"
#import "EMCDDeviceManager.h"
#import "XMGAnyView.h"
#import "MWPhotoBrowser.h"
#import "XMGCallController.h"
@interface XMGChatController ()<UITableViewDataSource,UITableViewDelegate,IEMChatProgressDelegate,EMChatManagerDelegate,XMGTollViewVoiceDelegate,UINavigationControllerDelegate,UIImagePickerControllerDelegate,XMGChatCellShowImageDelegate,MWPhotoBrowserDelegate,EMCallManagerDelegate>

/** 聊天消息 */
@property (nonatomic, strong) NSMutableArray *messageData;

/** <#Description#> */
@property (nonatomic, weak) UITableView *chatTableView;

/** 更多功能 */
@property (nonatomic, weak) XMGAnyView *chatAnyView;

/** 更多功能需要拿到的textView */
@property (nonatomic, weak) UITextView *anyViewNeedTextView;

/** 保存图片的message */
@property (nonatomic, strong) EMMessage *photoMessage;

/** 实时通话的Session */
@property (nonatomic, strong) EMCallSession *callSession;

@property (nonatomic,assign)BOOL isGroup;
@end

@implementation XMGChatController

- (instancetype)initWithIsGroup:(BOOL)isGroup
{
    if (self = [super init]) {
        self.isGroup = isGroup;
    }
    return self;
}

- (void)viewDidLoad {
    [super viewDidLoad];
    
    self.title =  self.budddy.username;
    
    NSString *path = [NSSearchPathForDirectoriesInDomains(NSLibraryDirectory, NSUserDomainMask, YES) lastObject];
    NSLog(@"path = %@",path);
    
    // 1. 创建tableview
    UITableView *tableView = [[UITableView alloc]initWithFrame:CGRectMake(0, 0, kWeChatScreenWidth, kWeChatScreenHeight - 64 - 44) style:UITableViewStylePlain];
    tableView.delegate = self;
    tableView.dataSource = self;
    tableView.separatorStyle = UITableViewCellSeparatorStyleNone;
    [self.contentView addSubview:tableView];
    
    self.chatTableView = tableView;
    // 2. 创建自定义控件
    XMGTollView *toolView = [[XMGTollView alloc]init];
    toolView.frame = CGRectMake(0, tableView.bottom, tableView.width, 44);
    toolView.delegate = self;
    // 发送消息
    toolView.sendTextBlock = ^(UITextView *textView,XMGTollViewEditTextViewType type){
            if (type == XMGTollViewEditTextViewTypeSend) {
                [self sendTextMsg:textView];
            }else{
                if (self.chatAnyView.top < kWeChatScreenHeight) {
                    self.chatAnyView.top = kWeChatScreenHeight;
                }
                self.anyViewNeedTextView = textView;
            }
        
    };
    [self.contentView addSubview:toolView];
    
    // 获取本地的聊天消息
    NSString *chatter = self.budddy.username;
    // 获取当前对象的会话
    EMConversation *conversation = [[EaseMob sharedInstance].chatManager conversationForChatter:chatter conversationType:eConversationTypeChat];
    // 加载当前会话的所有消息
    NSArray *conArr = [conversation loadAllMessages];
    NSLog(@"conArr = %@",conArr);
    for (EMMessage *msg in conArr) {
        [conversation markMessageWithId:msg.messageId asRead:YES];
    }
    // 初始化数组
    self.messageData = [NSMutableArray arrayWithArray:conArr];
    
    [self scrollBottom];
    
    // 添加通知
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(keyboardWillChangeFrameNotification:) name:UIKeyboardWillChangeFrameNotification object:nil];
    
    // 添加聊天代理
    [[EaseMob sharedInstance].chatManager addDelegate:self delegateQueue:nil];
    
    
    // 创建更多功能
    XMGAnyView *anyView = [[XMGAnyView alloc]initImageBlock:^{
        NSLog(@"你点击了图片");
        UIImagePickerController *picker = [[UIImagePickerController alloc]init];
        picker.sourceType = UIImagePickerControllerSourceTypePhotoLibrary;
        picker.delegate = self;
        [self presentViewController:picker animated:YES
                         completion:nil];
    } talkBlock:^{
        NSLog(@"你点击了语音");
        // 实时通话的类  ICallManagerCall
        // 发送一个语音通话请求
        EMCallSession *callSin = [[EaseMob sharedInstance].callManager asyncMakeVoiceCall:self.budddy.username timeout:20 error:nil];
        self.callSession = callSin;
    } vedioBlock:^{
        NSLog(@"你点击了视频");
        [[EaseMob sharedInstance].callManager asyncMakeVideoCall:self.budddy.username timeout:20 error:nil];
    }];
    anyView.frame = CGRectMake(0, kWeChatScreenHeight, kWeChatScreenWidth, 271);
    [[UIApplication sharedApplication].keyWindow addSubview:anyView];
    self.chatAnyView = anyView;
    // 1. 现在滚动视图隐藏
    // 2. 在输入文字的时候同时点击更多功能
    // 3. 在文本框同时显示的时候隐藏更多功能
    // 4. 当开始编辑的时候应该隐藏掉更多功能
    
    // moreBtn 的点击
    toolView.moreBtnBlock = ^(){
        if (self.anyViewNeedTextView) {
            [self.anyViewNeedTextView resignFirstResponder];
        }
        self.contentView.top = -271;
        anyView.top = kWeChatScreenHeight - 271;
    };
    
    
    // 添加实时通话代理
    [[EaseMob sharedInstance].callManager addDelegate:self delegateQueue:nil];
}

#pragma mark - 实时通话的代理方法
- (void)callSessionStatusChanged:(EMCallSession *)callSession changeReason:(EMCallStatusChangedReason)reason error:(EMError *)error
{
    NSLog(@"callSession = %@  reason %ld  status = %zd",callSession,reason,callSession.status);
    // 通话已连接 才跳转到下一个界面
    if (callSession.status == eCallSessionStatusConnected) {
        XMGCallController *callCtr = [[XMGCallController alloc]init];
        callCtr.currentSession = callSession;
        [self presentViewController:callCtr animated:YES completion:nil];
    }
    
}


// 通知回调的方法
- (void)keyboardWillChangeFrameNotification:(NSNotification *)noti
{
    NSLog(@"    noti.userInfo = %@",    noti.userInfo);
    CGRect keyboardF = [noti.userInfo[UIKeyboardFrameEndUserInfoKey] CGRectValue];
    if (keyboardF.origin.y < kWeChatScreenHeight) {
        self.contentView.top = - keyboardF.size.height;
    }else{
        self.contentView.top = 0;
    }
}

// 发送一条消息
- (void)scrollBottom
{
    if (self.messageData.count == 0) return;
    // 滚到最后一行
    NSIndexPath *indexPath = [NSIndexPath indexPathForRow:self.messageData.count - 1 inSection:0];
    [self.chatTableView scrollToRowAtIndexPath:indexPath atScrollPosition:UITableViewScrollPositionBottom animated:YES];
}

// 发送文字消息
- (void)sendTextMsg:(UITextView *)textView
{
    // 发送消息
    NSLog(@"你点击了完成按钮");
    
    // 5. 内容对象
    EMChatText *text = [[EMChatText alloc]initWithText:[textView.text substringToIndex:textView.text.length - 1]];
    
    // 4. 消息体
    //        EMTextMessageBody;  文本消息体
    //        EMImageMessageBody; 图片消息体
    //        EMVideoMessageBody; 视频消息体
    //        EMVoiceMessageBody; 语音消息体
    EMTextMessageBody *textBody = [[EMTextMessageBody alloc]initWithChatObject:text];
    
    // 3.接收者
    NSString *reciver = self.isGroup ? self.group.groupId : self.budddy.username;
    // 2.EMMessage对象
    EMMessage *msg = [[EMMessage alloc]initWithReceiver:reciver bodies:@[textBody]];
    msg.messageType = self.isGroup ? eMessageTypeGroupChat : eMessageTypeChat;
    // 1.异步发送消息
    [[EaseMob sharedInstance].chatManager asyncSendMessage:msg progress:self prepare:^(EMMessage *message, EMError *error) {
        NSLog(@"消息即将发送");
    } onQueue:nil completion:^(EMMessage *message, EMError *error) {
        NSLog(@"消息发送完成");
        // 添加数据
        [self.messageData addObject:message];
        // 刷新表格
        [self.chatTableView reloadData];
        [self scrollBottom];
        // 清空数据
        textView.text = @"";
    } onQueue:nil];
}

- (void)scrollViewWillBeginDragging:(UIScrollView *)scrollView
{
    [self.contentView endEditing:YES];
    [UIView animateWithDuration:1.0f animations:^{
        self.chatAnyView.top = kWeChatScreenHeight;
        if (self.contentView.top < 0) self.contentView.top = 0;
    }];
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section
{
    return self.messageData.count;
}

- (CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath
{
    static NSString *identifier = @"CHATCELL";
    XMGChatCell *cell = [tableView dequeueReusableCellWithIdentifier:identifier];
    if (cell == nil) {
        cell = [[XMGChatCell alloc]initWithStyle:UITableViewCellStyleDefault reuseIdentifier:identifier];
    }
    cell.message = self.messageData[indexPath.row];
    return cell.rowHeight;
}


- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    static NSString *identifier = @"CHATCELL";
    XMGChatCell *cell = [tableView dequeueReusableCellWithIdentifier:identifier];
    if (cell == nil) {
        cell = [[XMGChatCell alloc]initWithStyle:UITableViewCellStyleDefault reuseIdentifier:identifier];
    }
    cell.message = self.messageData[indexPath.row];
    // 设置显示大图片的代理
    cell.delegate = self;
    // 取消cell的选中
    [cell setSelectedBackgroundView:[[UIView alloc]init]];
    return cell;
}

#pragma mark - 发送消息的进度
- (void)setProgress:(float)progress forMessage:(EMMessage *)message forMessageBody:(id<IEMMessageBody>)messageBody
{
    NSLog(@"progress  = %f",progress);
}

#pragma mark - EMChatManagerDelegate
// 接收消息的回调
- (void)didReceiveMessage:(EMMessage *)message
{
    NSLog(@"=== %@",message);
    // 添加数据
    [self.messageData addObject:message];
    // 刷新表格
    [self.chatTableView reloadData];
    // 滚到最后一行
    [self scrollBottom];
}

#pragma mark - XMGTollViewVoiceDelegate
- (void)toolViewWithType:(XMGTollViewVoiceType)type button:(XMGNButton *)btn
{
    switch (type) {
        case XMGTollViewVoiceTypeStart:
        {
            NSLog(@"开始录音");
            int fileNameNum = arc4random() % 1000;
            NSTimeInterval time = [NSDate timeIntervalSinceReferenceDate];
            [[EMCDDeviceManager sharedInstance] asyncStartRecordingWithFileName:[NSString stringWithFormat:@"%zd%d",fileNameNum,(int)time] completion:^(NSError *error) {
                if (!error) {
                    NSLog(@"录音成功");
                    
                }
            }];
        }
            break;
            
        case XMGTollViewVoiceTypeStop:
        {
            NSLog(@"停止录音");
            [[EMCDDeviceManager sharedInstance] asyncStopRecordingWithCompletion:^(NSString *recordPath, NSInteger aDuration, NSError *error) {
                NSLog(@"recordPath = %@ , duration = %zd",recordPath,aDuration);
                [self sendVoiceWithFilePath:recordPath duration:aDuration];
            }];
        }
            break;
            
        case XMGTollViewVoiceTypeCancel:
        {
            NSLog(@"退出录音");
        }
            break;
            
        default:
            break;
    }
}

- (void)viewWillDisappear:(BOOL)animated
{
    [super viewWillDisappear:animated];
    self.contentView.top = 0;
    self.chatAnyView.top = kWeChatScreenHeight;
}

// 发送语音消息
- (void)sendVoiceWithFilePath:(NSString *)path duration:(NSInteger)aDuration
{
    EMChatVoice *voice = [[EMChatVoice alloc]initWithFile:path displayName:@"[AUDIO]"];
    // 需要设置语音时间
    voice.duration = aDuration;
    
    EMVoiceMessageBody *voiceBody = [[EMVoiceMessageBody alloc]initWithChatObject:voice];
    
    NSString *reciver = self.isGroup ? self.group.groupId : self.budddy.username;
    
    // message
    EMMessage *message = [[EMMessage alloc]initWithReceiver:reciver bodies:@[voiceBody]];
    
    message.messageType = self.group ? eMessageTypeGroupChat : eMessageTypeChat;
    
    // 发送消息
    [[EaseMob sharedInstance].chatManager asyncSendMessage:message progress:self prepare:^(EMMessage *message, EMError *error) {
        NSLog(@"即将发送");
    } onQueue:nil completion:^(EMMessage *message, EMError *error) {
        NSLog(@"发送完成");
        // 添加数据
        [self.messageData addObject:message];
        // 刷新表格
        [self.chatTableView reloadData];
        // 滚到最后一行
        [self scrollBottom];
    } onQueue:nil];
}

#pragma mark - UIImagePickerControllerDelegate
- (void)imagePickerController:(UIImagePickerController *)picker didFinishPickingMediaWithInfo:(NSDictionary<NSString *,id> *)info
{
    // 隐藏picker
    [picker dismissViewControllerAnimated:YES completion:nil];
    // 取出图片
    UIImage *image = info[UIImagePickerControllerOriginalImage];
    // 发送图片
    [self sendImage:image];
}

- (void)sendImage:(UIImage *)image
{
    EMChatImage *chatImg = [[EMChatImage alloc]initWithUIImage:image displayName:@"[IMAGE]"];
    
    // 第一个参数的原图片
    // 第二个参数是预览图片 如果传nil环信默认帮我们生成预览图片
    EMImageMessageBody *body = [[EMImageMessageBody alloc]initWithImage:chatImg thumbnailImage:nil];
    
    NSString *reciver = self.isGroup ? self.group.groupId : self.budddy.username;
    
    // 创建EMMessage对象
    EMMessage *msg = [[EMMessage alloc]initWithReceiver:reciver bodies:@[body]];
    
    msg.messageType = self.isGroup ? eMessageTypeGroupChat : eMessageTypeChat;
    
    [[EaseMob sharedInstance].chatManager asyncSendMessage:msg progress:self prepare:^(EMMessage *message, EMError *error) {
        NSLog(@"即将发送");
    } onQueue:nil completion:^(EMMessage *message, EMError *error) {
        if (!error) {
            NSLog(@"发送成功");
            //添加到数据源中
            [self.messageData addObject:message];
            // 刷新表格
            [self.chatTableView reloadData];
            // 滚到底部
            [self scrollBottom];
        }
    } onQueue:nil];
}

#pragma mark - 显示大图片
- (void)chatCellWithMessage:(EMMessage *)message
{
    self.photoMessage = message;
    NSLog(@"delegate message = %@",message);
    MWPhotoBrowser *browser = [[MWPhotoBrowser alloc]initWithDelegate:self];
    
    [self.navigationController pushViewController:browser animated:YES];
}



#pragma mark - 图片浏览器的代理方法
- (NSUInteger)numberOfPhotosInPhotoBrowser:(MWPhotoBrowser *)photoBrowser
{
    return 1;
}
- (id <MWPhoto>)photoBrowser:(MWPhotoBrowser *)photoBrowser photoAtIndex:(NSUInteger)index
{
    EMImageMessageBody *body = self.photoMessage.messageBodies[0];
    
    NSString *path = body.localPath;
    NSFileManager *fileMgr = [NSFileManager defaultManager];
    if ([fileMgr fileExistsAtPath:path]) {
        // 设置图片浏览器中的图片对象 (本地获取的)
        return [MWPhoto photoWithImage:[UIImage imageWithContentsOfFile:path]];
    }else{
        // 设置图片浏览器中的图片对象 (使用网络请求)
        path = body.remotePath;
        return [MWPhoto photoWithURL:[NSURL URLWithString:path]];
    }
}


- (void)dealloc
{
    [[EaseMob sharedInstance].chatManager removeDelegate:self];
    [[EaseMob sharedInstance].callManager removeDelegate:self];
}

@end
