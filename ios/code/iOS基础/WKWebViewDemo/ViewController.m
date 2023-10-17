//
//  ViewController.m
//  WKWebViewDemo
//
//  Created by WTW on 2019/12/25.
//  Copyright © 2019 WTW. All rights reserved.
//

/**
 * http://www.jidianba.com
 */

/**
 * 较好的文章：
 * https://www.jianshu.com/p/20cfd4f8c4ff
 * https://github.com/marcuswestin/WebViewJavascriptBridge
 * https://blog.csdn.net/super_man_ww/article/details/101370345
 * https://www.jianshu.com/p/90a90bd13aac
 * https://www.jianshu.com/p/870dba42ec15
 * 常见问题：
 * 在执行goBack 或 reload 或 goToBackForwardListItem 之后请不要马上执行 loadRequest，使用延迟加载
 */

/*
 -[ViewController webView:decidePolicyForNavigationAction:decisionHandler:]
 -[ViewController webView:didStartProvisionalNavigation:]
 -[ViewController webView:decidePolicyForNavigationResponse:decisionHandler:]
 -[ViewController webView:didCommitNavigation:]
 -[ViewController webView:didFinishNavigation:]
 */


#import "ViewController.h"
#import <WebKit/WebKit.h>

@interface ViewController ()<WKUIDelegate,WKNavigationDelegate,WKScriptMessageHandler>

@property (nonatomic,strong) WKWebView *webView;
@property (nonatomic,strong) UIProgressView *progressView;

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    self.webView.backgroundColor = [UIColor whiteColor];
    
    /// KVO 监听加载进度
    [self.webView addObserver:self forKeyPath:@"estimatedProgress" options:NSKeyValueObservingOptionNew context:nil];
    
//    NSURL *url = [NSURL URLWithString:@"http://10.1.8.160/tiens/gitlab-ee/tdmodule-ios/tdkit_home"];
    NSURL *url = [NSURL URLWithString:@"http://www.baidu.com"];
    NSMutableURLRequest *request = [NSMutableURLRequest requestWithURL:url];
    
//    /// 解决首次请求cookie 带不上的问题
//    /// 只要 sharedHTTPCookieStorage 中存在访问第一个页面就不会有问题
//    NSArray * cookies = [NSHTTPCookieStorage sharedHTTPCookieStorage].cookies;
//    NSDictionary *requestHeaderFields = [NSHTTPCookie requestHeaderFieldsWithCookies:cookies];
//    /// 设置请求头
//    request.allHTTPHeaderFields = requestHeaderFields;
    
//    [request addValue:@"testsss=testccc" forHTTPHeaderField:@"Cookie"];
    
    [self.webView loadRequest:request];
    
}

// 声明周期相关的代理
#pragma mark  - WKNavigationDelegate

// 1、发送请求之前，决定是否跳转
//   用户点击网页上链接，需要打开新的页面时，先调用这个方法
// 针对 action 决定是否跳转
- (void)webView:(WKWebView *)webView decidePolicyForNavigationAction:(WKNavigationAction *)navigationAction decisionHandler:(void (^)(WKNavigationActionPolicy))decisionHandler {
   
    NSLog(@"%s %@ %@ %d",__func__,webView.URL,navigationAction.request.URL,navigationAction.targetFrame.isMainFrame);
    
//    WKFrameInfo *sFrame = navigationAction.sourceFrame;  // 出处
//
//    WKFrameInfo *tFrame = navigationAction.targetFrame; // 目标
//
//    tFrame.mainFrame = NO 的时候标识会新开一个页面调用 createWebViewWithConfiguration 方法
    
    // 需要通过 <a href="tel:123456">拨号</a> 来拨打电话
//    if ([navigationAction.request.URL.scheme isEqualToString:@"tel"]) {
//
//        decisionHandler(WKNavigationActionPolicyCancel);
//        NSString * mutStr = [NSString stringWithFormat:@"telprompt://%@",navigationAction.request.URL.resourceSpecifier];
//        // 处理拨打电话逻辑
//
//    }else {
        decisionHandler(WKNavigationActionPolicyAllow);
//    }
}

