# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/dmirty/tddProject

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/dmirty/tddProject/build/Desktop-Debug

# Include any dependencies generated for this target.
include TestTask/libs/UnorderedMap/CMakeFiles/UnorderedMap_t.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include TestTask/libs/UnorderedMap/CMakeFiles/UnorderedMap_t.dir/compiler_depend.make

# Include the progress variables for this target.
include TestTask/libs/UnorderedMap/CMakeFiles/UnorderedMap_t.dir/progress.make

# Include the compile flags for this target's objects.
include TestTask/libs/UnorderedMap/CMakeFiles/UnorderedMap_t.dir/flags.make

TestTask/libs/UnorderedMap/CMakeFiles/UnorderedMap_t.dir/test/UnorderedMap_test.cpp.o: TestTask/libs/UnorderedMap/CMakeFiles/UnorderedMap_t.dir/flags.make
TestTask/libs/UnorderedMap/CMakeFiles/UnorderedMap_t.dir/test/UnorderedMap_test.cpp.o: ../../TestTask/libs/UnorderedMap/test/UnorderedMap_test.cpp
TestTask/libs/UnorderedMap/CMakeFiles/UnorderedMap_t.dir/test/UnorderedMap_test.cpp.o: TestTask/libs/UnorderedMap/CMakeFiles/UnorderedMap_t.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dmirty/tddProject/build/Desktop-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object TestTask/libs/UnorderedMap/CMakeFiles/UnorderedMap_t.dir/test/UnorderedMap_test.cpp.o"
	cd /home/dmirty/tddProject/build/Desktop-Debug/TestTask/libs/UnorderedMap && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT TestTask/libs/UnorderedMap/CMakeFiles/UnorderedMap_t.dir/test/UnorderedMap_test.cpp.o -MF CMakeFiles/UnorderedMap_t.dir/test/UnorderedMap_test.cpp.o.d -o CMakeFiles/UnorderedMap_t.dir/test/UnorderedMap_test.cpp.o -c /home/dmirty/tddProject/TestTask/libs/UnorderedMap/test/UnorderedMap_test.cpp

TestTask/libs/UnorderedMap/CMakeFiles/UnorderedMap_t.dir/test/UnorderedMap_test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/UnorderedMap_t.dir/test/UnorderedMap_test.cpp.i"
	cd /home/dmirty/tddProject/build/Desktop-Debug/TestTask/libs/UnorderedMap && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dmirty/tddProject/TestTask/libs/UnorderedMap/test/UnorderedMap_test.cpp > CMakeFiles/UnorderedMap_t.dir/test/UnorderedMap_test.cpp.i

TestTask/libs/UnorderedMap/CMakeFiles/UnorderedMap_t.dir/test/UnorderedMap_test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/UnorderedMap_t.dir/test/UnorderedMap_test.cpp.s"
	cd /home/dmirty/tddProject/build/Desktop-Debug/TestTask/libs/UnorderedMap && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dmirty/tddProject/TestTask/libs/UnorderedMap/test/UnorderedMap_test.cpp -o CMakeFiles/UnorderedMap_t.dir/test/UnorderedMap_test.cpp.s

TestTask/libs/UnorderedMap/CMakeFiles/UnorderedMap_t.dir/test/main.cpp.o: TestTask/libs/UnorderedMap/CMakeFiles/UnorderedMap_t.dir/flags.make
TestTask/libs/UnorderedMap/CMakeFiles/UnorderedMap_t.dir/test/main.cpp.o: ../../TestTask/libs/UnorderedMap/test/main.cpp
TestTask/libs/UnorderedMap/CMakeFiles/UnorderedMap_t.dir/test/main.cpp.o: TestTask/libs/UnorderedMap/CMakeFiles/UnorderedMap_t.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dmirty/tddProject/build/Desktop-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object TestTask/libs/UnorderedMap/CMakeFiles/UnorderedMap_t.dir/test/main.cpp.o"
	cd /home/dmirty/tddProject/build/Desktop-Debug/TestTask/libs/UnorderedMap && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT TestTask/libs/UnorderedMap/CMakeFiles/UnorderedMap_t.dir/test/main.cpp.o -MF CMakeFiles/UnorderedMap_t.dir/test/main.cpp.o.d -o CMakeFiles/UnorderedMap_t.dir/test/main.cpp.o -c /home/dmirty/tddProject/TestTask/libs/UnorderedMap/test/main.cpp

