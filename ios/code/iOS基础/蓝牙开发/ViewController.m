//
//  ViewController.m
//  蓝牙开发
//
//  Created by WTW on 2020/3/16.
//  Copyright © 2020 WTW. All rights reserved.
//

/*
 https://juejin.im/post/5cb6a0716fb9a0687c53d021
 https://github.com/coolnameismy/BabyBluetooth
 https://www.jianshu.com/p/c8326afacbea
 https://www.cnblogs.com/QianChia/p/6366915.html
 */

/*
 设备唯一标识符问题：
 在有些时候，需要获取 peripheral 的唯一标示符（比如要做自动连接或绑定用户等操作），但是在搜索到 peripheral 之后，只能拿到 identifier，而且这个 identifier 根据连接的 central 不同而不同。也就是说，不同的手机连上之后，identifier 是不同的。虽然比较坑爹，但是这并不影响你做蓝牙自动连接。
 唯一标示符（并且不会变的）是设备的 MAC 地址，对于 Android 来说，轻轻松松就能拿到，但对于 iOS，目前这一属性还是私有的。
 如果一定有这样的需求（即一定要使用 MAC 地址），可以和硬件工程师沟通，使用下面的某一种方式解决：
    将 MAC 地址写在某一个蓝牙特征中，当我们连接蓝牙设备之后，通过某一个特征获取 MAC 地址。
    将 MAC 地址放在蓝牙设备的广播数据当中，然后在广播的时候，将 MAC 地址以广播的形式发出来，在不建立连接的情况下，就能拿到 MAC 地址。
    我们可以通过蓝牙设备的出厂设备或者后期手动修改蓝牙设备的 name，作为唯一标识。
 */

#import "ViewController.h"
#import <CoreBluetooth/CoreBluetooth.h>

@interface ViewController ()<CBCentralManagerDelegate,CBPeripheralDelegate>
// 中心设备管理者(主设备)
@property (nonatomic,strong) CBCentralManager *centralManager;
// 用来保存被发现的设备
@property (nonatomic,strong) NSMutableArray *peripherals;

// 读特征值
@property (nonatomic,strong) CBCharacteristic *readCharacteristic;
// 写特征值
@property (nonatomic,strong) CBCharacteristic *writeCharateristic;

// 链接超时的定时器
@property (nonatomic,strong) NSTimer *connectTimer;

// 要对连接的外设强引用，否则会报错
// 一个主设备最多可连接7个设备，一个设备最多只能给一个主设备链接，链接成功、失败、断开会进入各自的代理方法
@property (nonatomic,strong) CBPeripheral *peripheral;

//    CBCharacteristic *characteristic;  // 特征
@end

@implementation ViewController

- (NSMutableArray *)peripherals {
    if (!_peripherals) {
        _peripherals = [NSMutableArray array];
    }
    return _peripherals;
}

- (void)viewDidLoad {
    [super viewDidLoad];
    
    // 1、建立中心角色，并设置代理, nil 默认是主队列
    self.centralManager = [[CBCentralManager alloc] initWithDelegate:self queue:nil];
}

#pragma mark - CBCentralManagerDelegate

/*
 typedef NS_ENUM(NSInteger, CBManagerState) {
     CBManagerStateUnknown = 0,
     CBManagerStateResetting,
     CBManagerStateUnsupported,
     CBManagerStateUnauthorized,
     CBManagerStatePoweredOff,
     CBManagerStatePoweredOn,
 }
 */
//主设备状态改变，在初始化CBCentralManager的时候会打开设备，只有当设备正确打开后才能使用
- (void)centralManagerDidUpdateState:(CBCentralManager *)central {
    
    switch (central.state) {
        case CBManagerStateUnknown:
            NSLog(@">>> CBCentralManagerStateUnknown");
            break;
        case CBManagerStateResetting:
            NSLog(@">>> CBCentralManagerStateResetting");
            break;
        case CBManagerStateUnsupported:
            NSLog(@">>> CBCentralManagerStateUnsupported");
            break;
        case CBManagerStateUnauthorized:
            NSLog(@">>> CBCentralManagerStateUnauthorized");
            break;
        case CBManagerStatePoweredOff:
            NSLog(@">>> CBCentralManagerStatePoweredOff");
            break;
        case CBManagerStatePoweredOn:
        {
            NSLog(@">>> CBCentralManagerStatePoweredOn");
            
            // 2、扫描外部外设
            // 第一个参数nil就是扫描周围所有的外设
            // 第二个参数是已发现的设备是否重复扫描 YES为同一设备会多次扫描  nil 时默认为 NO
            [self.centralManager scanForPeripheralsWithServices:nil options:nil];
        }
            break;
        default:
            break;
    }
}

