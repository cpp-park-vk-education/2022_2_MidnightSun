# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.25

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/marcussss1/2022_2_MidnightSun

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/marcussss1/2022_2_MidnightSun/build

# Include any dependencies generated for this target.
include project/CMakeFiles/test.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include project/CMakeFiles/test.dir/compiler_depend.make

# Include the progress variables for this target.
include project/CMakeFiles/test.dir/progress.make

# Include the compile flags for this target's objects.
include project/CMakeFiles/test.dir/flags.make

project/CMakeFiles/test.dir/test_autogen/mocs_compilation.cpp.o: project/CMakeFiles/test.dir/flags.make
project/CMakeFiles/test.dir/test_autogen/mocs_compilation.cpp.o: project/test_autogen/mocs_compilation.cpp
project/CMakeFiles/test.dir/test_autogen/mocs_compilation.cpp.o: project/CMakeFiles/test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/marcussss1/2022_2_MidnightSun/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object project/CMakeFiles/test.dir/test_autogen/mocs_compilation.cpp.o"
	cd /home/marcussss1/2022_2_MidnightSun/build/project && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT project/CMakeFiles/test.dir/test_autogen/mocs_compilation.cpp.o -MF CMakeFiles/test.dir/test_autogen/mocs_compilation.cpp.o.d -o CMakeFiles/test.dir/test_autogen/mocs_compilation.cpp.o -c /home/marcussss1/2022_2_MidnightSun/build/project/test_autogen/mocs_compilation.cpp

project/CMakeFiles/test.dir/test_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test.dir/test_autogen/mocs_compilation.cpp.i"
	cd /home/marcussss1/2022_2_MidnightSun/build/project && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/marcussss1/2022_2_MidnightSun/build/project/test_autogen/mocs_compilation.cpp > CMakeFiles/test.dir/test_autogen/mocs_compilation.cpp.i

project/CMakeFiles/test.dir/test_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test.dir/test_autogen/mocs_compilation.cpp.s"
	cd /home/marcussss1/2022_2_MidnightSun/build/project && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/marcussss1/2022_2_MidnightSun/build/project/test_autogen/mocs_compilation.cpp -o CMakeFiles/test.dir/test_autogen/mocs_compilation.cpp.s

project/CMakeFiles/test.dir/main.cpp.o: project/CMakeFiles/test.dir/flags.make
project/CMakeFiles/test.dir/main.cpp.o: /home/marcussss1/2022_2_MidnightSun/project/main.cpp
project/CMakeFiles/test.dir/main.cpp.o: project/CMakeFiles/test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/marcussss1/2022_2_MidnightSun/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object project/CMakeFiles/test.dir/main.cpp.o"
	cd /home/marcussss1/2022_2_MidnightSun/build/project && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT project/CMakeFiles/test.dir/main.cpp.o -MF CMakeFiles/test.dir/main.cpp.o.d -o CMakeFiles/test.dir/main.cpp.o -c /home/marcussss1/2022_2_MidnightSun/project/main.cpp

project/CMakeFiles/test.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test.dir/main.cpp.i"
	cd /home/marcussss1/2022_2_MidnightSun/build/project && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/marcussss1/2022_2_MidnightSun/project/main.cpp > CMakeFiles/test.dir/main.cpp.i

project/CMakeFiles/test.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test.dir/main.cpp.s"
	cd /home/marcussss1/2022_2_MidnightSun/build/project && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/marcussss1/2022_2_MidnightSun/project/main.cpp -o CMakeFiles/test.dir/main.cpp.s

project/CMakeFiles/test.dir/impl/MainWindow.cpp.o: project/CMakeFiles/test.dir/flags.make
project/CMakeFiles/test.dir/impl/MainWindow.cpp.o: /home/marcussss1/2022_2_MidnightSun/project/impl/MainWindow.cpp
project/CMakeFiles/test.dir/impl/MainWindow.cpp.o: project/CMakeFiles/test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/marcussss1/2022_2_MidnightSun/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object project/CMakeFiles/test.dir/impl/MainWindow.cpp.o"
	cd /home/marcussss1/2022_2_MidnightSun/build/project && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT project/CMakeFiles/test.dir/impl/MainWindow.cpp.o -MF CMakeFiles/test.dir/impl/MainWindow.cpp.o.d -o CMakeFiles/test.dir/impl/MainWindow.cpp.o -c /home/marcussss1/2022_2_MidnightSun/project/impl/MainWindow.cpp

