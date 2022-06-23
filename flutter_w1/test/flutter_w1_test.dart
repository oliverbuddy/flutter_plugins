import 'package:flutter_test/flutter_test.dart';
import 'package:flutter_w1/flutter_w1.dart';
import 'package:flutter_w1/flutter_w1_platform_interface.dart';
import 'package:flutter_w1/flutter_w1_method_channel.dart';
import 'package:plugin_platform_interface/plugin_platform_interface.dart';

class MockFlutterW1Platform 
    with MockPlatformInterfaceMixin
    implements FlutterW1Platform {

  @override
  Future<String?> getPlatformVersion() => Future.value('42');
}

void main() {
  final FlutterW1Platform initialPlatform = FlutterW1Platform.instance;

  test('$MethodChannelFlutterW1 is the default instance', () {
    expect(initialPlatform, isInstanceOf<MethodChannelFlutterW1>());
  });

  test('getPlatformVersion', () async {
    FlutterW1 flutterW1Plugin = FlutterW1();
    MockFlutterW1Platform fakePlatform = MockFlutterW1Platform();
    FlutterW1Platform.instance = fakePlatform;
  
    expect(await flutterW1Plugin.getPlatformVersion(), '42');
  });
}
