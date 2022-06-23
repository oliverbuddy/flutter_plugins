import 'flutter_w1plus_platform_interface.dart';

class FlutterW1plus {
  Future<String?> getPlatformVersion() {
    return FlutterW1plusPlatform.instance.getPlatformVersion();
  }

  init() {}

//   GET,0 //获取设备详细数据
  getDeviceInfo() {}
//   GET,10 //获取每天计步总数据
  getDailyStepCount() {}

  //   GET,11 //获取当天时间段增量数据
// getDaily
//   GET,12 //获取每天睡眠总数据
  getDailySleepInfo() {}
//   GET,13 //获取当天时间段睡眠数据

//   GET,14 //获取单次心率测试数据
  getSingleheartRate() {}
//   GET,15 //获取闹钟信息
  getAlarmInfo() {}
//   GET,16 //获取motion开关设置
  getMotionSwitch() {}
//   GET,22 //获取单次血压测试数据
  getSingleBloodPressure() {}
//   GET,23 //获取单次血氧测试数据
  getSingleBloodOxygen() {}
//   GET,61 //获取计步历史数据的日期信息
  getStepCountData() {}
//   GET,64 //获取运动历史数据(暂未使用)

//   GET,65 //获取所有的(每次)单项运动历史汇总数据(需要设备有GPS Sensor, 无忽略)
//   GET,66 //询问蓝牙设备连接状态
  getBleConnectStatus() {}
//   GET,67 //推送数据(表盘,应用(游戏),主题,EPO文件,OTA资源文件等)
  getPushData() {}
//   GET,69 //获取气压数据(需要设备有air pressure Sensor)
  getAirPressure() {}
//   GET,70 //获取潜水数据(需要设备有GPS Sensor)
// get
//   GET,71 //获取钓鱼数据(需要设备有GPS和air pressure Sensor)
//   GET,72 //获取联系人数据
  getContactData() {}
//   GET,73 //获取已推送的所有表盘序号
  getAllDialSerial() {}
//   GET,74 //获取已推送的所有主题序号
  getAllThemeSerial() {}
//   GET,75 //获取已推送的所有应用序号
  getAllApplicationSerial() {}
//   GET,101 //获取对应的一次单项运动GPS数据(需要设备有GPS Sensor)

//   APP向设备设置数据的指令头:
//   SET,10 //设置个人信息
  setPersonalInfo() {}
//   SET,11 //设置睡眠信息--暂不支持

//   SET,12 //设置久坐提醒
  setLongSitRemind() {}
//   SET,13 //设置闹钟
  setAlarm() {}
//   SET,14 //由设备发送给APK的指令打开手机相机
  setOpenCamera() {}
//   SET,15 //设置APK是否前/后台运行状态

//   SET,19 //设置喝水提醒
  setDrinkRemind() {}
//   SET,20 //设置手机找手表
  setPhoneFindWatch() {}
//   SET,21 //设置motion 闹钟静音、抬手亮屏、来电拒接

//   SET,30 //设置女性生理期
  setFemalePeriod() {}
//   SET,44 //设置语言
  setLanguage() {}
//   SET,45 //设置时间
  setTime() {}
//   SET,46 //设置单位制式

//   SET,68 //设置天气
  setWeather() {}
//   SET,72 //设置联系人
  setContact() {}
//   SET,73 //卸载表盘
  uninstallDial() {}
//   SET,74 //卸载主题
  uninstallTheme() {}
//   SET,75 //卸载应用
  uninstallApplication() {}
//   SET,77 //设置音乐信息
  setMusicInfo() {}
//   SET,78 //设置时间制式
  setTimeFormat() {}
//   SET,79 //设置屏幕常量
  setScreenLighting() {}
//   SET,80 //设置抬手亮屏
  setLiftWristLightScreen() {}
//   SET,81 //设置勿扰模式
  setDNDMode() {}
//   SET,82 //设置开启震动
  setVibration() {}

//   设备向APP发送的数据指令头: (注:必须要调用"SET,46"后才能接收到SEND返回的数据)

//   SEND,10 //发送计步数据
//   SEND,11 //发送当前时间段增量计步数据(暂未使用)
//   SEND,12 //发送实时连续心率测试数据
//   SEND,13 //设备找手机(APP收到指令做响铃或震动等响应)
//   SEND,14 //发送单次心率测试数据
//   SEND,15 //发送闹钟
//   SEND,16 //发送短信(设备把短信内容和联系人或者号码发送到APP，APP调用API发送短信)
//   SEND,22 //发送单次血压测试数据
//   SEND,23 //发送单次血氧饱和度测试数据
//   SEND,24 //发送设备电量(暂未使用)
//   SEND,62 //发送来电操作(APP收到指令做挂断或接听电话)
//   SEND,69 //发送请求索要EPO数据
// }

}