///  发现设备
/// @param central 中心设备
/// @param peripheral 外围设备
/// @param advertisementData 特征数据
/// @param RSSI 信号强度
- (void)centralManager:(CBCentralManager *)central didDiscoverPeripheral:(CBPeripheral *)peripheral advertisementData:(NSDictionary<NSString *,id> *)advertisementData RSSI:(NSNumber *)RSSI {
    
    NSMutableString *string = [NSMutableString stringWithString:@"\n"];
    [string appendFormat:@"NAME: %@\n"            , peripheral.name];
    [string appendFormat:@"UUID(identifier): %@\n", peripheral.identifier];
    [string appendFormat:@"RSSI: %@\n"            , RSSI];
    [string appendFormat:@"adverisement:%@\n"     , advertisementData];
    NSLog(@"\n didDiscoverPeripheral == 发现设备 %@",string);
    
   
    // 设置链接规则
    if ([peripheral.name hasPrefix:@"SMART_"] ||
        [peripheral.name hasPrefix:@"WP-808-"] ||
        [peripheral.name hasPrefix:@"JDY-10-V2.5"] ) {
        
        // 找到设备必须要持有它，否则CBCentralManager中也不会保存peripheral，那么CBPeripheralDelegate中的方法也不会被调用
        if (![self.peripherals containsObject:peripheral]) {
            [self.peripherals addObject:peripheral];
            
            self.peripheral = peripheral;  // 保存当前的外设
        }
        
        // 3、连接设备
        [self.centralManager connectPeripheral:peripheral options:nil];
        
        // 开启一个定时器，监控连接超时的情况
//        self.connectTimer = [NSTimer scheduledTimerWithTimeInterval:5.0 repeats:NO block:^(NSTimer * _Nonnull timer) {
//
//        }];
    }
}

// 连接外设成功
- (void)centralManager:(CBCentralManager *)central didConnectPeripheral:(CBPeripheral *)peripheral {
  
    NSLog(@">>>连接到名称为（%@）的设备-成功",peripheral.name);
    
//    [self.connectTimer invalidate];
//    self.connectTimer = nil;
    
    // 停止扫描
    [self.centralManager stopScan];
    
    //设置的peripheral委托CBPeripheralDelegate
    peripheral.delegate = self;
    
    // 4.1 扫描外设的所有服务
    [peripheral discoverServices:nil];
}

// 连接外设失败
- (void)centralManager:(CBCentralManager *)central didFailToConnectPeripheral:(CBPeripheral *)peripheral error:(NSError *)error {
    NSLog(@">>>连接到名称为（%@）的设备-失败,原因:%@",[peripheral name],[error localizedDescription]);
}

//Peripherals断开连接
- (void)centralManager:(CBCentralManager *)central didDisconnectPeripheral:(CBPeripheral *)peripheral error:(NSError *)error{
    NSLog(@">>>外设连接断开连接 %@: %@\n", [peripheral name], [error localizedDescription]);
}

#pragma mark - CBPeripheralDelegate

// 发现外设服务
- (void)peripheral:(CBPeripheral *)peripheral didDiscoverServices:(NSError *)error {
    NSLog(@">>>扫描到服务：%@",peripheral.services);
    if (error)
    {
        NSLog(@">>>Discovered services for %@ with error: %@", peripheral.name, [error localizedDescription]);
        return;
    }
    
    // 所有外设的服务
    for (CBService *service in peripheral.services) {
         NSLog(@"%@ == %@",service,service.UUID);
        // 根据 UUID 过滤服务 ,仅处理需要的服务
//        if ([service.UUID.UUIDString isEqualToString:@"FFE0"]) {
            // 4.2、获取需要的服务的特征 Characteristics
            [peripheral discoverCharacteristics:nil forService:service];
//        }
    }
}

/*
 接收characteristic 数据有两种方式：
 一种是 readValueForCharacteristic: 主动接收
 另外一种是用 setNotifyValue:forCharacteristic: 订阅，当有数据发送时，可以直接在回调中接收 (对于数据经常变化，采用这种比较好)
 */
