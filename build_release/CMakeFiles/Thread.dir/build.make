# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_SOURCE_DIR = /home/hdb/HDB_tempt/theProject/C_C++proj/ThreadProj

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/hdb/HDB_tempt/theProject/C_C++proj/ThreadProj/build_release

# Include any dependencies generated for this target.
include CMakeFiles/Thread.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Thread.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Thread.dir/flags.make

CMakeFiles/Thread.dir/src/Thread/makeThread.cpp.o: CMakeFiles/Thread.dir/flags.make
CMakeFiles/Thread.dir/src/Thread/makeThread.cpp.o: ../src/Thread/makeThread.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hdb/HDB_tempt/theProject/C_C++proj/ThreadProj/build_release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Thread.dir/src/Thread/makeThread.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Thread.dir/src/Thread/makeThread.cpp.o -c /home/hdb/HDB_tempt/theProject/C_C++proj/ThreadProj/src/Thread/makeThread.cpp

CMakeFiles/Thread.dir/src/Thread/makeThread.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Thread.dir/src/Thread/makeThread.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hdb/HDB_tempt/theProject/C_C++proj/ThreadProj/src/Thread/makeThread.cpp > CMakeFiles/Thread.dir/src/Thread/makeThread.cpp.i

CMakeFiles/Thread.dir/src/Thread/makeThread.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Thread.dir/src/Thread/makeThread.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hdb/HDB_tempt/theProject/C_C++proj/ThreadProj/src/Thread/makeThread.cpp -o CMakeFiles/Thread.dir/src/Thread/makeThread.cpp.s

CMakeFiles/Thread.dir/src/Thread/makeThread.cpp.o.requires:

.PHONY : CMakeFiles/Thread.dir/src/Thread/makeThread.cpp.o.requires

CMakeFiles/Thread.dir/src/Thread/makeThread.cpp.o.provides: CMakeFiles/Thread.dir/src/Thread/makeThread.cpp.o.requires
	$(MAKE) -f CMakeFiles/Thread.dir/build.make CMakeFiles/Thread.dir/src/Thread/makeThread.cpp.o.provides.build
.PHONY : CMakeFiles/Thread.dir/src/Thread/makeThread.cpp.o.provides

CMakeFiles/Thread.dir/src/Thread/makeThread.cpp.o.provides.build: CMakeFiles/Thread.dir/src/Thread/makeThread.cpp.o


CMakeFiles/Thread.dir/src/Thread/mian.cpp.o: CMakeFiles/Thread.dir/flags.make
CMakeFiles/Thread.dir/src/Thread/mian.cpp.o: ../src/Thread/mian.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hdb/HDB_tempt/theProject/C_C++proj/ThreadProj/build_release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Thread.dir/src/Thread/mian.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Thread.dir/src/Thread/mian.cpp.o -c /home/hdb/HDB_tempt/theProject/C_C++proj/ThreadProj/src/Thread/mian.cpp

CMakeFiles/Thread.dir/src/Thread/mian.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Thread.dir/src/Thread/mian.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hdb/HDB_tempt/theProject/C_C++proj/ThreadProj/src/Thread/mian.cpp > CMakeFiles/Thread.dir/src/Thread/mian.cpp.i

CMakeFiles/Thread.dir/src/Thread/mian.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Thread.dir/src/Thread/mian.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hdb/HDB_tempt/theProject/C_C++proj/ThreadProj/src/Thread/mian.cpp -o CMakeFiles/Thread.dir/src/Thread/mian.cpp.s

CMakeFiles/Thread.dir/src/Thread/mian.cpp.o.requires:

.PHONY : CMakeFiles/Thread.dir/src/Thread/mian.cpp.o.requires

CMakeFiles/Thread.dir/src/Thread/mian.cpp.o.provides: CMakeFiles/Thread.dir/src/Thread/mian.cpp.o.requires
	$(MAKE) -f CMakeFiles/Thread.dir/build.make CMakeFiles/Thread.dir/src/Thread/mian.cpp.o.provides.build
.PHONY : CMakeFiles/Thread.dir/src/Thread/mian.cpp.o.provides

CMakeFiles/Thread.dir/src/Thread/mian.cpp.o.provides.build: CMakeFiles/Thread.dir/src/Thread/mian.cpp.o


