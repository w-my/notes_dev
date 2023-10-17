//
//  XMGChatCell.m
//  XMGEaseMob5
//
//  Created by xiaomage on 15/12/27.
//  Copyright © 2015年 xiaomage. All rights reserved.
//

#import "XMGChatCell.h"
#import "UIImage+XMGResizing.h"
#import "NSDateUtilities.h"
#import "EMCDDeviceManager.h"
#import "UIButton+WebCache.h"
@interface XMGChatCell ()

/** 时间 */
@property (nonatomic, weak) UILabel *chatTime;

/** <#Description#> */
@property (nonatomic, weak) XMGNButton *chatButton;

/** <#Description#> */
@property (nonatomic, weak) XMGNButton *chatIcon;

@end

@implementation XMGChatCell


- (instancetype)initWithStyle:(UITableViewCellStyle)style reuseIdentifier:(NSString *)reuseIdentifier
{
    if (self = [super initWithStyle:style reuseIdentifier:reuseIdentifier]) {
        // 添加子控件
        // 时间
        UILabel *timeLbl = [[UILabel alloc]init];
        timeLbl.textAlignment = NSTextAlignmentCenter;
        [self.contentView addSubview:timeLbl];
        
        // 聊天消息
        XMGNButton *chatBtn = [XMGNButton createXMGButton];
        chatBtn.titleLabel.font = [UIFont systemFontOfSize:15.0f];
        // 需要设置内容的内边距
        chatBtn.contentEdgeInsets = UIEdgeInsetsMake(15, 20, 25, 20);
        [chatBtn setTitleColor:[UIColor blackColor] forState:UIControlStateNormal];
        [chatBtn addTarget:self action:@selector(chatBtnClick:) forControlEvents:UIControlEventTouchUpInside];
        chatBtn.titleLabel.numberOfLines = 0;
        [self.contentView addSubview:chatBtn];
        
        // 头像
        XMGNButton *iconBtn = [XMGNButton createXMGButton];
        [iconBtn setImage:[UIImage imageNamed:@"chatListCellHead"] forState:UIControlStateNormal];
        [self.contentView addSubview:iconBtn];
        
        self.chatButton = chatBtn;
        self.chatIcon = iconBtn;
        self.chatTime = timeLbl;
        
//        self.contentView.backgroundColor = [UIColor grayColor];
    }
    return self;
}

- (void)layoutSubviews
{
    [super layoutSubviews];
    self.chatTime.frame = CGRectMake(0, 0, kWeChatScreenWidth, 30);
}

- (void)setMessage:(EMMessage *)message
{
    _message = message;
    // 获取消息体
    id body = message.messageBodies[0];
    
//    NSString *time = [self conversationTime:message.timestamp];
    
//    NSString *lastTime = [[NSUserDefaults standardUserDefaults] objectForKey:@"lastTime"];
//    if (![time isEqualToString:lastTime]) {
//        self.chatTime.text = time;
//        [[NSUserDefaults standardUserDefaults] setObject:time forKey:@"lastTime"];
//    }
    
    self.chatTime.text = [self conversationTime:message.timestamp];
    
    if ([body isKindOfClass:[EMTextMessageBody class]]) {// 文本类型
        EMTextMessageBody *textBody = body;
        
        [self.chatButton setTitle:textBody.text forState:UIControlStateNormal];
        [self.chatButton setImage:nil forState:UIControlStateNormal];
//        double time = message.timestamp;
//        if (message.timestamp > 140000000000) {
//            time = message.timestamp/1000;
//        }
//        NSDate *date = [[NSDate alloc]initWithTimeIntervalSince1970:time];
//        NSString *timeStr = [date dateTimeString2];
        CGSize size = [textBody.text boundingRectWithSize:CGSizeMake(kWeChatScreenWidth/2, MAXFLOAT) options:NSStringDrawingUsesLineFragmentOrigin attributes:@{NSFontAttributeName:[UIFont systemFontOfSize:15.0f]} context:nil].size;
        CGSize realSize = CGSizeMake(size.width + 40, size.height + 40);
        // 聊天按钮的size
        self.chatButton.size = realSize;
        
        
    }else if ([body isKindOfClass:[EMVoiceMessageBody class]]){// 语音类型
        EMVoiceMessageBody *voiceBody = body;
        // 设置图片 和 时间
        [self.chatButton setImage:[UIImage imageNamed:@"chat_receiver_audio_playing_full"] forState:UIControlStateNormal];
        [self.chatButton setTitle:[NSString stringWithFormat:@"%zd'",voiceBody.duration] forState:UIControlStateNormal];
        self.chatButton.size = CGSizeMake(kWeChatAllSubviewHeight + 40, kWeChatAllSubviewHeight + 40);
        self.chatButton.titleEdgeInsets = UIEdgeInsetsMake(0, 10, 0, 0);
        self.chatButton.imageEdgeInsets = UIEdgeInsetsMake(0, 0, 0, 10);
    }else if([body isKindOfClass:[EMImageMessageBody class]]){
        EMImageMessageBody *imgBody = body;
//        imgBody.localPath; 本地大图片
//        imgBody.thumbnailLocalPath, 本地的预览图
//        imgBody.remotePath, 服务端上的大图
//        imgBody.thumbnailRemotePath, 服务端的预览图
        
        self.chatButton.size = CGSizeMake(kWeChatAllSubviewHeight*2 + 40, kWeChatAllSubviewHeight*2 + 40);
        // 获得本地预览图片的路径
        NSString *path = imgBody.thumbnailLocalPath;
        NSFileManager *fileMgr = [NSFileManager defaultManager];
        // 使用sdWedImage下载图片
        // 设置URL
        NSURL *url = nil;
        if ([fileMgr fileExistsAtPath:path]) {
            url = [NSURL fileURLWithPath:path];
        }else{
            url = [NSURL URLWithString:imgBody.thumbnailRemotePath];
        }
        [self.chatButton sd_setImageWithURL:url forState:UIControlStateNormal];
        
    }
    
    
    NSString *chatter = [[EaseMob sharedInstance].chatManager loginInfo][@"username"];
    if ([message.from isEqualToString:chatter]) {// 自己发送的
        [self setBtnImage:@"SenderTextNodeBkg"];
        // 头像在右边
        self.chatIcon.frame = CGRectMake(kWeChatScreenWidth - kWeChatAllSubviewHeight - kWeChatPadding, 30 + kWeChatPadding, kWeChatAllSubviewHeight, kWeChatAllSubviewHeight);
        
        // 聊天消息是左边
        self.chatButton.left = kWeChatScreenWidth - self.chatButton.width - self.chatIcon.width - kWeChatPadding*2;
        
    }else{// 别人发的
        // 头像在右边
        self.chatIcon.frame = CGRectMake(kWeChatPadding,30 + kWeChatPadding, kWeChatAllSubviewHeight, kWeChatAllSubviewHeight);
        
        // 聊天消息是左边
        self.chatButton.left = self.chatIcon.right + kWeChatPadding;
        
        [self setBtnImage:@"ReceiverTextNodeBkg"];
    }
    // Y轴
    self.chatButton.top = self.chatIcon.top;
    
}

