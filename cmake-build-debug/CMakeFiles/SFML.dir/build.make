# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.20

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.2.4\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.2.4\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\ozgur\Documents\C++Projects\2DSpaceShouter

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\ozgur\Documents\C++Projects\2DSpaceShouter\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/SFML.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/SFML.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/SFML.dir/flags.make

CMakeFiles/SFML.dir/main.cpp.obj: CMakeFiles/SFML.dir/flags.make
CMakeFiles/SFML.dir/main.cpp.obj: CMakeFiles/SFML.dir/includes_CXX.rsp
CMakeFiles/SFML.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\ozgur\Documents\C++Projects\2DSpaceShouter\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/SFML.dir/main.cpp.obj"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\SFML.dir\main.cpp.obj -c C:\Users\ozgur\Documents\C++Projects\2DSpaceShouter\main.cpp

CMakeFiles/SFML.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SFML.dir/main.cpp.i"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\ozgur\Documents\C++Projects\2DSpaceShouter\main.cpp > CMakeFiles\SFML.dir\main.cpp.i

CMakeFiles/SFML.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SFML.dir/main.cpp.s"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\ozgur\Documents\C++Projects\2DSpaceShouter\main.cpp -o CMakeFiles\SFML.dir\main.cpp.s

CMakeFiles/SFML.dir/Game.cpp.obj: CMakeFiles/SFML.dir/flags.make
CMakeFiles/SFML.dir/Game.cpp.obj: CMakeFiles/SFML.dir/includes_CXX.rsp
CMakeFiles/SFML.dir/Game.cpp.obj: ../Game.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\ozgur\Documents\C++Projects\2DSpaceShouter\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/SFML.dir/Game.cpp.obj"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\SFML.dir\Game.cpp.obj -c C:\Users\ozgur\Documents\C++Projects\2DSpaceShouter\Game.cpp

CMakeFiles/SFML.dir/Game.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SFML.dir/Game.cpp.i"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\ozgur\Documents\C++Projects\2DSpaceShouter\Game.cpp > CMakeFiles\SFML.dir\Game.cpp.i

CMakeFiles/SFML.dir/Game.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SFML.dir/Game.cpp.s"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\ozgur\Documents\C++Projects\2DSpaceShouter\Game.cpp -o CMakeFiles\SFML.dir\Game.cpp.s

CMakeFiles/SFML.dir/Practice.cpp.obj: CMakeFiles/SFML.dir/flags.make
CMakeFiles/SFML.dir/Practice.cpp.obj: CMakeFiles/SFML.dir/includes_CXX.rsp
CMakeFiles/SFML.dir/Practice.cpp.obj: ../Practice.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\ozgur\Documents\C++Projects\2DSpaceShouter\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/SFML.dir/Practice.cpp.obj"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\SFML.dir\Practice.cpp.obj -c C:\Users\ozgur\Documents\C++Projects\2DSpaceShouter\Practice.cpp

CMakeFiles/SFML.dir/Practice.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SFML.dir/Practice.cpp.i"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\ozgur\Documents\C++Projects\2DSpaceShouter\Practice.cpp > CMakeFiles\SFML.dir\Practice.cpp.i

CMakeFiles/SFML.dir/Practice.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SFML.dir/Practice.cpp.s"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\ozgur\Documents\C++Projects\2DSpaceShouter\Practice.cpp -o CMakeFiles\SFML.dir\Practice.cpp.s

CMakeFiles/SFML.dir/Bullet.cpp.obj: CMakeFiles/SFML.dir/flags.make
CMakeFiles/SFML.dir/Bullet.cpp.obj: CMakeFiles/SFML.dir/includes_CXX.rsp
CMakeFiles/SFML.dir/Bullet.cpp.obj: ../Bullet.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\ozgur\Documents\C++Projects\2DSpaceShouter\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/SFML.dir/Bullet.cpp.obj"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\SFML.dir\Bullet.cpp.obj -c C:\Users\ozgur\Documents\C++Projects\2DSpaceShouter\Bullet.cpp

CMakeFiles/SFML.dir/Bullet.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SFML.dir/Bullet.cpp.i"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\ozgur\Documents\C++Projects\2DSpaceShouter\Bullet.cpp > CMakeFiles\SFML.dir\Bullet.cpp.i

CMakeFiles/SFML.dir/Bullet.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SFML.dir/Bullet.cpp.s"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\ozgur\Documents\C++Projects\2DSpaceShouter\Bullet.cpp -o CMakeFiles\SFML.dir\Bullet.cpp.s

CMakeFiles/SFML.dir/Player.cpp.obj: CMakeFiles/SFML.dir/flags.make
CMakeFiles/SFML.dir/Player.cpp.obj: CMakeFiles/SFML.dir/includes_CXX.rsp
CMakeFiles/SFML.dir/Player.cpp.obj: ../Player.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\ozgur\Documents\C++Projects\2DSpaceShouter\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/SFML.dir/Player.cpp.obj"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\SFML.dir\Player.cpp.obj -c C:\Users\ozgur\Documents\C++Projects\2DSpaceShouter\Player.cpp

