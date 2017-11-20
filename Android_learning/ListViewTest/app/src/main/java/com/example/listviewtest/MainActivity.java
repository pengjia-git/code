package com.example.listviewtest;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.ListView;
import android.widget.Toast;

import java.util.ArrayList;
import java.util.List;

import static android.R.attr.data;

public class MainActivity extends AppCompatActivity {
//    private String[] data={"Apple","Banana","Orange",
//    "Watermelon","Pear","Grape","Pineapple","Strawberry",
//    "Cherry","Mango","pengjia1","pengjia2","pengjia3",
//            "pengjia4","pengjia5","pengjia6",
//            "pengjia7","pengjia8","pengjia9",
//            "pengjia10","pengjia12","pengjia13",
//            "pengjia21","pengjia22","pengjia23",};
    private List<Fruit> fruitList=new ArrayList<>();

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        initFruit();
        FruitAdapter adapter=new FruitAdapter(MainActivity.this,R.layout.fruit_item,fruitList);

        ListView listview=(ListView)findViewById(R.id.list_view);
        listview.setAdapter(adapter);
        listview.setOnItemClickListener(new AdapterView.OnItemClickListener(){
            @Override
            public void onItemClick(AdapterView<?> parent, View view, int position, long id) {
                Fruit fruit=fruitList.get(position);
                Toast.makeText(MainActivity.this,fruit.getName(),Toast.LENGTH_SHORT).show();
            }
        });
    }

    private void initFruit()
    {
        Fruit apple=new Fruit("apple",R.drawable.daxiong1);
        fruitList.add(apple);

        Fruit pear=new Fruit("pear",R.drawable.daxiong3);
        fruitList.add(pear);

        Fruit pear2=new Fruit("pear2",R.drawable.daxiong4);
        fruitList.add(pear2);

    }
}
