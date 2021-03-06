//
//  PLPlayerOption.h
//  PLPlayerKit
//
//  Created by WangSiyu on 2/24/16.
//  Copyright © 2016 qgenius. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 接收/发送数据包超时时间间隔所对应的键值，单位为 s ，默认配置为 10s
 
 @since v1.0.0
 */
extern NSString  * _Nonnull PLPlayerOptionKeyTimeoutIntervalForMediaPackets;

/**
 @abstract 一级缓存大小，单位为 ms，默认为 1000ms，增大该值可以减小播放过程中的卡顿率，但会增大弱网环境的最大累积延迟
 
 @discussion 该缓存存放的是网络层读取到的数据，为保证实时性，超过该缓存池大小的过期音频数据将被丢弃，视频将加速渲染追上音频
 
 @warning 该参数仅对 rtmp 生效
 
 @since v2.1.3
 */
extern NSString  * _Nonnull PLPlayerOptionKeyMaxL1BufferDuration;

/**
 @abstract 默认二级缓存大小，单位为 ms，默认为 1000ms，增大该值可以减小播放过程中的卡顿率，但会增大弱网环境的最大累积延迟
 
 @discussion 该缓存存放的是解码之后待渲染的数据，如果该缓存池满，则二级缓存将不再接收来自一级缓存的数据
 
 @warning 该参数仅对 rtmp 生效
 
 @since v2.1.3
 */
extern NSString  * _Nonnull PLPlayerOptionKeyMaxL2BufferDuration;

/**
 PLPlayer 的可选配置类，在初始化 PLPlayer 对象的时候传入其实例进行 PLPlayer 的可选项配置
 
 @since v1.0.0
 */
@interface PLPlayerOption : NSObject

/**
 @abstract 使用默认配置生成一个 PLPlayerOption 对象
 
 @discussion
 
 @return 生成的 PLPlayerOption 对象
 
 @since v1.0.0
 */
+ (nonnull PLPlayerOption *)defaultOption;

/**
 使用一个 NSDictionary 对象来生成一个 PLPlayerOption 对象
 
 @param dic 用于初始化 PLPlyerOption 对象的 NSDictionary 对象
 
 @return 生成的 PLPlayerOption 对象
 
 @since v1.0.0
 */
+ (nonnull PLPlayerOption *)optionWithDictionary:(nonnull NSDictionary *)dic;

/**
 设置相应的键所对应的值
 
 @param value 要设置的值
 @param key   要设置值的键
 
 @since v1.0.0
 */
- (void)setOptionValue:(nullable id)value forKey:(nonnull NSString *)key;

/**
 获取特定键所对应的值
 
 @param key 要获取值的键名
 
 @return 获取到的值，当该值为 nil 时表示没有找到该键名对应的值。
 
 @since v1.0.0
 */
- (nullable id)optionValueForKey:(nonnull NSString *)key;

/**
 生成一个包含该 PLPlayer 所有键值对信息的 NSDictionary 对象来
 
 @return 所生成的 NSDictionary 对象
 
 @since v1.0.0
 */
- (nonnull NSDictionary *)dictionaryValue;

@end