// 发现服务里面的所有特征
- (void)peripheral:(CBPeripheral *)peripheral didDiscoverCharacteristicsForService:(CBService *)service error:(NSError *)error {
    
    NSLog(@"发现服务里的所有特征didDiscoverCharacteristicsForService == %@",service.characteristics);
     if (error)
     {
         NSLog(@"error Discovered characteristics for %@ with error: %@", service.UUID, [error localizedDescription]);
         return;
     }
    
    // 扫描特征中的所有特征值和描述
    for (CBCharacteristic *cts in service.characteristics) {
        
        NSLog(@"扫描到服务：%@ 的特征：%@", service.UUID, cts.UUID);
        
        // 找到需要的特征 读的特征 和 写的特性 保存起来，进行数据交互(读和写)
        if ([cts.UUID.UUIDString hasPrefix:@"FFE1"]) { // read
           
            // 如果设备断开直接return
            if (peripheral.state != CBPeripheralStateConnected) return;
            
            // 保存读的特征
            self.readCharacteristic = cts;
            
            if (cts.properties & CBCharacteristicPropertyNotify ||
                cts.properties & CBCharacteristicPropertyIndicate) {
                if (!cts.isNotifying) {
                    [peripheral setNotifyValue:YES forCharacteristic:cts];
                }
            }
            
            // 读取特征值
            [peripheral readValueForCharacteristic:cts];
            
        }
        
        if ([cts.UUID.UUIDString hasPrefix:@"FFE1"]) { // write

            // 保存写的特征
            self.writeCharateristic = cts;

            // 读取特征值
            [peripheral readValueForCharacteristic:cts];
        }
            
        // 读取特征的描述
        [peripheral discoverDescriptorsForCharacteristic:cts];
    }
}

// 获取 Characteristics 的 Descriptor
- (void)peripheral:(CBPeripheral *)peripheral didDiscoverDescriptorsForCharacteristic:(CBCharacteristic *)characteristic error:(NSError *)error {
    
    //打印出Characteristic和他的Descriptors
    NSLog(@"characteristic uuid:%@ descriptors : %@ ",characteristic.UUID,characteristic.descriptors);
    
    // 读取特征描述
    for (CBDescriptor *dp in characteristic.descriptors) {
       
        NSLog(@"搜索到特征：%@ 的 Descriptors：%@", characteristic.UUID, dp.UUID);
        
        // 获取Descriptors的值
        [peripheral readValueForDescriptor:dp];
    }
    
}

// 获取的特征的值 数据
-(void)peripheral:(CBPeripheral *)peripheral didUpdateValueForCharacteristic:(nonnull CBCharacteristic *)characteristic error:(nullable NSError *)error {
    
    //打印出characteristic的UUID和值
    //!注意，value的类型是NSData，具体开发时，会根据外设协议制定的方式去解析数据
    NSLog(@"characteristic uuid:%@  value:%@",characteristic.UUID,characteristic.value);
    
    const char *cstring = [[characteristic.value description] cStringUsingEncoding:NSUTF8StringEncoding];
    NSString *value = @"";
    if (cstring) {
        value = [NSString stringWithCString:cstring encoding:NSUTF8StringEncoding];
        value = [value stringByReplacingOccurrencesOfString:@" " withString:@""];
    }
    
//    if ([value hasPrefix:@"<d1"] &&
//        (value.length == 14 ||
//         value.length == 42)
//        ) {
//        NSString *hexStr = [value substringWithRange:NSMakeRange(3, 8)];
//        NSInteger step = strtoul([hexStr UTF8String], 0, 16);
//        NSString *dateHex = [value substringWithRange:NSMakeRange(11, 2)];
//        NSInteger dateValue = strtoul([dateHex UTF8String], 0, 16);
//
//        NSLog(@"date:%zd == 步数step:%zd",dateValue,step);
//
//    }else if ([value hasPrefix:@"<d1"]) { // 读取到心率数据
//        NSLog(@"获取到心率数据");
//    }else if ([value hasPrefix:@"<90"]) { // 读取到血压数据
//        NSLog(@"获取到心率数据");
//    }else if ([value hasPrefix:@"<e0"]) { // 读取到睡眠数据
//         NSLog(@"获取到睡眠数据");
//    }else if ([value hasPrefix:@"<a5"]) { // 设置时间
//        NSString *status = [value substringWithRange:NSMakeRange(3, 2)];
//        if ([status isEqualToString:@"01"]) {
//           [self openHMSwitch];
//           NSLog(@"时间设置成功啦");
//        }else if ([status isEqualToString:@"00"]){
//           NSLog(@"时间设置失败啦");
//        }
//    }
    
}

