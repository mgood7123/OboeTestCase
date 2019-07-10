//
// Created by konek on 6/23/2019.
//

#ifndef MEDIA_PLAYER_PRO_PLAYBACK_H
#define MEDIA_PLAYER_PRO_PLAYBACK_H

#include "core.h"

// TODO: guard against playing without first loading an audio track, in multi track situations such as when using the
//  Mixer, simply relying on currentAudioTrack is unreliable
NATIVE(void, Oboe, Play)(JNIEnv *env, jobject type) {
    if (currentAudioTrack != NULL) {
        LOGW("Oboe_Init: requesting Start");
        oboe::Result result = stream->requestStart();
        LOGW("Oboe_Init: requested Start");
        if (result != oboe::Result::OK) {
            LOGE("Oboe_Play: Failed to start AudioStream . Error: %s", oboe::convertToText(result));
            return;
        }
        currentAudioTrack->setPlaying(true);
    }
}

#endif //MEDIA_PLAYER_PRO_PLAYBACK_H