project/CMakeFiles/test.dir/impl/MainWindow.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test.dir/impl/MainWindow.cpp.i"
	cd /home/marcussss1/2022_2_MidnightSun/build/project && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/marcussss1/2022_2_MidnightSun/project/impl/MainWindow.cpp > CMakeFiles/test.dir/impl/MainWindow.cpp.i

project/CMakeFiles/test.dir/impl/MainWindow.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test.dir/impl/MainWindow.cpp.s"
	cd /home/marcussss1/2022_2_MidnightSun/build/project && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/marcussss1/2022_2_MidnightSun/project/impl/MainWindow.cpp -o CMakeFiles/test.dir/impl/MainWindow.cpp.s

project/CMakeFiles/test.dir/impl/CurrentTrack.cpp.o: project/CMakeFiles/test.dir/flags.make
project/CMakeFiles/test.dir/impl/CurrentTrack.cpp.o: /home/marcussss1/2022_2_MidnightSun/project/impl/CurrentTrack.cpp
project/CMakeFiles/test.dir/impl/CurrentTrack.cpp.o: project/CMakeFiles/test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/marcussss1/2022_2_MidnightSun/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object project/CMakeFiles/test.dir/impl/CurrentTrack.cpp.o"
	cd /home/marcussss1/2022_2_MidnightSun/build/project && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT project/CMakeFiles/test.dir/impl/CurrentTrack.cpp.o -MF CMakeFiles/test.dir/impl/CurrentTrack.cpp.o.d -o CMakeFiles/test.dir/impl/CurrentTrack.cpp.o -c /home/marcussss1/2022_2_MidnightSun/project/impl/CurrentTrack.cpp

project/CMakeFiles/test.dir/impl/CurrentTrack.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test.dir/impl/CurrentTrack.cpp.i"
	cd /home/marcussss1/2022_2_MidnightSun/build/project && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/marcussss1/2022_2_MidnightSun/project/impl/CurrentTrack.cpp > CMakeFiles/test.dir/impl/CurrentTrack.cpp.i

project/CMakeFiles/test.dir/impl/CurrentTrack.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test.dir/impl/CurrentTrack.cpp.s"
	cd /home/marcussss1/2022_2_MidnightSun/build/project && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/marcussss1/2022_2_MidnightSun/project/impl/CurrentTrack.cpp -o CMakeFiles/test.dir/impl/CurrentTrack.cpp.s

project/CMakeFiles/test.dir/impl/TitleBarButtons.cpp.o: project/CMakeFiles/test.dir/flags.make
project/CMakeFiles/test.dir/impl/TitleBarButtons.cpp.o: /home/marcussss1/2022_2_MidnightSun/project/impl/TitleBarButtons.cpp
project/CMakeFiles/test.dir/impl/TitleBarButtons.cpp.o: project/CMakeFiles/test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/marcussss1/2022_2_MidnightSun/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object project/CMakeFiles/test.dir/impl/TitleBarButtons.cpp.o"
	cd /home/marcussss1/2022_2_MidnightSun/build/project && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT project/CMakeFiles/test.dir/impl/TitleBarButtons.cpp.o -MF CMakeFiles/test.dir/impl/TitleBarButtons.cpp.o.d -o CMakeFiles/test.dir/impl/TitleBarButtons.cpp.o -c /home/marcussss1/2022_2_MidnightSun/project/impl/TitleBarButtons.cpp

project/CMakeFiles/test.dir/impl/TitleBarButtons.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test.dir/impl/TitleBarButtons.cpp.i"
	cd /home/marcussss1/2022_2_MidnightSun/build/project && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/marcussss1/2022_2_MidnightSun/project/impl/TitleBarButtons.cpp > CMakeFiles/test.dir/impl/TitleBarButtons.cpp.i

project/CMakeFiles/test.dir/impl/TitleBarButtons.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test.dir/impl/TitleBarButtons.cpp.s"
	cd /home/marcussss1/2022_2_MidnightSun/build/project && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/marcussss1/2022_2_MidnightSun/project/impl/TitleBarButtons.cpp -o CMakeFiles/test.dir/impl/TitleBarButtons.cpp.s

