#line 1 "src/Tweak.x"
#import "Person.h"

#define XLUserDefault [NSUserDefaults standardUserDefaults]
#define XLAutoSwitchKey @"xl_auto_switch_key"

#define XLFile(path) @"/Library/PreferenceLoader/Preferences/XLWeChat/" #path




@interface FindFriendEntryViewController

- (long long)numberOfSectionsInTableView:(id)tableView;

@end


#include <substrate.h>
#if defined(__clang__)
#if __has_feature(objc_arc)
#define _LOGOS_SELF_TYPE_NORMAL __unsafe_unretained
#define _LOGOS_SELF_TYPE_INIT __attribute__((ns_consumed))
#define _LOGOS_SELF_CONST const
#define _LOGOS_RETURN_RETAINED __attribute__((ns_returns_retained))
#else
#define _LOGOS_SELF_TYPE_NORMAL
#define _LOGOS_SELF_TYPE_INIT
#define _LOGOS_SELF_CONST
#define _LOGOS_RETURN_RETAINED
#endif
#else
#define _LOGOS_SELF_TYPE_NORMAL
#define _LOGOS_SELF_TYPE_INIT
#define _LOGOS_SELF_CONST
#define _LOGOS_RETURN_RETAINED
#endif

@class FindFriendEntryViewController; 
static long long (*_logos_orig$_ungrouped$FindFriendEntryViewController$numberOfSectionsInTableView$)(_LOGOS_SELF_TYPE_NORMAL FindFriendEntryViewController* _LOGOS_SELF_CONST, SEL, id); static long long _logos_method$_ungrouped$FindFriendEntryViewController$numberOfSectionsInTableView$(_LOGOS_SELF_TYPE_NORMAL FindFriendEntryViewController* _LOGOS_SELF_CONST, SEL, id); static long long (*_logos_orig$_ungrouped$FindFriendEntryViewController$tableView$numberOfRowsInSection$)(_LOGOS_SELF_TYPE_NORMAL FindFriendEntryViewController* _LOGOS_SELF_CONST, SEL, id, long long); static long long _logos_method$_ungrouped$FindFriendEntryViewController$tableView$numberOfRowsInSection$(_LOGOS_SELF_TYPE_NORMAL FindFriendEntryViewController* _LOGOS_SELF_CONST, SEL, id, long long); static id (*_logos_orig$_ungrouped$FindFriendEntryViewController$tableView$cellForRowAtIndexPath$)(_LOGOS_SELF_TYPE_NORMAL FindFriendEntryViewController* _LOGOS_SELF_CONST, SEL, id, id); static id _logos_method$_ungrouped$FindFriendEntryViewController$tableView$cellForRowAtIndexPath$(_LOGOS_SELF_TYPE_NORMAL FindFriendEntryViewController* _LOGOS_SELF_CONST, SEL, id, id); static double (*_logos_orig$_ungrouped$FindFriendEntryViewController$tableView$heightForRowAtIndexPath$)(_LOGOS_SELF_TYPE_NORMAL FindFriendEntryViewController* _LOGOS_SELF_CONST, SEL, id, id); static double _logos_method$_ungrouped$FindFriendEntryViewController$tableView$heightForRowAtIndexPath$(_LOGOS_SELF_TYPE_NORMAL FindFriendEntryViewController* _LOGOS_SELF_CONST, SEL, id, id); static void _logos_method$_ungrouped$FindFriendEntryViewController$xl_switchChange$(_LOGOS_SELF_TYPE_NORMAL FindFriendEntryViewController* _LOGOS_SELF_CONST, SEL, UISwitch *); static void (*_logos_orig$_ungrouped$FindFriendEntryViewController$tableView$didSelectRowAtIndexPath$)(_LOGOS_SELF_TYPE_NORMAL FindFriendEntryViewController* _LOGOS_SELF_CONST, SEL, id, id); static void _logos_method$_ungrouped$FindFriendEntryViewController$tableView$didSelectRowAtIndexPath$(_LOGOS_SELF_TYPE_NORMAL FindFriendEntryViewController* _LOGOS_SELF_CONST, SEL, id, id); 

#line 17 "src/Tweak.x"




static long long _logos_method$_ungrouped$FindFriendEntryViewController$numberOfSectionsInTableView$(_LOGOS_SELF_TYPE_NORMAL FindFriendEntryViewController* _LOGOS_SELF_CONST __unused self, SEL __unused _cmd, id tableView) {
	return _logos_orig$_ungrouped$FindFriendEntryViewController$numberOfSectionsInTableView$(self, _cmd, tableView) + 1;
}



static long long _logos_method$_ungrouped$FindFriendEntryViewController$tableView$numberOfRowsInSection$(_LOGOS_SELF_TYPE_NORMAL FindFriendEntryViewController* _LOGOS_SELF_CONST __unused self, SEL __unused _cmd, id tableView, long long section) {
	if (section == [self numberOfSectionsInTableView:tableView] - 1) {
		return 2;
	} else {
		return _logos_orig$_ungrouped$FindFriendEntryViewController$tableView$numberOfRowsInSection$(self, _cmd, tableView, section);
	}
}


