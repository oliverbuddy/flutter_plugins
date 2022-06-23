import 'package:plugin_platform_interface/plugin_platform_interface.dart';

import 'flutter_w1_method_channel.dart';

abstract class FlutterW1Platform extends PlatformInterface {
  /// Constructs a FlutterW1Platform.
  FlutterW1Platform() : super(token: _token);

  static final Object _token = Object();

  static FlutterW1Platform _instance = MethodChannelFlutterW1();

  /// The default instance of [FlutterW1Platform] to use.
  ///
  /// Defaults to [MethodChannelFlutterW1].
  static FlutterW1Platform get instance => _instance;

  /// Platform-specific implementations should set this with their own
  /// platform-specific class that extends [FlutterW1Platform] when
  /// they register themselves.
  static set instance(FlutterW1Platform instance) {
    PlatformInterface.verifyToken(instance, _token);
    _instance = instance;
  }

  Future<String?> getPlatformVersion() {
    throw UnimplementedError('platformVersion() has not been implemented.');
  }
}
