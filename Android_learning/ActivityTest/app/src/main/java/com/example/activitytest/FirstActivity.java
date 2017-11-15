package com.example.activitytest;

import android.content.DialogInterface;
import android.content.Intent;
import android.net.Uri;
import android.support.v7.app.AlertDialog;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.ImageView;
import android.widget.ProgressBar;
import android.widget.Toast;

import com.google.android.gms.appindexing.Action;
import com.google.android.gms.appindexing.AppIndex;
import com.google.android.gms.appindexing.Thing;
import com.google.android.gms.common.api.GoogleApiClient;

public class FirstActivity extends BaseActivity {

    /**
     * ATTENTION: This was auto-generated to implement the App Indexing API.
     * See https://g.co/AppIndexing/AndroidStudio for more information.
     */
    private GoogleApiClient client;
    private int count=0;
//    private  EditText text;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        Log.d("onCreate", "onCreate: first activity will entern again");
        Log.d("onCreate","first activity Task id is"+getTaskId());
        setContentView(R.layout.first_layout);

        Button button = (Button) findViewById(R.id.button);
        button.setOnClickListener(new View.OnClickListener() {
            private static final String TAG = "FirstActivity";
            @Override
            public void onClick(View v) {
                count++;
                int i = Log.d(TAG, "onClick:" + count);
                EditText text=(EditText) findViewById(R.id.edit_text);
                Log.d(TAG, "onClick: "+text.getText().toString());
                ImageView image=(ImageView) findViewById(R.id.image);
                int image_array[]={R.drawable.daxiong1,
                        R.drawable.daxiong3,
                        R.drawable.daxiong4};
                image.setImageResource(image_array[count%3]);
                ProgressBar progressBar=(ProgressBar)findViewById(R.id.progress);
//                if(count%2 == 1)
//                    progressBar.setVisibility(View.VISIBLE);
//                else
//                    progressBar.setVisibility(View.GONE);
                progressBar.setProgress(count*10);
                //Toast.makeText(FirstActivity.this, "You clicked Button", Toast.LENGTH_SHORT).show();
                //finish();
//                Intent intent=new Intent("com.example.activitytest.ACTION_STAR");
//                 intent.addCategory("com.example.activitytest.jia");
//                Intent intent= new Intent(Intent.ACTION_DIAL);
//                intent.setData(Uri.parse("tel:10086"));
//                Intent intent=new Intent(FirstActivity.this,SecondActivity.class);
                //intent.putExtra("extra_data","Come from first activity");
                //startActivityForResult(intent,1);
//                startActivity(intent);
                AlertDialog.Builder dialog=new AlertDialog.Builder(FirstActivity.this);
                dialog.setTitle("Look Meiren");
                dialog.setMessage("Look down");
                dialog.setCancelable(false);
                dialog.setPositiveButton("OK", new DialogInterface.OnClickListener() {
                    @Override
                    public void onClick(DialogInterface dialog, int which) {

                    }
                });
                dialog.setNegativeButton("No", new DialogInterface.OnClickListener() {
                    @Override
                    public void onClick(DialogInterface dialog, int which) {

                    }
                });
                dialog.show();
            }
        });

        // ATTENTION: This was auto-generated to implement the App Indexing API.
        // See https://g.co/AppIndexing/AndroidStudio for more information.
        client = new GoogleApiClient.Builder(this).addApi(AppIndex.API).build();
    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
       getMenuInflater().inflate(R.menu.main,menu);
        return true;
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        switch (item.getItemId()){
            case R.id.add_item:
                Toast.makeText(this,"You clicked add",Toast.LENGTH_SHORT).show();
                break;
            case R.id.remove_item:
                Toast.makeText(this,"You clicked remove",Toast.LENGTH_SHORT).show();
                break;
            default:
                break;
        }
        return true;
    }

    @Override
    protected void onActivityResult(int requestCode, int resultCode, Intent data) {
        switch (requestCode){
            case 1:
                Log.d("onActivityResult", "onActivityResult: "+data.getStringExtra("data_return"));
        }
    }

    /**
     * ATTENTION: This was auto-generated to implement the App Indexing API.
     * See https://g.co/AppIndexing/AndroidStudio for more information.
     */
    public Action getIndexApiAction() {
        Thing object = new Thing.Builder()
                .setName("First Page") // TODO: Define a title for the content shown.
                // TODO: Make sure this auto-generated URL is correct.
                .setUrl(Uri.parse("http://[ENTER-YOUR-URL-HERE]"))
                .build();
        return new Action.Builder(Action.TYPE_VIEW)
                .setObject(object)
                .setActionStatus(Action.STATUS_TYPE_COMPLETED)
                .build();
    }

    @Override
    public void onStart() {
        super.onStart();

        // ATTENTION: This was auto-generated to implement the App Indexing API.
        // See https://g.co/AppIndexing/AndroidStudio for more information.
        client.connect();
        AppIndex.AppIndexApi.start(client, getIndexApiAction());
    }

    @Override
    public void onStop() {
        super.onStop();

        // ATTENTION: This was auto-generated to implement the App Indexing API.
        // See https://g.co/AppIndexing/AndroidStudio for more information.
        AppIndex.AppIndexApi.end(client, getIndexApiAction());
        client.disconnect();
    }
}
