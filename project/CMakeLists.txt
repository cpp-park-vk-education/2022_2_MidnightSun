CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

PROJECT(project)

set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt5Widgets REQUIRED)
find_package(Qt5Core REQUIRED)
find_package(Qt5Gui REQUIRED)

INCLUDE_DIRECTORIES("${PROJECT_SOURCES_DIR} impl")
INCLUDE_DIRECTORIES("${PROJECT_SOURCES_DIR} impl/style")

include_directories(${Qt5Widgets_INCLUDES})
add_definitions(${Qt5Widgets_DEFINITIONS})

set(CMAKE_CXX_FLAGS "${Qt5Widgets_EXECUTABLE_COMPILE_FLAGS}")


add_executable(test main.cpp 
                    impl/mainWindow.cpp 
                    impl/currentTrack.cpp 
                    impl/optionsWindow.cpp 
                    impl/leftBoard.cpp)
target_link_libraries(test ${Qt5Widgets_LIBRARIES})
