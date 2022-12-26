# CMAKE_MINIMUM_REQUIRED(VERSION 2.9)


# PROJECT(tests)

# SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -Werror -Wextra -Wpedantic -Wall -fPIE -fPIC")

# INCLUDE_DIRECTORIES("${PROJECT_SOURCES_DIR} lib/Components")
# INCLUDE_DIRECTORIES("${PROJECT_SOURCES_DIR} lib/GlobalModels")
# INCLUDE_DIRECTORIES("${PROJECT_SOURCES_DIR} lib/Models")
# INCLUDE_DIRECTORIES("${PROJECT_SOURCES_DIR} tests/MockClasses")

# SET(SOURCES 
#            lib/Components/CurrentPlaylist.cpp
#            lib/Components/CurrentTrack.cpp
#            lib/GlobalModels/TrackPlaylistModel.cpp
#            lib/Models/Playlist.cpp
#            lib/Models/Track.cpp)

# SET(MOCKSOURCES 
#                tests/MockClasses/MockClasses.cpp)
        
# INCLUDE(CTest)
# FIND_PACKAGE(GTest REQUIRED)
# INCLUDE_DIRECTORIES(GoogleTest)

# set(TESTS 
#          PlaylistModelTest
#          TrackModelTest
#          PlaylistUIModelTest
#          CurrentTrackUIModelTest)

# SET(i 0)
# FOREACH(_test ${TESTS})
#     IF(${i} LESS 2 )
#         ADD_EXECUTABLE(${_test} ${SOURCES} tests/ModelsTests/${_test}.cpp)
#         TARGET_LINK_LIBRARIES(${_test} GTest::GTest GTest::Main)
#     ELSE()
#         ADD_EXECUTABLE(${_test} ${SOURCES} ${MOCKSOURCES} tests/UIModelsTests/${_test}.cpp)
#         TARGET_LINK_LIBRARIES(${_test} GTest::gtest GTest::gtest_main GTest::gmock GTest::gmock_main)
#     ENDIF()
#     GTEST_DISCOVER_TESTS(${_test})
#     ADD_TEST(NAME ${_test} COMMAND ${_test})
#     MATH(EXPR i "${i} + 1")
# ENDFOREACH()

















CMAKE_MINIMUM_REQUIRED(VERSION 2.9)


PROJECT(tests)

# FLAGS    = -L /lib64 
# LIBS     = -lusb-1.0 -l pthread

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -Werror -Wextra -Wpedantic -Wall -L /lib64 -lrt -lm -lpthread")
# set(CMAKE_THREAD_LIBS_INIT "-lpthread")
# SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")
# set(CMAKE_HAVE_THREADS_LIBRARY 1)
# set(CMAKE_USE_WIN32_THREADS_INIT 0)
# set(CMAKE_USE_PTHREADS_INIT 1)
# set(THREADS_PREFER_PTHREAD_FLAG ON)

SET(CMAKE_AUTOMOC ON)
SET(CMAKE_INCLUDE_CURRENT_DIR ON)

FIND_PACKAGE(Qt5Widgets REQUIRED)
FIND_PACKAGE(Qt5Core REQUIRED)
FIND_PACKAGE(Qt5Gui REQUIRED)
FIND_PACKAGE(Qt5Multimedia REQUIRED)

INCLUDE_DIRECTORIES("${PROJECT_SOURCES_DIR} impl/icons")
INCLUDE_DIRECTORIES("${PROJECT_SOURCES_DIR} impl/style")
INCLUDE_DIRECTORIES("${PROJECT_SOURCES_DIR} impl/views")

INCLUDE_DIRECTORIES("${PROJECT_SOURCES_DIR} lib/Controllers")
INCLUDE_DIRECTORIES("${PROJECT_SOURCES_DIR} lib/FileLib")
INCLUDE_DIRECTORIES("${PROJECT_SOURCES_DIR} lib/Mediator")
INCLUDE_DIRECTORIES("${PROJECT_SOURCES_DIR} lib/SoundLib")
INCLUDE_DIRECTORIES("${PROJECT_SOURCES_DIR} lib/SoundLibWithOuterDependncies")
INCLUDE_DIRECTORIES("${PROJECT_SOURCES_DIR} lib/UIModels")

INCLUDE_DIRECTORIES(${Qt5Widgets_INCLUDES})
INCLUDE_DIRECTORIES(${Qt5Multimedia_INCLUDES})

# set(app_icon_resource_windows "/home/marcussss1/2022_2_MidnightSun/project/impl/icons/close.png")
# qt_add_executable(photosurface main.cpp ${app_icon_resource_windows})

SET(CMAKE_CXX_FLAGS "${Qt5Widgets_EXECUTABLE_COMPILE_FLAGS}")


SET(LIB 
        lib/Controllers/CurrentPlaylistController.cpp
        lib/Controllers/CurrentTrackController.cpp
        lib/Controllers/FileSystemController.cpp
        lib/Mediator/GlobalModel.cpp
        lib/SoundLib/Parser.cpp
        lib/SoundLib/Playlist.cpp
        lib/SoundLib/Track.cpp
        lib/SoundLibWithOuterDependncies/QTrack.cpp
        lib/UIModels/CurrentPlaylistUIModel.cpp
        lib/UIModels/CurrentTrackUIModel.cpp
        lib/UIModels/FileSystemUIModel.cpp)

SET(IMPL
        impl/views/CurrentPlaylistView.cpp
        impl/views/CurrentTrackView.cpp
        impl/views/FileSystemView.cpp
        impl/views/LeftWallView.cpp
        impl/views/MainWindowView.cpp
        impl/views/TitleBarButtonsView.cpp)

ADD_EXECUTABLE(mplayer main.cpp ${LIB} ${IMPL})
TARGET_LINK_LIBRARIES(mplayer ${Qt5Widgets_LIBRARIES} ${Qt5Multimedia_LIBRARIES} pthread stdc++fs)