project/CMakeFiles/test.dir/impl/LeftWall.cpp.o: project/CMakeFiles/test.dir/flags.make
project/CMakeFiles/test.dir/impl/LeftWall.cpp.o: /home/marcussss1/2022_2_MidnightSun/project/impl/LeftWall.cpp
project/CMakeFiles/test.dir/impl/LeftWall.cpp.o: project/CMakeFiles/test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/marcussss1/2022_2_MidnightSun/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object project/CMakeFiles/test.dir/impl/LeftWall.cpp.o"
	cd /home/marcussss1/2022_2_MidnightSun/build/project && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT project/CMakeFiles/test.dir/impl/LeftWall.cpp.o -MF CMakeFiles/test.dir/impl/LeftWall.cpp.o.d -o CMakeFiles/test.dir/impl/LeftWall.cpp.o -c /home/marcussss1/2022_2_MidnightSun/project/impl/LeftWall.cpp

project/CMakeFiles/test.dir/impl/LeftWall.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test.dir/impl/LeftWall.cpp.i"
	cd /home/marcussss1/2022_2_MidnightSun/build/project && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/marcussss1/2022_2_MidnightSun/project/impl/LeftWall.cpp > CMakeFiles/test.dir/impl/LeftWall.cpp.i

project/CMakeFiles/test.dir/impl/LeftWall.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test.dir/impl/LeftWall.cpp.s"
	cd /home/marcussss1/2022_2_MidnightSun/build/project && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/marcussss1/2022_2_MidnightSun/project/impl/LeftWall.cpp -o CMakeFiles/test.dir/impl/LeftWall.cpp.s

# Object files for target test
test_OBJECTS = \
"CMakeFiles/test.dir/test_autogen/mocs_compilation.cpp.o" \
"CMakeFiles/test.dir/main.cpp.o" \
"CMakeFiles/test.dir/impl/MainWindow.cpp.o" \
"CMakeFiles/test.dir/impl/CurrentTrack.cpp.o" \
"CMakeFiles/test.dir/impl/TitleBarButtons.cpp.o" \
"CMakeFiles/test.dir/impl/LeftWall.cpp.o"

# External object files for target test
test_EXTERNAL_OBJECTS =

project/test: project/CMakeFiles/test.dir/test_autogen/mocs_compilation.cpp.o
project/test: project/CMakeFiles/test.dir/main.cpp.o
project/test: project/CMakeFiles/test.dir/impl/MainWindow.cpp.o
project/test: project/CMakeFiles/test.dir/impl/CurrentTrack.cpp.o
project/test: project/CMakeFiles/test.dir/impl/TitleBarButtons.cpp.o
project/test: project/CMakeFiles/test.dir/impl/LeftWall.cpp.o
project/test: project/CMakeFiles/test.dir/build.make
project/test: /usr/lib/x86_64-linux-gnu/libQt5Widgets.so.5.12.8
project/test: /usr/lib/x86_64-linux-gnu/libQt5Multimedia.so.5.12.8
project/test: /usr/lib/x86_64-linux-gnu/libQt5Gui.so.5.12.8
project/test: /usr/lib/x86_64-linux-gnu/libQt5Network.so.5.12.8
project/test: /usr/lib/x86_64-linux-gnu/libQt5Core.so.5.12.8
project/test: project/CMakeFiles/test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/marcussss1/2022_2_MidnightSun/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable test"
	cd /home/marcussss1/2022_2_MidnightSun/build/project && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
project/CMakeFiles/test.dir/build: project/test
.PHONY : project/CMakeFiles/test.dir/build

project/CMakeFiles/test.dir/clean:
	cd /home/marcussss1/2022_2_MidnightSun/build/project && $(CMAKE_COMMAND) -P CMakeFiles/test.dir/cmake_clean.cmake
.PHONY : project/CMakeFiles/test.dir/clean

project/CMakeFiles/test.dir/depend:
	cd /home/marcussss1/2022_2_MidnightSun/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/marcussss1/2022_2_MidnightSun /home/marcussss1/2022_2_MidnightSun/project /home/marcussss1/2022_2_MidnightSun/build /home/marcussss1/2022_2_MidnightSun/build/project /home/marcussss1/2022_2_MidnightSun/build/project/CMakeFiles/test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : project/CMakeFiles/test.dir/depend