// 2、开始加载网页时调用
- (void)webView:(WKWebView *)webView didStartProvisionalNavigation:(null_unspecified WKNavigation *)navigation {
    
    NSLog(@"%s",__func__);
    
    // 显示 progressView
    self.progressView.hidden = NO;
    self.progressView.transform = CGAffineTransformMakeScale(1.0f, 1.5f);
    [self.view bringSubviewToFront:self.progressView];
}

//3、收到响应后，决定是否跳转
// 根据导航返回的信息决定是否加载网页
// 根据响应决定是否跳转
- (void)webView:(WKWebView *)webView decidePolicyForNavigationResponse:(WKNavigationResponse *)navigationResponse decisionHandler:(void (^)(WKNavigationResponsePolicy))decisionHandler {
     
    NSLog(@"%s %@",__func__,navigationResponse.response);
    
    // navigationResponse.forMainFrame 标识导航的frame 是否在主frame
    
    decisionHandler(WKNavigationResponsePolicyAllow);
}

// 4、当内容开始返回时调用
- (void)webView:(WKWebView *)webView didCommitNavigation:(null_unspecified WKNavigation *)navigation {
    NSLog(@"%s",__func__);
}

// 5、页面加载完成之后调用
- (void)webView:(WKWebView *)webView didFinishNavigation:(null_unspecified WKNavigation *)navigation {
    NSLog(@"%s",__func__);
    
    // iOS 调用 JS
//    [webView evaluateJavaScript:@"iOSCallJsAlert()" completionHandler:^(id _Nullable object, NSError * _Nullable error) {
//        NSLog(@"error: %@",error);
//    }];
    
    // 隐藏 progressView
    self.progressView.hidden = YES;
}

// 跳转失败的时候调用
- (void)webView:(WKWebView *)webView didFailNavigation:(null_unspecified WKNavigation *)navigation withError:(NSError *)error {
    NSLog(@"%s",__func__);
    
    if (error.code == NSURLErrorCancelled) {
        [self webView:webView didFinishNavigation:navigation];
    }else {
        self.progressView.hidden = YES;
    }
}

// 页面加载失败时调用
// 当报错999的时候可能是上一个页面已经加载完毕，点击返回的时候会去加载缓存而不会再次加载
- (void)webView:(WKWebView *)webView didFailProvisionalNavigation:(null_unspecified WKNavigation *)navigation withError:(NSError *)error {
    NSLog(@"%s %@",__func__,error);
    
    self.progressView.hidden = YES;
}

// 当由服务端进行重定向时触发
- (void)webView:(WKWebView *)webView didReceiveServerRedirectForProvisionalNavigation:(null_unspecified WKNavigation *)navigation {
    NSLog(@"%s",__func__);
}

//当web视图的web内容流程终止时调用，9.0 才可以使用
- (void)webViewWebContentProcessDidTerminate:(WKWebView *)webView  {
    
    /// 这样可以解决加载的网页过大导致的页面白屏问题
    [webView reload];
    
    NSLog(@"%s",__func__);
}

// 进行证书验证时触发，与使用 AFN 进行 HTTPS 证书验证是一样的
// 身份验证处理
//- (void)webView:(WKWebView *)webView didReceiveAuthenticationChallenge:(NSURLAuthenticationChallenge *)challenge completionHandler:(void (^)(NSURLSessionAuthChallengeDisposition disposition, NSURLCredential * _Nullable credential))completionHandler {
//    NSLog(@"%s",__func__);
//}

#pragma mark - WKUIDelegate

// 一定要处理，不然可能会导致需要新开tab的时候导致点击没有反应
// 不能返回原webview 会崩溃
- (WKWebView *)webView:(WKWebView *)webView createWebViewWithConfiguration:(WKWebViewConfiguration *)configuration forNavigationAction:(WKNavigationAction *)navigationAction windowFeatures:(WKWindowFeatures *)windowFeatures {

    // 如下处理是如果要打开新的页面，直接在当前页面去加载要load的请求，然后返回nil，这样可以实现在当前网页打开新的tab了
    // 也可以直接判断targetFrame是否空来进行loadRequest
    WKFrameInfo *frameInfo = navigationAction.targetFrame;

    if (![frameInfo isMainFrame]) {

        [webView loadRequest:navigationAction.request];
    }

    return  nil;
}

/// webView 关闭时回调
- (void)webViewDidClose:(WKWebView *)webView {
    
}