//获取到Descriptors的值
-(void)peripheral:(CBPeripheral *)peripheral didUpdateValueForDescriptor:(CBDescriptor *)descriptor error:(NSError *)error{
   //打印出DescriptorsUUID 和value
   //这个descriptor都是对于characteristic的描述，一般都是字符串，所以这里我们转换成字符串去解析
   NSLog(@"获取到 Descriptors：%@ 的值：%@",[NSString stringWithFormat:@"%@",descriptor.UUID],descriptor.value);
}

// 成功写入数据
- (void)peripheral:(CBPeripheral *)peripheral didWriteValueForCharacteristic:(CBCharacteristic *)characteristic error:(NSError *)error {
    
    if (error) {
        
        NSLog(@"Error writing characteristic value: %@",[error localizedDescription]);
        
    }
    
    NSLog(@"写数据完成到特征：%@ 中完成：%@", characteristic.UUID, characteristic.value);
}

///
- (void)peripheral:(CBPeripheral *)peripheral didUpdateNotificationStateForCharacteristic:(CBCharacteristic *)characteristic error:(NSError *)error {
    
    if (error) {
        
        NSLog(@"Error changing notification state: %@",[error localizedDescription]);
        
    }
    
}

//把数据写到Characteristic中   自定义的方法
-(void)writeCharacteristic:(CBPeripheral *)peripheral
            characteristic:(CBCharacteristic *)characteristic
                     value:(NSData *)value{

    //打印出 characteristic 的权限，可以看到有很多种，这是一个NS_OPTIONS，就是可以同时用于好几个值，常见的有read，write，notify，indicate，知知道这几个基本就够用了，前连个是读写权限，后两个都是通知，两种不同的通知方式。
    /*
     typedef NS_OPTIONS(NSUInteger, CBCharacteristicProperties) {
     CBCharacteristicPropertyBroadcast                                                = 0x01,
     CBCharacteristicPropertyRead                                                    = 0x02,
     CBCharacteristicPropertyWriteWithoutResponse                                    = 0x04,
     CBCharacteristicPropertyWrite                                                    = 0x08,
     CBCharacteristicPropertyNotify                                                    = 0x10,
     CBCharacteristicPropertyIndicate                                                = 0x20,
     CBCharacteristicPropertyAuthenticatedSignedWrites                                = 0x40,
     CBCharacteristicPropertyExtendedProperties                                        = 0x80,
     CBCharacteristicPropertyNotifyEncryptionRequired NS_ENUM_AVAILABLE(NA, 6_0)        = 0x100,
     CBCharacteristicPropertyIndicateEncryptionRequired NS_ENUM_AVAILABLE(NA, 6_0)    = 0x200
     };

     */
    NSLog(@"%lu", (unsigned long)characteristic.properties);


    //只有 characteristic.properties 有write的权限才可以写
    if(characteristic.properties & CBCharacteristicPropertyWrite){
        /*
            最好一个type参数可以为CBCharacteristicWriteWithResponse或type:CBCharacteristicWriteWithResponse,区别是是否会有反馈
        */
        [peripheral writeValue:value forCharacteristic:characteristic type:CBCharacteristicWriteWithResponse];
    }else{
        NSLog(@"该字段不可写！");
    }
}

/*
 适时断开连接，对于以下两种情况：
 当 characteristic 不再发送数据时。（可以通过 isNotifying 属性来判断）
 你已经接收到了你所需要的所有数据时。
 
 // 先结束订阅
 [peripheral setNotifyValue:NO forCharacteristic:characteristic];
 // 然后断开连接
 [myCentralManager cancelPeripheralConnection:peripheral];
 */
//停止扫描并断开连接  自定义方法
-(void)disconnectPeripheral:(CBCentralManager *)centralManager
                peripheral:(CBPeripheral *)peripheral{
   //停止扫描
   [self.centralManager stopScan];
   //断开连接
   [self.centralManager cancelPeripheralConnection:peripheral];
}

