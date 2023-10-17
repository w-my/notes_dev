//
//  XMGContactController.m
//  XMGEaseMob5
//
//  Created by xiaomage on 15/12/27.
//  Copyright © 2015年 xiaomage. All rights reserved.
//

#import "XMGContactController.h"
#import "XMGChatController.h"
#import "XMGGroupController.h"
@interface XMGContactController ()<EMChatManagerDelegate,UITableViewDataSource,UITableViewDelegate>

/** 好友列表 */
@property (nonatomic, strong) NSArray *buddies;

/** tableView */
@property (nonatomic, weak) UITableView *myTableView;
@end

@implementation XMGContactController

- (void)viewDidLoad {
    [super viewDidLoad];
    XMGNButton *rightBtn = [XMGNButton createXMGButton];
    rightBtn.frame = CGRectMake(kWeChatScreenWidth - 50, 0, 30, 30);
    [rightBtn setImage:[UIImage imageNamed:@"contacts_add_friend"] forState:UIControlStateNormal];
    self.navigationItem.rightBarButtonItem = [[UIBarButtonItem alloc] initWithCustomView:rightBtn];
    rightBtn.block = ^(XMGNButton *btn){
        UIAlertController *alert = [UIAlertController alertControllerWithTitle:@"添加好友的请求信息" message:@"" preferredStyle:UIAlertControllerStyleAlert];
        // 好友名称
        [alert addTextFieldWithConfigurationHandler:^(UITextField * _Nonnull textField) {
            textField.placeholder = @"请输入好友的名称";
        }];
        // 请求信息
        [alert addTextFieldWithConfigurationHandler:^(UITextField * _Nonnull textField) {
            textField.placeholder = @"请输入请求信息";
        }];
        
        // 获取alert中的文本输入框
        UITextField *usernameFiled = [alert.textFields firstObject];
        UITextField *descriptionFiled = [alert.textFields lastObject];
        
        // 添加按钮
        UIAlertAction *comitAction = [UIAlertAction actionWithTitle:@"确定" style:UIAlertActionStyleDefault handler:^(UIAlertAction * _Nonnull action) {
            if (usernameFiled.text.length == 0) {
                [[TKAlertCenter defaultCenter]postAlertWithMessage:@"请输入用户名"];
                return;
            }
            // 如果附带信息输入为空,那么就自定义一个
            NSString *message = (descriptionFiled.text.length == 0)?@"我想加你":descriptionFiled.text;
            // 发送好友请求
//            BOOL isSuccess = [[EaseMob sharedInstance].chatManager addBuddy:usernameFiled.text message:message error:nil];
            // 将好友添加到哪个分组中
            BOOL isSuccess = [[EaseMob sharedInstance].chatManager addBuddy:usernameFiled.text message:message toGroups:@[@"xmg5"] error:nil];
            if (isSuccess) {
                NSLog(@"添加成功");
            }else{
                NSLog(@"添加失败");
            }
        }];
        // 取消按钮
        UIAlertAction *cancelAction = [UIAlertAction actionWithTitle:@"取消" style:UIAlertActionStyleDefault handler:^(UIAlertAction * _Nonnull action) {
            
        }];
        
        // 添加两个按钮
        [alert addAction:comitAction];
        [alert addAction:cancelAction];
        [self presentViewController:alert animated:YES completion:nil];
    };
    // 设置代理方法
    [[EaseMob sharedInstance].chatManager addDelegate:self delegateQueue:nil];
    
// ------------------------------华丽的分割线------------------------------------
    // 创建tableview
    UITableView *tableView = [[UITableView alloc]initWithFrame:CGRectMake(0,0 , kWeChatScreenWidth, kWeChatScreenHeight) style:UITableViewStylePlain];
    tableView.delegate = self;
    tableView.dataSource = self;
    [self.contentView addSubview:tableView];
    self.myTableView = tableView;
    
    // 群组按钮
    XMGNButton *groupBtn = [XMGNButton createXMGButton];
    groupBtn.frame = CGRectMake(0, 0, kWeChatScreenWidth, kWeChatAllSubviewHeight);
    groupBtn.backgroundColor = [UIColor grayColor];
    [groupBtn setTitle:@"群组" forState:UIControlStateNormal];
    tableView.tableHeaderView = groupBtn;
    
    // 群组点击事件
    groupBtn.block = ^(XMGNButton *btn){
        XMGGroupController *groupCtr = [[XMGGroupController alloc]init];
        [self.navigationController pushViewController:groupCtr animated:YES];
    };
    
    self.buddies = [NSArray array];
    // 从本地获取好友列表
    self.buddies = [[EaseMob sharedInstance].chatManager buddyList];
    if (self.buddies.count == 0) {
        // 从服务器上获取到的好友列表
        [[EaseMob sharedInstance].chatManager asyncFetchBuddyListWithCompletion:^(NSArray *buddyList, EMError *error) {
            self.buddies = buddyList;
            [tableView reloadData];
        } onQueue:nil];
    }
    
}



- (void)didUpdateBuddyList:(NSArray *)buddyList changedBuddies:(NSArray *)changedBuddies isAdd:(BOOL)isAdd
{
    NSString *str = isAdd ? @"添加的":@"删除的";
    NSLog(@"添加或者是删除  = %@",str);
    self.buddies = buddyList;
    [self.myTableView reloadData];
}



#pragma mark - tableView Delegate
- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section
{
    return self.buddies.count;
}

- (void)tableView:(UITableView *)tableView commitEditingStyle:(UITableViewCellEditingStyle)editingStyle forRowAtIndexPath:(NSIndexPath *)indexPath
{
    EMBuddy *buddy = self.buddies[indexPath.row];
    if (editingStyle == UITableViewCellEditingStyleDelete) {
        BOOL isSuccess = [[EaseMob sharedInstance].chatManager removeBuddy:buddy.username removeFromRemote:YES error:nil];
        if (isSuccess) {
            [[TKAlertCenter defaultCenter]postAlertWithMessage:@"删除好友成功"];
        }
    }
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    // 1.确定重用标示:
    static NSString *identifier = @"contactCell";
    // 2.从缓存池中取
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:identifier];
    // 3.如果空就手动创建
    if (!cell) {
        cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:identifier];
    }
    EMBuddy *buddy = self.buddies[indexPath.row];
    cell.textLabel.text = buddy.username;
    return cell;
}

// 好友同意添加的回调
- (void)didAcceptBuddySucceed:(NSString *)username
{
    NSLog(@"同意添加好友成功%@",username);
}

// 当前用户被别人移除的时候调用
- (void)didRemovedByBuddy:(NSString *)username
{
    NSLog(@"我被%@删除",username);
}

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath
{
    XMGChatController *chatCtr = [[XMGChatController alloc]initWithIsGroup:NO];
    [chatCtr setHidesBottomBarWhenPushed:YES];
    chatCtr.budddy = self.buddies[indexPath.row];
    [self.navigationController pushViewController:chatCtr animated:YES];
}


- (void)dealloc
{
    [[EaseMob sharedInstance].chatManager removeDelegate:self];
}

@end
