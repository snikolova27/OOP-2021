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
CMAKE_SOURCE_DIR = /home/sonya/Uni/OOP/OOP/Seminars/Classes/Task01

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/sonya/Uni/OOP/OOP/Seminars/Classes/Task01/build

# Include any dependencies generated for this target.
include CMakeFiles/task01.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/task01.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/task01.dir/flags.make

CMakeFiles/task01.dir/main.cpp.o: CMakeFiles/task01.dir/flags.make
CMakeFiles/task01.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sonya/Uni/OOP/OOP/Seminars/Classes/Task01/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/task01.dir/main.cpp.o"
	/bin/clang++-10  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/task01.dir/main.cpp.o -c /home/sonya/Uni/OOP/OOP/Seminars/Classes/Task01/main.cpp

CMakeFiles/task01.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/task01.dir/main.cpp.i"
	/bin/clang++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sonya/Uni/OOP/OOP/Seminars/Classes/Task01/main.cpp > CMakeFiles/task01.dir/main.cpp.i

CMakeFiles/task01.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/task01.dir/main.cpp.s"
	/bin/clang++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sonya/Uni/OOP/OOP/Seminars/Classes/Task01/main.cpp -o CMakeFiles/task01.dir/main.cpp.s

CMakeFiles/task01.dir/Person.cpp.o: CMakeFiles/task01.dir/flags.make
CMakeFiles/task01.dir/Person.cpp.o: ../Person.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sonya/Uni/OOP/OOP/Seminars/Classes/Task01/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/task01.dir/Person.cpp.o"
	/bin/clang++-10  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/task01.dir/Person.cpp.o -c /home/sonya/Uni/OOP/OOP/Seminars/Classes/Task01/Person.cpp

CMakeFiles/task01.dir/Person.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/task01.dir/Person.cpp.i"
	/bin/clang++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sonya/Uni/OOP/OOP/Seminars/Classes/Task01/Person.cpp > CMakeFiles/task01.dir/Person.cpp.i

CMakeFiles/task01.dir/Person.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/task01.dir/Person.cpp.s"
	/bin/clang++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sonya/Uni/OOP/OOP/Seminars/Classes/Task01/Person.cpp -o CMakeFiles/task01.dir/Person.cpp.s

CMakeFiles/task01.dir/Utils.cpp.o: CMakeFiles/task01.dir/flags.make
CMakeFiles/task01.dir/Utils.cpp.o: ../Utils.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sonya/Uni/OOP/OOP/Seminars/Classes/Task01/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/task01.dir/Utils.cpp.o"
	/bin/clang++-10  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/task01.dir/Utils.cpp.o -c /home/sonya/Uni/OOP/OOP/Seminars/Classes/Task01/Utils.cpp

CMakeFiles/task01.dir/Utils.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/task01.dir/Utils.cpp.i"
	/bin/clang++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sonya/Uni/OOP/OOP/Seminars/Classes/Task01/Utils.cpp > CMakeFiles/task01.dir/Utils.cpp.i

CMakeFiles/task01.dir/Utils.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/task01.dir/Utils.cpp.s"
	/bin/clang++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sonya/Uni/OOP/OOP/Seminars/Classes/Task01/Utils.cpp -o CMakeFiles/task01.dir/Utils.cpp.s

# Object files for target task01
task01_OBJECTS = \
"CMakeFiles/task01.dir/main.cpp.o" \
"CMakeFiles/task01.dir/Person.cpp.o" \
"CMakeFiles/task01.dir/Utils.cpp.o"

# External object files for target task01
task01_EXTERNAL_OBJECTS =

task01: CMakeFiles/task01.dir/main.cpp.o
task01: CMakeFiles/task01.dir/Person.cpp.o
task01: CMakeFiles/task01.dir/Utils.cpp.o
task01: CMakeFiles/task01.dir/build.make
task01: CMakeFiles/task01.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/sonya/Uni/OOP/OOP/Seminars/Classes/Task01/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable task01"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/task01.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/task01.dir/build: task01

.PHONY : CMakeFiles/task01.dir/build

CMakeFiles/task01.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/task01.dir/cmake_clean.cmake
.PHONY : CMakeFiles/task01.dir/clean

CMakeFiles/task01.dir/depend:
	cd /home/sonya/Uni/OOP/OOP/Seminars/Classes/Task01/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/sonya/Uni/OOP/OOP/Seminars/Classes/Task01 /home/sonya/Uni/OOP/OOP/Seminars/Classes/Task01 /home/sonya/Uni/OOP/OOP/Seminars/Classes/Task01/build /home/sonya/Uni/OOP/OOP/Seminars/Classes/Task01/build /home/sonya/Uni/OOP/OOP/Seminars/Classes/Task01/build/CMakeFiles/task01.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/task01.dir/depend