// 警告
// 最常用 前端中调用 alert 函数时，会触发此代理方法， JS 端调用 alert 传的数据可以通过 message 拿到
// 在原生拿到结果后，需要回调 JS ，通过 completionHandler  回调。
- (void)webView:(WKWebView *)webView runJavaScriptAlertPanelWithMessage:(NSString *)message initiatedByFrame:(WKFrameInfo *)frame completionHandler:(void (^)(void))completionHandler {
    
    NSLog(@"message = %@",message);
    
    UIAlertController *alert = [UIAlertController alertControllerWithTitle:@"提示" message:message preferredStyle:UIAlertControllerStyleAlert];
    UIAlertAction *cancelAction = [UIAlertAction actionWithTitle:@"确定" style:UIAlertActionStyleCancel handler:nil];
    [alert addAction:cancelAction];
    [self presentViewController:alert animated:YES completion:nil];
    completionHandler();
}

// 确认框
// JS 端调用 confirm 函数时，会触发此方法， 通过 message 拿到 JS 端传的数据，在 iOS 端显示原生 alter 得到 YES/NO 后，通过 completionHandler 回调给 JS 端
- (void)webView:(WKWebView *)webView runJavaScriptConfirmPanelWithMessage:(NSString *)message initiatedByFrame:(WKFrameInfo *)frame completionHandler:(void (^)(BOOL))completionHandler {
    
    NSLog(@"message = %@",message);
    
    // xxxxxxxxxxx 处理
    
    completionHandler(YES);
}

// 输入框
// JS端调用prompt函数时，会触发此方法,要求输入一段文本,在原生输入得到文本内容后，通过completionHandler回调给JS
- (void)webView:(WKWebView *)webView runJavaScriptTextInputPanelWithPrompt:(NSString *)prompt defaultText:(nullable NSString *)defaultText initiatedByFrame:(WKFrameInfo *)frame completionHandler:(void (^)(NSString * __nullable result))completionHandler
{
   NSLog(@"%s", __FUNCTION__);
   NSLog(@"%@", prompt);
   UIAlertController *alert = [UIAlertController alertControllerWithTitle:@"textinput" message:@"JS调用输入框" preferredStyle:UIAlertControllerStyleAlert];
   [alert addTextFieldWithConfigurationHandler:^(UITextField * _Nonnull textField)
   {
       textField.textColor = [UIColor redColor];
   }];
   [alert addAction:[UIAlertAction actionWithTitle:@"确定" style:UIAlertActionStyleDefault handler:^(UIAlertAction * _Nonnull action)
   {
       completionHandler([[alert.textFields lastObject] text]);
   }]];
       [self presentViewController:alert animated:YES completion:NULL];
}

// 如果设置了 allowsLinkPreview = YES，此方法返回NO 也无法使用3DTouch
- (BOOL)webView:(WKWebView *)webView shouldPreviewElement:(WKPreviewElementInfo *)elementInfo {
    
    return  YES;
}

/// 可以通过此方法来自定义预览页面
- (UIViewController *)webView:(WKWebView *)webView previewingViewControllerForElement:(WKPreviewElementInfo *)elementInfo defaultActions:(NSArray<id<WKPreviewActionItem>> *)previewActions {
    
    return nil;
}

/// 预览弹出的时候调用
- (void)webView:(WKWebView *)webView commitPreviewingViewController:(UIViewController *)previewingViewController {
    
}

#pragma mark - 与 JS 交互
/**
 * JS 调用 OC ：
 * 1、[userContentController addScriptMessageHandler:self name:JS_Function_Name]  在创建wkWebView时，需要将被js调用的方法注册进去,oc与js端对应实现
 * 2、 WKScriptMessageHandler
 * 3、removeScriptMessageHandlerForName
 *
 * 使用 WKWebView ，JS 调用 iOS,JS 端必须使用 window.webkit.messageHandlers.JS_Function_Name.postMessage(null),
 * 其中 JS_Function_Name 是 iOS 端提供 JS 交互的就是 addScriptMessageHandler: name： 的第二个参数
 *  function iOSCallJsAlert()
 *  {
 *     alert('弹个窗，再调用iOS端的JS_Function_Name');
 *     window.webkit.messageHandlers.JS_Function_Name.postMessage({body: 'paramters'});
 *  }
 *  注意： body 内部不能为空什么都不写，不然不会走代理方法,没有参数就写 null
 *
 * iOS 调用 JS ：
 * 只需要知道在 JS 中的函数名和函数需要的参数，通过原生的方法：
 * iOSCallJsAlert() 是 JS 端的函数名称，如果有参数 iOS 端写法: iOSCallJsAlert('p1','p2')
 * [webView evaluateJavaScript:@"iOSCallJsAlert()" completionHandler:nil]
 */

