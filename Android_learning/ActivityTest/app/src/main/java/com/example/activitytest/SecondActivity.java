package com.example.activitytest;

import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;

public class SecondActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.second_layout);
        Intent intent=getIntent();
        Log.d("SecondActivity", "onCreate: "+intent.getStringExtra("extra_data"));
        Button button2=(Button) findViewById(R.id.button2);
        button2.setOnClickListener(new View.OnClickListener(){
            public void onClick(View v){
                Intent intent=new Intent();
                intent.putExtra("data_return","Hello firstactivity");
                setResult(RESULT_OK,intent);
                finish();
            }
        });
    }

    @Override
    protected void onStart() {
        super.onStart();
        Log.d("secondActivity", "onStart: secondActivity!");
    }

    @Override
    protected void onPostResume() {
        super.onPostResume();
        Log.d("secondActivity","onPostResume");
    }

    @Override
    protected void onPause() {
        super.onPause();
        Log.d("secondActivity","onPause");
    }

    @Override
    protected void onStop() {
        super.onStop();
        Log.d("secondActivity","onStop");
    }

    @Override
    protected void onDestroy() {
        super.onDestroy();
        Log.d("secondActivity","onDestroy");
    }
}
