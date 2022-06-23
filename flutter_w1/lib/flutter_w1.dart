
import 'flutter_w1_platform_interface.dart';

class FlutterW1 {
  Future<String?> getPlatformVersion() {
    return FlutterW1Platform.instance.getPlatformVersion();
  }
}
