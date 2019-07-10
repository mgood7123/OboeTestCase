cmake_minimum_required(VERSION 3.4.1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")
add_subdirectory (oboeSDK)

include_directories (oboeSDK)
include_directories (native)

add_library (
        TestCase SHARED
        native/AudioTime.cpp
        Oboe/Generator.cpp
        Oboe/AudioEngine.cpp
        Oboe/audio/SoundRecording.cpp
        Oboe/audio/Mixer.cpp
        Oboe/Player.cpp
)

target_link_libraries (
        TestCase
        log
        android
        oboe
        m
)