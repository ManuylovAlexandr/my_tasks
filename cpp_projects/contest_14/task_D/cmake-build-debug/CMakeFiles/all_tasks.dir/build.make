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
CMAKE_SOURCE_DIR = /cygdrive/c/Users/Manura/CLionProjects/contest_14/task_D

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /cygdrive/c/Users/Manura/CLionProjects/contest_14/task_D/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/all_tasks.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/all_tasks.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/all_tasks.dir/flags.make

CMakeFiles/all_tasks.dir/main_D.cpp.o: CMakeFiles/all_tasks.dir/flags.make
CMakeFiles/all_tasks.dir/main_D.cpp.o: ../main_D.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/c/Users/Manura/CLionProjects/contest_14/task_D/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/all_tasks.dir/main_D.cpp.o"
	/usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/all_tasks.dir/main_D.cpp.o -c /cygdrive/c/Users/Manura/CLionProjects/contest_14/task_D/main_D.cpp

CMakeFiles/all_tasks.dir/main_D.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/all_tasks.dir/main_D.cpp.i"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cygdrive/c/Users/Manura/CLionProjects/contest_14/task_D/main_D.cpp > CMakeFiles/all_tasks.dir/main_D.cpp.i

CMakeFiles/all_tasks.dir/main_D.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/all_tasks.dir/main_D.cpp.s"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cygdrive/c/Users/Manura/CLionProjects/contest_14/task_D/main_D.cpp -o CMakeFiles/all_tasks.dir/main_D.cpp.s

# Object files for target all_tasks
all_tasks_OBJECTS = \
"CMakeFiles/all_tasks.dir/main_D.cpp.o"

# External object files for target all_tasks
all_tasks_EXTERNAL_OBJECTS =

all_tasks.exe: CMakeFiles/all_tasks.dir/main_D.cpp.o
all_tasks.exe: CMakeFiles/all_tasks.dir/build.make
all_tasks.exe: CMakeFiles/all_tasks.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/cygdrive/c/Users/Manura/CLionProjects/contest_14/task_D/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable all_tasks.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/all_tasks.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/all_tasks.dir/build: all_tasks.exe

.PHONY : CMakeFiles/all_tasks.dir/build

CMakeFiles/all_tasks.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/all_tasks.dir/cmake_clean.cmake
.PHONY : CMakeFiles/all_tasks.dir/clean

CMakeFiles/all_tasks.dir/depend:
	cd /cygdrive/c/Users/Manura/CLionProjects/contest_14/task_D/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /cygdrive/c/Users/Manura/CLionProjects/contest_14/task_D /cygdrive/c/Users/Manura/CLionProjects/contest_14/task_D /cygdrive/c/Users/Manura/CLionProjects/contest_14/task_D/cmake-build-debug /cygdrive/c/Users/Manura/CLionProjects/contest_14/task_D/cmake-build-debug /cygdrive/c/Users/Manura/CLionProjects/contest_14/task_D/cmake-build-debug/CMakeFiles/all_tasks.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/all_tasks.dir/depend