#pragma mark - WKScriptMessageHandler

// js 调用 JS_Function_Name 方法时，会调用此代理方法
// 传递的js message 中不能包含 js 的 function ，如果包含了则收不到回调 （一般js的参数中包含function是为了异步回调，可以把js的function转换为字符串，再传递给OC）
/// JS 想获取返回值的话可以通过异步回调的形式
- (void)userContentController:(WKUserContentController *)userContentController didReceiveScriptMessage:(WKScriptMessage *)message {
    //message.name 注入的JS对象名称
    //message.body 前端传的参数
    NSLog(@"JS 调用 iOS name : %@  body : %@",message.name,message.body);
    
    if ([message.name isEqualToString:@"JS_Function_Name"]) {
        // xxxxx
        NSLog(@"JS_Function_Name");
    }else if([message.name isEqualToString:@"xxx"]){
        NSLog(@"触发了xxx");
    }else {
        
    }
}

#pragma mark - 加载进度显示

- (void)observeValueForKeyPath:(NSString *)keyPath ofObject:(id)object change:(NSDictionary<NSKeyValueChangeKey,id> *)change context:(void *)context {
    if ([keyPath isEqualToString:@"estimatedProgress"]) {
        self.progressView.progress = self.webView.estimatedProgress;
        if (self.progressView.progress == 1) {
            [UIView animateWithDuration:0.25 delay:0.3f options:UIViewAnimationOptionCurveEaseOut animations:^{
                self.progressView.transform = CGAffineTransformMakeScale(1.0f, 1.4f);
            } completion:^(BOOL finished) {
                self.progressView.hidden = YES;
            }];
        }
    }
}

#pragma mark - 清除缓存

/// 清除缓存一般使用 WKWebsiteDataStore
/// 或者直接把沙盒中的cache 文件夹直接干掉即可
- (void) cleanCacheAndCookie {
    // 清除 cookies
    NSHTTPCookie *cookie;
    NSHTTPCookieStorage *storage = [NSHTTPCookieStorage sharedHTTPCookieStorage];
    for (cookie in [storage cookies]) {
        [storage deleteCookie:cookie];
    }
    
    // 清除缓存
    [[NSURLCache sharedURLCache] removeAllCachedResponses];
    NSURLCache *cache = [NSURLCache sharedURLCache];
    [cache removeAllCachedResponses];
    [cache setDiskCapacity:0];
    [cache setMemoryCapacity:0];
    
    WKWebsiteDataStore *dataStore = [WKWebsiteDataStore defaultDataStore];
    [dataStore fetchDataRecordsOfTypes:[WKWebsiteDataStore allWebsiteDataTypes]
                     completionHandler:^(NSArray<WKWebsiteDataRecord *> * _Nonnull records) {
        for (WKWebsiteDataRecord *record in records) {
            [[WKWebsiteDataStore defaultDataStore] removeDataOfTypes:record.dataTypes
                                                       forDataRecords:@[record]
                                                   completionHandler:^{
                NSLog(@"Cookies for %@ deleted successfully",record.displayName);
            }];
        }
    }];
}

#pragma mark - getter

