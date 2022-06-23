import 'package:flutter_test/flutter_test.dart';
import 'package:flutter_w1plus/flutter_w1plus.dart';
import 'package:flutter_w1plus/flutter_w1plus_platform_interface.dart';
import 'package:flutter_w1plus/flutter_w1plus_method_channel.dart';
import 'package:plugin_platform_interface/plugin_platform_interface.dart';

class MockFlutterW1plusPlatform 
    with MockPlatformInterfaceMixin
    implements FlutterW1plusPlatform {

  @override
  Future<String?> getPlatformVersion() => Future.value('42');
}

void main() {
  final FlutterW1plusPlatform initialPlatform = FlutterW1plusPlatform.instance;

  test('$MethodChannelFlutterW1plus is the default instance', () {
    expect(initialPlatform, isInstanceOf<MethodChannelFlutterW1plus>());
  });

  test('getPlatformVersion', () async {
    FlutterW1plus flutterW1plusPlugin = FlutterW1plus();
    MockFlutterW1plusPlatform fakePlatform = MockFlutterW1plusPlatform();
    FlutterW1plusPlatform.instance = fakePlatform;
  
    expect(await flutterW1plusPlugin.getPlatformVersion(), '42');
  });
}
