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

ADD_EXECUTABLE(test main.cpp)













# CMAKE_MINIMUM_REQUIRED(VERSION 2.9)


# PROJECT(tests)

# SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++2a -Werror -Wextra -Wpedantic -Wall")

# IF(WITH_CLANG_TIDY)
#     SET(CMAKE_CXX_CLANG_TIDY 
#         clang-tidy;
#         -header-filter=<gtest/gtest.h>;
#         -checks=*)
# ENDIF()

# IF(WITH_MEMCHECK)
#     SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address")
# ENDIF()

# INCLUDE(CTest)
# FIND_PACKAGE(GTest REQUIRED)
# INCLUDE_DIRECTORIES(GoogleTest)




# CMAKE_MINIMUM_REQUIRED(VERSION 2.9)

# PROJECT(tests)

# set(CMAKE_AUTOMOC ON)
# set(CMAKE_INCLUDE_CURRENT_DIR ON)

# SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++2a -Werror -Wextra -Wpedantic -Wall")

# IF(WITH_CLANG_TIDY)
#     SET(CMAKE_CXX_CLANG_TIDY 
#         clang-tidy;
#         -checks=*)
# ENDIF()

# find_package(Qt5Widgets REQUIRED)
# find_package(Qt5Core REQUIRED)
# find_package(Qt5Gui REQUIRED)
# find_package(Qt5Multimedia REQUIRED)

# INCLUDE_DIRECTORIES("${PROJECT_SOURCES_DIR} lib")
# INCLUDE_DIRECTORIES("${PROJECT_SOURCES_DIR} impl")

# include_directories(${Qt5Widgets_INCLUDES})
# include_directories(${Qt5Multimedia_INCLUDES})
# add_definitions(${Qt5Widgets_DEFINITIONS})
# add_definitions(${Qt5Multimedia_DEFINITIONS})

# set(CMAKE_CXX_FLAGS "${Qt5Widgets_EXECUTABLE_COMPILE_FLAGS}")


# add_executable(test main.cpp 
#                     impl/MainWindow.cpp 
#                     impl/CurrentTrack.cpp 
#                     impl/TitleBarButtons.cpp 
#                     impl/LeftWall.cpp
#                     lib/InterfaceButtons.cpp)
# target_link_libraries(test ${Qt5Widgets_LIBRARIES} ${Qt5Multimedia_LIBRARIES})
