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

# Utility rule file for NightlyBuild.

# Include any custom commands dependencies for this target.
include project/unit_tests/CMakeFiles/NightlyBuild.dir/compiler_depend.make

# Include the progress variables for this target.
include project/unit_tests/CMakeFiles/NightlyBuild.dir/progress.make

project/unit_tests/CMakeFiles/NightlyBuild:
	cd /home/marcussss1/2022_2_MidnightSun/build/project/unit_tests && /usr/local/bin/ctest -D NightlyBuild

NightlyBuild: project/unit_tests/CMakeFiles/NightlyBuild
NightlyBuild: project/unit_tests/CMakeFiles/NightlyBuild.dir/build.make
.PHONY : NightlyBuild

# Rule to build all files generated by this target.
project/unit_tests/CMakeFiles/NightlyBuild.dir/build: NightlyBuild
.PHONY : project/unit_tests/CMakeFiles/NightlyBuild.dir/build

project/unit_tests/CMakeFiles/NightlyBuild.dir/clean:
	cd /home/marcussss1/2022_2_MidnightSun/build/project/unit_tests && $(CMAKE_COMMAND) -P CMakeFiles/NightlyBuild.dir/cmake_clean.cmake
.PHONY : project/unit_tests/CMakeFiles/NightlyBuild.dir/clean

project/unit_tests/CMakeFiles/NightlyBuild.dir/depend:
	cd /home/marcussss1/2022_2_MidnightSun/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/marcussss1/2022_2_MidnightSun /home/marcussss1/2022_2_MidnightSun/project/unit_tests /home/marcussss1/2022_2_MidnightSun/build /home/marcussss1/2022_2_MidnightSun/build/project/unit_tests /home/marcussss1/2022_2_MidnightSun/build/project/unit_tests/CMakeFiles/NightlyBuild.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : project/unit_tests/CMakeFiles/NightlyBuild.dir/depend

