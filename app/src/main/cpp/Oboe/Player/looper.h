//
// Created by konek on 6/23/2019.
//

#ifndef MEDIA_PLAYER_PRO_LOOPER_H
#define MEDIA_PLAYER_PRO_LOOPER_H

#include "core.h"

NATIVE(void, Oboe, Loop)(JNIEnv *env, jobject type, jboolean value) {
    currentAudioTrack->setLooping(value);
}

#endif //MEDIA_PLAYER_PRO_LOOPER_H
