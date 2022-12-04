CMAKE_MINIMUM_REQUIRED(VERSION 2.9)


PROJECT(tests)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -Werror -Wextra -Wpedantic -Wall -fPIE -fPIC")

INCLUDE_DIRECTORIES("${PROJECT_SOURCES_DIR} lib/Models")
INCLUDE_DIRECTORIES("${PROJECT_SOURCES_DIR} lib/UIModels")
INCLUDE_DIRECTORIES("${PROJECT_SOURCES_DIR} tests/MockClasses")

SET(SOURCES 
           lib/Models/Models.cpp
           lib/UIModels/TrackPlaylistModel.cpp)

SET(MOCKSOURCES 
               tests/MockClasses/MockClasses.cpp)
        
INCLUDE(CTest)
FIND_PACKAGE(GTest REQUIRED)
INCLUDE_DIRECTORIES(GoogleTest)

set(TESTS 
         PlaylistModelTest
         TrackModelTest
         PlaylistUIModelTest
         CurrentTrackUIModelTest)

SET(i 0)
FOREACH(_test ${TESTS})
    IF(${i} LESS 2 )
        ADD_EXECUTABLE(${_test} ${SOURCES} tests/ModelsTests/${_test}.cpp)
        TARGET_LINK_LIBRARIES(${_test} GTest::GTest GTest::Main)
    ELSE()
        ADD_EXECUTABLE(${_test} ${SOURCES} ${MOCKSOURCES} tests/UIModelsTests/${_test}.cpp)
        TARGET_LINK_LIBRARIES(${_test} GTest::gtest GTest::gtest_main GTest::gmock GTest::gmock_main)
    ENDIF()
    GTEST_DISCOVER_TESTS(${_test})
    ADD_TEST(NAME ${_test} COMMAND ${_test})
    MATH(EXPR i "${i} + 1")
ENDFOREACH()
