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

# Include any dependencies generated for this target.
include CMakeFiles/T1.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/T1.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/T1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/T1.dir/flags.make

CMakeFiles/T1.dir/T1.cpp.o: CMakeFiles/T1.dir/flags.make
CMakeFiles/T1.dir/T1.cpp.o: /home/maith/Desktop/rt/raytracing/T1.cpp
CMakeFiles/T1.dir/T1.cpp.o: CMakeFiles/T1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/maith/Desktop/rt/raytracing/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/T1.dir/T1.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/T1.dir/T1.cpp.o -MF CMakeFiles/T1.dir/T1.cpp.o.d -o CMakeFiles/T1.dir/T1.cpp.o -c /home/maith/Desktop/rt/raytracing/T1.cpp

CMakeFiles/T1.dir/T1.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/T1.dir/T1.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/maith/Desktop/rt/raytracing/T1.cpp > CMakeFiles/T1.dir/T1.cpp.i

CMakeFiles/T1.dir/T1.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/T1.dir/T1.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/maith/Desktop/rt/raytracing/T1.cpp -o CMakeFiles/T1.dir/T1.cpp.s

# Object files for target T1
T1_OBJECTS = \
"CMakeFiles/T1.dir/T1.cpp.o"

# External object files for target T1
T1_EXTERNAL_OBJECTS =

T1: CMakeFiles/T1.dir/T1.cpp.o
T1: CMakeFiles/T1.dir/build.make
T1: pugixml/libpugixml.a
T1: CMakeFiles/T1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/maith/Desktop/rt/raytracing/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable T1"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/T1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/T1.dir/build: T1
.PHONY : CMakeFiles/T1.dir/build

CMakeFiles/T1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/T1.dir/cmake_clean.cmake
.PHONY : CMakeFiles/T1.dir/clean

CMakeFiles/T1.dir/depend:
	cd /home/maith/Desktop/rt/raytracing/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/maith/Desktop/rt/raytracing /home/maith/Desktop/rt/raytracing /home/maith/Desktop/rt/raytracing/build /home/maith/Desktop/rt/raytracing/build /home/maith/Desktop/rt/raytracing/build/CMakeFiles/T1.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/T1.dir/depend

