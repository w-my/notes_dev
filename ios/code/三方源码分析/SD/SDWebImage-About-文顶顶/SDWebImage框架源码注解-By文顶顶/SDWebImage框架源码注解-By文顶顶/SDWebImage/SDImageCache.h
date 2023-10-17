/*
 * This file is part of the SDWebImage package.
 * (c) Olivier Poitrey <rs@dailymotion.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

#import <Foundation/Foundation.h>
#import "SDWebImageCompat.h"

typedef NS_ENUM(NSInteger, SDImageCacheType) {
    /**
     * The image wasn't available the SDWebImage caches, but was downloaded from the web.
     * 该图片没有使用任何缓存，直接从web上面下载
     */
    SDImageCacheTypeNone,
    /**
     * The image was obtained from the disk cache.
     * 使用了该图片的磁盘缓存
     */
    SDImageCacheTypeDisk,
    /**
     * The image was obtained from the memory cache.
     * 使用了该图片的内存缓存
     */
    SDImageCacheTypeMemory
};

/**
 * 定义SDWebImageQueryCompletedBlock块，处理查询的回调，接受两个参数分别为图片和缓存类型枚举
 */
typedef void(^SDWebImageQueryCompletedBlock)(UIImage *image, SDImageCacheType cacheType);

/**
 * 定义SDWebImageCheckCacheCompletionBlock块，处理内存缓存检查的回调，参数（是否有缓存）
 */
typedef void(^SDWebImageCheckCacheCompletionBlock)(BOOL isInCache);

/**
 * 定义SDWebImageCalculateSizeBlock块，处理缓存空间的回调，接受两个参数分别为文件的大小和总大小
 */
typedef void(^SDWebImageCalculateSizeBlock)(NSUInteger fileCount, NSUInteger totalSize);

/*
 * SDImageCache maintains a memory cache and an optional disk cache. Disk cache write operations are performed
 * asynchronous so it doesn’t add unnecessary latency to the UI.
 *
 * SDImageCache维护一个内存缓存以及一个"可选"的磁盘缓存。磁盘缓存的写入操作是异步执行的，因此不会造成UI的延迟（卡顿）
 */
@interface SDImageCache : NSObject



/**
 * Decompressing images that are downloaded and cached can improve performance but can consume lot of memory.
 * Defaults to YES. Set this to NO if you are experiencing a crash due to excessive memory consumption.
 *  解压缩图片能提高性能，但是会占用较大的内存空间。
 *  默认为YES，如果你的下载任务对内存空间敏感，建议设置为NO
 */
@property (assign, nonatomic) BOOL shouldDecompressImages;

/**
 *  disable iCloud backup [defaults to YES]
 *  禁用iCloud备份,默认为YES
 */
@property (assign, nonatomic) BOOL shouldDisableiCloud;

/**
 * use memory cache [defaults to YES]
 * 使用内存缓存，默认为YES
 */
@property (assign, nonatomic) BOOL shouldCacheImagesInMemory;

/**
 * The maximum "total cost" of the in-memory image cache. The cost function is the number of pixels held in memory.
 * 内存缓存中的最大“总成本”。"成本"是在内存中存储的像素数。成本概念要与NSCache相关
 */
@property (assign, nonatomic) NSUInteger maxMemoryCost;

/**
 * The maximum number of objects the cache should hold.
 * 缓存中可以存放缓存的最大数量，与NSCache相关
 */
@property (assign, nonatomic) NSUInteger maxMemoryCountLimit;

/**
 * The maximum length of time to keep an image in the cache, in seconds
 * 缓存的最长时间，以秒为单位，默认为1周
 */
@property (assign, nonatomic) NSInteger maxCacheAge;

/**
 * The maximum size of the cache, in bytes.
 * 缓存图像总大小，以字节为单位，默认数值为0，表示不作限制
 */
@property (assign, nonatomic) NSUInteger maxCacheSize;

/**
 * Returns global shared cache instance
 * 单例方法，获得一个全局的缓存实例
 *
 * @return SDImageCache global instance
 */
+ (SDImageCache *)sharedImageCache;

/**
 * Init a new cache store with a specific namespace
 * 使用指定的命名空间实例化一个新的缓存存储
 *
 * @param ns The namespace to use for this cache store 缓存存储使用的命名空间
 */
- (id)initWithNamespace:(NSString *)ns;

/**
 * Init a new cache store with a specific namespace and directory
 * 使用指定的命名空间实例化一个新的缓存存储和目录
 *
 * @param ns        The namespace to use for this cache store 缓存存储使用的命名空间
 * @param directory Directory to cache disk images in 磁盘缓存映像所在目录
 */
