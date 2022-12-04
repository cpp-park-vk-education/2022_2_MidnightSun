CMAKE_MINIMUM_REQUIRED(VERSION 2.9)


PROJECT(tests)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -Werror -Wextra -Wpedantic -Wall")

SET(CMAKE_AUTOMOC ON)
SET(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt5Widgets REQUIRED)
find_package(Qt5Core REQUIRED)
find_package(Qt5Gui REQUIRED)
find_package(Qt5Multimedia REQUIRED)

INCLUDE_DIRECTORIES("${PROJECT_SOURCES_DIR} impl")
INCLUDE_DIRECTORIES("${PROJECT_SOURCES_DIR} impl/style")

include_directories(${Qt5Widgets_INCLUDES})
include_directories(${Qt5Multimedia_INCLUDES})
add_definitions(${Qt5Widgets_DEFINITIONS})
add_definitions(${Qt5Multimedia_DEFINITIONS})

set(CMAKE_CXX_FLAGS "${Qt5Widgets_EXECUTABLE_COMPILE_FLAGS}")


add_executable(test main.cpp 
                    impl/MainWindow.cpp
                    impl/CurrentPlaylist.cpp 
                    impl/CurrentTrack.cpp 
                    impl/LeftWall.cpp 
                    impl/MenuBar.cpp
                    impl/TitleBarButtons.cpp)
target_link_libraries(test ${Qt5Widgets_LIBRARIES} ${Qt5Multimedia_LIBRARIES})


# CMAKE_MINIMUM_REQUIRED(VERSION 2.9)


# PROJECT(tests)

# SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++2a -Werror -Wextra -Wpedantic -Wall")

# IF(WITH_CLANG_TIDY)
#     SET(CMAKE_CXX_CLANG_TIDY 
#         clang-tidy;
#         -header-filter=<QApplication><QtGui/QMouseEvent><QWidget><QMainWindow><QFile><QMediaPlayer><QPushButton><QSlider>;
#         -checks=*)
# ENDIF()

# IF(WITH_MEMCHECK)
#     SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address")
# ENDIF()

# SET(CMAKE_AUTOMOC ON)
# SET(CMAKE_INCLUDE_CURRENT_DIR ON)

# FIND_PACKAGE(Qt5Widgets REQUIRED)
# FIND_PACKAGE(Qt5Core REQUIRED)
# FIND_PACKAGE(Qt5Gui REQUIRED)
# FIND_PACKAGE(Qt5Multimedia REQUIRED)

# INCLUDE_DIRECTORIES("${PROJECT_SOURCES_DIR} lib")
# INCLUDE_DIRECTORIES("${PROJECT_SOURCES_DIR} impl")

# INCLUDE_DIRECTORIES(${Qt5Widgets_INCLUDES})
# INCLUDE_DIRECTORIES(${Qt5Multimedia_INCLUDES})

# SET(CMAKE_CXX_FLAGS "${Qt5Widgets_EXECUTABLE_COMPILE_FLAGS}")
# SET(CMAKE_CXX_FLAGS "${Qt5Multimedia_EXECUTABLE_COMPILE_FLAGS}")

# ADD_EXECUTABLE(SOURCES tests/current_track.cpp
#                        impl/MainWindow.cpp 
#                        impl/CurrentTrack.cpp 
#                        impl/TitleBarButtons.cpp 
#                        impl/LeftWall.cpp
#                        impl/CurrentPlaylist.cpp
#                        impl/MenuBar.cpp)

# TARGET_LINK_LIBRARIES(SOURCES ${Qt5Widgets_LIBRARIES} ${Qt5Multimedia_LIBRARIES})

# ADD_EXECUTABLE(current_track_test ${SOURCES} tests/current_track.cpp)

# TARGET_LINK_LIBRARIES(current_track_test ${Qt5Widgets_LIBRARIES} ${Qt5Multimedia_LIBRARIES})