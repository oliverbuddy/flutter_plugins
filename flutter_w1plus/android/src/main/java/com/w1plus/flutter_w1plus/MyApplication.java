package com.w1plus.flutter_w1plus;

import android.app.Application;

import com.smtlink.transferprotocolsdk.ble.BleTransferManager;


public class MyApplication extends Application {

    static BleTransferManager sBleManager;

    static MyApplication instance;

    static MyApplication getInstance() {
        return instance;
    }

    @Override
    public void onCreate() {
        super.onCreate();
        instance = this;

        sBleManager = BleTransferManager.initialized(this);

    }
}
