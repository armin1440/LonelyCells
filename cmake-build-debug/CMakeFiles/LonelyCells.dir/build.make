# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.15

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2019.2.5\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2019.2.5\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\novin\Documents\Github\LonelyCells

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\novin\Documents\Github\LonelyCells\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/LonelyCells.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/LonelyCells.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/LonelyCells.dir/flags.make

CMakeFiles/LonelyCells.dir/LonelyCells.c.obj: CMakeFiles/LonelyCells.dir/flags.make
CMakeFiles/LonelyCells.dir/LonelyCells.c.obj: ../LonelyCells.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\novin\Documents\Github\LonelyCells\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/LonelyCells.dir/LonelyCells.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\LonelyCells.dir\LonelyCells.c.obj   -c C:\Users\novin\Documents\Github\LonelyCells\LonelyCells.c

CMakeFiles/LonelyCells.dir/LonelyCells.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/LonelyCells.dir/LonelyCells.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\novin\Documents\Github\LonelyCells\LonelyCells.c > CMakeFiles\LonelyCells.dir\LonelyCells.c.i

CMakeFiles/LonelyCells.dir/LonelyCells.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/LonelyCells.dir/LonelyCells.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\novin\Documents\Github\LonelyCells\LonelyCells.c -o CMakeFiles\LonelyCells.dir\LonelyCells.c.s

CMakeFiles/LonelyCells.dir/map_read.c.obj: CMakeFiles/LonelyCells.dir/flags.make
CMakeFiles/LonelyCells.dir/map_read.c.obj: ../map_read.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\novin\Documents\Github\LonelyCells\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/LonelyCells.dir/map_read.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\LonelyCells.dir\map_read.c.obj   -c C:\Users\novin\Documents\Github\LonelyCells\map_read.c

CMakeFiles/LonelyCells.dir/map_read.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/LonelyCells.dir/map_read.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\novin\Documents\Github\LonelyCells\map_read.c > CMakeFiles\LonelyCells.dir\map_read.c.i

CMakeFiles/LonelyCells.dir/map_read.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/LonelyCells.dir/map_read.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\novin\Documents\Github\LonelyCells\map_read.c -o CMakeFiles\LonelyCells.dir\map_read.c.s

CMakeFiles/LonelyCells.dir/map_save.c.obj: CMakeFiles/LonelyCells.dir/flags.make
CMakeFiles/LonelyCells.dir/map_save.c.obj: ../map_save.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\novin\Documents\Github\LonelyCells\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/LonelyCells.dir/map_save.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\LonelyCells.dir\map_save.c.obj   -c C:\Users\novin\Documents\Github\LonelyCells\map_save.c

CMakeFiles/LonelyCells.dir/map_save.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/LonelyCells.dir/map_save.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\novin\Documents\Github\LonelyCells\map_save.c > CMakeFiles\LonelyCells.dir\map_save.c.i

CMakeFiles/LonelyCells.dir/map_save.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/LonelyCells.dir/map_save.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\novin\Documents\Github\LonelyCells\map_save.c -o CMakeFiles\LonelyCells.dir\map_save.c.s

CMakeFiles/LonelyCells.dir/map_build.c.obj: CMakeFiles/LonelyCells.dir/flags.make
CMakeFiles/LonelyCells.dir/map_build.c.obj: ../map_build.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\novin\Documents\Github\LonelyCells\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/LonelyCells.dir/map_build.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\LonelyCells.dir\map_build.c.obj   -c C:\Users\novin\Documents\Github\LonelyCells\map_build.c

CMakeFiles/LonelyCells.dir/map_build.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/LonelyCells.dir/map_build.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\novin\Documents\Github\LonelyCells\map_build.c > CMakeFiles\LonelyCells.dir\map_build.c.i

CMakeFiles/LonelyCells.dir/map_build.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/LonelyCells.dir/map_build.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\novin\Documents\Github\LonelyCells\map_build.c -o CMakeFiles\LonelyCells.dir\map_build.c.s

