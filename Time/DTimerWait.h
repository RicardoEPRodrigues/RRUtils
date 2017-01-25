
/*
 * File DTimerWait.h in project RRUtils
 * 
 * Copyright (C) Ricardo Rodrigues 2016 - All Rights Reserved
 */
#ifndef RRUTILS_DTIMERWAIT_H
#define RRUTILS_DTIMERWAIT_H

#include <memory>
#include "DTimer.h"

namespace RRUtils {

    class DTimerWait : public DTimer {
        public:
            DTimerWait(milliseconds duration = 1000, std::function<void()> onCompleteCallback = []() {});

            const std::function<void()>& getOnCompleteCallback() const;

            void setOnCompleteCallback(const std::function<void()>& onCompleteCallback);

        protected:
            void onComplete() override;

        private:
            std::function<void()> onCompleteCallback;
    };

} /* namespace RRUtils */

#endif //RRUTILS_DTIMERWAIT_H
