# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.13.0/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.13.0/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/Oskar/Code/ipk/uebung06/source

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/Oskar/Code/ipk/uebung06/build2

# Include any dependencies generated for this target.
include CMakeFiles/uniform.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/uniform.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/uniform.dir/flags.make

CMakeFiles/uniform.dir/uniform.cc.o: CMakeFiles/uniform.dir/flags.make
CMakeFiles/uniform.dir/uniform.cc.o: /Users/Oskar/Code/ipk/uebung06/source/uniform.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/Oskar/Code/ipk/uebung06/build2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/uniform.dir/uniform.cc.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/uniform.dir/uniform.cc.o -c /Users/Oskar/Code/ipk/uebung06/source/uniform.cc

CMakeFiles/uniform.dir/uniform.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/uniform.dir/uniform.cc.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/Oskar/Code/ipk/uebung06/source/uniform.cc > CMakeFiles/uniform.dir/uniform.cc.i

CMakeFiles/uniform.dir/uniform.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/uniform.dir/uniform.cc.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/Oskar/Code/ipk/uebung06/source/uniform.cc -o CMakeFiles/uniform.dir/uniform.cc.s

# Object files for target uniform
uniform_OBJECTS = \
"CMakeFiles/uniform.dir/uniform.cc.o"

# External object files for target uniform
uniform_EXTERNAL_OBJECTS =

uniform: CMakeFiles/uniform.dir/uniform.cc.o
uniform: CMakeFiles/uniform.dir/build.make
uniform: libio.a
uniform: libstatistics.a
uniform: CMakeFiles/uniform.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/Oskar/Code/ipk/uebung06/build2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable uniform"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/uniform.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/uniform.dir/build: uniform

.PHONY : CMakeFiles/uniform.dir/build

CMakeFiles/uniform.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/uniform.dir/cmake_clean.cmake
.PHONY : CMakeFiles/uniform.dir/clean

CMakeFiles/uniform.dir/depend:
	cd /Users/Oskar/Code/ipk/uebung06/build2 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/Oskar/Code/ipk/uebung06/source /Users/Oskar/Code/ipk/uebung06/source /Users/Oskar/Code/ipk/uebung06/build2 /Users/Oskar/Code/ipk/uebung06/build2 /Users/Oskar/Code/ipk/uebung06/build2/CMakeFiles/uniform.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/uniform.dir/depend
