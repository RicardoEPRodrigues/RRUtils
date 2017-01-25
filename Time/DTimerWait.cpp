
/*
 * File DTimerWait.cpp in project RRUtils
 * 
 * Copyright (C) Ricardo Rodrigues 2016 - All Rights Reserved
 */
#include "DTimerWait.h"

namespace RRUtils {

    DTimerWait::DTimerWait(milliseconds duration,
                           std::function<void()> onCompleteCallback) : DTimer(duration),
                                                                       onCompleteCallback(
                                                                               onCompleteCallback) {}

    void DTimerWait::onComplete() {
        if (onCompleteCallback) {
            onCompleteCallback();
        }
    }

    const std::function<void()>& DTimerWait::getOnCompleteCallback() const {
        return onCompleteCallback;
    }

    void DTimerWait::setOnCompleteCallback(const std::function<void()>& onCompleteCallback) {
        DTimerWait::onCompleteCallback = onCompleteCallback;
    }
} /* namespace RRUtils */