static id _logos_method$_ungrouped$FindFriendEntryViewController$tableView$cellForRowAtIndexPath$(_LOGOS_SELF_TYPE_NORMAL FindFriendEntryViewController* _LOGOS_SELF_CONST __unused self, SEL __unused _cmd, id tableView, id indexPath) {
	
	if([indexPath section] == [self numberOfSectionsInTableView:tableView] - 1) {  
		NSString *cellId = [indexPath row] == 0 ? @"autoCellId" : @"exitCellId";
		UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:cellId];
		if (!cell){
			cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault 
										  reuseIdentifier:cellId];
			cell.backgroundColor = [UIColor whiteColor];
			
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
	return _logos_orig$_ungrouped$FindFriendEntryViewController$tableView$cellForRowAtIndexPath$(self, _cmd, tableView, indexPath);
}

static double _logos_method$_ungrouped$FindFriendEntryViewController$tableView$heightForRowAtIndexPath$(_LOGOS_SELF_TYPE_NORMAL FindFriendEntryViewController* _LOGOS_SELF_CONST __unused self, SEL __unused _cmd, id tableView, id indexPath){
	if([indexPath section] != [self numberOfSectionsInTableView:tableView] - 1) {  
		return _logos_orig$_ungrouped$FindFriendEntryViewController$tableView$heightForRowAtIndexPath$(self, _cmd, tableView, indexPath);
	}else {
		
		return 44;
	}
}






static void _logos_method$_ungrouped$FindFriendEntryViewController$xl_switchChange$(_LOGOS_SELF_TYPE_NORMAL FindFriendEntryViewController* _LOGOS_SELF_CONST __unused self, SEL __unused _cmd, UISwitch * switchView){
    [XLUserDefault setBool:switchView.isOn forKey:XLAutoSwitchKey];
    [XLUserDefault synchronize];
}



static void _logos_method$_ungrouped$FindFriendEntryViewController$tableView$didSelectRowAtIndexPath$(_LOGOS_SELF_TYPE_NORMAL FindFriendEntryViewController* _LOGOS_SELF_CONST __unused self, SEL __unused _cmd, id tableView, id indexPath) {
	if ([indexPath section] == [self numberOfSectionsInTableView:tableView] - 1){
		if ([indexPath row] == 0){
			[tableView deselectRowAtIndexPath:indexPath animated:YES];

			
			Person *person = [[Person alloc] init];
			person.age = 10;
			NSLog(@" age is %zd",person.age);
			

		}else if([indexPath row] == 1){
			
			
			abort();
		}
	}else{
		_logos_orig$_ungrouped$FindFriendEntryViewController$tableView$didSelectRowAtIndexPath$(self, _cmd, tableView, indexPath);
	}
}


static __attribute__((constructor)) void _logosLocalInit() {
{Class _logos_class$_ungrouped$FindFriendEntryViewController = objc_getClass("FindFriendEntryViewController"); MSHookMessageEx(_logos_class$_ungrouped$FindFriendEntryViewController, @selector(numberOfSectionsInTableView:), (IMP)&_logos_method$_ungrouped$FindFriendEntryViewController$numberOfSectionsInTableView$, (IMP*)&_logos_orig$_ungrouped$FindFriendEntryViewController$numberOfSectionsInTableView$);MSHookMessageEx(_logos_class$_ungrouped$FindFriendEntryViewController, @selector(tableView:numberOfRowsInSection:), (IMP)&_logos_method$_ungrouped$FindFriendEntryViewController$tableView$numberOfRowsInSection$, (IMP*)&_logos_orig$_ungrouped$FindFriendEntryViewController$tableView$numberOfRowsInSection$);MSHookMessageEx(_logos_class$_ungrouped$FindFriendEntryViewController, @selector(tableView:cellForRowAtIndexPath:), (IMP)&_logos_method$_ungrouped$FindFriendEntryViewController$tableView$cellForRowAtIndexPath$, (IMP*)&_logos_orig$_ungrouped$FindFriendEntryViewController$tableView$cellForRowAtIndexPath$);MSHookMessageEx(_logos_class$_ungrouped$FindFriendEntryViewController, @selector(tableView:heightForRowAtIndexPath:), (IMP)&_logos_method$_ungrouped$FindFriendEntryViewController$tableView$heightForRowAtIndexPath$, (IMP*)&_logos_orig$_ungrouped$FindFriendEntryViewController$tableView$heightForRowAtIndexPath$);{ char _typeEncoding[1024]; unsigned int i = 0; _typeEncoding[i] = 'v'; i += 1; _typeEncoding[i] = '@'; i += 1; _typeEncoding[i] = ':'; i += 1; memcpy(_typeEncoding + i, @encode(UISwitch *), strlen(@encode(UISwitch *))); i += strlen(@encode(UISwitch *)); _typeEncoding[i] = '\0'; class_addMethod(_logos_class$_ungrouped$FindFriendEntryViewController, @selector(xl_switchChange:), (IMP)&_logos_method$_ungrouped$FindFriendEntryViewController$xl_switchChange$, _typeEncoding); }MSHookMessageEx(_logos_class$_ungrouped$FindFriendEntryViewController, @selector(tableView:didSelectRowAtIndexPath:), (IMP)&_logos_method$_ungrouped$FindFriendEntryViewController$tableView$didSelectRowAtIndexPath$, (IMP*)&_logos_orig$_ungrouped$FindFriendEntryViewController$tableView$didSelectRowAtIndexPath$);} }
#line 110 "src/Tweak.x"
