import 'package:plugin_platform_interface/plugin_platform_interface.dart';

import 'flutter_w1plus_method_channel.dart';

abstract class FlutterW1plusPlatform extends PlatformInterface {
  /// Constructs a FlutterW1plusPlatform.
  FlutterW1plusPlatform() : super(token: _token);

  static final Object _token = Object();

  static FlutterW1plusPlatform _instance = MethodChannelFlutterW1plus();

  /// The default instance of [FlutterW1plusPlatform] to use.
  ///
  /// Defaults to [MethodChannelFlutterW1plus].
  static FlutterW1plusPlatform get instance => _instance;
  
  /// Platform-specific implementations should set this with their own
  /// platform-specific class that extends [FlutterW1plusPlatform] when
  /// they register themselves.
  static set instance(FlutterW1plusPlatform instance) {
    PlatformInterface.verifyToken(instance, _token);
    _instance = instance;
  }

  Future<String?> getPlatformVersion() {
    throw UnimplementedError('platformVersion() has not been implemented.');
  }
}
