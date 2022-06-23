//
//  BLEDataManager.h
//  smuu
//
//  Created by smtlink smtlink on 2022/2/17.
//  Copyright © 2022 com.smtlink.smuu. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <CoreBluetooth/CoreBluetooth.h>

NS_ASSUME_NONNULL_BEGIN


typedef enum:NSInteger{
    DialLocationLeftTop = 1,
    DialLocationRightTop,
    DialLocationLeftBottom,
    DialLocationRightBotom,
    DialLocationMid,
}DialLocation;



typedef void(^CallBack)(NSDictionary *dictionary);
typedef void(^VoidBlock)(void);
typedef void(^FailBlock)(void);
typedef void(^SuccessFull)(void);
typedef void(^ArrayBlock)(NSArray *ary);
typedef void(^StatusBack)(NSString *status);


@protocol BLEDataManagerDelegate <NSObject>

/// 推送表盘结果返回
/// @param state 0:失败 1:成功
- (void)sendDialResultMsgState:(NSInteger)state;

@end

@interface BLEDataManager : NSObject

@property (nonatomic,strong) CBPeripheral *writePeripheral;

/// 建议设备和app选择是无响应方式
@property(nonatomic,strong) CBCharacteristic *writeCmdAckChrtcs;

@property (nonatomic,weak) id<BLEDataManagerDelegate> delegate;
/**默认不显示*/
@property (nonatomic,assign) BOOL showLog;


+ (instancetype)manager;

- (void)wristSendCmdAckMsg:(NSData*)data;




/// 解析蓝牙返回的数据
/// @param data 数据
- (void)notifyDataFromPeriperal:(NSData*)data;

/***************************返回解析完的数据*********************************/

/// 连续心率
/// heart:心率值
/// @param block 心率值
- (void)notifyContinuationHeartBlock:(CallBack)block;

/// 实时步数
/// 重要！！！ 只有同步完单位  - (void)asyncDeviceUnit:(NSString*)uint 后，设备才主动返回实时计步数据
/// calorie:卡路里，单位kal，带一位小数点，如3212，实际是321.2kal
/// date:2022-3-2
/// distance:距离，单位m，带一位小数点，如6721，实际是672.1m
/// step:步数
/// @param block 计步数据 设备每10分钟保留一次数据
- (void)notifyCurrentStepBlock:(CallBack)block;


/// 相机状态
/// @param block  camera 状态  1表示打开相机  2表示拍照  0表示关闭相机
- (void)notifyCameraStatusBlock:(CallBack)block;


/// 血压主动返回
/// @param block 血压值
- (void)notifyBloodDataBlock:(CallBack)block;


/// 心率主动返回
/// @param block 心率值
- (void)notifyHeartDataBlock:(CallBack)block;

/// 设备返回 同步12/24时间制
/// @param block  0:12 1:24(默认24小时制)
- (void)notifyHourFormatBlock:(StatusBack)block;

/// 同步长时间亮屏
/// @param block 0:关闭  1:开
- (void)notifyTimeLightBlock:(StatusBack)block;

///同步长时间亮屏
/// @param block 0:关闭  1:开
- (void)notifyDisturbBlock:(StatusBack)block;

/// 同步震动开关
/// @param block 0:关闭  1:开
- (void)notifyShakeBlock:(StatusBack)block;

/// 订阅闹钟数据
/// array:闹钟数据 W1设备ringe和type这两项用不上，默认0 只用到date、flag和weeks
- (void)notifyClockMsgInfoBlock:(void(^)(NSArray *ary))block;

/// 血氧主动返回
/// @param block 血氧值
- (void)notifyOxgenDataBlock:(CallBack)block;


/// 设备主动返回电量
/// @param block 当前电量
- (void)notifyBatteryNumberBlock:(void(^)(NSString *battery))block;

/***************************发送数据**********默认20byte一包数据，分包发送***********************/


///同步12/24时间制 0:12 1:24(默认24小时制)
- (void)updateHourFormatTips:(BOOL)status;

///同步长时间亮屏 0:关闭  1:开
- (void)updateTimeLightTips:(BOOL)status;
///同步勿扰开关 0:关闭  1:开
- (void)updateDisturbTips:(BOOL)status;
///同步震动开关 0:关闭  1:开
- (void)updateShakeTips:(BOOL)status;

/// 设置抬手亮屏
/// @param start 开始时间
/// @param end 结束时间
/// @param status 开/关 0:关闭  1:开
- (void)updateLightDurationStart:(NSString *)start end:(NSString *)end status:(BOOL)status;

/**********主题提醒**********/

/// 获取设备已经存在的主题提醒信息
/// @param block 提醒信息
- (void)getThemeClockInfoBlock:(ArrayBlock)block;

/// 卸载主题闹钟
/// @param block 结果
- (void)uploadThemeClockBlock:(VoidBlock)block;


/// 获取已经安装的表盘下标数组
/// @param block 表盘下标数组
- (void)getInstallDialInfoBlock:(void(^)(NSArray *ary))block;


