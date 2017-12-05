package com.example.readcontact;

import android.Manifest;
import android.content.pm.PackageManager;
import android.database.Cursor;
import android.provider.ContactsContract;
import android.support.annotation.NonNull;
import android.support.v4.app.ActivityCompat;
import android.support.v4.content.ContextCompat;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.widget.ArrayAdapter;
import android.widget.ListView;

import java.util.ArrayList;
import java.util.List;

public class MainActivity extends AppCompatActivity {
    ArrayAdapter<String> adapter;
    List<String> contactsList=new ArrayList<String>();

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        ListView listView=(ListView)findViewById(R.id.contacts_view);
        adapter=new ArrayAdapter<String>(this,android.R.layout.simple_list_item_1,
                contactsList);
        listView.setAdapter(adapter);

        if(ContextCompat.checkSelfPermission(this, Manifest.permission.READ_CONTACTS) !=
                PackageManager.PERMISSION_GRANTED){
            Log.d("Contact","No permisison");
            ActivityCompat.requestPermissions(this,new String[]
                    {Manifest.permission.READ_CONTACTS},1);
        }
        else{
            Log.d("Contact","has permisison");
            readContacts();
        }
    }

    private void readContacts(){
        Cursor cursor=null;
        Log.d("Contact","readContacts");
        try{
            cursor=getContentResolver().query(ContactsContract.CommonDataKinds.Phone.CONTENT_URI,
                    null,null,null,null);
            if(cursor != null){
                while(cursor.moveToNext()){
                    String displayName=cursor.getString(cursor.getColumnIndex(
                            ContactsContract.CommonDataKinds.Phone.DISPLAY_NAME
                    ));
                    String number=cursor.getString(cursor.getColumnIndex(
                            ContactsContract.CommonDataKinds.Phone.NUMBER
                    ));
                    Log.d("Contact",displayName +"\n\t"+number);
                    contactsList.add(displayName +"\n\t"+number);
                }
                adapter.notifyDataSetChanged();
            }
        }
        catch (Exception e){
            e.printStackTrace();
        }
        finally {
            if(cursor != null)
                cursor.close();
        }
    }

    @Override
    public void onRequestPermissionsResult(int requestCode, @NonNull String[] permissions,
                                           @NonNull int[] grantResults) {
        switch (requestCode){
            case 1:
                if(grantResults.length > 0  && grantResults[0] ==
                        PackageManager.PERMISSION_GRANTED) {
                    Log.d("Contact","request permisison success");
                    readContacts();
                }
        }
    }
}
