package com.example.filestoretest;

import android.content.Context;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;

import java.io.BufferedOutputStream;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        String data="data to save;fuck you";
        FileOutputStream out=null;
        BufferedWriter write=null;
        try{
            out=openFileOutput("data_jia", Context.MODE_PRIVATE);
            write=new BufferedWriter(new OutputStreamWriter(out));
            write.write(data);
            write.close();
        }catch (IOException e){
            e.printStackTrace();
        }

        FileInputStream input=null;
        BufferedReader read=null;
        char buf[]=new char[256];
        try{
            int size;

            input=openFileInput("data_jia");
            read=new BufferedReader(new InputStreamReader(input));
            size=read.read(buf,0,256);
            Log.i("filestore",String.valueOf(buf,0,size));
        }catch (IOException e){
            e.printStackTrace();
        }
    }
}