- (WKWebView *)webView {
    if (!_webView) {
        
        /// WKUserContentController 对象为 JS 提供了一种方式，可以将消息发送到 web 视图，并将用户脚本注入到 web 视图中
        /// 添加脚本 删除脚本 读取添加过的脚本等
        WKUserContentController *userContentController = [[WKUserContentController alloc] init];
        
        /// 动态注入脚本
        /// 执行 js 添加 cookies (请求前添加cookies  某些情况下第一次可能会注入不成功可以使用在header中添加 Cookie 的方式)
        NSString *js = @"document.cookie='userId=zhangsan';document.cookie='test_key1=test_value1';";
        WKUserScript *cookieScript = [[WKUserScript alloc] initWithSource:js injectionTime:WKUserScriptInjectionTimeAtDocumentStart forMainFrameOnly:NO];
        [userContentController addUserScript:cookieScript];
        
        /// 测试创建脚本 添加脚本
//        WKUserScript *alertCookie = [[WKUserScript alloc] initWithSource:@"alert(document.cookie);" injectionTime:WKUserScriptInjectionTimeAtDocumentEnd forMainFrameOnly:NO];
//        [userContentController addUserScript:alertCookie];
        
        // 初始化 web 视图配置
        WKWebViewConfiguration *config = [[WKWebViewConfiguration alloc] init];
        config.userContentController = userContentController;
        
        // 注入 JS 对象名称，当 JS 通过对象名称来调用时，我们可以在 WKScriptMessageHandler 代理中接收到
        // 第一个参数是 userContentController 的代理对象
        // 第二个参数是 js 里发送的 postMessage 的对象
        // 为了避免循环引用，必须在dealloc 方法中移除
        
        //[userContentController addScriptMessageHandler:self name:JS_Function_Name];
// 或者如下方式多个名称
//        for (NSString *scriptMessage in self.scriptMessages) {
//            [config.userContentController addScriptMessageHandler:self name:scriptMessage];
//        }
        
        // preferences
        config.preferences.minimumFontSize = 10;
        config.preferences.javaScriptEnabled = YES;  // 默认 YES
        config.preferences.javaScriptCanOpenWindowsAutomatically = NO;  // 默认是 NO
        
        _webView = [[WKWebView alloc] initWithFrame:CGRectMake(0, 0, [UIScreen mainScreen].bounds.size.width,  [UIScreen mainScreen].bounds.size.height) configuration:config];
        
        /// 是否允许右滑返回上个链接，左滑前进
        _webView.allowsBackForwardNavigationGestures = true;
        
        /// 是否支持 3dtouch 预览
        _webView.allowsLinkPreview = YES;
        
        /// 自定义UA
//        _webView.customUserAgent = @"WebViewDemo/1.0.0";
        
        //UIDelegate： webView 的用户界面代理  ，UIDelegate 提供了代表网页呈现本地用户元素的方法
        _webView.UIDelegate = self;
        
        // navigationDelegate ： 导航代理  实现在 webView 接受、加载和完成导航请求过程中触发的自定义行为
        _webView.navigationDelegate = self;
        
        // 可以通过KVO 监听以下属性做出对应的处理
//        _webView.title
//        _webView.URL
//        _webView.canGoBack
//        _webView.canGoForward
//        _webView.estimatedProgress // 进度
//        _webView.isLoading  // 是否正在加载中
        
        [self.view addSubview:_webView];
    }
    return _webView;
}

/*
 {
   "m_lang": "zh-cn",
   "m_curr": "TRY",
   "m_snat": "tr",
   "m_did": "89153554",
   "m_uid": "562",
   "m_token": "H_RqkuBhAlM0Zwa79QchYbHP8wQ=",
   "m_userInfo": "{\"head_url\":\"https://dev-res.tiens.com/pocket/avatar/3.png\",\"nick_name\":\"zhibo\",\"user_type\":2,\"mobile\":\"0086159308273601\",\"email\":\"1123@tiens.com\",\"name\":\"NAGA SUGARA4\",\"distributor_country\":\"KZ\"}"
 }

 */

- (UIProgressView *)progressView {
    if (!_progressView) {
        _progressView = [[UIProgressView alloc] initWithFrame:CGRectMake(0, 40, [UIScreen mainScreen].bounds.size.width, 2)];
        _progressView.backgroundColor = [UIColor blueColor];
        _progressView.transform = CGAffineTransformMakeScale(1.0f, 1.5f);
        _progressView.progressTintColor = [UIColor redColor];
        [self.view addSubview:self.progressView];
    }
    return _progressView;
}

- (void)dealloc {
    [self.webView removeObserver:self forKeyPath:@"estimatedProgress"];
    [self.webView stopLoading];
    [self.webView setNavigationDelegate:nil];
    [self cleanCacheAndCookie];
    // 必须移除，否者会导致循环引用
    [self.webView.configuration.userContentController removeScriptMessageHandlerForName:@"JS_Function_Name"];
}

@end
