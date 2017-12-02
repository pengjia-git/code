package com.example.sqlitettest;

import android.content.ContentValues;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;

public class MainActivity extends AppCompatActivity {
    private MyDatabaseHelper helper;
    private SQLiteDatabase db;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        helper=new MyDatabaseHelper(this,"BookStore.db",null,1);

        Button button=(Button)findViewById(R.id.database_button);
        button.setOnClickListener(new View.OnClickListener(){
            @Override
            public void onClick(View v) {
                db=helper.getWritableDatabase();
                //db.insert("Book",null,)
            }
        });

//        insert
        button=(Button)findViewById(R.id.add_data);
        button.setOnClickListener(new View.OnClickListener(){
            @Override
            public void onClick(View v) {
                ContentValues values=new ContentValues();
                values.put("name","The Da Vinci Code");
                values.put("author","Dan Brown");
                values.put("pages",454);
                values.put("price",16.96);
                db.insert("Book",null,values);
                values.clear();

                values.put("name","The Lost Symbol");
                values.put("author","Dan Brown");
                values.put("pages",510);
                values.put("price",19.76);
                db.insert("Book",null,values);
                values.clear();
            }
        });

//        update
        button=(Button)findViewById(R.id.update);
        button.setOnClickListener(new View.OnClickListener(){
            @Override
            public void onClick(View v) {
                ContentValues values=new ContentValues();
                values.put("price",18.0);
                db.update("Book",values,"name=?",new String[]{"The Da Vinci Code"});
            }
        });
//      delete
        button=(Button)findViewById(R.id.delete);
        button.setOnClickListener(new View.OnClickListener(){
            @Override
            public void onClick(View v) {
                db=helper.getWritableDatabase();
                db.delete("Book","pages > ?",new String[]{"500"});
            }
        });
//query
        button=(Button)findViewById(R.id.query);
        button.setOnClickListener(new View.OnClickListener(){
            @Override
            public void onClick(View v) {
                db=helper.getWritableDatabase();
                Cursor cursor=db.query("Book",new String[]{"author"},null,null,null,null,null);
                if(cursor.moveToFirst()){
                    do {
//                        String name = cursor.getString(cursor.getColumnIndex("name"));
                        String author = cursor.getString(cursor.getColumnIndex("author"));
//                        int pages = cursor.getInt(cursor.getColumnIndex("pages"));
//                        double price = cursor.getDouble(cursor.getColumnIndex("price"));
//                        Log.d("query", "name="+name+";author="+author+";pages="+pages+";price="+price);
                        Log.d("query", "onClick: "+author);
                    }while (cursor.moveToNext());
                }
                cursor.close();
            }
        });
    }

}
