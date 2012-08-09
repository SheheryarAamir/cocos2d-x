#include <stdlib.h>
#include <jni.h>
#include <android/log.h>
#include <android/asset_manager.h>
#include <android/asset_manager_jni.h>
#include "JniHelper.h"
#include "platform/CCFileUtils.h"


#define  LOG_TAG    "Java_org_cocos2dx_lib_Cocos2dxHelper.cpp"
#define  LOGD(...)  __android_log_print(ANDROID_LOG_DEBUG,LOG_TAG,__VA_ARGS__)

extern "C" {
    void Java_org_cocos2dx_lib_Cocos2dxHelper_nativeSetAssetManager(JNIEnv* env, jobject thiz, jobject java_assetmanager) {
        AAssetManager* assetmanager = AAssetManager_fromJava(env, java_assetmanager);
        if (assetmanager == NULL) {
            LOGD("assetmanager == NULL");
            return;
        }
        
        cocos2d::JniHelper::setAssetManager(assetmanager);
    }
    
    void Java_org_cocos2dx_lib_Cocos2dxHelper_nativeSetApkPath(JNIEnv*  env, jobject thiz, jstring apkPath) {
        const char* apkPathChars = env->GetStringUTFChars(apkPath, NULL);
        cocos2d::CCFileUtils::sharedFileUtils()->setResourcePath(apkPathChars);
        env->ReleaseStringUTFChars(apkPath, apkPathChars);
    }

    void Java_org_cocos2dx_lib_Cocos2dxHelper_nativeSetExternalAssetPath(JNIEnv*  env, jobject thiz, jstring externalAssetPath) {
        const char* externalAssetPathChars = env->GetStringUTFChars(externalAssetPath, NULL);
        cocos2d::JniHelper::setExternalAssetPath(externalAssetPathChars);
        env->ReleaseStringUTFChars(externalAssetPath, externalAssetPathChars);
    }
}
