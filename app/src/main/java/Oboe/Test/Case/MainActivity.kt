package Oboe.Test.Case

import android.content.Context
import android.content.res.AssetManager
import android.media.AudioManager
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import kotlinx.android.synthetic.main.activity_main.*

external fun Oboe_Init(sampleRate: Int, framesPerBurst: Int)
external fun Oboe_LoadTrackFromAssets(asset: String, assetManager: AssetManager)
external fun Oboe_Play()
external fun Oboe_Loop(value: Boolean)

class MainActivity : AppCompatActivity() {

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        val audioManager = getSystemService(Context.AUDIO_SERVICE) as AudioManager
        val sampleRateStr = audioManager.getProperty(AudioManager.PROPERTY_OUTPUT_SAMPLE_RATE)
        val defaultSampleRate = Integer.parseInt(sampleRateStr)
        val framesPerBurstStr = audioManager.getProperty(AudioManager.PROPERTY_OUTPUT_FRAMES_PER_BUFFER)
        val defaultFramesPerBurst = Integer.parseInt(framesPerBurstStr)
        System.loadLibrary("TestCase")
        Oboe_Init(defaultSampleRate, defaultFramesPerBurst)
        Oboe_LoadTrackFromAssets("00001313_48000.raw", assets)
        Oboe_Loop(true)
        Oboe_Play()
    }
}
