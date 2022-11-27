CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

PROJECT(project)

if (WITH_MEMCHECK)
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++2a -Werror -Wextra -Wpedantic -Wall -fsanitize=address")
else()
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++2a -Werror -Wextra -Wpedantic -Wall")
endif()

SET(SOURCES 
            project/audio-player/src/square.cpp
            project/net/client/src/client.cpp
            project/net/server/src/server.cpp)

INCLUDE_DIRECTORIES("${PROJECT_SOURCES_DIR}project/audio-player/include")
INCLUDE_DIRECTORIES("${PROJECT_SOURCES_DIR}project/net/client/include")
INCLUDE_DIRECTORIES("${PROJECT_SOURCES_DIR}project/net/server/include")

FIND_PACKAGE(GTest REQUIRED)
INCLUDE_DIRECTORIES(${GTEST_INCLUDE_DIRS})



ADD_EXECUTABLE(tests ${SOURCES} project/tests/test.cpp)
TARGET_LINK_LIBRARIES(tests ${GTEST_LIBRARIES} pthread)
