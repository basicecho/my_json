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
include src/CMakeFiles/SRC_LIST.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/SRC_LIST.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/SRC_LIST.dir/flags.make

src/CMakeFiles/SRC_LIST.dir/leptjson.cpp.o: src/CMakeFiles/SRC_LIST.dir/flags.make
src/CMakeFiles/SRC_LIST.dir/leptjson.cpp.o: ../src/leptjson.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/basicecho/Desktop/project/my_json/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/SRC_LIST.dir/leptjson.cpp.o"
	cd /home/basicecho/Desktop/project/my_json/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SRC_LIST.dir/leptjson.cpp.o -c /home/basicecho/Desktop/project/my_json/src/leptjson.cpp

src/CMakeFiles/SRC_LIST.dir/leptjson.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SRC_LIST.dir/leptjson.cpp.i"
	cd /home/basicecho/Desktop/project/my_json/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/basicecho/Desktop/project/my_json/src/leptjson.cpp > CMakeFiles/SRC_LIST.dir/leptjson.cpp.i

src/CMakeFiles/SRC_LIST.dir/leptjson.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SRC_LIST.dir/leptjson.cpp.s"
	cd /home/basicecho/Desktop/project/my_json/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/basicecho/Desktop/project/my_json/src/leptjson.cpp -o CMakeFiles/SRC_LIST.dir/leptjson.cpp.s

src/CMakeFiles/SRC_LIST.dir/util.cpp.o: src/CMakeFiles/SRC_LIST.dir/flags.make
src/CMakeFiles/SRC_LIST.dir/util.cpp.o: ../src/util.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/basicecho/Desktop/project/my_json/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/CMakeFiles/SRC_LIST.dir/util.cpp.o"
	cd /home/basicecho/Desktop/project/my_json/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SRC_LIST.dir/util.cpp.o -c /home/basicecho/Desktop/project/my_json/src/util.cpp

src/CMakeFiles/SRC_LIST.dir/util.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SRC_LIST.dir/util.cpp.i"
	cd /home/basicecho/Desktop/project/my_json/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/basicecho/Desktop/project/my_json/src/util.cpp > CMakeFiles/SRC_LIST.dir/util.cpp.i

src/CMakeFiles/SRC_LIST.dir/util.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SRC_LIST.dir/util.cpp.s"
	cd /home/basicecho/Desktop/project/my_json/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/basicecho/Desktop/project/my_json/src/util.cpp -o CMakeFiles/SRC_LIST.dir/util.cpp.s

# Object files for target SRC_LIST
SRC_LIST_OBJECTS = \
"CMakeFiles/SRC_LIST.dir/leptjson.cpp.o" \
"CMakeFiles/SRC_LIST.dir/util.cpp.o"

# External object files for target SRC_LIST
SRC_LIST_EXTERNAL_OBJECTS =

src/libSRC_LIST.a: src/CMakeFiles/SRC_LIST.dir/leptjson.cpp.o
src/libSRC_LIST.a: src/CMakeFiles/SRC_LIST.dir/util.cpp.o
src/libSRC_LIST.a: src/CMakeFiles/SRC_LIST.dir/build.make
src/libSRC_LIST.a: src/CMakeFiles/SRC_LIST.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/basicecho/Desktop/project/my_json/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX static library libSRC_LIST.a"
	cd /home/basicecho/Desktop/project/my_json/build/src && $(CMAKE_COMMAND) -P CMakeFiles/SRC_LIST.dir/cmake_clean_target.cmake
	cd /home/basicecho/Desktop/project/my_json/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SRC_LIST.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/SRC_LIST.dir/build: src/libSRC_LIST.a

.PHONY : src/CMakeFiles/SRC_LIST.dir/build

src/CMakeFiles/SRC_LIST.dir/clean:
	cd /home/basicecho/Desktop/project/my_json/build/src && $(CMAKE_COMMAND) -P CMakeFiles/SRC_LIST.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/SRC_LIST.dir/clean

src/CMakeFiles/SRC_LIST.dir/depend:
	cd /home/basicecho/Desktop/project/my_json/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/basicecho/Desktop/project/my_json /home/basicecho/Desktop/project/my_json/src /home/basicecho/Desktop/project/my_json/build /home/basicecho/Desktop/project/my_json/build/src /home/basicecho/Desktop/project/my_json/build/src/CMakeFiles/SRC_LIST.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/SRC_LIST.dir/depend

