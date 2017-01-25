
/*
 * File DTimer.h in project RRUtils
 * 
 * Copyright (C) Ricardo Rodrigues 2016 - All Rights Reserved
 */
#ifndef RRUTILS_DTIMER_H
#define RRUTILS_DTIMER_H

#include "Time.h"

namespace RRUtils {

    class DTimer {
        public:
            DTimer(milliseconds duration = 1000);

            virtual ~DTimer();

            /**
             * Updates the time and checks if the timer has completed
             * @return True if the Timer has completed, false otherwise.
             */
            bool update();

            bool isPaused() const;

            void play();

            void pause();

            milliseconds getDuration() const;

            void setDuration(milliseconds duration);

        protected:
            /**
             * Called when the Timer completes it's cicle
             */
            virtual void onComplete();

            /**
             * Called when the Timer is updated, but has not yet completed it's cicle
             * @param counter current time of the cicle
             * @return True if the Timer should stop it's cicle, false otherwise.
             */
            virtual bool onUpdate(milliseconds counter);

        private:

            milliseconds counter;

            milliseconds duration;

            bool paused;

            void setPaused(bool paused);
    };

} /* namespace RRUtils */

#endif //RRUTILS_DTIMER_H
