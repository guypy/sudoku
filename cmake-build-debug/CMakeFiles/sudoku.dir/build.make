# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.9

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/Users/yuvalbarzam/Documents/TAU/Software Project/sudoku"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/yuvalbarzam/Documents/TAU/Software Project/sudoku/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/sudoku.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/sudoku.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/sudoku.dir/flags.make

CMakeFiles/sudoku.dir/main.c.o: CMakeFiles/sudoku.dir/flags.make
CMakeFiles/sudoku.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/yuvalbarzam/Documents/TAU/Software Project/sudoku/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/sudoku.dir/main.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/sudoku.dir/main.c.o   -c "/Users/yuvalbarzam/Documents/TAU/Software Project/sudoku/main.c"

CMakeFiles/sudoku.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/sudoku.dir/main.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/Users/yuvalbarzam/Documents/TAU/Software Project/sudoku/main.c" > CMakeFiles/sudoku.dir/main.c.i

CMakeFiles/sudoku.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/sudoku.dir/main.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/Users/yuvalbarzam/Documents/TAU/Software Project/sudoku/main.c" -o CMakeFiles/sudoku.dir/main.c.s

CMakeFiles/sudoku.dir/main.c.o.requires:

.PHONY : CMakeFiles/sudoku.dir/main.c.o.requires

CMakeFiles/sudoku.dir/main.c.o.provides: CMakeFiles/sudoku.dir/main.c.o.requires
	$(MAKE) -f CMakeFiles/sudoku.dir/build.make CMakeFiles/sudoku.dir/main.c.o.provides.build
.PHONY : CMakeFiles/sudoku.dir/main.c.o.provides

CMakeFiles/sudoku.dir/main.c.o.provides.build: CMakeFiles/sudoku.dir/main.c.o


CMakeFiles/sudoku.dir/parser.c.o: CMakeFiles/sudoku.dir/flags.make
CMakeFiles/sudoku.dir/parser.c.o: ../parser.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/yuvalbarzam/Documents/TAU/Software Project/sudoku/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/sudoku.dir/parser.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/sudoku.dir/parser.c.o   -c "/Users/yuvalbarzam/Documents/TAU/Software Project/sudoku/parser.c"

CMakeFiles/sudoku.dir/parser.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/sudoku.dir/parser.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/Users/yuvalbarzam/Documents/TAU/Software Project/sudoku/parser.c" > CMakeFiles/sudoku.dir/parser.c.i

CMakeFiles/sudoku.dir/parser.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/sudoku.dir/parser.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/Users/yuvalbarzam/Documents/TAU/Software Project/sudoku/parser.c" -o CMakeFiles/sudoku.dir/parser.c.s

CMakeFiles/sudoku.dir/parser.c.o.requires:

.PHONY : CMakeFiles/sudoku.dir/parser.c.o.requires

CMakeFiles/sudoku.dir/parser.c.o.provides: CMakeFiles/sudoku.dir/parser.c.o.requires
	$(MAKE) -f CMakeFiles/sudoku.dir/build.make CMakeFiles/sudoku.dir/parser.c.o.provides.build
.PHONY : CMakeFiles/sudoku.dir/parser.c.o.provides

CMakeFiles/sudoku.dir/parser.c.o.provides.build: CMakeFiles/sudoku.dir/parser.c.o


CMakeFiles/sudoku.dir/game.c.o: CMakeFiles/sudoku.dir/flags.make
CMakeFiles/sudoku.dir/game.c.o: ../game.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/yuvalbarzam/Documents/TAU/Software Project/sudoku/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/sudoku.dir/game.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/sudoku.dir/game.c.o   -c "/Users/yuvalbarzam/Documents/TAU/Software Project/sudoku/game.c"

CMakeFiles/sudoku.dir/game.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/sudoku.dir/game.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/Users/yuvalbarzam/Documents/TAU/Software Project/sudoku/game.c" > CMakeFiles/sudoku.dir/game.c.i

CMakeFiles/sudoku.dir/game.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/sudoku.dir/game.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/Users/yuvalbarzam/Documents/TAU/Software Project/sudoku/game.c" -o CMakeFiles/sudoku.dir/game.c.s

