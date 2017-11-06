package com.example.helllworld;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;

public class HelloWorldActivity extends AppCompatActivity {
    private static final String TAG = "HelloWorldActivity";
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.hello_world_layout);
        Log.d("HelloWorldActivity","onCreate execute");
        Log.d(TAG, "onCreate:1 ");
        Log.d(TAG, "onCreate:2 ");
        Log.i(TAG, "onCreate: 3");
    }
}
