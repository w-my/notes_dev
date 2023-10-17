//
//  TDURLProtocol.swift
//  TDKit_YHY_APP
//
//  Created by WTW on 2021/9/22.
//  参考：https://blog.csdn.net/u014600626/article/details/108195234

import UIKit

let URLProtocolHandledKey = "URLProtocolHandledKey"

/// NSURLProtocol 抽象类
/// 子类化 注册
/*
 /// 注册
 /// 基于 NSURLConnection 或 [NSURLSession sharedSession]  初始化对象创建的请求调用 registerClass 即可
 URLProtocol.registerClass(TDURLProtocol.classForCoder())
 
 /// 基于 NSURLSession 的网络请求，需要通过配置初始化对象
 let config = URLSessionConfiguration.default
 let protocolArr = [TDURLProtocol.classForCoder()]
 config.protocolClasses = protocolArr
 URLSession.init(configuration: config, delegate: self,delegateQueue: OperationQueue.main)

 /// 不需要时注销
 URLProtocol.unregisterClass(TDURLProtocol.classForCoder())
 */

class TDURLProtocol: URLProtocol {

    /// 定义全局的session 用于取消用
    var session: URLSession?
    
    /// 所有注册此Protocol的请求都会经过这个方法的判断, 筛选是否对这个request生成一个NSURLProtocol实例并处理
    override class func canInit(with request: URLRequest) -> Bool {
     
        // 尝试只拦截 http 请求
        if request.url?.scheme?.lowercased() == "http" {
            
            return true
        }
        
        // 看是否已经处理，防止无限循环，根据业务来截取
        if (URLProtocol.property(forKey: URLProtocolHandledKey, in: request) != nil) {
            
            return false
        }
        
        return false
    }
    
    /// 可选方法，对需要拦截的请求进行自定义的处理
    /// 统一处理请求 URLRequest 对象，可以修改头信息和重定向 ，没有特殊需求直接返回 request
    /// 添加请求头或者重定向的时候要判断是否已经修改过或已经重定向，该方法可能会被调用多次
    override class func canonicalRequest(for request: URLRequest) -> URLRequest {
       
        return request
    }
    
    /// 主要是用来判断两个request是否相同，这个方法基本不常用
    /// 判断两个request 是否相同，如果相同可以使用缓存数据，通常只调用父类的实现
    override class func requestIsCacheEquivalent(_ a: URLRequest, to b: URLRequest) -> Bool {
    
        return super.requestIsCacheEquivalent(a, to: b)
    }
    
    /// 初始化protocol实例，所有来源的请求都以NSURLRequest形式接收
    /// 转发 拦截到请求后，并对请求处理定制完以后，需要把请求接着发出去
    override init(request: URLRequest, cachedResponse: CachedURLResponse?, client: URLProtocolClient?) {
        
        return super.init(request: request, cachedResponse: cachedResponse, client: client)
    }
    
    /// 开始请求
    /// 转发的核心方法，当前的request 拦截下来以后可以在这里进行修改信息或者重定向，DNS 解析等
    /// 需要标记已经修改过的请求
    override func startLoading() {
        
        var mutableRequest = self.request
        
        /// 标识处理过，防止多次处理
        URLProtocol.setProperty(true, forKey: URLProtocolHandledKey, in: mutableRequest as! NSMutableURLRequest)
        
        /// 也可以在这里使用本地数据返回出去
        
        /// 使用 nsurlsession 继续把 request 发出去
        let config = URLSessionConfiguration.default
        
        session = URLSession(configuration: config, delegate: self, delegateQueue: OperationQueue.main)
        
        let dataTask = session?.dataTask(with: mutableRequest)
        
        dataTask?.resume()
        
    }
    
    /// 请求结束
    override func stopLoading() {
        session?.invalidateAndCancel()
        session = nil
    }
}

extension TDURLProtocol : URLSessionDelegate {

    /// 接收到返回信息时(还未开始下载), 执行的代理方法
    func urlSession(_ session: URLSession, dataTask: URLSessionDataTask, didReceive response: URLResponse, completionHandler: @escaping (URLSession.ResponseDisposition) -> Void) {
        
        /// 将新的response作为request对应的response
        self.client?.urlProtocol(self, didReceive: response,cacheStoragePolicy: .notAllowed)
        completionHandler(.allow)
    }
    
    
    /// 接收到服务器返回的数据 调用多次
    func urlSession(_ session: URLSession, dataTask: URLSessionDataTask, didReceive data: Data) {
        
        // 打印返回数据
        if let dataStr = String(data: data, encoding: .utf8) {
            
            print("截取到的数据:",dataStr)
        }
        
        /// 设置request对应的 响应数据 response data
        self.client?.urlProtocol(self, didLoad: data)
        
    }
        
    /// 请求结束或者是失败的时候调用
    func urlSession(_ session: URLSession, task: URLSessionTask, didCompleteWithError error: Error?) {
        
        if (error != nil) {
            self.client?.urlProtocol(self, didFailWithError: error!)
        }else {
            self.client?.urlProtocolDidFinishLoading(self)
        }
    }
}
