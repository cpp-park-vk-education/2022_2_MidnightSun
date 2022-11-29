# CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

# PROJECT(project)

# if (WITH_MEMCHECK)
#     SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++2a -Werror -Wextra -Wpedantic -Wall -fsanitize=address")
# else()
#     SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++2a -Werror -Wextra -Wpedantic -Wall")
# endif()

# # SET(SOURCES 
# #             project/audio-player/src/square.cpp
# #             project/net/client/src/client.cpp
# #             project/net/server/src/server.cpp)

# FIND_PACKAGE(Qt6 REQUIRED COMPONENTS Widgets)

# INCLUDE_DIRECTORIES("${PROJECT_SOURCES_DIR}project/lib/audio\ mixer")
# INCLUDE_DIRECTORIES("${PROJECT_SOURCES_DIR}project/lib/models")
# INCLUDE_DIRECTORIES("${PROJECT_SOURCES_DIR}project/lib/user\ interface")


# FIND_PACKAGE(GTest REQUIRED)
# INCLUDE_DIRECTORIES(${GTEST_INCLUDE_DIRS})

# ADD_EXECUTABLE(tests ${SOURCES} project/tests/test.cpp)
# TARGET_LINK_LIBRARIES(tests ${GTEST_LIBRARIES} pthread)

CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

PROJECT(project)

set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt5Widgets REQUIRED)
find_package(Qt5Core REQUIRED)
find_package(Qt5Gui REQUIRED)
find_package(Qt5Multimedia REQUIRED)

include_directories(${PROJECT_SOURCES_DIR}/project/test)
include_directories(${Qt5Widgets_INCLUDES})

add_definitions(${Qt5Widgets_DEFINITIONS})

set(CMAKE_CXX_FLAGS "${Qt5Widgets_EXECUTABLE_COMPILE_FLAGS}")
qt5_wrap_ui(UIS_HDRS
    project/test/mainwindow.ui)


add_executable(test ${UIS_HDRS} project/test/main.cpp project/test/abc.cpp)
target_link_libraries(QtTesting Qt5::Widgets Qt5::Multimedia)
