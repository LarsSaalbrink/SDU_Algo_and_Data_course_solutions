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
CMAKE_SOURCE_DIR = "/mnt/c/Users/kaasv/Desktop/Git checkouts/SDU_Algo_and_Data_course_solutions/L7"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/mnt/c/Users/kaasv/Desktop/Git checkouts/SDU_Algo_and_Data_course_solutions/L7/out"

# Include any dependencies generated for this target.
include lib/CMakeFiles/Lib.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include lib/CMakeFiles/Lib.dir/compiler_depend.make

# Include the progress variables for this target.
include lib/CMakeFiles/Lib.dir/progress.make

# Include the compile flags for this target's objects.
include lib/CMakeFiles/Lib.dir/flags.make

lib/CMakeFiles/Lib.dir/Lib.cpp.o: lib/CMakeFiles/Lib.dir/flags.make
lib/CMakeFiles/Lib.dir/Lib.cpp.o: ../lib/Lib.cpp
lib/CMakeFiles/Lib.dir/Lib.cpp.o: lib/CMakeFiles/Lib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/mnt/c/Users/kaasv/Desktop/Git checkouts/SDU_Algo_and_Data_course_solutions/L7/out/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object lib/CMakeFiles/Lib.dir/Lib.cpp.o"
	cd "/mnt/c/Users/kaasv/Desktop/Git checkouts/SDU_Algo_and_Data_course_solutions/L7/out/lib" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT lib/CMakeFiles/Lib.dir/Lib.cpp.o -MF CMakeFiles/Lib.dir/Lib.cpp.o.d -o CMakeFiles/Lib.dir/Lib.cpp.o -c "/mnt/c/Users/kaasv/Desktop/Git checkouts/SDU_Algo_and_Data_course_solutions/L7/lib/Lib.cpp"

lib/CMakeFiles/Lib.dir/Lib.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Lib.dir/Lib.cpp.i"
	cd "/mnt/c/Users/kaasv/Desktop/Git checkouts/SDU_Algo_and_Data_course_solutions/L7/out/lib" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/mnt/c/Users/kaasv/Desktop/Git checkouts/SDU_Algo_and_Data_course_solutions/L7/lib/Lib.cpp" > CMakeFiles/Lib.dir/Lib.cpp.i

lib/CMakeFiles/Lib.dir/Lib.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Lib.dir/Lib.cpp.s"
	cd "/mnt/c/Users/kaasv/Desktop/Git checkouts/SDU_Algo_and_Data_course_solutions/L7/out/lib" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/mnt/c/Users/kaasv/Desktop/Git checkouts/SDU_Algo_and_Data_course_solutions/L7/lib/Lib.cpp" -o CMakeFiles/Lib.dir/Lib.cpp.s

lib/CMakeFiles/Lib.dir/BinarySearchTree.cpp.o: lib/CMakeFiles/Lib.dir/flags.make
lib/CMakeFiles/Lib.dir/BinarySearchTree.cpp.o: ../lib/BinarySearchTree.cpp
lib/CMakeFiles/Lib.dir/BinarySearchTree.cpp.o: lib/CMakeFiles/Lib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/mnt/c/Users/kaasv/Desktop/Git checkouts/SDU_Algo_and_Data_course_solutions/L7/out/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object lib/CMakeFiles/Lib.dir/BinarySearchTree.cpp.o"
	cd "/mnt/c/Users/kaasv/Desktop/Git checkouts/SDU_Algo_and_Data_course_solutions/L7/out/lib" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT lib/CMakeFiles/Lib.dir/BinarySearchTree.cpp.o -MF CMakeFiles/Lib.dir/BinarySearchTree.cpp.o.d -o CMakeFiles/Lib.dir/BinarySearchTree.cpp.o -c "/mnt/c/Users/kaasv/Desktop/Git checkouts/SDU_Algo_and_Data_course_solutions/L7/lib/BinarySearchTree.cpp"

lib/CMakeFiles/Lib.dir/BinarySearchTree.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Lib.dir/BinarySearchTree.cpp.i"
	cd "/mnt/c/Users/kaasv/Desktop/Git checkouts/SDU_Algo_and_Data_course_solutions/L7/out/lib" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/mnt/c/Users/kaasv/Desktop/Git checkouts/SDU_Algo_and_Data_course_solutions/L7/lib/BinarySearchTree.cpp" > CMakeFiles/Lib.dir/BinarySearchTree.cpp.i

lib/CMakeFiles/Lib.dir/BinarySearchTree.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Lib.dir/BinarySearchTree.cpp.s"
	cd "/mnt/c/Users/kaasv/Desktop/Git checkouts/SDU_Algo_and_Data_course_solutions/L7/out/lib" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/mnt/c/Users/kaasv/Desktop/Git checkouts/SDU_Algo_and_Data_course_solutions/L7/lib/BinarySearchTree.cpp" -o CMakeFiles/Lib.dir/BinarySearchTree.cpp.s

# Object files for target Lib
Lib_OBJECTS = \
"CMakeFiles/Lib.dir/Lib.cpp.o" \
"CMakeFiles/Lib.dir/BinarySearchTree.cpp.o"

# External object files for target Lib
Lib_EXTERNAL_OBJECTS =

lib/libLib.a: lib/CMakeFiles/Lib.dir/Lib.cpp.o
lib/libLib.a: lib/CMakeFiles/Lib.dir/BinarySearchTree.cpp.o
lib/libLib.a: lib/CMakeFiles/Lib.dir/build.make
lib/libLib.a: lib/CMakeFiles/Lib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/mnt/c/Users/kaasv/Desktop/Git checkouts/SDU_Algo_and_Data_course_solutions/L7/out/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX static library libLib.a"
	cd "/mnt/c/Users/kaasv/Desktop/Git checkouts/SDU_Algo_and_Data_course_solutions/L7/out/lib" && $(CMAKE_COMMAND) -P CMakeFiles/Lib.dir/cmake_clean_target.cmake
	cd "/mnt/c/Users/kaasv/Desktop/Git checkouts/SDU_Algo_and_Data_course_solutions/L7/out/lib" && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Lib.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
lib/CMakeFiles/Lib.dir/build: lib/libLib.a
.PHONY : lib/CMakeFiles/Lib.dir/build

lib/CMakeFiles/Lib.dir/clean:
	cd "/mnt/c/Users/kaasv/Desktop/Git checkouts/SDU_Algo_and_Data_course_solutions/L7/out/lib" && $(CMAKE_COMMAND) -P CMakeFiles/Lib.dir/cmake_clean.cmake
.PHONY : lib/CMakeFiles/Lib.dir/clean

lib/CMakeFiles/Lib.dir/depend:
	cd "/mnt/c/Users/kaasv/Desktop/Git checkouts/SDU_Algo_and_Data_course_solutions/L7/out" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/mnt/c/Users/kaasv/Desktop/Git checkouts/SDU_Algo_and_Data_course_solutions/L7" "/mnt/c/Users/kaasv/Desktop/Git checkouts/SDU_Algo_and_Data_course_solutions/L7/lib" "/mnt/c/Users/kaasv/Desktop/Git checkouts/SDU_Algo_and_Data_course_solutions/L7/out" "/mnt/c/Users/kaasv/Desktop/Git checkouts/SDU_Algo_and_Data_course_solutions/L7/out/lib" "/mnt/c/Users/kaasv/Desktop/Git checkouts/SDU_Algo_and_Data_course_solutions/L7/out/lib/CMakeFiles/Lib.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : lib/CMakeFiles/Lib.dir/depend

