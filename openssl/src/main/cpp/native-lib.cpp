#include <jni.h>
#include <string>
#include <string.h>
#include <iostream>
#include "include/openssl/md5.h"
#include "include/openssl/evp.h"
#include "include/openssl/bio.h"
#include "include/openssl/buffer.h"
#include "encrypt.h"

extern "C"
JNIEXPORT jstring JNICALL
Java_me_sam_openssl_NativeSdk_md5(JNIEnv *env, jobject thiz, jstring text) {
    const char *str = env->GetStringUTFChars(text, 0);
    Encrypt encrypt;
    char *enc_output = encrypt.Base64Encode(str, strlen(str), false);
    env->ReleaseStringUTFChars(text, str);

    return env->NewStringUTF(enc_output);
}

extern "C"
JNIEXPORT jstring JNICALL
Java_me_sam_openssl_NativeSdk_base64Encode(JNIEnv *env, jobject thiz, jstring text) {
    const char *str = env->GetStringUTFChars(text, 0);
    Encrypt encrypt;
    char *enc_output = encrypt.Base64Encode(str, strlen(str), false);
    return env->NewStringUTF(enc_output);
}

extern "C"
JNIEXPORT jstring JNICALL
Java_me_sam_openssl_NativeSdk_base64Decode(JNIEnv *env, jobject thiz, jstring text) {
    const char *str = env->GetStringUTFChars(text, 0);
    Encrypt encrypt;
    char *enc_output = encrypt.Base64Decode(str, strlen(str), false);
    return env->NewStringUTF(enc_output);
}

//extern "C"
//JNIEXPORT jstring JNICALL
//Java_me_sam_openssl_NativeSdk_aesEncode(JNIEnv *env, jobject thiz, jstring text, jstring key) {
//    // TODO: implement aesEncode()
//    return nullptr;
//}
//
//extern "C"
//JNIEXPORT jstring JNICALL
//Java_me_sam_openssl_NativeSdk_aesDecode(JNIEnv *env, jobject thiz, jstring text, jstring key) {
//    // TODO: implement aesDecode()
//    return nullptr;
//}