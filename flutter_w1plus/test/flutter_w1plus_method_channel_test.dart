import 'package:flutter/services.dart';
import 'package:flutter_test/flutter_test.dart';
import 'package:flutter_w1plus/flutter_w1plus_method_channel.dart';

void main() {
  MethodChannelFlutterW1plus platform = MethodChannelFlutterW1plus();
  const MethodChannel channel = MethodChannel('flutter_w1plus');

  TestWidgetsFlutterBinding.ensureInitialized();

  setUp(() {
    channel.setMockMethodCallHandler((MethodCall methodCall) async {
      return '42';
    });
  });

  tearDown(() {
    channel.setMockMethodCallHandler(null);
  });

  test('getPlatformVersion', () async {
    expect(await platform.getPlatformVersion(), '42');
  });
}