CMakeFiles/SFML.dir/Player.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SFML.dir/Player.cpp.i"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\ozgur\Documents\C++Projects\2DSpaceShouter\Player.cpp > CMakeFiles\SFML.dir\Player.cpp.i

CMakeFiles/SFML.dir/Player.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SFML.dir/Player.cpp.s"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\ozgur\Documents\C++Projects\2DSpaceShouter\Player.cpp -o CMakeFiles\SFML.dir\Player.cpp.s

CMakeFiles/SFML.dir/Enemy.cpp.obj: CMakeFiles/SFML.dir/flags.make
CMakeFiles/SFML.dir/Enemy.cpp.obj: CMakeFiles/SFML.dir/includes_CXX.rsp
CMakeFiles/SFML.dir/Enemy.cpp.obj: ../Enemy.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\ozgur\Documents\C++Projects\2DSpaceShouter\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/SFML.dir/Enemy.cpp.obj"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\SFML.dir\Enemy.cpp.obj -c C:\Users\ozgur\Documents\C++Projects\2DSpaceShouter\Enemy.cpp

CMakeFiles/SFML.dir/Enemy.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SFML.dir/Enemy.cpp.i"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\ozgur\Documents\C++Projects\2DSpaceShouter\Enemy.cpp > CMakeFiles\SFML.dir\Enemy.cpp.i

CMakeFiles/SFML.dir/Enemy.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SFML.dir/Enemy.cpp.s"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\ozgur\Documents\C++Projects\2DSpaceShouter\Enemy.cpp -o CMakeFiles\SFML.dir\Enemy.cpp.s

# Object files for target SFML
SFML_OBJECTS = \
"CMakeFiles/SFML.dir/main.cpp.obj" \
"CMakeFiles/SFML.dir/Game.cpp.obj" \
"CMakeFiles/SFML.dir/Practice.cpp.obj" \
"CMakeFiles/SFML.dir/Bullet.cpp.obj" \
"CMakeFiles/SFML.dir/Player.cpp.obj" \
"CMakeFiles/SFML.dir/Enemy.cpp.obj"

# External object files for target SFML
SFML_EXTERNAL_OBJECTS =

SFML.exe: CMakeFiles/SFML.dir/main.cpp.obj
SFML.exe: CMakeFiles/SFML.dir/Game.cpp.obj
SFML.exe: CMakeFiles/SFML.dir/Practice.cpp.obj
SFML.exe: CMakeFiles/SFML.dir/Bullet.cpp.obj
SFML.exe: CMakeFiles/SFML.dir/Player.cpp.obj
SFML.exe: CMakeFiles/SFML.dir/Enemy.cpp.obj
SFML.exe: CMakeFiles/SFML.dir/build.make
SFML.exe: C:/SFML/lib/libsfml-system-s-d.a
SFML.exe: C:/SFML/lib/libsfml-window-s-d.a
SFML.exe: C:/SFML/lib/libsfml-graphics-s-d.a
SFML.exe: C:/SFML/lib/libsfml-audio-s-d.a
SFML.exe: C:/SFML/lib/libsfml-window-s-d.a
SFML.exe: C:/SFML/lib/libfreetype.a
SFML.exe: C:/SFML/lib/libsfml-system-s-d.a
SFML.exe: C:/SFML/lib/libopenal32.a
SFML.exe: C:/SFML/lib/libvorbisfile.a
SFML.exe: C:/SFML/lib/libvorbisenc.a
SFML.exe: C:/SFML/lib/libvorbis.a
SFML.exe: C:/SFML/lib/libogg.a
SFML.exe: C:/SFML/lib/libFLAC.a
SFML.exe: CMakeFiles/SFML.dir/linklibs.rsp
SFML.exe: CMakeFiles/SFML.dir/objects1.rsp
SFML.exe: CMakeFiles/SFML.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\ozgur\Documents\C++Projects\2DSpaceShouter\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable SFML.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\SFML.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/SFML.dir/build: SFML.exe
.PHONY : CMakeFiles/SFML.dir/build

CMakeFiles/SFML.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\SFML.dir\cmake_clean.cmake
.PHONY : CMakeFiles/SFML.dir/clean

CMakeFiles/SFML.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\ozgur\Documents\C++Projects\2DSpaceShouter C:\Users\ozgur\Documents\C++Projects\2DSpaceShouter C:\Users\ozgur\Documents\C++Projects\2DSpaceShouter\cmake-build-debug C:\Users\ozgur\Documents\C++Projects\2DSpaceShouter\cmake-build-debug C:\Users\ozgur\Documents\C++Projects\2DSpaceShouter\cmake-build-debug\CMakeFiles\SFML.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/SFML.dir/depend

