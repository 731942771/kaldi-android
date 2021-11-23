
cmake_minimum_required(VERSION 3.4.1)

# ${CMAKE_SOURCE_DIR} 即本CMakeLists.txt文件所在目录
# 设置一个路径变量KALDI_DIR，对应与CMakeLists.txt同级的 ./kaldi
set(KALDI_DIR ${CMAKE_SOURCE_DIR}/kaldi)

# ${ANDROID_ABI} 对应 build.gradle文件 android / defaultConfig /  ndk / abiFilters 的芯片架构
add_library(libkaldi-base SHARED IMPORTED)
set_target_properties(libkaldi-base PROPERTIES IMPORTED_LOCATION
        ${KALDI_DIR}/lib/${ANDROID_ABI}/libkaldi-base.so)

add_library(libkaldi-chain SHARED IMPORTED)
set_target_properties(libkaldi-chain PROPERTIES IMPORTED_LOCATION
        ${KALDI_DIR}/lib/${ANDROID_ABI}/libkaldi-chain.so)

add_library(libkaldi-decoder SHARED IMPORTED)
set_target_properties(libkaldi-decoder PROPERTIES IMPORTED_LOCATION
        ${KALDI_DIR}/lib/${ANDROID_ABI}/libkaldi-decoder.so)

add_library(libkaldi-feat SHARED IMPORTED)
set_target_properties(libkaldi-feat PROPERTIES IMPORTED_LOCATION
        ${KALDI_DIR}/lib/${ANDROID_ABI}/libkaldi-feat.so)

add_library(libkaldi-fstext SHARED IMPORTED)
set_target_properties(libkaldi-fstext PROPERTIES IMPORTED_LOCATION
        ${KALDI_DIR}/lib/${ANDROID_ABI}/libkaldi-fstext.so)

add_library(libkaldi-gmm SHARED IMPORTED)
set_target_properties(libkaldi-gmm PROPERTIES IMPORTED_LOCATION
        ${KALDI_DIR}/lib/${ANDROID_ABI}/libkaldi-gmm.so)

add_library(libkaldi-hmm SHARED IMPORTED)
set_target_properties(libkaldi-hmm PROPERTIES IMPORTED_LOCATION
        ${KALDI_DIR}/lib/${ANDROID_ABI}/libkaldi-hmm.so)

add_library(libkaldi-ivector SHARED IMPORTED)
set_target_properties(libkaldi-ivector PROPERTIES IMPORTED_LOCATION
        ${KALDI_DIR}/lib/${ANDROID_ABI}/libkaldi-ivector.so)

add_library(libkaldi-kws SHARED IMPORTED)
set_target_properties(libkaldi-kws PROPERTIES IMPORTED_LOCATION
        ${KALDI_DIR}/lib/${ANDROID_ABI}/libkaldi-kws.so)

add_library(libkaldi-lat SHARED IMPORTED)
set_target_properties(libkaldi-lat PROPERTIES IMPORTED_LOCATION
        ${KALDI_DIR}/lib/${ANDROID_ABI}/libkaldi-lat.so)

add_library(libkaldi-lm SHARED IMPORTED)
set_target_properties(libkaldi-lm PROPERTIES IMPORTED_LOCATION
        ${KALDI_DIR}/lib/${ANDROID_ABI}/libkaldi-lm.so)

add_library(libkaldi-matrix SHARED IMPORTED)
set_target_properties(libkaldi-matrix PROPERTIES IMPORTED_LOCATION
        ${KALDI_DIR}/lib/${ANDROID_ABI}/libkaldi-matrix.so)

add_library(libkaldi-nnet SHARED IMPORTED)
set_target_properties(libkaldi-nnet PROPERTIES IMPORTED_LOCATION
        ${KALDI_DIR}/lib/${ANDROID_ABI}/libkaldi-nnet.so)

add_library(libkaldi-nnet2 SHARED IMPORTED)
set_target_properties(libkaldi-nnet2 PROPERTIES IMPORTED_LOCATION
        ${KALDI_DIR}/lib/${ANDROID_ABI}/libkaldi-nnet2.so)

add_library(libkaldi-nnet3 SHARED IMPORTED)
set_target_properties(libkaldi-nnet3 PROPERTIES IMPORTED_LOCATION
        ${KALDI_DIR}/lib/${ANDROID_ABI}/libkaldi-nnet3.so)

add_library(libkaldi-online2 SHARED IMPORTED)
set_target_properties(libkaldi-online2 PROPERTIES IMPORTED_LOCATION
        ${KALDI_DIR}/lib/${ANDROID_ABI}/libkaldi-online2.so)

add_library(libkaldi-rnnlm SHARED IMPORTED)
set_target_properties(libkaldi-rnnlm PROPERTIES IMPORTED_LOCATION
        ${KALDI_DIR}/lib/${ANDROID_ABI}/libkaldi-rnnlm.so)

add_library(libkaldi-sgmm2 SHARED IMPORTED)
set_target_properties(libkaldi-sgmm2 PROPERTIES IMPORTED_LOCATION
        ${KALDI_DIR}/lib/${ANDROID_ABI}/libkaldi-sgmm2.so)

add_library(libkaldi-transform SHARED IMPORTED)
set_target_properties(libkaldi-transform PROPERTIES IMPORTED_LOCATION
        ${KALDI_DIR}/lib/${ANDROID_ABI}/libkaldi-transform.so)

add_library(libkaldi-tree SHARED IMPORTED)
set_target_properties(libkaldi-tree PROPERTIES IMPORTED_LOCATION
        ${KALDI_DIR}/lib/${ANDROID_ABI}/libkaldi-tree.so)

add_library(libkaldi-util SHARED IMPORTED)
set_target_properties(libkaldi-util PROPERTIES IMPORTED_LOCATION
        ${KALDI_DIR}/lib/${ANDROID_ABI}/libkaldi-util.so)

# 自己编写的本地方法类
add_library(KaldiUtil SHARED
            KaldiUtil.cpp) # 相对CMakeLists.txt的路径

target_include_directories(KaldiUtil PRIVATE
                           ${KALDI_DIR}/head) # 自定义本地方法中 include头文件 时拼接的路径

# build application's shared lib
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

# 最终编译的so文件路径：项目/app/build/intermediates/merged_native_libs/debug/out/lib/arm64-v8a
target_link_libraries(KaldiUtil
                      android
                      libkaldi-base # 对应本例演示用的 base/kaldi-math.h
                    #  libkaldi-chain
                    #  libkaldi-decoder
                    #  libkaldi-feat
                    #  libkaldi-fstext
                    #  libkaldi-gmm
                    #  libkaldi-hmm
                    #  libkaldi-ivector
                    #  libkaldi-kws
                    #  libkaldi-lat
                    #  libkaldi-lm
                    #  libkaldi-matrix
                    #  libkaldi-nnet
                    #  libkaldi-nnet2
                    #  libkaldi-nnet3
                    #  libkaldi-online2
                    #  libkaldi-rnnlm
                    #  libkaldi-sgmm2
                    #  libkaldi-transform
                    #  libkaldi-tree
                    #  libkaldi-util
                      log)