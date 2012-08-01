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
    void Java_org_cocos2dx_lib_Cocos2dxHelper_nativeSetAssetManager(JNIEnv* env, jclass clazz, jobject java_assetmanager) {
        LOGD("nativeSetAssetManager");
        
        AAssetManager* assetmanager = AAssetManager_fromJava(env, java_assetmanager);
        if (NULL == assetmanager) {
            LOGD("assetmanager : is NULL");
            return;
        }
        
        cocos2d::JniHelper::setAssetManager(assetmanager);
        
        LOGD("... assetmanager set successfully.");
    }
    
    void Java_org_cocos2dx_lib_Cocos2dxHelper_nativeSetPaths(JNIEnv*  env, jclass clazz, jstring apkPath) {
        const char* str = env->GetStringUTFChars(apkPath, NULL);

        cocos2d::CCFileUtils::sharedFileUtils()->setResourcePath(str);

        env->ReleaseStringUTFChars(apkPath, str);
    }
}
