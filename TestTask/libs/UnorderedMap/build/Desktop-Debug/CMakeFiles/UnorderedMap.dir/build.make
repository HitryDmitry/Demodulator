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
CMAKE_SOURCE_DIR = /home/dmirty/tddProject/TestTask/libs/UnorderedMap

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/dmirty/tddProject/TestTask/libs/UnorderedMap/build/Desktop-Debug

# Include any dependencies generated for this target.
include CMakeFiles/UnorderedMap.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/UnorderedMap.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/UnorderedMap.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/UnorderedMap.dir/flags.make

CMakeFiles/UnorderedMap.dir/UnorderedMap_autogen/mocs_compilation.cpp.o: CMakeFiles/UnorderedMap.dir/flags.make
CMakeFiles/UnorderedMap.dir/UnorderedMap_autogen/mocs_compilation.cpp.o: UnorderedMap_autogen/mocs_compilation.cpp
CMakeFiles/UnorderedMap.dir/UnorderedMap_autogen/mocs_compilation.cpp.o: CMakeFiles/UnorderedMap.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dmirty/tddProject/TestTask/libs/UnorderedMap/build/Desktop-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/UnorderedMap.dir/UnorderedMap_autogen/mocs_compilation.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/UnorderedMap.dir/UnorderedMap_autogen/mocs_compilation.cpp.o -MF CMakeFiles/UnorderedMap.dir/UnorderedMap_autogen/mocs_compilation.cpp.o.d -o CMakeFiles/UnorderedMap.dir/UnorderedMap_autogen/mocs_compilation.cpp.o -c /home/dmirty/tddProject/TestTask/libs/UnorderedMap/build/Desktop-Debug/UnorderedMap_autogen/mocs_compilation.cpp

CMakeFiles/UnorderedMap.dir/UnorderedMap_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/UnorderedMap.dir/UnorderedMap_autogen/mocs_compilation.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dmirty/tddProject/TestTask/libs/UnorderedMap/build/Desktop-Debug/UnorderedMap_autogen/mocs_compilation.cpp > CMakeFiles/UnorderedMap.dir/UnorderedMap_autogen/mocs_compilation.cpp.i

CMakeFiles/UnorderedMap.dir/UnorderedMap_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/UnorderedMap.dir/UnorderedMap_autogen/mocs_compilation.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dmirty/tddProject/TestTask/libs/UnorderedMap/build/Desktop-Debug/UnorderedMap_autogen/mocs_compilation.cpp -o CMakeFiles/UnorderedMap.dir/UnorderedMap_autogen/mocs_compilation.cpp.s

CMakeFiles/UnorderedMap.dir/unorderedmap.cpp.o: CMakeFiles/UnorderedMap.dir/flags.make
CMakeFiles/UnorderedMap.dir/unorderedmap.cpp.o: ../../unorderedmap.cpp
CMakeFiles/UnorderedMap.dir/unorderedmap.cpp.o: CMakeFiles/UnorderedMap.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dmirty/tddProject/TestTask/libs/UnorderedMap/build/Desktop-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/UnorderedMap.dir/unorderedmap.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/UnorderedMap.dir/unorderedmap.cpp.o -MF CMakeFiles/UnorderedMap.dir/unorderedmap.cpp.o.d -o CMakeFiles/UnorderedMap.dir/unorderedmap.cpp.o -c /home/dmirty/tddProject/TestTask/libs/UnorderedMap/unorderedmap.cpp

CMakeFiles/UnorderedMap.dir/unorderedmap.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/UnorderedMap.dir/unorderedmap.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dmirty/tddProject/TestTask/libs/UnorderedMap/unorderedmap.cpp > CMakeFiles/UnorderedMap.dir/unorderedmap.cpp.i

CMakeFiles/UnorderedMap.dir/unorderedmap.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/UnorderedMap.dir/unorderedmap.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dmirty/tddProject/TestTask/libs/UnorderedMap/unorderedmap.cpp -o CMakeFiles/UnorderedMap.dir/unorderedmap.cpp.s

# Object files for target UnorderedMap
UnorderedMap_OBJECTS = \
"CMakeFiles/UnorderedMap.dir/UnorderedMap_autogen/mocs_compilation.cpp.o" \
"CMakeFiles/UnorderedMap.dir/unorderedmap.cpp.o"

# External object files for target UnorderedMap
UnorderedMap_EXTERNAL_OBJECTS =

libUnorderedMap.so: CMakeFiles/UnorderedMap.dir/UnorderedMap_autogen/mocs_compilation.cpp.o
libUnorderedMap.so: CMakeFiles/UnorderedMap.dir/unorderedmap.cpp.o
libUnorderedMap.so: CMakeFiles/UnorderedMap.dir/build.make
libUnorderedMap.so: /usr/lib/x86_64-linux-gnu/libQt5Core.so.5.15.3
libUnorderedMap.so: CMakeFiles/UnorderedMap.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/dmirty/tddProject/TestTask/libs/UnorderedMap/build/Desktop-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX shared library libUnorderedMap.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/UnorderedMap.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/UnorderedMap.dir/build: libUnorderedMap.so
.PHONY : CMakeFiles/UnorderedMap.dir/build

CMakeFiles/UnorderedMap.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/UnorderedMap.dir/cmake_clean.cmake
.PHONY : CMakeFiles/UnorderedMap.dir/clean

CMakeFiles/UnorderedMap.dir/depend:
	cd /home/dmirty/tddProject/TestTask/libs/UnorderedMap/build/Desktop-Debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/dmirty/tddProject/TestTask/libs/UnorderedMap /home/dmirty/tddProject/TestTask/libs/UnorderedMap /home/dmirty/tddProject/TestTask/libs/UnorderedMap/build/Desktop-Debug /home/dmirty/tddProject/TestTask/libs/UnorderedMap/build/Desktop-Debug /home/dmirty/tddProject/TestTask/libs/UnorderedMap/build/Desktop-Debug/CMakeFiles/UnorderedMap.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/UnorderedMap.dir/depend

