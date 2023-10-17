#import "Person.h"

#define XLUserDefault [NSUserDefaults standardUserDefaults]
#define XLAutoSwitchKey @"xl_auto_switch_key"
//图片存放路径 #path = "path"
#define XLFile(path) @"/Library/PreferenceLoader/Preferences/XLWeChat/" #path

/* 对FindFriendEntryViewController 及 numberOfSectionsInTableView 方法做前向声明。
 * 否则无法调用[self numberOfSectionsInTableView:]方法
 */
@interface FindFriendEntryViewController

- (long long)numberOfSectionsInTableView:(id)tableView;

@end

%hook FindFriendEntryViewController

// 一共有多少组
- (long long)numberOfSectionsInTableView:(id)tableView
{
	return %orig + 1;
}

// 每一组有多少行
- (long long)tableView:(id)tableView numberOfRowsInSection:(long long)section
{
	if (section == [self numberOfSectionsInTableView:tableView] - 1) {
		return 2;
	} else {
		return %orig;
	}
}

// 返回对应的cell 
- (id)tableView:(id)tableView cellForRowAtIndexPath:(id)indexPath {
	// 处理最后一组，自己添加的cell 
	if([indexPath section] == [self numberOfSectionsInTableView:tableView] - 1) {  
		NSString *cellId = [indexPath row] == 0 ? @"autoCellId" : @"exitCellId";
		UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:cellId];
		if (!cell){
			cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault 
										  reuseIdentifier:cellId];
			cell.backgroundColor = [UIColor whiteColor];
			//设置图片
			cell.imageView.image = [UIImage imageWithContentsOfFile:XLFile(skull.png)];
		}
		
		if ([indexPath row] == 0) {
	        cell.textLabel.text = @"自动抢红包";
	        
	        UISwitch *switchView = [[UISwitch alloc] init];
	        switchView.on = [XLUserDefault boolForKey:XLAutoSwitchKey];
	        [switchView addTarget:self 
	        			   action:@selector(xl_switchChange:) 
	        	 forControlEvents:UIControlEventValueChanged];
	        cell.accessoryView = switchView;

	    }else if ([indexPath row] == 1){
	        cell.textLabel.text = @"退出微信";
	    }
	    return cell;
	}
	return %orig;
}

- (double)tableView:(id)tableView heightForRowAtIndexPath:(id)indexPath{
	if([indexPath section] != [self numberOfSectionsInTableView:tableView] - 1) {  
		return %orig;
	}else {
		//不是最后一组返回 44 
		return 44;
	}
}

/* 
 * 在%hook和%end内部所写的方法，默认是覆盖当前hook的类中的方法，如果在原类中没有此方法，会崩溃
 * 		   如果想要在原类中增加新的方法，需要在方法前增加 %new 标识
 */
%new
- (void)xl_switchChange:(UISwitch *)switchView{
    [XLUserDefault setBool:switchView.isOn forKey:XLAutoSwitchKey];
    [XLUserDefault synchronize];
}

//cell点击事件
- (void)tableView:(id)tableView didSelectRowAtIndexPath:(id)indexPath
{
	if ([indexPath section] == [self numberOfSectionsInTableView:tableView] - 1){
		if ([indexPath row] == 0){
			[tableView deselectRowAtIndexPath:indexPath animated:YES];

			//测试 Person 
			Person *person = [[Person alloc] init];
			person.age = 10;
			NSLog(@" age is %zd",person.age);
			

		}else if([indexPath row] == 1){
			//exit(0); 不推荐这种方式，会卡顿后才退出
			//调用此函数，直接退出App
			abort();
		}
	}else{
		%orig;
	}
}

%end
