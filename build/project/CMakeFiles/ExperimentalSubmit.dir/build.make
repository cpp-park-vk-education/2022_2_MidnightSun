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

# Utility rule file for ExperimentalSubmit.

# Include any custom commands dependencies for this target.
include project/CMakeFiles/ExperimentalSubmit.dir/compiler_depend.make

# Include the progress variables for this target.
include project/CMakeFiles/ExperimentalSubmit.dir/progress.make

project/CMakeFiles/ExperimentalSubmit:
	cd /home/marcussss1/2022_2_MidnightSun/build/project && /usr/local/bin/ctest -D ExperimentalSubmit

ExperimentalSubmit: project/CMakeFiles/ExperimentalSubmit
ExperimentalSubmit: project/CMakeFiles/ExperimentalSubmit.dir/build.make
.PHONY : ExperimentalSubmit

# Rule to build all files generated by this target.
project/CMakeFiles/ExperimentalSubmit.dir/build: ExperimentalSubmit
.PHONY : project/CMakeFiles/ExperimentalSubmit.dir/build

project/CMakeFiles/ExperimentalSubmit.dir/clean:
	cd /home/marcussss1/2022_2_MidnightSun/build/project && $(CMAKE_COMMAND) -P CMakeFiles/ExperimentalSubmit.dir/cmake_clean.cmake
.PHONY : project/CMakeFiles/ExperimentalSubmit.dir/clean

project/CMakeFiles/ExperimentalSubmit.dir/depend:
	cd /home/marcussss1/2022_2_MidnightSun/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/marcussss1/2022_2_MidnightSun /home/marcussss1/2022_2_MidnightSun/project /home/marcussss1/2022_2_MidnightSun/build /home/marcussss1/2022_2_MidnightSun/build/project /home/marcussss1/2022_2_MidnightSun/build/project/CMakeFiles/ExperimentalSubmit.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : project/CMakeFiles/ExperimentalSubmit.dir/depend

