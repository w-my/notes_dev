//
//  XMGGroupController.m
//  XMGEaseMob5
//
//  Created by xiaomage on 15/12/30.
//  Copyright © 2015年 xiaomage. All rights reserved.
//

#import "XMGGroupController.h"
#import "XMGChatController.h"

@interface XMGGroupController ()<UITableViewDataSource,UITableViewDelegate,EMChatManagerDelegate>

/** 群组列表 */
@property (nonatomic, strong) NSMutableArray *groupArr;

@end

@implementation XMGGroupController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    XMGNButton *rightBtn = [XMGNButton createXMGButton];
    rightBtn.frame = CGRectMake(kWeChatScreenWidth - 50, 0, 60, 30);
    [rightBtn setTitle:@"创建群" forState:UIControlStateNormal];
    self.navigationItem.rightBarButtonItem = [[UIBarButtonItem alloc] initWithCustomView:rightBtn];
    
    
    
    // 显示数据
    UITableView *tableView = [[UITableView alloc]initWithFrame:CGRectMake(0, 0, kWeChatScreenWidth, kWeChatScreenHeight) style:UITableViewStylePlain];
    tableView.delegate = self;
    tableView.dataSource =self;
    [self.contentView addSubview:tableView];
    
    
    // 获取 群列表
    NSArray *arr = [[EaseMob sharedInstance].chatManager groupList];
    self.groupArr = [NSMutableArray arrayWithArray:arr];
    if (self.groupArr.count == 0) {
        // 从服务端获取群列表
        [[EaseMob sharedInstance].chatManager asyncFetchMyGroupsListWithCompletion:^(NSArray *groups, EMError *error) {
            [self.groupArr addObjectsFromArray:groups];
            [tableView reloadData];
            NSLog(@"self.groupArr = %@",self.groupArr);
        } onQueue:nil];
    }
    
    rightBtn.block = ^(XMGNButton *btn){
        
        UIAlertController *alert = [UIAlertController alertControllerWithTitle:@"创建群" message:@"" preferredStyle:UIAlertControllerStyleAlert];
        
        [alert addTextFieldWithConfigurationHandler:^(UITextField * _Nonnull textField) {
            textField.placeholder = @"请输入群名称";
        }];
        [alert addTextFieldWithConfigurationHandler:^(UITextField * _Nonnull textField) {
            textField.placeholder = @"自我介绍";
        }];
        
        UITextField *groupNameFiled = [alert.textFields firstObject];
        UITextField *detailFiled = [alert.textFields lastObject];
        
        [alert addAction:[UIAlertAction actionWithTitle:@"确定" style:UIAlertActionStyleDefault handler:^(UIAlertAction * _Nonnull action) {
            //        @brief 群组类型
            //        @constant eGroupStyle_PrivateOnlyOwnerInvite 私有群组，只能owner权限的人邀请人加入
            //        @constant eGroupStyle_PrivateMemberCanInvite 私有群组，owner和member权限的人可以邀请人加入
            //        @constant eGroupStyle_PublicJoinNeedApproval 公开群组，允许非群组成员申请加入，需要管理员同意才能真正加入该群组
            //        @constant eGroupStyle_PublicOpenJoin         公开群组，允许非群组成员加入，不需要管理员同意
            //        @constant eGroupStyle_PublicAnonymous        公开匿名群组，允许非群组成员加入，不需要管理员同意
            //        @constant eGroupStyle_Default                默认群组类型
            //        @discussion
            //        eGroupStyle_Private：私有群组，只允许群组成员邀请人进入
            //        eGroupStyle_Public： 公有群组，允许非群组成员加入
            
            EMGroupStyleSetting *groupSetting = [[EMGroupStyleSetting alloc]init];
            // 设置群里的类型
            groupSetting.groupStyle = eGroupStyle_PublicJoinNeedApproval;
            // 设置群组最多容纳多少人
            groupSetting.groupMaxUsersCount = 400;
            [[EaseMob sharedInstance].chatManager asyncCreateGroupWithSubject:groupNameFiled.text description:detailFiled.text invitees:@[@"xmg1",@"xmg5"] initialWelcomeMessage:@"欢迎光临" styleSetting:groupSetting completion:^(EMGroup *group, EMError *error) {
                if (!error) {
                    NSLog(@"创建群组成功");
                    [self.groupArr addObject:group];
                    [tableView reloadData];
                }
            } onQueue:nil];
        }]];
        
        [alert addAction:[UIAlertAction actionWithTitle:@"取消" style:UIAlertActionStyleCancel handler:^(UIAlertAction * _Nonnull action) {
            
        }]];
        
        [self presentViewController:alert animated:YES completion:nil];
    };
}


#pragma mark -  tableview数据源方法
- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section
{
    return self.groupArr.count;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    static NSString *identifier = @"GroupCell";
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:identifier];
    if (cell == nil) {
        cell = [[UITableViewCell alloc]initWithStyle:UITableViewCellStyleDefault reuseIdentifier:identifier];
    }
    EMGroup *group = self.groupArr[indexPath.row];
    cell.textLabel.text = [NSString stringWithFormat:@"%@",group.groupSubject];
    
    return cell;
}


- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath
{
    XMGChatController *chatCtr = [[XMGChatController alloc]initWithIsGroup:YES];
    [chatCtr setHidesBottomBarWhenPushed:YES];
    chatCtr.group = self.groupArr[indexPath.row];
    [self.navigationController pushViewController:chatCtr animated:YES];
}

- (void)dealloc
{
    [[EaseMob sharedInstance].chatManager removeDelegate:self];
}

@end