- (id)initWithNamespace:(NSString *)ns diskCacheDirectory:(NSString *)directory;

/**
 * 设置磁盘缓存路径
 */
-(NSString *)makeDiskCachePath:(NSString*)fullNamespace;

/**
 * Add a read-only cache path to search for images pre-cached by SDImageCache
 * Useful if you want to bundle pre-loaded images with your app
 * 如果希望在 bundle 中存储预加载的图像，可以添加一个只读的缓存路径
 * 让 SDImageCache 从 Bundle 中搜索预先缓存的图像
 *
 * @param path The path to use for this read-only cache path 只读缓存路径(mainBundle中的全路径)
 */
- (void)addReadOnlyCachePath:(NSString *)path;

/**
 * Store an image into memory and disk cache at the given key.
 * 使用指定的键将图像保存到内存和磁盘缓存
 *
 * @param image The image to store  要保存的图片
 * @param key   The unique image cache key, usually it's image absolute URL 图像缓存键，通常是图像的完整 URL
 */
- (void)storeImage:(UIImage *)image forKey:(NSString *)key;

/**
 * Store an image into memory and optionally disk cache at the given key.
 * 使用指定的键将图像保存到内存和可选的磁盘缓存中
 *
 * @param image  The image to store 要保存的图片
 * @param key    The unique image cache key, usually it's image absolute URL  图像缓存键，通常是图像的完整 URL
 * @param toDisk Store the image to disk cache if YES  如果该值为YES，则将图像缓存到磁盘
 */
- (void)storeImage:(UIImage *)image forKey:(NSString *)key toDisk:(BOOL)toDisk;

/**
 * Store an image into memory and optionally disk cache at the given key.
 * 使用指定的键将图像保存到内存和可选的磁盘缓存
 *
 * @param image       The image to store 要保存的图片
 * @param recalculate BOOL indicates if imageData can be used or a new data should be constructed from the UIImage 是否直接使用 imageData，还是从 UIImage 重新构造数据
 * @param imageData   The image data as returned by the server, this representation will be used for disk storage
 *                    instead of converting the given image object into a storable/compressed image format in order
 *                    to save quality and CPU
 *   从服务器返回图像的二进制数据，表示会保存到磁盘，而不是将给定的图像对象转换成一个可存储/可压缩的图像格式，从而保留图片质量并降低 CPU 开销
 * @param key         The unique image cache key, usually it's image absolute URL 图像缓存键，通常是图像的完整 URL
 * @param toDisk      Store the image to disk cache if YES  如果是 YES，则将图像缓存到磁盘
 */
- (void)storeImage:(UIImage *)image recalculateFromImage:(BOOL)recalculate imageData:(NSData *)imageData forKey:(NSString *)key toDisk:(BOOL)toDisk;

#warning 新增加的方法
/**
 * Store image NSData into disk cache at the given key.
 * 根据给定的Key对图片的二进制数据进行磁盘缓存
 *
 * @param imageData The image data to store     图片的二进制数据
 * @param key   The unique image cache key, usually it's image absolute URL 图片的缓存KEY
 */
- (void)storeImageDataToDisk:(NSData *)imageData forKey:(NSString *)key;

/**
 * Query the disk cache asynchronously.
 * 异步查询磁盘缓存
 *
 * @param key The unique key used to store the wanted image 保存图像的键（key）
 */
- (NSOperation *)queryDiskCacheForKey:(NSString *)key done:(SDWebImageQueryCompletedBlock)doneBlock;

/**
 * Query the memory cache synchronously.
 * 同步查询内存缓存
 *
 * @param key The unique key used to store the wanted image 保存图像的键（key）
 */
- (UIImage *)imageFromMemoryCacheForKey:(NSString *)key;

/**
 * Query the disk cache synchronously after checking the memory cache.
 * 查询内存缓存之后同步查询磁盘缓存
 *
 * @param key The unique key used to store the wanted image 保存图像的键（key）
 */
- (UIImage *)imageFromDiskCacheForKey:(NSString *)key;

/**
 * Remove the image from memory and disk cache asynchronously
 * 同步从内存和磁盘缓存删除图像
 *
 * @param key The unique image cache key 图片的缓存Key
 */
- (void)removeImageForKey:(NSString *)key;


/**
 * Remove the image from memory and disk cache asynchronously
 * 异步的从内存和磁盘缓存删除图像
 *
 * @param key             The unique image cache key 图片的缓存键
 * @param completion      An block that should be executed after the image has been removed (optional)  当图片被删除后会调用该block块
 */
- (void)removeImageForKey:(NSString *)key withCompletion:(SDWebImageNoParamsBlock)completion;

