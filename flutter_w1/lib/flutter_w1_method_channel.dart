import 'package:flutter/foundation.dart';
import 'package:flutter/services.dart';

import 'flutter_w1_platform_interface.dart';

/// An implementation of [FlutterW1Platform] that uses method channels.
class MethodChannelFlutterW1 extends FlutterW1Platform {
  /// The method channel used to interact with the native platform.
  @visibleForTesting
  final methodChannel = const MethodChannel('flutter_w1');

  @override
  Future<String?> getPlatformVersion() async {
    final version = await methodChannel.invokeMethod<String>('getPlatformVersion');
    return version;
  }
}
