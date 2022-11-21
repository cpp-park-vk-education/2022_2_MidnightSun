CMAKE_MINIMUM_REQUIRED(VERSION 2.9)

PROJECT(run)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++2a -Werror -Wextra -Wpedantic -Wall")

IF(WITH_CLANG_TIDY)
    SET(CMAKE_CXX_CLANG_TIDY 
        clang-tidy;
        -header-filter=<gtest/gtest.h>;
        -checks=*)
ENDIF()

IF(WITH_MEMCHECK)
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address")
ENDIF()

SET(CMAKE_CXX_FLAGS "${Qt5Widgets_EXECUTABLE_COMPILE_FLAGS}")

INCLUDE(CTest)
FIND_PACKAGE(GTest REQUIRED)
INCLUDE_DIRECTORIES(GoogleTest)

ADD_EXECUTABLE(add_track add_track.cpp)
TARGET_LINK_LIBRARIES(add_track GTest::GTest GTest::Main)
GTEST_DISCOVER_TESTS(add_track)
ADD_TEST(NAME AddTrack COMMAND add_track)

