/*
 * Copyright (C) Google Inc.
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
#include <random>
#include "sfxman.h"

#define SAMPLES_PER_SEC 8000
#define BUF_SAMPLES_MAX SAMPLES_PER_SEC*5 // 5 seconds
#define DEFAULT_VOLUME 0.9f

static SfxMan *_instance = new SfxMan();
static short _sample_buf[BUF_SAMPLES_MAX];
static volatile bool _bufferActive = false;

SfxMan* SfxMan::GetInstance() {
    return _instance ? _instance : (_instance = new SfxMan());
}

//static bool _checkError(SLresult r, const char *what) {
//    //Do nothing
//    return true;//has error
//}

//static void _bqPlayerCallback(SLAndroidSimpleBufferQueueItf bq, void *context) {
//    _bufferActive = false;
//}


SfxMan::SfxMan() {
   // Note: this initialization code was mostly copied from the NDK audio sample.
   //Do nothing
    mInitOk = false;
}

bool SfxMan::IsIdle() {
    return !_bufferActive;
}

static const char *_parseInt(const char *s, int *result) {
    //Do nothing
    return s;
}

static int _synth(int frequency, int duration, float amplitude, short *sample_buf, int samples) {
    return 0;//Do nothing
}

static void _taper(short *sample_buf, int samples) {
   //DO nothing
}

void SfxMan::PlayTone(const char *tone) {
    //Do nothing
}
