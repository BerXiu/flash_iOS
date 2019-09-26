//
//  CLShanYanSDKManager.h
//  CL_ShanYanSDK
//
//  Created by wanglijun on 2018/10/29.
//  Copyright © 2018 wanglijun. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#import "CLCompleteResult.h"
#import "CLUIConfigure.h"

NS_ASSUME_NONNULL_BEGIN
@interface CLShanYanSDKManager : NSObject
/**
 预初始化 Block方式
 @param appId 闪验后台申请的appId
 @param appKey 闪验后台申请的appKey
 @param complete 预初始化回调block 
 */
+(void)initWithAppId:(NSString *)appId
              AppKey:(NSString *)appKey
            complete:(nullable CLComplete)complete;


/**
 预取号
 --建议在即将执行一键登录的地方的前60s调用此方法，比如调一键登录的vc的viewdidload中，当初始化的预取号失败的情况下，此调用将有助于提高闪验拉起授权页的速度和成功率
 --不建议频繁的多次调用和在拉起授权页后调用
 */
+(void)preGetPhonenumber:(nullable CLComplete)complete;

/**
 一键登录
 @param clUIConfigure 闪验授权页参数配置
 @param complete 回调block
 */
+(void)quickAuthLoginWithConfigure:(CLUIConfigure *)clUIConfigure
                          complete:(nonnull CLComplete)complete;


/**
 一键登录 区分拉起授权页之前和之后的回调
 
 @param clUIConfigure 闪验授权页参数配置
 @param openLoginAuthListener 拉起授权页监听
 @param oneKeyLoginListener 一键登录监听
 */
+(void)quickAuthLoginWithConfigure:(CLUIConfigure *)clUIConfigure
           openLoginAuthListener:(CLComplete)openLoginAuthListener
                          oneKeyLoginListener:(CLComplete)oneKeyLoginListener;


/**
 关闭授权页
 @param completion dismissViewcontroller`completion
 */
+(void)finishAuthControllerCompletion:( void(^ _Nullable )(void) )completion;



/**************本机认证功能***************/
/**
 本机号码校验
 
 @param phoneNum 输入的手机号码
 @param complete 校验回调
 */
+ (void)mobileCheckWithLocalPhoneNumber:(NSString *)phoneNum
                               complete:(CLComplete)complete;

/**************本机认证功能***************/


/**
 模式控制台日志输出控制（默认关闭）
 @param enable 开关参数
 */
+ (void)printConsoleEnable:(BOOL)enable;
@end

NS_ASSUME_NONNULL_END
