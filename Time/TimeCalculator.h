/*
 * File TimeCalculator.h in project RRUtils
 * 
 * Copyright (C) Ricardo Rodrigues 2016 - All Rights Reserved
 */
#ifndef RRUTILS_TIMECALCULATOR_H
#define RRUTILS_TIMECALCULATOR_H

namespace RRUtils {
    typedef double milliseconds;

    class TimeCalculator {
        public:
            TimeCalculator() {};

            virtual ~TimeCalculator() {};

            virtual void update() = 0;

            virtual milliseconds startTime() = 0;

            virtual milliseconds now() = 0;

            virtual milliseconds delta() = 0;

            virtual void play() = 0;

            virtual void pause() = 0;
    };
}


#endif //RRUTILS_TIMECALCULATOR_H
