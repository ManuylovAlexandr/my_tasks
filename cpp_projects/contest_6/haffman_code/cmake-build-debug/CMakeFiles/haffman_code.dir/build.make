# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

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
CMAKE_COMMAND = /cygdrive/c/Users/Manura/.CLion2019.2/system/cygwin_cmake/bin/cmake.exe

# The command to remove a file.
RM = /cygdrive/c/Users/Manura/.CLion2019.2/system/cygwin_cmake/bin/cmake.exe -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /cygdrive/c/Users/Manura/CLionProjects/haffman_code

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /cygdrive/c/Users/Manura/CLionProjects/haffman_code/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/haffman_code.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/haffman_code.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/haffman_code.dir/flags.make

CMakeFiles/haffman_code.dir/main.cpp.o: CMakeFiles/haffman_code.dir/flags.make
CMakeFiles/haffman_code.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/c/Users/Manura/CLionProjects/haffman_code/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/haffman_code.dir/main.cpp.o"
	/usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/haffman_code.dir/main.cpp.o -c /cygdrive/c/Users/Manura/CLionProjects/haffman_code/main.cpp

CMakeFiles/haffman_code.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/haffman_code.dir/main.cpp.i"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cygdrive/c/Users/Manura/CLionProjects/haffman_code/main.cpp > CMakeFiles/haffman_code.dir/main.cpp.i

CMakeFiles/haffman_code.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/haffman_code.dir/main.cpp.s"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cygdrive/c/Users/Manura/CLionProjects/haffman_code/main.cpp -o CMakeFiles/haffman_code.dir/main.cpp.s

# Object files for target haffman_code
haffman_code_OBJECTS = \
"CMakeFiles/haffman_code.dir/main.cpp.o"

# External object files for target haffman_code
haffman_code_EXTERNAL_OBJECTS =

haffman_code.exe: CMakeFiles/haffman_code.dir/main.cpp.o
haffman_code.exe: CMakeFiles/haffman_code.dir/build.make
haffman_code.exe: CMakeFiles/haffman_code.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/cygdrive/c/Users/Manura/CLionProjects/haffman_code/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable haffman_code.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/haffman_code.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/haffman_code.dir/build: haffman_code.exe

.PHONY : CMakeFiles/haffman_code.dir/build

CMakeFiles/haffman_code.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/haffman_code.dir/cmake_clean.cmake
.PHONY : CMakeFiles/haffman_code.dir/clean

CMakeFiles/haffman_code.dir/depend:
	cd /cygdrive/c/Users/Manura/CLionProjects/haffman_code/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /cygdrive/c/Users/Manura/CLionProjects/haffman_code /cygdrive/c/Users/Manura/CLionProjects/haffman_code /cygdrive/c/Users/Manura/CLionProjects/haffman_code/cmake-build-debug /cygdrive/c/Users/Manura/CLionProjects/haffman_code/cmake-build-debug /cygdrive/c/Users/Manura/CLionProjects/haffman_code/cmake-build-debug/CMakeFiles/haffman_code.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/haffman_code.dir/depend

