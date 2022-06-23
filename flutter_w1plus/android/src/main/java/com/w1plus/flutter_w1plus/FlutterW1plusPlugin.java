package com.w1plus.flutter_w1plus;

import android.bluetooth.BluetoothGatt;

import androidx.annotation.NonNull;

import com.smtlink.transferprotocolsdk.ble.AnalyticalDataCallBack;
import com.smtlink.transferprotocolsdk.ble.BTMGattCallBack;

import org.json.JSONObject;

import io.flutter.embedding.engine.plugins.FlutterPlugin;
import io.flutter.plugin.common.MethodCall;
import io.flutter.plugin.common.MethodChannel;
import io.flutter.plugin.common.MethodChannel.MethodCallHandler;
import io.flutter.plugin.common.MethodChannel.Result;

/**
 * FlutterW1plusPlugin
 */
public class FlutterW1plusPlugin implements FlutterPlugin, MethodCallHandler {
    /// The MethodChannel that will the communication between Flutter and native Android
    ///
    /// This local reference serves to register the plugin with the Flutter Engine and unregister it
    /// when the Flutter Engine is detached from the Activity
    private MethodChannel channel;

    @Override
    public void onAttachedToEngine(@NonNull FlutterPluginBinding flutterPluginBinding) {
        channel = new MethodChannel(flutterPluginBinding.getBinaryMessenger(), "flutter_w1plus");
        channel.setMethodCallHandler(this);
    }

    @Override
    public void onMethodCall(@NonNull MethodCall call, @NonNull Result result) {
        switch (call.method) {
            case "getPlatformVersion":
                result.success("Android " + android.os.Build.VERSION.RELEASE);
                break;
            case "init":

                //蓝牙状态回调
                MyApplication.sBleManager.setBTMGattCallBack(new BTMGattCallBack() {
                    @Override
                    public void onConnectionStateChange(BluetoothGatt bluetoothGatt, int i, int i1) {

                    }

                    @Override
                    public void onConnected() {

                    }

                    @Override
                    public void onDisConnect() {

                    }
                });

                ///蓝牙数据传输回调
                MyApplication.sBleManager.setAnalyticalDataCallBack(new AnalyticalDataCallBack() {
                    @Override
                    public void jsonObjectData(String s, JSONObject jsonObject) {

                    }

                    @Override
                    public void pushDataProgress(int i, int i1) {

                    }

                    @Override
                    public void pushDataProgressState(int i) {

                    }

                    @Override
                    public void pushDataNotStartedLowBattery() {

                    }
                });

                result.success("success ");
                break;


            case "connect":
                String address = call.argument("address");
                MyApplication.sBleManager.connectGatt(address);
                break;

            case "disconnect":
                MyApplication.sBleManager.disconnectGatt();
                break;
            default:

                result.notImplemented();
                break;
        }
    }

    @Override
    public void onDetachedFromEngine(@NonNull FlutterPluginBinding binding) {
        channel.setMethodCallHandler(null);
    }
}
