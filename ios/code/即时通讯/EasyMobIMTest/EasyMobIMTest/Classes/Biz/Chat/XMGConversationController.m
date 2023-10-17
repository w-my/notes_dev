//
//  XMGConversationController.m
//  XMGEaseMob5
//
//  Created by xiaomage on 15/12/27.
//  Copyright © 2015年 xiaomage. All rights reserved.
//

#import "XMGConversationController.h"
#import "XMGChatController.h"

@interface XMGConversationController ()<EMChatManagerDelegate,UITableViewDataSource,UITableViewDelegate>

/** 数据源 */
@property (nonatomic, strong) NSMutableArray *conversations;

/** tableview */
@property (nonatomic, weak) UITableView *m_tableView;

@end

@implementation XMGConversationController

- (void)viewDidLoad {
    [super viewDidLoad];
    // 创建tableview
    UITableView *tableView = [[UITableView alloc]initWithFrame:CGRectMake(0, 0, kWeChatScreenWidth, kWeChatScreenHeight) style:UITableViewStylePlain];
    tableView.delegate = self;
    tableView.dataSource = self;
    [self.contentView addSubview:tableView];
    self.m_tableView = tableView;
    
    [[EaseMob sharedInstance].chatManager addDelegate:self delegateQueue:nil];
    [self loadConversation];
}

- (void)viewWillAppear:(BOOL)animated
{
    [super viewWillAppear:animated];
    [self loadConversation];
}

- (void)loadConversation
{
    [self.conversations removeAllObjects];
    // 从本地获取
//    NSArray *tempArr = [[EaseMob sharedInstance].chatManager conversations];
//    self.conversations = [NSMutableArray arrayWithArray:tempArr];
    // 获取所有会话
//    if (self.conversations.count == 0) {
    NSArray *loadArr = [[EaseMob sharedInstance].chatManager loadAllConversationsFromDatabaseWithAppend2Chat:YES];
        // 应该是使用添加数组的方式
    self.conversations = [NSMutableArray arrayWithArray:loadArr];
//    [self.conversations addObjectsFromArray:loadArr];
//    }
    [self.m_tableView reloadData];
}


- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section
{
    return self.conversations.count;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    static NSString *identifier = @"ConversationCell";
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:identifier];
    if (cell == nil) {
        cell = [[UITableViewCell alloc]initWithStyle:UITableViewCellStyleValue1 reuseIdentifier:identifier];
    }
    EMConversation *conver = self.conversations[indexPath.row];
    NSLog(@" conversation.latestMessage = %@",conver.latestMessage);
    EMMessage *message = conver.latestMessage;
    
    NSString *textStr = nil;
    id msgBody = message.messageBodies[0];
    if ([msgBody isKindOfClass:[EMTextMessageBody class]]) {
        EMTextMessageBody *textBody = msgBody;
        textStr = textBody.text;
    }else if ([msgBody isKindOfClass:[EMImageMessageBody class]]){
        EMImageMessageBody *imgBody = msgBody;
        textStr = imgBody.displayName;
    }else if ([msgBody isKindOfClass:[EMVoiceMessageBody class]]){
        EMVoiceMessageBody *voiceBody = msgBody;
        textStr = voiceBody.displayName;
    }
    
    // 显示名字和未读消息
    NSString *chatter = nil;
    if(conver.conversationType == eConversationTypeGroupChat){
        EMGroup *group = [EMGroup groupWithId:conver.chatter];
        chatter = group.groupSubject;
    }else{
        chatter = conver.chatter;
    }
    NSString *str = [NSString stringWithFormat:@"%@-%zd",conver.chatter,[conver unreadMessagesCount]];
    cell.textLabel.text = str;
    cell.detailTextLabel.text = textStr;
    cell.imageView.image = [UIImage imageNamed:@"chatListCellHead"];
    
    return cell;
}

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath
{
    EMConversation *conversation = self.conversations[indexPath.row];
    XMGChatController *chatVC = [[XMGChatController alloc]initWithIsGroup:NO];
    [chatVC setHidesBottomBarWhenPushed:YES];
    // conversation.chatter  如果是群: 那么就是群的id  如果是单聊 : 那么就是 用户名
    chatVC.budddy = [EMBuddy buddyWithUsername:conversation.chatter];
    [self.navigationController pushViewController:chatVC animated:YES];
}


- (void)didUnreadMessagesCountChanged
{
    [self.m_tableView reloadData];
    NSInteger count = 0;
    for (EMConversation *conversation in self.conversations) {
//        NSLog(@"未读消息 = %zd",[conversation unreadMessagesCount]);
        count += [conversation unreadMessagesCount];
    }
    
    NSString *badgeStr = nil;
    if (count > 0) {
         badgeStr = [NSString stringWithFormat:@"%zd",count];
    }
    
    self.navigationController.tabBarItem.badgeValue = badgeStr;
}


// 即将自动连接
- (void)willAutoReconnect
{
    NSLog(@"即将自动连接");
    self.title = @"即将自动连接...";
    
}

// 自动连接成功
- (void)didAutoReconnectFinishedWithError:(NSError *)error
{
    NSLog(@"自动连接成功");
    self.title = @"聊天";
}

// 监听状态的改变
- (void)didConnectionStateChanged:(EMConnectionState)connectionState
{
    NSLog(@"类型为 = %zd",connectionState);
    switch (connectionState) {
        case eEMConnectionConnected:
        {
            self.title = @"连接成功";
        }
            break;
        case eEMConnectionDisconnected:
        {
            self.title = @"未连接";
        }
            break;
            
        default:
            break;
    }
}

#pragma mark - EMChatManagerDelegate
// 接收到好友的请求
- (void)didReceiveBuddyRequest:(NSString *)username message:(NSString *)message
{
    NSLog(@"userName = %@ msg = %@",username,message);
    // 同意 或者 拒绝
    UIAlertController *alert = [UIAlertController alertControllerWithTitle:@"好友请求信息" message:@"" preferredStyle:UIAlertControllerStyleActionSheet];
    
    // 确定按钮
    UIAlertAction *addAction = [UIAlertAction actionWithTitle:@"添加" style:UIAlertActionStyleDefault handler:^(UIAlertAction * _Nonnull action) {
        BOOL isSuccess = [[EaseMob sharedInstance].chatManager acceptBuddyRequest:username error:nil];
        if (isSuccess) {
            NSLog(@"添加成功");
        }
    }];
    // 拒绝按钮
    UIAlertAction *rejecteAction = [UIAlertAction actionWithTitle:@"拒绝" style:UIAlertActionStyleDefault handler:^(UIAlertAction * _Nonnull action) {
        BOOL isSuccess = [[EaseMob sharedInstance].chatManager rejectBuddyRequest:username reason:@"我不想加" error:nil];
        if (isSuccess) {
            NSLog(@"拒绝成功");
        }
    }];
    
    [alert addAction:addAction];
    [alert addAction:rejecteAction];
    
    [self presentViewController:alert animated:YES completion:nil];
}

- (void)dealloc
{
    [[EaseMob sharedInstance].chatManager removeDelegate:self];
}

@end
