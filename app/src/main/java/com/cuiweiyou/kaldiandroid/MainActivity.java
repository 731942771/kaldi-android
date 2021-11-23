package com.cuiweiyou.kaldiandroid;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.util.Log;

import com.cuiweiyou.kaldiandroid.util.KaldiUtil;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        double v = new KaldiUtil().KaldiMathLogAdd(1, 2);
        Log.e("ard", "这里是java。kaldi计算的结果：" + v);
    }
}