CMAKE_MINIMUM_REQUIRED(VERSION 2.9)


PROJECT(tests)

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

SET(SOURCES audio-player/src/square.cpp
            tests/test.cpp)

INCLUDE(CTest)
FIND_PACKAGE(GTest REQUIRED)
INCLUDE_DIRECTORIES(GoogleTest)

ADD_EXECUTABLE(test ${SOURCES})
TARGET_LINK_LIBRARIES(test GTest::GTest GTest::Main)
GTEST_DISCOVER_TESTS(test)
ADD_TEST(NAME Test COMMAND test)
