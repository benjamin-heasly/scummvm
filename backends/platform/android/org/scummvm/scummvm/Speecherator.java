package org.scummvm.scummvm;

import android.content.Context;
import android.content.Intent;
import android.os.Bundle;
import android.speech.RecognitionListener;
import android.speech.RecognizerIntent;
import android.speech.SpeechRecognizer;

import java.util.ArrayList;

/**
 * Created by ben on 1/3/16.
 */
public class Speecherator {

    public interface Listener {
        void onResults(String results);
        void onError(int error);
    }

    private final Listener listener;

    private final Context context;

    private SpeechRecognizer speechRecognizer;

    public Speecherator(Listener listener, Context context) {
        this.listener = listener;
        this.context = context;
    }

    public void destroyRecognizer() {
        if (null != speechRecognizer) {
            speechRecognizer.destroy();
        }
        speechRecognizer = null;
    }

    public void createRecognizer() {
        destroyRecognizer();
        speechRecognizer = SpeechRecognizer.createSpeechRecognizer(context);
        speechRecognizer.setRecognitionListener(new SpeechListener());
        startRecognizing();
    }

    public void startRecognizing() {
        if (null == speechRecognizer) {
            return;
        }
        speechRecognizer.startListening(getRecognizerIntent());
    }

    private Intent getRecognizerIntent() {
        Intent intent = new Intent();
        intent.putExtra(RecognizerIntent.EXTRA_PARTIAL_RESULTS, false);
        return intent;
    }

    private class SpeechListener implements RecognitionListener {
        @Override
        public void onReadyForSpeech(Bundle params) {
        }

        @Override
        public void onBeginningOfSpeech() {
        }

        @Override
        public void onRmsChanged(float rmsdB) {
        }

        @Override
        public void onBufferReceived(byte[] buffer) {
        }

        @Override
        public void onEndOfSpeech() {
        }

        @Override
        public void onError(int error) {
            if (null == listener) {
                return;
            }

            listener.onError(error);
            if (SpeechRecognizer.ERROR_SPEECH_TIMEOUT == error) {
                createRecognizer();
            }
        }

        @Override
        public void onResults(Bundle results) {
            if (null == listener) {
                return;
            }

            ArrayList<String> speech = results.getStringArrayList(SpeechRecognizer.RESULTS_RECOGNITION);
            if (null != speech && !speech.isEmpty()) {
                listener.onResults(speech.get(0));
            }
            startRecognizing();
        }

        @Override
        public void onPartialResults(Bundle partialResults) {
        }

        @Override
        public void onEvent(int eventType, Bundle params) {
        }
    }
}
