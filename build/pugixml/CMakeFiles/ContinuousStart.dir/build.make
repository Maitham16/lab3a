# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.26

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
CMAKE_COMMAND = /home/maith/.local/lib/python3.11/site-packages/cmake/data/bin/cmake

# The command to remove a file.
RM = /home/maith/.local/lib/python3.11/site-packages/cmake/data/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/maith/Desktop/rt/raytracing

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/maith/Desktop/rt/raytracing/build

# Utility rule file for ContinuousStart.

# Include any custom commands dependencies for this target.
include pugixml/CMakeFiles/ContinuousStart.dir/compiler_depend.make

# Include the progress variables for this target.
include pugixml/CMakeFiles/ContinuousStart.dir/progress.make

pugixml/CMakeFiles/ContinuousStart:
	cd /home/maith/Desktop/rt/raytracing/build/pugixml && /home/maith/.local/lib/python3.11/site-packages/cmake/data/bin/ctest -D ContinuousStart

ContinuousStart: pugixml/CMakeFiles/ContinuousStart
ContinuousStart: pugixml/CMakeFiles/ContinuousStart.dir/build.make
.PHONY : ContinuousStart

# Rule to build all files generated by this target.
pugixml/CMakeFiles/ContinuousStart.dir/build: ContinuousStart
.PHONY : pugixml/CMakeFiles/ContinuousStart.dir/build

pugixml/CMakeFiles/ContinuousStart.dir/clean:
	cd /home/maith/Desktop/rt/raytracing/build/pugixml && $(CMAKE_COMMAND) -P CMakeFiles/ContinuousStart.dir/cmake_clean.cmake
.PHONY : pugixml/CMakeFiles/ContinuousStart.dir/clean

pugixml/CMakeFiles/ContinuousStart.dir/depend:
	cd /home/maith/Desktop/rt/raytracing/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/maith/Desktop/rt/raytracing /home/maith/Desktop/rt/raytracing/pugixml /home/maith/Desktop/rt/raytracing/build /home/maith/Desktop/rt/raytracing/build/pugixml /home/maith/Desktop/rt/raytracing/build/pugixml/CMakeFiles/ContinuousStart.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : pugixml/CMakeFiles/ContinuousStart.dir/depend

