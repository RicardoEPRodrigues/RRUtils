/*
 * File Looper.cpp in project RRUtils
 * 
 * Copyright (C) ricardo 2016 - All Rights Reserved
 */

#include "Looper.h"

using namespace std;

namespace RRUtils {

    Looper::Looper() : continueLoop(false), interval(250) {}

    Looper::Looper(std::function<void()> callback, long int interval) :
            Looper::Looper() {
        this->callback = callback;
        this->interval = interval;
    }

    Looper::~Looper() {

    }

    void Looper::setCallback(std::function<void()> callback) {
        this->callback = callback;
    }

    void Looper::setInterval(long int interval) {
        this->interval = interval;
    }


    void Looper::start() {
        if (this->continueLoop) { // If it has already begun, then ignore call
            return;
        }

        this->continueLoop = true;

        chrono::milliseconds intervalMilliseconds(this->interval);

        while (this->continueLoop) {
            this->callback();
            this_thread::sleep_for(intervalMilliseconds);
        }
    }

    void Looper::start(std::function<void()> callback) {
        this->setCallback(callback);
        this->start();
    }

    bool Looper::isRunning() {
        return this->continueLoop;
    }

    void Looper::stop() {
        this->continueLoop = false;
    }
} /* namespace RRUtils */
