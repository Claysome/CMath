# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list

# Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/bin/ccmake

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /root/workspace/CMath

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /root/workspace/CMath/build

# Include any dependencies generated for this target.
include CMakeFiles/entrance.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/entrance.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/entrance.dir/flags.make

CMakeFiles/entrance.dir/src/main.cpp.o: CMakeFiles/entrance.dir/flags.make
CMakeFiles/entrance.dir/src/main.cpp.o: ../src/main.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /root/workspace/CMath/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/entrance.dir/src/main.cpp.o"
	/usr/bin/g++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/entrance.dir/src/main.cpp.o -c /root/workspace/CMath/src/main.cpp

CMakeFiles/entrance.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/entrance.dir/src/main.cpp.i"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_FLAGS) -E /root/workspace/CMath/src/main.cpp > CMakeFiles/entrance.dir/src/main.cpp.i

CMakeFiles/entrance.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/entrance.dir/src/main.cpp.s"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_FLAGS) -S /root/workspace/CMath/src/main.cpp -o CMakeFiles/entrance.dir/src/main.cpp.s

CMakeFiles/entrance.dir/src/main.cpp.o.requires:
.PHONY : CMakeFiles/entrance.dir/src/main.cpp.o.requires

CMakeFiles/entrance.dir/src/main.cpp.o.provides: CMakeFiles/entrance.dir/src/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/entrance.dir/build.make CMakeFiles/entrance.dir/src/main.cpp.o.provides.build
.PHONY : CMakeFiles/entrance.dir/src/main.cpp.o.provides

CMakeFiles/entrance.dir/src/main.cpp.o.provides.build: CMakeFiles/entrance.dir/src/main.cpp.o

CMakeFiles/entrance.dir/src/matlib.cpp.o: CMakeFiles/entrance.dir/flags.make
CMakeFiles/entrance.dir/src/matlib.cpp.o: ../src/matlib.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /root/workspace/CMath/build/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/entrance.dir/src/matlib.cpp.o"
	/usr/bin/g++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/entrance.dir/src/matlib.cpp.o -c /root/workspace/CMath/src/matlib.cpp

CMakeFiles/entrance.dir/src/matlib.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/entrance.dir/src/matlib.cpp.i"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_FLAGS) -E /root/workspace/CMath/src/matlib.cpp > CMakeFiles/entrance.dir/src/matlib.cpp.i

CMakeFiles/entrance.dir/src/matlib.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/entrance.dir/src/matlib.cpp.s"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_FLAGS) -S /root/workspace/CMath/src/matlib.cpp -o CMakeFiles/entrance.dir/src/matlib.cpp.s

CMakeFiles/entrance.dir/src/matlib.cpp.o.requires:
.PHONY : CMakeFiles/entrance.dir/src/matlib.cpp.o.requires

CMakeFiles/entrance.dir/src/matlib.cpp.o.provides: CMakeFiles/entrance.dir/src/matlib.cpp.o.requires
	$(MAKE) -f CMakeFiles/entrance.dir/build.make CMakeFiles/entrance.dir/src/matlib.cpp.o.provides.build
.PHONY : CMakeFiles/entrance.dir/src/matlib.cpp.o.provides

CMakeFiles/entrance.dir/src/matlib.cpp.o.provides.build: CMakeFiles/entrance.dir/src/matlib.cpp.o

# Object files for target entrance
entrance_OBJECTS = \
"CMakeFiles/entrance.dir/src/main.cpp.o" \
"CMakeFiles/entrance.dir/src/matlib.cpp.o"

# External object files for target entrance
entrance_EXTERNAL_OBJECTS =

entrance: CMakeFiles/entrance.dir/src/main.cpp.o
entrance: CMakeFiles/entrance.dir/src/matlib.cpp.o
entrance: CMakeFiles/entrance.dir/build.make
entrance: CMakeFiles/entrance.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable entrance"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/entrance.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/entrance.dir/build: entrance
.PHONY : CMakeFiles/entrance.dir/build

CMakeFiles/entrance.dir/requires: CMakeFiles/entrance.dir/src/main.cpp.o.requires
CMakeFiles/entrance.dir/requires: CMakeFiles/entrance.dir/src/matlib.cpp.o.requires
.PHONY : CMakeFiles/entrance.dir/requires

CMakeFiles/entrance.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/entrance.dir/cmake_clean.cmake
.PHONY : CMakeFiles/entrance.dir/clean

CMakeFiles/entrance.dir/depend:
	cd /root/workspace/CMath/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /root/workspace/CMath /root/workspace/CMath /root/workspace/CMath/build /root/workspace/CMath/build /root/workspace/CMath/build/CMakeFiles/entrance.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/entrance.dir/depend