// 订阅 Characteristic 的通知
// 设置通知，自定义方法
- (void)notifyCharacteristic:(CBPeripheral *)peripheral characteristic:(CBCharacteristic *)characteristic{
    
    // 设置通知，数据通知会进入：didUpdateValueForCharacteristic 方法
    
    [peripheral setNotifyValue:YES forCharacteristic:characteristic];
}

// 取消通知，自定义方法
- (void)cancelNotifyCharacteristic:(CBPeripheral *)peripheral characteristic:(CBCharacteristic *)characteristic{
    
    [peripheral setNotifyValue:NO forCharacteristic:characteristic];
}

// 测试获取数据和设置数据
- (void)touchesBegan:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event {
    

//    Byte b[9]={0};
//    b[0] = 0X68;
//    b[1] = 0x12;
//    b[2] = 0x75;
//    b[3] = 0x02;
//    b[4] = 0x80;
//    b[5] = 0x01;
//    b[6] = 0x87;
//    b[7] = 0xcf;
//    b[8] = 0x16;
    
       Byte b[11]={0};
       b[0] = 0X68;
       b[1] = 0x12;
       b[2] = 0x75;
       b[3] = 0x04;
       b[4] = 0x80;
       b[5] = 0x01;
       b[6] = 0x00;
       b[7] = 0x01;
       b[8] = 0x9a;
       b[9] = 0x64;
       b[10] = 0x16;
          
    NSData *data = [NSData dataWithBytes:&b length:sizeof(b)];
    if (self.writeCharateristic) {
        [self.peripheral writeValue:data forCharacteristic:self.writeCharateristic type:CBCharacteristicWriteWithoutResponse];
//        [self.peripheral readValueForCharacteristic:self.writeCharateristic];
    }

//
//    // 停止测量血压
//    dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(20 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
//        Byte b[2]={0};
//        b[0]=0X90;
//        b[1]=0X00;
//        NSData *data = [NSData dataWithBytes:&b length:sizeof(b)];
//        if (self.writeCharateristic) {
//            [self.peripheral writeValue:data forCharacteristic:self.writeCharateristic type:CBCharacteristicWriteWithResponse];
//            [self.peripheral readValueForCharacteristic:self.writeCharateristic];
//        }
//    });
    
//    // 设置时间
//    NSCalendar *calendar = [NSCalendar currentCalendar];
//    NSDateComponents *components = [calendar components:NSCalendarUnitYear | NSCalendarUnitMonth | NSCalendarUnitDay | NSCalendarUnitHour | NSCalendarUnitMinute | NSCalendarUnitSecond fromDate:[NSDate date]];
//    NSInteger year = components.year;
//    NSInteger month = components.month;
//    NSInteger day = components.day;
//    NSInteger hour = components.hour;
//    NSInteger minute = components.minute;
//    NSInteger second = components.second;
//
//    Byte b[9]={0};
//    b[0]=0XA5;
//    b[1] = year/(16*16);
//    b[2] = year%(16*16);
//    b[3] = month;
//    b[4] = day;
//    b[5] = hour;
//    b[6] = minute;
//    b[7] = second;
//    b[8] = 1;
//    NSData *data = [NSData dataWithBytes:&b length:sizeof(b)];
//    if (self.writeCharateristic) {
//        [self.peripheral writeValue:data forCharacteristic:self.writeCharateristic type:CBCharacteristicWriteWithResponse];
//        [self.peripheral readValueForCharacteristic:self.writeCharateristic];
//    }
}


#pragma mark - private

- (void)openHMSwitch{
    Byte b[20]={0};
    b[0]=0XB8;
    b[1] = 1;
    b[2] = 1;
    b[3] = 1;
    b[4] = 1;
    b[5] = 1;
    b[6] = 0;
    b[7] = 0;
    b[8] = 0;
    b[9] = 0;
    b[10] = 0;
    b[11] = 0;
    b[12] = 0;
    b[13] = 0;
    b[14] = 0;
    b[15] = 0;
    b[16] = 0;
    b[17] = 0;
    b[18] = 0;
    b[19] = 0;
    NSData *data = [NSData dataWithBytes:&b length:sizeof(b)];
    
    if (self.writeCharateristic) {
        CBPeripheral * currentPeripheral = [self.peripherals lastObject];
        [currentPeripheral writeValue:data forCharacteristic:self.writeCharateristic type:CBCharacteristicWriteWithResponse];
        [currentPeripheral readValueForCharacteristic:self.writeCharateristic];
    }
}

@end
