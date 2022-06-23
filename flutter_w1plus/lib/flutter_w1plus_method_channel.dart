import 'package:flutter/foundation.dart';
import 'package:flutter/services.dart';

import 'flutter_w1plus_platform_interface.dart';

/// An implementation of [FlutterW1plusPlatform] that uses method channels.
class MethodChannelFlutterW1plus extends FlutterW1plusPlatform {
  /// The method channel used to interact with the native platform.
  @visibleForTesting
  final methodChannel = const MethodChannel('flutter_w1plus');

  @override
  Future<String?> getPlatformVersion() async {
    final version = await methodChannel.invokeMethod<String>('getPlatformVersion');
    return version;
  }
}
