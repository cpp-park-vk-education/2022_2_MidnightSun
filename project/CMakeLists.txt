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
                    #    impl/MainWindow.cpp 
                    #    impl/CurrentTrack.cpp 
                    #    impl/TitleBarButtons.cpp 
                    #    impl/LeftWall.cpp
                    #    impl/CurrentPlaylist.cpp
                    #    impl/MenuBar.cpp)

# TARGET_LINK_LIBRARIES(SOURCES ${Qt5Widgets_LIBRARIES} ${Qt5Multimedia_LIBRARIES})

# ADD_EXECUTABLE(current_track_test ${SOURCES} tests/current_track.cpp)

# TARGET_LINK_LIBRARIES(current_track_test ${Qt5Widgets_LIBRARIES} ${Qt5Multimedia_LIBRARIES})

# INCLUDE(CTest)
# FIND_PACKAGE(GTest REQUIRED)
# INCLUDE_DIRECTORIES(GoogleTest)



# TARGET_LINK_LIBRARIES(current_track_test GTest::GTest GTest::Main )
# GTEST_DISCOVER_TESTS(current_track_test)
# ADD_TEST(NAME TestCurrentTrackComponent COMMAND current_track_test)





CMAKE_MINIMUM_REQUIRED(VERSION 2.9)


PROJECT(tests)



# SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++2a -g")

# ADD_EXECUTABLE(current_track_test tests/current_track.cpp)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++2a -g -Werror -Wextra -Wpedantic -Wall")

IF(WITH_CLANG_TIDY)
    SET(CMAKE_CXX_CLANG_TIDY 
        clang-tidy;
        -header-filter=<gtest/gtest.h>;
        -checks=*)
ENDIF()

IF(WITH_MEMCHECK)
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address")
ENDIF()

INCLUDE(CTest)
FIND_PACKAGE(GTest REQUIRED)
INCLUDE_DIRECTORIES(GoogleTest)

SET(CMAKE_AUTOMOC ON)
SET(CMAKE_INCLUDE_CURRENT_DIR ON)

FIND_PACKAGE(Qt5QuickCompiler QUIET)
FIND_PACKAGE(Qt5Widgets REQUIRED)
FIND_PACKAGE(Qt5Core REQUIRED)
FIND_PACKAGE(Qt5Gui REQUIRED)
FIND_PACKAGE(Qt5Multimedia REQUIRED)

INCLUDE_DIRECTORIES("${PROJECT_SOURCES_DIR} lib")
INCLUDE_DIRECTORIES("${PROJECT_SOURCES_DIR} impl")

INCLUDE_DIRECTORIES(${Qt5Mainwindow_INCLUDES})
INCLUDE_DIRECTORIES(${Qt5Widgets_INCLUDES})
INCLUDE_DIRECTORIES(${Qt5Multimedia_INCLUDES})

SET(CMAKE_CXX_FLAGS "${Qt5Mainwindow_EXECUTABLE_COMPILE_FLAGS}")
SET(CMAKE_CXX_FLAGS "${Qt5Widgets_EXECUTABLE_COMPILE_FLAGS}")
SET(CMAKE_CXX_FLAGS "${Qt5Multimedia_EXECUTABLE_COMPILE_FLAGS}")

# ADD_EXECUTABLE(current_track_test tests/current_track.cpp)



SET(SOURCES 
           impl/MainWindow.cpp 
           impl/CurrentTrack.cpp 
           impl/TitleBarButtons.cpp 
           impl/LeftWall.cpp
           impl/CurrentPlaylist.cpp
           impl/MenuBar.cpp)

# TARGET_LINK_LIBRARIES(current_track_test ${Qt5Widgets_LIBRARIES} ${Qt5Multimedia_LIBRARIES} GTest::GTest GTest::Main)
# GTEST_DISCOVER_TESTS(current_track_test)


# ADD_TEST(NAME CurrentTrackTest COMMAND current_track_test)
ADD_EXECUTABLE(current_track_test ${SOURCES} tests/current_track.cpp)
TARGET_COMPILE_DEFINITIONS(current_track_test
  PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)
TARGET_LINK_LIBRARIES(current_track_test ${Qt5Widgets_LIBRARIES} ${Qt5Multimedia_LIBRARIES} GTest::GTest GTest::Main)


# ADD_EXECUTABLE(test_constructors ${SOURCES} tests/current_track.cpp)
# TARGET_LINK_LIBRARIES(test_constructors GTest::GTest GTest::Main)
# GTEST_DISCOVER_TESTS(test_constructors)
# ADD_TEST(NAME TestConstructors COMMAND test_constructors)
























# TARGET_LINK_LIBRARIES(test_current_track_component GTest::GTest GTest::Main)
# TARGET_LINK_LIBRARIES(test_current_track_component ${Qt5Widgets_LIBRARIES} ${Qt5Multimedia_LIBRARIES})

# GTEST_DISCOVER_TESTS(test_current_track_component)

# ADD_TEST(NAME TestCurrentTrackComponent COMMAND test_current_track_component)
