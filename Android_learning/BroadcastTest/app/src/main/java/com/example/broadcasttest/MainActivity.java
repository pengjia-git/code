package com.example.broadcasttest;

import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.content.IntentFilter;
import android.net.ConnectivityManager;
import android.net.NetworkInfo;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {
    private IntentFilter intentFilter;
    private NetworkChangeReceiver networkChangeRecevier;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        intentFilter =new IntentFilter();
        intentFilter.addAction("android.net.conn.CONNECTIVITY_CHANGE");
        networkChangeRecevier=new NetworkChangeReceiver();
        registerReceiver(networkChangeRecevier,intentFilter);
    }

    @Override
    protected void onDestroy() {
        super.onDestroy();
        unregisterReceiver(networkChangeRecevier);
    }

    class NetworkChangeReceiver extends BroadcastReceiver{
        @Override
        public void onReceive(Context context, Intent intent) {
            ConnectivityManager connectivityManager=(ConnectivityManager)getSystemService(
                    Context.CONNECTIVITY_SERVICE
            );
            NetworkInfo networkInfo=connectivityManager.getActiveNetworkInfo();
            if(networkInfo != null && networkInfo.isConnected())
                Toast.makeText(context,"network is connected",Toast.LENGTH_SHORT).show();
            else
                Toast.makeText(context,"network isn,t connected",Toast.LENGTH_SHORT).show();
        }
    }
}
