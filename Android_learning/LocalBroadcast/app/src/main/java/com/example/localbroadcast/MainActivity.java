package com.example.localbroadcast;

import android.support.v4.content.LocalBroadcastManager;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.content.*;
import android.view.View;
import android.widget.Button;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {
    private LocalReceiver localReceiver;
    private LocalBroadcastManager localBroadcastManager;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        localBroadcastManager =localBroadcastManager.getInstance(this);
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        Button button=(Button)findViewById(R.id.local_cast);
        button.setOnClickListener(new View.OnClickListener(){
            @Override
            public void onClick(View v) {
                Intent intent=new Intent("com.example.broadcast.LOCAL_BROADCAST");
                localBroadcastManager.sendBroadcast(intent);
            }
        });

        IntentFilter filter=new IntentFilter("com.example.broadcast.LOCAL_BROADCAST");
        localReceiver=new LocalReceiver();
        localBroadcastManager.registerReceiver(localReceiver,filter);
    }

    class LocalReceiver extends BroadcastReceiver {

        @Override
        public void onReceive(Context context, Intent intent) {
            Toast.makeText(context, "received local broadcast", Toast.LENGTH_SHORT).show();
        }

    }
}
