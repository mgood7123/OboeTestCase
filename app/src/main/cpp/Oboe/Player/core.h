//
// Created by konek on 6/23/2019.
//

#ifndef MEDIA_PLAYER_PRO_CORE_H
#define MEDIA_PLAYER_PRO_CORE_H

#include <include/oboe/Oboe.h>
#include <src/common/OboeDebug.h>
#include <native.h>
#include "../AudioEngine.h"
#include <android/asset_manager_jni.h>


oboe::AudioStream *stream {nullptr};
oboe::AudioStreamBuilder streamBuilder;
AudioEngine AudioEngine;
Mixer Mixer;
AAssetManager *mAssetManager {nullptr};

SoundRecording *currentAudioTrack {nullptr};

#endif //MEDIA_PLAYER_PRO_CORE_H
