# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


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

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/basicecho/Desktop/project/my_json

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/basicecho/Desktop/project/my_json/build

# Include any dependencies generated for this target.
include CMakeFiles/test_literal.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/test_literal.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/test_literal.dir/flags.make

CMakeFiles/test_literal.dir/test/test_literal.cpp.o: CMakeFiles/test_literal.dir/flags.make
CMakeFiles/test_literal.dir/test/test_literal.cpp.o: ../test/test_literal.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/basicecho/Desktop/project/my_json/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/test_literal.dir/test/test_literal.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test_literal.dir/test/test_literal.cpp.o -c /home/basicecho/Desktop/project/my_json/test/test_literal.cpp

CMakeFiles/test_literal.dir/test/test_literal.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_literal.dir/test/test_literal.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/basicecho/Desktop/project/my_json/test/test_literal.cpp > CMakeFiles/test_literal.dir/test/test_literal.cpp.i

CMakeFiles/test_literal.dir/test/test_literal.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_literal.dir/test/test_literal.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/basicecho/Desktop/project/my_json/test/test_literal.cpp -o CMakeFiles/test_literal.dir/test/test_literal.cpp.s

# Object files for target test_literal
test_literal_OBJECTS = \
"CMakeFiles/test_literal.dir/test/test_literal.cpp.o"

# External object files for target test_literal
test_literal_EXTERNAL_OBJECTS =

test_literal: CMakeFiles/test_literal.dir/test/test_literal.cpp.o
test_literal: CMakeFiles/test_literal.dir/build.make
test_literal: src/libSRC_LIST.a
test_literal: CMakeFiles/test_literal.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/basicecho/Desktop/project/my_json/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable test_literal"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_literal.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/test_literal.dir/build: test_literal

.PHONY : CMakeFiles/test_literal.dir/build

CMakeFiles/test_literal.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/test_literal.dir/cmake_clean.cmake
.PHONY : CMakeFiles/test_literal.dir/clean

CMakeFiles/test_literal.dir/depend:
	cd /home/basicecho/Desktop/project/my_json/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/basicecho/Desktop/project/my_json /home/basicecho/Desktop/project/my_json /home/basicecho/Desktop/project/my_json/build /home/basicecho/Desktop/project/my_json/build /home/basicecho/Desktop/project/my_json/build/CMakeFiles/test_literal.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/test_literal.dir/depend

