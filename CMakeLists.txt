cmake_minimum_required(VERSION 3.6)
project(RRUtils)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall -g3 -Og -Wuninitialized")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Ofast")

set(SOURCE_FILES
        Time/DTimer.cpp
        Time/DTimer.h
        Time/DTimerIfWait.cpp
        Time/DTimerIfWait.h
        Time/DTimerManager.cpp
        Time/DTimerManager.h
        Time/DTimerWait.cpp
        Time/DTimerWait.h
        Time/Time.h
        Time/TimeCalculator.h
        Looper.cpp
        Looper.h
        Module.h)

add_library(RRUtils SHARED ${SOURCE_FILES})