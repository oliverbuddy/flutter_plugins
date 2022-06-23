import Flutter
import UIKit



public class SwiftFlutterW1plusPlugin: NSObject, FlutterPlugin {
    
    
    
    
    
    public static func register(with registrar: FlutterPluginRegistrar) {
        let channel = FlutterMethodChannel(name: "flutter_w1plus", binaryMessenger: registrar.messenger())
        let instance = SwiftFlutterW1plusPlugin()
        registrar.addMethodCallDelegate(instance, channel: channel)
    }
    
    public func handle(_ call: FlutterMethodCall, result: @escaping FlutterResult) {
        
        let method =  call.method;
        
        let manager:
        
        switch(method){
        case "getPlatformVersion":
            result("iOS 123" + UIDevice.current.systemVersion)
            break
        default:
            result(FlutterMethodNotImplemented)
        }
        
    }
    
    
}

