//
// 这个原本是javac生成的com_cuiweiyou_kaldiandroid_util_KaldiUtil.h文件，
// 直接改后缀名为cpp，并修改代码。
//
// 此cpp文件在jni入口 CMakeLists.txt 中引入进行编译。
//

// 引用Android准备好的
#include <cstring>
#include <jni.h>
#include <cinttypes>
#include <android/log.h>

// 这里引用kaldi及自己写的
#include "kaldi.h" // 这里可以直接include自己需要的h。

#define LOG_TAG "System.out"
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__) // 调用Android的log。

#ifndef _Included_com_cuiweiyou_kaldiandroid_util_KaldiUtil
#define _Included_com_cuiweiyou_kaldiandroid_util_KaldiUtil
#ifdef __cplusplus
extern "C" {
#endif

/*
 * 这个是原h文件声明的函数，这里直接修改为实现函数。
 * Class:     com_cuiweiyou_kaldiandroid_util_KaldiUtil
 * Method:    KaldiMathLogAdd
 * Signature: (DD)D
 */
JNIEXPORT jdouble JNICALL Java_com_cuiweiyou_kaldiandroid_util_KaldiUtil_KaldiMathLogAdd
  (JNIEnv *jniEnv, jobject, jdouble x, jdouble y){

    LOGE("进入JNI的范畴了", "");
    LOGE("调用kaldi的函数", "");

    double v = kaldi::LogAdd(x, y); // 调用 base/kaldi-math.h 中的函数

    LOGE("kaldi计算结束，返回java", "");

    return v;
};

#ifdef __cplusplus
}
#endif
#endif