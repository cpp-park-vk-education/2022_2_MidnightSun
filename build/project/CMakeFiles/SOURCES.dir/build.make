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
include project/CMakeFiles/SOURCES.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include project/CMakeFiles/SOURCES.dir/compiler_depend.make

# Include the progress variables for this target.
include project/CMakeFiles/SOURCES.dir/progress.make

# Include the compile flags for this target's objects.
include project/CMakeFiles/SOURCES.dir/flags.make

project/CMakeFiles/SOURCES.dir/SOURCES_autogen/mocs_compilation.cpp.o: project/CMakeFiles/SOURCES.dir/flags.make
project/CMakeFiles/SOURCES.dir/SOURCES_autogen/mocs_compilation.cpp.o: project/SOURCES_autogen/mocs_compilation.cpp
project/CMakeFiles/SOURCES.dir/SOURCES_autogen/mocs_compilation.cpp.o: project/CMakeFiles/SOURCES.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/marcussss1/2022_2_MidnightSun/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object project/CMakeFiles/SOURCES.dir/SOURCES_autogen/mocs_compilation.cpp.o"
	cd /home/marcussss1/2022_2_MidnightSun/build/project && /usr/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT project/CMakeFiles/SOURCES.dir/SOURCES_autogen/mocs_compilation.cpp.o -MF CMakeFiles/SOURCES.dir/SOURCES_autogen/mocs_compilation.cpp.o.d -o CMakeFiles/SOURCES.dir/SOURCES_autogen/mocs_compilation.cpp.o -c /home/marcussss1/2022_2_MidnightSun/build/project/SOURCES_autogen/mocs_compilation.cpp

project/CMakeFiles/SOURCES.dir/SOURCES_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SOURCES.dir/SOURCES_autogen/mocs_compilation.cpp.i"
	cd /home/marcussss1/2022_2_MidnightSun/build/project && /usr/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/marcussss1/2022_2_MidnightSun/build/project/SOURCES_autogen/mocs_compilation.cpp > CMakeFiles/SOURCES.dir/SOURCES_autogen/mocs_compilation.cpp.i

project/CMakeFiles/SOURCES.dir/SOURCES_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SOURCES.dir/SOURCES_autogen/mocs_compilation.cpp.s"
	cd /home/marcussss1/2022_2_MidnightSun/build/project && /usr/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/marcussss1/2022_2_MidnightSun/build/project/SOURCES_autogen/mocs_compilation.cpp -o CMakeFiles/SOURCES.dir/SOURCES_autogen/mocs_compilation.cpp.s

# Object files for target SOURCES
SOURCES_OBJECTS = \
"CMakeFiles/SOURCES.dir/SOURCES_autogen/mocs_compilation.cpp.o"

# External object files for target SOURCES
SOURCES_EXTERNAL_OBJECTS =

project/SOURCES: project/CMakeFiles/SOURCES.dir/SOURCES_autogen/mocs_compilation.cpp.o
project/SOURCES: project/CMakeFiles/SOURCES.dir/build.make
project/SOURCES: /usr/lib/x86_64-linux-gnu/libQt5Widgets.so.5.12.8
project/SOURCES: /usr/lib/x86_64-linux-gnu/libQt5Multimedia.so.5.12.8
project/SOURCES: /usr/lib/x86_64-linux-gnu/libQt5Gui.so.5.12.8
project/SOURCES: /usr/lib/x86_64-linux-gnu/libQt5Network.so.5.12.8
project/SOURCES: /usr/lib/x86_64-linux-gnu/libQt5Core.so.5.12.8
project/SOURCES: project/CMakeFiles/SOURCES.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/marcussss1/2022_2_MidnightSun/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable SOURCES"
	cd /home/marcussss1/2022_2_MidnightSun/build/project && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SOURCES.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
project/CMakeFiles/SOURCES.dir/build: project/SOURCES
.PHONY : project/CMakeFiles/SOURCES.dir/build

project/CMakeFiles/SOURCES.dir/clean:
	cd /home/marcussss1/2022_2_MidnightSun/build/project && $(CMAKE_COMMAND) -P CMakeFiles/SOURCES.dir/cmake_clean.cmake
.PHONY : project/CMakeFiles/SOURCES.dir/clean

project/CMakeFiles/SOURCES.dir/depend:
	cd /home/marcussss1/2022_2_MidnightSun/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/marcussss1/2022_2_MidnightSun /home/marcussss1/2022_2_MidnightSun/project /home/marcussss1/2022_2_MidnightSun/build /home/marcussss1/2022_2_MidnightSun/build/project /home/marcussss1/2022_2_MidnightSun/build/project/CMakeFiles/SOURCES.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : project/CMakeFiles/SOURCES.dir/depend