/// 卸载已经安装的表盘
/// @param index 表盘下标
- (void)uploadDeviceInstallInfo:(NSInteger)index;


/// 喝水提醒
/// @param status 0: 关闭   1:打开
- (void)asyncWaterStatus:(NSInteger)status;


/// 设置闹钟 dict必须包含 星期 铃声 类型和状态
/// date 时间 08:00
/// weeks 周日～周六   0101010。生效天为长度为7的字符串，0表示不使用，1为开启，周日开始算起，0111111=周一到周六闹钟启用，周日不用如果全部为0，表示闹钟响一次
/// ringe  闹钟铃声，0到4，代表铃声1到铃声5。w1设备没用改选项，默认0。
/// type 提示类型，0：仅响铃，1：仅震动，2：震动及响铃。w1设备没用改选项，默认0。
/// flag  闹钟是否开启使用，0：表示不开启，1表示开启
/// @param array 设置闹钟信息 W1最多可以设置3个闹钟
- (void)setClockMsgArray:(NSArray<NSDictionary*>*)array successfull:(SuccessFull)successfull fail:(FailBlock)fail;


/// 设置久坐提醒
/// @param time : 久坐提醒时间，单位为分钟，范围为0到90分钟，以30一个阶梯变化，0表示关闭久坐提醒
/// @param block 结果返回
- (void)setLongSitTime:(NSString*)time block:(VoidBlock)block;

/// 重要！！！！ App连接成功后，发送模式切换    APK运行状态(ON/OFF=是否在前台运行:1表示APK在前台运行 设备发送数据； 0表示APK不在前台运行 设备不发送数据)
- (void)setAPKActivityWithOnoff:(NSInteger)onoff;


/// 获取app与手机之间通信是否正常
/// @param block 有数据返回则通讯正常
- (void)getIsBluetoothOKBlock:(void(^)(NSInteger staus))block;

/// 获取设备信息
///  bt_address: 蓝牙3.0地址
/// deviceId:barCode设备唯一标识，手动写入
/// name：终端名字串号
/// software_version:软件版本号
/// version:协议版本号
/// start: "08:00" 抬手亮屏开始时间
/// end: "22:00" 抬手亮屏结束时间
/// status: 1 抬手亮屏状态 0:关闭  1:开启
/// screen_light: 1 屏幕常亮   0:关闭  1:开启
/// shake: 1 震动 0:关闭  1:开启
/// time_format: 1 12时间制式  默认0:24  1:12
/// disturb_mode: 1 勿扰模式 0:关闭  1:开启
/// @param block 设备详情信息
- (void)getDeviceInfoBlock:(CallBack)block;

/// 获取总的计步数据
/// calorie:卡路里 单位kal，带一位小数点，如3212，实际是321.2kal
/// date：日期   2022-3-2
/// distance:距离 单位m，带一位小数点，如6721，实际是672.1m
/// step :步数
/// @param block 字典
- (void)getPedometerInfoDayBlock:(CallBack)block;


/// 获取计步详情
/// date :2022-3-2
/// dataArr: 0|0|0 step|distance|calorie   step=步数 distance=距离，单位m，带一位小数点，如6721，实际是672.1m calorie=卡路里，单位kal，带一位小数点，如3212，实际是321.2kal
/// @param block 计步数据 114组数据， 设备每10分钟保留一次数据  总计步数据是10分钟保存一次数据
/// @param dateStr nil 默认为当天时间 dateStr格式：yyyy-MM-dd
- (void)getPedometerInfoTime:(NSString *)dateStr stepBlock:(CallBack)block;


/// 睡眠总数
/// date:2022-3-1
/// hour: 00:00 睡眠时长
/// mode  0: 未进入睡眠    1：轻度睡眠     2：深度睡眠
/// time = 22:0 开始时间
/// @param block 睡眠数据
- (void)getSleepInfoBlock:(CallBack)block;

/// 获取睡眠详情
/// date :2022-3-2
/// dataArr: 0|0|0 step|distance|calorie   step=步数 distance=距离，单位m，带一位小数点，如6721，实际是672.1m calorie=卡路里，单位kal，带一位小数点，如3212，实际是321.2kal
/// @param block 计步数据 设备每10分钟保留一次数据
- (void)getSleepInfoTimeBlock:(CallBack)block;

/// 血压
/// bmp1:105 收缩压
/// bmp2:76 舒张压
/// date_time:2022-3-2 13:51:41
/// @param block 血压返回值
- (void)getSigleBloodPressureBlock:(CallBack)block;

/// 单次测量心率
/// date_time:时间 2022-3-2 13:49:55
/// heart :心率值 66 （或者返回24小时内心率值0|0|0|0|0|0|0|0|0|88|0|0|0|0|109|0|104|98|0|0|0|0|0|0，记录在整点时间上）
/// @param block 心率数据
- (void)getSigleHeartBlock:(CallBack)block;

