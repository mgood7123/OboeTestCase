/*
 * Copyright 2018 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef MEDIA_PLAYER_PRO_MIXER_H
#define MEDIA_PLAYER_PRO_MIXER_H


#include "SoundRecording.h"

constexpr int32_t kBufferSize = 192*10; // Temporary buffer is used for mixing
constexpr uint8_t kMaxTracks = 10;
constexpr int32_t kChannelCount = 2;

class Mixer {

public:
    void addTrack(SoundRecording *renderer);
    void renderAudio(int16_t *audioData, int32_t numFrames);
private:

    int16_t *mixingBuffer = new int16_t[kBufferSize]; // TODO: smart pointer
    SoundRecording *mTracks[kMaxTracks]; // TODO: this might be better as a linked list for easy track removal
    uint8_t mNextFreeTrackIndex = 0;
};


#endif //MEDIA_PLAYER_PRO_MIXER_H
