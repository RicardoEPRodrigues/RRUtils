/*
 * File Module.h in project RRUtils
 * 
 * Copyright (C) Ricardo Rodrigues 2016 - All Rights Reserved
 */
#ifndef RRUTILS_MODULE_H
#define RRUTILS_MODULE_H

#include <memory>

namespace RRUtils {

    template<typename T, typename U>
    class Module {
        public:
            Module() {}

            virtual ~Module() {}

            virtual T execute(U param) = 0;
    };

    template<typename T>
    class Module<T, void> {
        public:
            Module() {}

            virtual ~Module() {}

            virtual T execute() = 0;
    };
} /* namespace RRUtils */

#endif //RRUTILS_MODULE_H