/// 血氧
/// date_time:2022-3-2 13:52:21
/// oxgen血氧值: 96
/// @param block 血氧数据
- (void)getOxgenBlock:(CallBack)block;


/// 获取闹钟数据
/// array:闹钟数据
- (void)getClockMsgInfoBlock:(void(^)(NSArray *ary))block;

/// 找手环
/// @param status 0: 结束查找    1:开始查找
- (void)findDevice:(NSString*)status;


/// 手环找手机
/// @param block 0:停止。1:查找
- (void)findPhoneStatusBlock:(CallBack)block;

/// 设置单位 该指令发完后，实时计步才主动返回
/// @param uint 0: 公制   1:英制
- (void)asyncDeviceUnit:(NSString*)uint;


/// 同步语言
/// @param language 语言
- (void)asyncLanguage:(NSString*)language;


/// motion设置
/// @param clock 闹钟。0: 关闭    1:打开
/// @param light 抬手亮屏。0: 关闭    1:打开
/// @param phone 来电拒接。0: 关闭    1:打开
- (void)asyncMotionClock:(NSInteger)clock light:(NSInteger)light phone:(NSInteger)phone;

///  同步时间
/// @param format 12小时制。 24小时制。 0:跟随手机系统
- (void)asyncTimeSynch:(NSInteger)format;

/// 同步ancs消息提醒
/// @param msg 顺序不能错，切记，切记 打开所有推送、电话、短息、QQ、微信、facebook、twitter、Google、LinkedIn、whatsApp、Line、Instagram、Snapchat、其他推送
- (void)asyncANCSMsg:(NSString*)msg;



/**********************************表盘相关*********************************************/
/**在发送表盘数据的时候最好把ancs通知信息给关闭，保证app只处理表盘数据，推送完成后在发送ancs开关状态*/


/// ota 资源拼包
/// @param data 图片数据
/// @param block 返回结果
- (void)configurationResOtaData:(NSData*)data block:(void(^)(NSArray *array))block;



/// 时间事件握手
/// @param ary 图片数据
/// @param count 闹钟个数
/// @param successs 成功
/// @param failer 失败
- (void)handleClockEventAry:(NSArray*)ary count:(NSInteger)count success:(SuccessFull)successs failer:(FailBlock)failer;



/// ota 资源升级
/// @param data 图片资源
/// @param successs 成功
/// @param failer 失败
- (void)handleResMsgData:(NSData*)data success:(SuccessFull)successs failer:(FailBlock)failer;



/// 拼接时间事件数据 时间顺序和图片都顺序一一对应
/// @param data_ary bmp图片
/// @param clock 时间数据 目前暂定20个闹钟
- (void)configurationlockEventPicData:(NSArray*)data_ary clock:(NSArray*)clock block:(ArrayBlock)block;


/// 表盘数据较小的话，先发送握手，再组数据包，如果表盘较大的话，建议先组数据包，再发送握手信息
/// 普通表盘握手信息
/// @param index 表盘的当前下标。设备生成数据bin的时候，已经生成，即截取bin名字 eg：....dyn_swatch_7.data 下标就是：7
/// @param successs 返回成功
/// @param failer 失败
- (void)handleMsgIndex:(NSString*)index success:(SuccessFull)successs failer:(FailBlock)failer;


/// 自定义表盘握手信息 发送表盘之前发送握手信息 可以修改时间标签的颜色、位置和背景图
/// @param location 时间在表盘中的位置 上、左、下、右、中
/// @param flag 表盘下表 表盘名字中的数字
/// @param successs 返回成功
/// @param failer 失败
- (void)handleCustomMsgFlag:(NSInteger)flag location:(DialLocation)location success:(SuccessFull)successs failer:(FailBlock)failer;


/// 构建默认表盘数据
/// @param data 表盘数据
- (void)configurationDialDefaultData:(NSData*)data block:(ArrayBlock)block;


/// 自定义表盘 选择一张图片作为表盘的背景图 w1图片数据要旋转90度
/// @param binData 原数据
/// @param rtk_pre_data 前景图数据 替换掉原数据 图片要转bmp
/// @param rtk_bg_data 背景图数据 替换掉原数据 图片要转bmp
/// @param rtk_rgb_data 颜色数据 替换掉原数据
/// @param pre_width 前景图宽度 默认:160
/// @param pre_height 前景图高度 默认:187
/// @param bg_width 背景图宽度 默认:240
/// @param bg_height 背景图高度 默认:280
- (void)customDialData:(NSData*)binData rtk_pre_data:(NSData*)rtk_pre_data rtk_bg_data:(NSData*)rtk_bg_data pre_width:(CGFloat)pre_width pre_height:(CGFloat)pre_height bg_width:(CGFloat)bg_width bg_height:(CGFloat)bg_height rtk_rgb_data:(NSData*)rtk_rgb_data block:(ArrayBlock)block;


@end

NS_ASSUME_NONNULL_END