TestTask/libs/UnorderedMap/CMakeFiles/UnorderedMap_t.dir/test/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/UnorderedMap_t.dir/test/main.cpp.i"
	cd /home/dmirty/tddProject/build/Desktop-Debug/TestTask/libs/UnorderedMap && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dmirty/tddProject/TestTask/libs/UnorderedMap/test/main.cpp > CMakeFiles/UnorderedMap_t.dir/test/main.cpp.i

TestTask/libs/UnorderedMap/CMakeFiles/UnorderedMap_t.dir/test/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/UnorderedMap_t.dir/test/main.cpp.s"
	cd /home/dmirty/tddProject/build/Desktop-Debug/TestTask/libs/UnorderedMap && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dmirty/tddProject/TestTask/libs/UnorderedMap/test/main.cpp -o CMakeFiles/UnorderedMap_t.dir/test/main.cpp.s

# Object files for target UnorderedMap_t
UnorderedMap_t_OBJECTS = \
"CMakeFiles/UnorderedMap_t.dir/test/UnorderedMap_test.cpp.o" \
"CMakeFiles/UnorderedMap_t.dir/test/main.cpp.o"

# External object files for target UnorderedMap_t
UnorderedMap_t_EXTERNAL_OBJECTS =

test/UnorderedMap_t: TestTask/libs/UnorderedMap/CMakeFiles/UnorderedMap_t.dir/test/UnorderedMap_test.cpp.o
test/UnorderedMap_t: TestTask/libs/UnorderedMap/CMakeFiles/UnorderedMap_t.dir/test/main.cpp.o
test/UnorderedMap_t: TestTask/libs/UnorderedMap/CMakeFiles/UnorderedMap_t.dir/build.make
test/UnorderedMap_t: tddProject/binaries/lib/libUnorderedMap.so
test/UnorderedMap_t: tddProject/binaries/lib/libgtest.so
test/UnorderedMap_t: TestTask/libs/UnorderedMap/CMakeFiles/UnorderedMap_t.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/dmirty/tddProject/build/Desktop-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable ../../../test/UnorderedMap_t"
	cd /home/dmirty/tddProject/build/Desktop-Debug/TestTask/libs/UnorderedMap && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/UnorderedMap_t.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
TestTask/libs/UnorderedMap/CMakeFiles/UnorderedMap_t.dir/build: test/UnorderedMap_t
.PHONY : TestTask/libs/UnorderedMap/CMakeFiles/UnorderedMap_t.dir/build

TestTask/libs/UnorderedMap/CMakeFiles/UnorderedMap_t.dir/clean:
	cd /home/dmirty/tddProject/build/Desktop-Debug/TestTask/libs/UnorderedMap && $(CMAKE_COMMAND) -P CMakeFiles/UnorderedMap_t.dir/cmake_clean.cmake
.PHONY : TestTask/libs/UnorderedMap/CMakeFiles/UnorderedMap_t.dir/clean

TestTask/libs/UnorderedMap/CMakeFiles/UnorderedMap_t.dir/depend:
	cd /home/dmirty/tddProject/build/Desktop-Debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/dmirty/tddProject /home/dmirty/tddProject/TestTask/libs/UnorderedMap /home/dmirty/tddProject/build/Desktop-Debug /home/dmirty/tddProject/build/Desktop-Debug/TestTask/libs/UnorderedMap /home/dmirty/tddProject/build/Desktop-Debug/TestTask/libs/UnorderedMap/CMakeFiles/UnorderedMap_t.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : TestTask/libs/UnorderedMap/CMakeFiles/UnorderedMap_t.dir/depend

