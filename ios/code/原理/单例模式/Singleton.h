
/**
 * 使用方式，仅需 .h 文件导入 singleton.h
 * .h 文件  SingletonH(name)
 * .m 文件 SingletonM(name)
 */

#define SingletonH(name) + (instancetype)share##name;

#if __has_feature(objc_arc)  // ARC

#define SingletonM(name) static id _instance; \
                                                           \
+ (instancetype)allocWithZone:(struct _NSZone *)zone { \
    static dispatch_once_t onceToken;               \
    dispatch_once(&onceToken, ^{                    \
        _instance = [super allocWithZone:zone];     \
    });                                             \
    return _instance;                               \
}                                                   \
                                                    \
+ (instancetype)share##name {                       \
    return [[self alloc] init];                     \
}                                                   \
                                                    \
- (id)copyWithZone:(struct _NSZone *)zone{          \
    return _instance;                               \
}                                                   \
                                                    \
- (id)mutableCopyWithZone:(struct _NSZone *)zone{   \
    return _instance;                               \
}

#else  // MRC

#define SingletonM(name) static id _instance; \
                                                          \
+ (instancetype)allocWithZone:(struct _NSZone *)zone { \
   static dispatch_once_t onceToken;               \
   dispatch_once(&onceToken, ^{                    \
       _instance = [super allocWithZone:zone];     \
   });                                             \
   return _instance;                               \
}                                                  \
                                                   \
+ (instancetype)share##name {                      \
   return [[self alloc] init];                     \
}                                                  \
                                                   \
- (id)copyWithZone:(struct _NSZone *)zone{         \
   return _instance;                               \
}                                                  \
                                                   \
- (id)mutableCopyWithZone:(struct _NSZone *)zone{  \
   return _instance;                               \
}                                                  \
- (oneway void)release {                           \
                                                   \
}                                                  \
                                                   \
- (instancetype)retain {                           \
    return _instance;                              \
}                                                  \
                                                   \
- (NSUInteger)retainCount {                        \
    return  MAXFLOAT;                              \
}                                                  \

#endif
