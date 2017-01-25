
/*
 * File DTimer.cpp in project RRUtils
 * 
 * Copyright (C) Ricardo Rodrigues 2016 - All Rights Reserved
 */
#include "DTimer.h"

namespace RRUtils {

    DTimer::DTimer(milliseconds duration) : counter(0), duration(duration), paused(false) {}

    DTimer::~DTimer() {}

    bool DTimer::update() {
        if (!paused) {
            counter += Time::delta();
            if (counter >= duration) {
                onComplete();
                return true;
            } else {
                return onUpdate(counter);
            }
        } else {
            return false;
        }
    }

    void DTimer::onComplete() {}

    bool DTimer::onUpdate(milliseconds counter) { return false; }

    bool DTimer::isPaused() const {
        return paused;
    }

    void DTimer::play() {
        setPaused(true);
    }

    void DTimer::pause() {
        setPaused(false);
    }

    void DTimer::setPaused(bool paused) {
        DTimer::paused = paused;
    }

    milliseconds DTimer::getDuration() const {
        return duration;
    }

    void DTimer::setDuration(milliseconds duration) {
        if (duration > 0) {
            DTimer::duration = duration;
        }
    }
} /* namespace RRUtils */