CMakeFiles/sudoku.dir/game.c.o.requires:

.PHONY : CMakeFiles/sudoku.dir/game.c.o.requires

CMakeFiles/sudoku.dir/game.c.o.provides: CMakeFiles/sudoku.dir/game.c.o.requires
	$(MAKE) -f CMakeFiles/sudoku.dir/build.make CMakeFiles/sudoku.dir/game.c.o.provides.build
.PHONY : CMakeFiles/sudoku.dir/game.c.o.provides

CMakeFiles/sudoku.dir/game.c.o.provides.build: CMakeFiles/sudoku.dir/game.c.o


CMakeFiles/sudoku.dir/solver.c.o: CMakeFiles/sudoku.dir/flags.make
CMakeFiles/sudoku.dir/solver.c.o: ../solver.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/yuvalbarzam/Documents/TAU/Software Project/sudoku/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/sudoku.dir/solver.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/sudoku.dir/solver.c.o   -c "/Users/yuvalbarzam/Documents/TAU/Software Project/sudoku/solver.c"

CMakeFiles/sudoku.dir/solver.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/sudoku.dir/solver.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/Users/yuvalbarzam/Documents/TAU/Software Project/sudoku/solver.c" > CMakeFiles/sudoku.dir/solver.c.i

CMakeFiles/sudoku.dir/solver.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/sudoku.dir/solver.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/Users/yuvalbarzam/Documents/TAU/Software Project/sudoku/solver.c" -o CMakeFiles/sudoku.dir/solver.c.s

CMakeFiles/sudoku.dir/solver.c.o.requires:

.PHONY : CMakeFiles/sudoku.dir/solver.c.o.requires

CMakeFiles/sudoku.dir/solver.c.o.provides: CMakeFiles/sudoku.dir/solver.c.o.requires
	$(MAKE) -f CMakeFiles/sudoku.dir/build.make CMakeFiles/sudoku.dir/solver.c.o.provides.build
.PHONY : CMakeFiles/sudoku.dir/solver.c.o.provides

CMakeFiles/sudoku.dir/solver.c.o.provides.build: CMakeFiles/sudoku.dir/solver.c.o


CMakeFiles/sudoku.dir/main_aux.c.o: CMakeFiles/sudoku.dir/flags.make
CMakeFiles/sudoku.dir/main_aux.c.o: ../main_aux.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/yuvalbarzam/Documents/TAU/Software Project/sudoku/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/sudoku.dir/main_aux.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/sudoku.dir/main_aux.c.o   -c "/Users/yuvalbarzam/Documents/TAU/Software Project/sudoku/main_aux.c"

CMakeFiles/sudoku.dir/main_aux.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/sudoku.dir/main_aux.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/Users/yuvalbarzam/Documents/TAU/Software Project/sudoku/main_aux.c" > CMakeFiles/sudoku.dir/main_aux.c.i

CMakeFiles/sudoku.dir/main_aux.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/sudoku.dir/main_aux.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/Users/yuvalbarzam/Documents/TAU/Software Project/sudoku/main_aux.c" -o CMakeFiles/sudoku.dir/main_aux.c.s

CMakeFiles/sudoku.dir/main_aux.c.o.requires:

.PHONY : CMakeFiles/sudoku.dir/main_aux.c.o.requires

CMakeFiles/sudoku.dir/main_aux.c.o.provides: CMakeFiles/sudoku.dir/main_aux.c.o.requires
	$(MAKE) -f CMakeFiles/sudoku.dir/build.make CMakeFiles/sudoku.dir/main_aux.c.o.provides.build
.PHONY : CMakeFiles/sudoku.dir/main_aux.c.o.provides

CMakeFiles/sudoku.dir/main_aux.c.o.provides.build: CMakeFiles/sudoku.dir/main_aux.c.o


CMakeFiles/sudoku.dir/sudoku_board.c.o: CMakeFiles/sudoku.dir/flags.make
CMakeFiles/sudoku.dir/sudoku_board.c.o: ../sudoku_board.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/yuvalbarzam/Documents/TAU/Software Project/sudoku/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/sudoku.dir/sudoku_board.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/sudoku.dir/sudoku_board.c.o   -c "/Users/yuvalbarzam/Documents/TAU/Software Project/sudoku/sudoku_board.c"