- (CGFloat)rowHeight
{
    return self.chatButton.bottom + kWeChatPadding;
}

- (void)setBtnImage:(NSString *)name
{
    //@"SenderTextNodeBkg"
    [self.chatButton setBackgroundImage:[UIImage resizingImageWithName:name] forState:UIControlStateNormal];
    NSString *hightName = [NSString stringWithFormat:@"%@HL",name];
    [self.chatButton setBackgroundImage:[UIImage resizingImageWithName:hightName] forState:UIControlStateHighlighted];
}

- (void)setSelected:(BOOL)selected animated:(BOOL)animated {
    [super setSelected:selected animated:animated];

    // Configure the view for the selected state
}

// 头像按钮的点击
- (void)chatBtnClick:(XMGNButton *)btn
{
    NSLog(@"message = %@",self.message);
    id body = self.message.messageBodies[0];
    if ([body isKindOfClass:[EMVoiceMessageBody class]]) {// 播放语音
        [self playVoice:body];
    }else if([body isKindOfClass:[EMImageMessageBody class]]){
        EMImageMessageBody *imageBody = body;
        // 显示大图片
        if (self.delegate && [self.delegate respondsToSelector:@selector(chatCellWithMessage:)]) {
            [self.delegate chatCellWithMessage:self.message];
        }
    }
}

- (void)playVoice:(EMVoiceMessageBody *)body
{
    EMVoiceMessageBody *voiceBody = body;
    // 获取本地路径
    NSString *path = voiceBody.localPath;
    NSFileManager *fileMgr = [NSFileManager defaultManager];
    // 判断path是否存在
    // 如果是不存在
    if (![fileMgr fileExistsAtPath:path]) {
        // 从远程服务器获取地址
        path = voiceBody.remotePath;
    }
    
    //        NSLog(@"path = %@ voiceBody.localPath = %@  voiceBody.remotePath = %@",path,voiceBody.localPath,voiceBody.remotePath);
    [[EMCDDeviceManager sharedInstance] asyncPlayingWithPath:path completion:^(NSError *error) {
        if (!error) {
            NSLog(@"播放成功");
        }
    }];
}

// 时间的转换
- (NSString *)conversationTime:(long long)time
{
    // 今天 11:20
    // 昨天 23:23
    // 前天以前 11:11
    // 1. 创建一个日历对象
    NSCalendar *calendar = [NSCalendar currentCalendar];
    // 2. 获取当前时间
    NSDate *currentDate = [NSDate date];
    // 3. 获取当前时间的年月日
    NSDateComponents *components = [calendar components:NSCalendarUnitYear | NSCalendarUnitMonth | NSCalendarUnitDay fromDate:currentDate];
    NSInteger currentYear = components.year;
    NSInteger currentMonth = components.month;
    NSInteger currentDay = components.day;
    // 4. 获取发送时间
    NSDate *sendDate = [NSDate dateWithTimeIntervalSince1970:time/1000];
    // 5. 获取发送时间的年月日
    NSDateComponents *sendComponents = [calendar components:NSCalendarUnitYear | NSCalendarUnitMonth | NSCalendarUnitDay fromDate:sendDate];
    NSInteger sendYear = sendComponents.year;
    NSInteger sendMonth =  sendComponents.month;
    NSInteger sendDay = sendComponents.day;
    
    NSDateFormatter *fmt = [[NSDateFormatter alloc]init];
    // 6. 当前时间与发送时间的比较
    if (currentYear == sendYear &&
        currentMonth == sendMonth &&
        currentDay == sendDay) {// 今天
        fmt.dateFormat = @"今天 HH:mm";
    }else if(currentYear == sendYear &&
             currentMonth == sendMonth &&
             currentDay == sendDay + 1){
        fmt.dateFormat = @"昨天 HH:mm";
    }else{
        fmt.dateFormat = @"昨天以前 HH:mm";
    }
    
    return  [fmt stringFromDate:sendDate];
}


@end
