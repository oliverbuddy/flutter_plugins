#import "FlutterW1Plugin.h"
#if __has_include(<flutter_w1/flutter_w1-Swift.h>)
#import <flutter_w1/flutter_w1-Swift.h>
#else
// Support project import fallback if the generated compatibility header
// is not copied when this plugin is created as a library.
// https://forums.swift.org/t/swift-static-libraries-dont-copy-generated-objective-c-header/19816
#import "flutter_w1-Swift.h"
#endif

@implementation FlutterW1Plugin
+ (void)registerWithRegistrar:(NSObject<FlutterPluginRegistrar>*)registrar {
  [SwiftFlutterW1Plugin registerWithRegistrar:registrar];
}
@end
