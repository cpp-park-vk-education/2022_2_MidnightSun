CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

PROJECT(project)

if (WITH_MEMCHECK)
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++2a -Werror -Wextra -Wpedantic -Wall -fsanitize=address")
else()
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++2a -Werror -Wextra -Wpedantic -Wall")
endif()

SET(SOURCES 
            project/src/square.cpp)

INCLUDE_DIRECTORIES("${PROJECT_SOURCES_DIR}project/include")

FIND_PACKAGE(GTest REQUIRED)
INCLUDE_DIRECTORIES(${GTEST_INCLUDE_DIRS})

ADD_EXECUTABLE(tests ${SOURCES} project/main.cpp)
TARGET_LINK_LIBRARIES(tests ${GTEST_LIBRARIES} pthread)