/**
 * Remove the image from memory and optionally disk cache asynchronously
 * 异步从内存和可选磁盘缓存删除图像
 *
 * @param key      The unique image cache key 图片的缓存键
 * @param fromDisk Also remove cache entry from disk if YES 如果值为YES，则从磁盘删除缓存
 */
- (void)removeImageForKey:(NSString *)key fromDisk:(BOOL)fromDisk;

/**
 * Remove the image from memory and optionally disk cache asynchronously
 *  异步的从内存和可选磁盘缓存中删除图片
 *
 * @param key             The unique image cache key 图片的缓存键
 * @param fromDisk        Also remove cache entry from disk if YES  如果是 YES，则从磁盘删除缓存
 * @param completion      An block that should be executed after the image has been removed (optional)  当图片被删除后会调用该block块
 */
- (void)removeImageForKey:(NSString *)key fromDisk:(BOOL)fromDisk withCompletion:(SDWebImageNoParamsBlock)completion;

/**
 * Clear all memory cached images
 * 删除图片的所有内存缓存
 */
- (void)clearMemory;

/**
 * Clear all disk cached images. Non-blocking method - returns immediately.
 * 删除所有磁盘缓存中的图片
 * @param completion    An block that should be executed after cache expiration completes (optional) 删除操作后的块代码回调（可选）
 */
- (void)clearDiskOnCompletion:(SDWebImageNoParamsBlock)completion;

/**
 * Clear all disk cached images
 * 删除所有的磁盘缓存
 *
 * @see clearDiskOnCompletion: 参考clearDiskOnCompletion：方法
 */
- (void)clearDisk;

/**
 * Remove all expired cached image from disk. Non-blocking method - returns immediately.
 * 从磁盘中删除所有过期的缓存图像
 * @param completionBlock An block that should be executed after cache expiration completes (optional) 删除操作后的块代码回调（可选）
 */
- (void)cleanDiskWithCompletionBlock:(SDWebImageNoParamsBlock)completionBlock;

/**
 * Remove all expired cached image from disk
 * 从磁盘中删除所有过期的缓存图像
 * @see cleanDiskWithCompletionBlock: 参考cleanDiskWithCompletionBlock：方法
 */
- (void)cleanDisk;

/**
 * Get the size used by the disk cache
 * 获得磁盘缓存占用空间
 */
- (NSUInteger)getSize;

/**
 * Get the number of images in the disk cache
 * 获得磁盘缓存图像的数量（count）
 */
- (NSUInteger)getDiskCount;

/**
 * Asynchronously calculate the disk cache's size.
 *  异步计算磁盘缓存的大小
 */
- (void)calculateSizeWithCompletionBlock:(SDWebImageCalculateSizeBlock)completionBlock;
#warning 下面两个方法用来检查指定的图片是否存在磁盘缓存，区别在于是否异步执行

/**
 *  Async check if image exists in disk cache already (does not load the image)
 *  异步检查图像是否已经在磁盘缓存中存在（不加载图像）
 *
 *  @param key             the key describing the url   图片的缓存Key
 *  @param completionBlock the block to be executed when the check is done. 检查完毕后的block回调
 *  @note the completion block will be always executed on the main queue  completionblock总是在队列（主线程）中执行
 */
- (void)diskImageExistsWithKey:(NSString *)key completion:(SDWebImageCheckCacheCompletionBlock)completionBlock;

/**
 *  Check if image exists in disk cache already (does not load the image)
 *  检查图像是否已经在磁盘缓存中存在（不加载图像）
 *
 *  @param key the key describing the url   图片的缓存Key
 *
 *  @return YES if an image exists for the given key 如果图片已经存在，那么返回YES
 */
- (BOOL)diskImageExistsWithKey:(NSString *)key;

/**
 *  Get the cache path for a certain key (needs the cache path root folder)
 *  获得指定 key 对应的缓存路径(需要指定缓存路径的根目录)
 *
 *  @param key  the key (can be obtained from url using cacheKeyForURL) 键（可以调用cacheKeyForURL方法获得）
 *  @param path the cache path root folder 缓存路径根文件夹
 *
 *  @return the cache path 缓存路径
 */
- (NSString *)cachePathForKey:(NSString *)key inPath:(NSString *)path;

/**
 *  Get the default cache path for a certain key
 *
 *  获得指定 key 的默认缓存路径
 *  @param key the key (can be obtained from url using cacheKeyForURL) 键（可以调用cacheKeyForURL方法获得）
 *
 *  @return the default cache path 默认缓存路径
 */
- (NSString *)defaultCachePathForKey:(NSString *)key;

@end
