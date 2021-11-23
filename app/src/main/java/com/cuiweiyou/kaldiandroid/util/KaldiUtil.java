package com.cuiweiyou.kaldiandroid.util;

public class KaldiUtil {

    static {
        System.loadLibrary("KaldiUtil"); // 加载cmake生成的库
    }

    public native double KaldiMathLogAdd(double x, double y);

}
