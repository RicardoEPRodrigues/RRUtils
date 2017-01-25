
/*
 * File DTimerIfWait.h in project RRUtils
 * 
 * Copyright (C) Ricardo Rodrigues 2016 - All Rights Reserved
 */
#ifndef RRUTILS_DTIMERIFWAIT_H
#define RRUTILS_DTIMERIFWAIT_H

#include "DTimerWait.h"

namespace RRUtils {

    class DTimerIfWait : public DTimerWait {
        public:
            DTimerIfWait(milliseconds duration = 1000, std::function<void()> onCompleteCallback = []() {},
                         std::function<bool(milliseconds)> onUpdateCallback = [](
                                 milliseconds counter) { return false; });

            const std::function<bool(milliseconds)>& getOnUpdateCallback() const;

            void setOnUpdateCallback(const std::function<bool(milliseconds)>& onUpdateCallback);

        protected:
            bool onUpdate(milliseconds counter) override;

        private:
            std::function<bool(milliseconds)> onUpdateCallback;
    };

} /* namespace RRUtils */

#endif //RRUTILS_DTIMERIFWAIT_H