CMakeFiles/LonelyCells.dir/map_print.c.obj: CMakeFiles/LonelyCells.dir/flags.make
CMakeFiles/LonelyCells.dir/map_print.c.obj: ../map_print.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\novin\Documents\Github\LonelyCells\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/LonelyCells.dir/map_print.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\LonelyCells.dir\map_print.c.obj   -c C:\Users\novin\Documents\Github\LonelyCells\map_print.c

CMakeFiles/LonelyCells.dir/map_print.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/LonelyCells.dir/map_print.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\novin\Documents\Github\LonelyCells\map_print.c > CMakeFiles\LonelyCells.dir\map_print.c.i

CMakeFiles/LonelyCells.dir/map_print.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/LonelyCells.dir/map_print.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\novin\Documents\Github\LonelyCells\map_print.c -o CMakeFiles\LonelyCells.dir\map_print.c.s

CMakeFiles/LonelyCells.dir/cell_data_read.c.obj: CMakeFiles/LonelyCells.dir/flags.make
CMakeFiles/LonelyCells.dir/cell_data_read.c.obj: ../cell_data_read.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\novin\Documents\Github\LonelyCells\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/LonelyCells.dir/cell_data_read.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\LonelyCells.dir\cell_data_read.c.obj   -c C:\Users\novin\Documents\Github\LonelyCells\cell_data_read.c

CMakeFiles/LonelyCells.dir/cell_data_read.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/LonelyCells.dir/cell_data_read.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\novin\Documents\Github\LonelyCells\cell_data_read.c > CMakeFiles\LonelyCells.dir\cell_data_read.c.i

CMakeFiles/LonelyCells.dir/cell_data_read.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/LonelyCells.dir/cell_data_read.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\novin\Documents\Github\LonelyCells\cell_data_read.c -o CMakeFiles\LonelyCells.dir\cell_data_read.c.s

# Object files for target LonelyCells
LonelyCells_OBJECTS = \
"CMakeFiles/LonelyCells.dir/LonelyCells.c.obj" \
"CMakeFiles/LonelyCells.dir/map_read.c.obj" \
"CMakeFiles/LonelyCells.dir/map_save.c.obj" \
"CMakeFiles/LonelyCells.dir/map_build.c.obj" \
"CMakeFiles/LonelyCells.dir/map_print.c.obj" \
"CMakeFiles/LonelyCells.dir/cell_data_read.c.obj"

# External object files for target LonelyCells
LonelyCells_EXTERNAL_OBJECTS =

LonelyCells.exe: CMakeFiles/LonelyCells.dir/LonelyCells.c.obj
LonelyCells.exe: CMakeFiles/LonelyCells.dir/map_read.c.obj
LonelyCells.exe: CMakeFiles/LonelyCells.dir/map_save.c.obj
LonelyCells.exe: CMakeFiles/LonelyCells.dir/map_build.c.obj
LonelyCells.exe: CMakeFiles/LonelyCells.dir/map_print.c.obj
LonelyCells.exe: CMakeFiles/LonelyCells.dir/cell_data_read.c.obj
LonelyCells.exe: CMakeFiles/LonelyCells.dir/build.make
LonelyCells.exe: CMakeFiles/LonelyCells.dir/linklibs.rsp
LonelyCells.exe: CMakeFiles/LonelyCells.dir/objects1.rsp
LonelyCells.exe: CMakeFiles/LonelyCells.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\novin\Documents\Github\LonelyCells\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking C executable LonelyCells.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\LonelyCells.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/LonelyCells.dir/build: LonelyCells.exe

.PHONY : CMakeFiles/LonelyCells.dir/build

CMakeFiles/LonelyCells.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\LonelyCells.dir\cmake_clean.cmake
.PHONY : CMakeFiles/LonelyCells.dir/clean

CMakeFiles/LonelyCells.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\novin\Documents\Github\LonelyCells C:\Users\novin\Documents\Github\LonelyCells C:\Users\novin\Documents\Github\LonelyCells\cmake-build-debug C:\Users\novin\Documents\Github\LonelyCells\cmake-build-debug C:\Users\novin\Documents\Github\LonelyCells\cmake-build-debug\CMakeFiles\LonelyCells.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/LonelyCells.dir/depend