CMakeFiles/Thread.dir/src/Thread/mutex_lock.cpp.o: CMakeFiles/Thread.dir/flags.make
CMakeFiles/Thread.dir/src/Thread/mutex_lock.cpp.o: ../src/Thread/mutex_lock.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hdb/HDB_tempt/theProject/C_C++proj/ThreadProj/build_release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Thread.dir/src/Thread/mutex_lock.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Thread.dir/src/Thread/mutex_lock.cpp.o -c /home/hdb/HDB_tempt/theProject/C_C++proj/ThreadProj/src/Thread/mutex_lock.cpp

CMakeFiles/Thread.dir/src/Thread/mutex_lock.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Thread.dir/src/Thread/mutex_lock.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hdb/HDB_tempt/theProject/C_C++proj/ThreadProj/src/Thread/mutex_lock.cpp > CMakeFiles/Thread.dir/src/Thread/mutex_lock.cpp.i

CMakeFiles/Thread.dir/src/Thread/mutex_lock.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Thread.dir/src/Thread/mutex_lock.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hdb/HDB_tempt/theProject/C_C++proj/ThreadProj/src/Thread/mutex_lock.cpp -o CMakeFiles/Thread.dir/src/Thread/mutex_lock.cpp.s

CMakeFiles/Thread.dir/src/Thread/mutex_lock.cpp.o.requires:

.PHONY : CMakeFiles/Thread.dir/src/Thread/mutex_lock.cpp.o.requires

CMakeFiles/Thread.dir/src/Thread/mutex_lock.cpp.o.provides: CMakeFiles/Thread.dir/src/Thread/mutex_lock.cpp.o.requires
	$(MAKE) -f CMakeFiles/Thread.dir/build.make CMakeFiles/Thread.dir/src/Thread/mutex_lock.cpp.o.provides.build
.PHONY : CMakeFiles/Thread.dir/src/Thread/mutex_lock.cpp.o.provides

CMakeFiles/Thread.dir/src/Thread/mutex_lock.cpp.o.provides.build: CMakeFiles/Thread.dir/src/Thread/mutex_lock.cpp.o


# Object files for target Thread
Thread_OBJECTS = \
"CMakeFiles/Thread.dir/src/Thread/makeThread.cpp.o" \
"CMakeFiles/Thread.dir/src/Thread/mian.cpp.o" \
"CMakeFiles/Thread.dir/src/Thread/mutex_lock.cpp.o"

# External object files for target Thread
Thread_EXTERNAL_OBJECTS =

bin/Thread: CMakeFiles/Thread.dir/src/Thread/makeThread.cpp.o
bin/Thread: CMakeFiles/Thread.dir/src/Thread/mian.cpp.o
bin/Thread: CMakeFiles/Thread.dir/src/Thread/mutex_lock.cpp.o
bin/Thread: CMakeFiles/Thread.dir/build.make
bin/Thread: libsample_common.a
bin/Thread: CMakeFiles/Thread.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/hdb/HDB_tempt/theProject/C_C++proj/ThreadProj/build_release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable bin/Thread"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Thread.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Thread.dir/build: bin/Thread

.PHONY : CMakeFiles/Thread.dir/build

CMakeFiles/Thread.dir/requires: CMakeFiles/Thread.dir/src/Thread/makeThread.cpp.o.requires
CMakeFiles/Thread.dir/requires: CMakeFiles/Thread.dir/src/Thread/mian.cpp.o.requires
CMakeFiles/Thread.dir/requires: CMakeFiles/Thread.dir/src/Thread/mutex_lock.cpp.o.requires

.PHONY : CMakeFiles/Thread.dir/requires

CMakeFiles/Thread.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Thread.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Thread.dir/clean

CMakeFiles/Thread.dir/depend:
	cd /home/hdb/HDB_tempt/theProject/C_C++proj/ThreadProj/build_release && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/hdb/HDB_tempt/theProject/C_C++proj/ThreadProj /home/hdb/HDB_tempt/theProject/C_C++proj/ThreadProj /home/hdb/HDB_tempt/theProject/C_C++proj/ThreadProj/build_release /home/hdb/HDB_tempt/theProject/C_C++proj/ThreadProj/build_release /home/hdb/HDB_tempt/theProject/C_C++proj/ThreadProj/build_release/CMakeFiles/Thread.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Thread.dir/depend