CMakeFiles/sudoku.dir/sudoku_board.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/sudoku.dir/sudoku_board.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/Users/yuvalbarzam/Documents/TAU/Software Project/sudoku/sudoku_board.c" > CMakeFiles/sudoku.dir/sudoku_board.c.i

CMakeFiles/sudoku.dir/sudoku_board.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/sudoku.dir/sudoku_board.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/Users/yuvalbarzam/Documents/TAU/Software Project/sudoku/sudoku_board.c" -o CMakeFiles/sudoku.dir/sudoku_board.c.s

CMakeFiles/sudoku.dir/sudoku_board.c.o.requires:

.PHONY : CMakeFiles/sudoku.dir/sudoku_board.c.o.requires

CMakeFiles/sudoku.dir/sudoku_board.c.o.provides: CMakeFiles/sudoku.dir/sudoku_board.c.o.requires
	$(MAKE) -f CMakeFiles/sudoku.dir/build.make CMakeFiles/sudoku.dir/sudoku_board.c.o.provides.build
.PHONY : CMakeFiles/sudoku.dir/sudoku_board.c.o.provides

CMakeFiles/sudoku.dir/sudoku_board.c.o.provides.build: CMakeFiles/sudoku.dir/sudoku_board.c.o


# Object files for target sudoku
sudoku_OBJECTS = \
"CMakeFiles/sudoku.dir/main.c.o" \
"CMakeFiles/sudoku.dir/parser.c.o" \
"CMakeFiles/sudoku.dir/game.c.o" \
"CMakeFiles/sudoku.dir/solver.c.o" \
"CMakeFiles/sudoku.dir/main_aux.c.o" \
"CMakeFiles/sudoku.dir/sudoku_board.c.o"

# External object files for target sudoku
sudoku_EXTERNAL_OBJECTS =

sudoku: CMakeFiles/sudoku.dir/main.c.o
sudoku: CMakeFiles/sudoku.dir/parser.c.o
sudoku: CMakeFiles/sudoku.dir/game.c.o
sudoku: CMakeFiles/sudoku.dir/solver.c.o
sudoku: CMakeFiles/sudoku.dir/main_aux.c.o
sudoku: CMakeFiles/sudoku.dir/sudoku_board.c.o
sudoku: CMakeFiles/sudoku.dir/build.make
sudoku: CMakeFiles/sudoku.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/yuvalbarzam/Documents/TAU/Software Project/sudoku/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_7) "Linking C executable sudoku"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/sudoku.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/sudoku.dir/build: sudoku

.PHONY : CMakeFiles/sudoku.dir/build

CMakeFiles/sudoku.dir/requires: CMakeFiles/sudoku.dir/main.c.o.requires
CMakeFiles/sudoku.dir/requires: CMakeFiles/sudoku.dir/parser.c.o.requires
CMakeFiles/sudoku.dir/requires: CMakeFiles/sudoku.dir/game.c.o.requires
CMakeFiles/sudoku.dir/requires: CMakeFiles/sudoku.dir/solver.c.o.requires
CMakeFiles/sudoku.dir/requires: CMakeFiles/sudoku.dir/main_aux.c.o.requires
CMakeFiles/sudoku.dir/requires: CMakeFiles/sudoku.dir/sudoku_board.c.o.requires

.PHONY : CMakeFiles/sudoku.dir/requires

CMakeFiles/sudoku.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/sudoku.dir/cmake_clean.cmake
.PHONY : CMakeFiles/sudoku.dir/clean

CMakeFiles/sudoku.dir/depend:
	cd "/Users/yuvalbarzam/Documents/TAU/Software Project/sudoku/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/yuvalbarzam/Documents/TAU/Software Project/sudoku" "/Users/yuvalbarzam/Documents/TAU/Software Project/sudoku" "/Users/yuvalbarzam/Documents/TAU/Software Project/sudoku/cmake-build-debug" "/Users/yuvalbarzam/Documents/TAU/Software Project/sudoku/cmake-build-debug" "/Users/yuvalbarzam/Documents/TAU/Software Project/sudoku/cmake-build-debug/CMakeFiles/sudoku.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/sudoku.dir/depend

