
/*
 * File DTimerManager.h in project RRUtils
 * 
 * Copyright (C) Ricardo Rodrigues 2016 - All Rights Reserved
 */
#ifndef RRUTILS_DTIMERMANAGER_H
#define RRUTILS_DTIMERMANAGER_H

#include <vector>
#include <memory>
#include "DTimer.h"

namespace RRUtils {

    class DTimerManager {
        public:
            DTimerManager();

            virtual ~DTimerManager();

        protected:
            void timersUpdate();

            std::shared_ptr<DTimer> wait(milliseconds duration, std::function<void()> onCompleteCallback);

            std::shared_ptr<DTimer> ifWait(milliseconds duration, std::function<void()> onCompleteCallback,
                                           std::function<bool(milliseconds)> onUpdateCallback);

        private:
            std::vector<std::shared_ptr<DTimer>> timers;
    };

} /* namespace RRUtils */

#endif //RRUTILS_DTIMERMANAGER_H
