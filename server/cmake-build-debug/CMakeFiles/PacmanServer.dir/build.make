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
CMAKE_COMMAND = /snap/clion/22/bin/cmake/bin/cmake

# The command to remove a file.
RM = /snap/clion/22/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/views/github/PacmanAndroid/server

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/views/github/PacmanAndroid/server/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/PacmanServer.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/PacmanServer.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/PacmanServer.dir/flags.make

CMakeFiles/PacmanServer.dir/home/views/github/PacmanAndroid/common/Messages/Messages.cpp.o: CMakeFiles/PacmanServer.dir/flags.make
CMakeFiles/PacmanServer.dir/home/views/github/PacmanAndroid/common/Messages/Messages.cpp.o: /home/views/github/PacmanAndroid/common/Messages/Messages.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/views/github/PacmanAndroid/server/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/PacmanServer.dir/home/views/github/PacmanAndroid/common/Messages/Messages.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/PacmanServer.dir/home/views/github/PacmanAndroid/common/Messages/Messages.cpp.o -c /home/views/github/PacmanAndroid/common/Messages/Messages.cpp

CMakeFiles/PacmanServer.dir/home/views/github/PacmanAndroid/common/Messages/Messages.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PacmanServer.dir/home/views/github/PacmanAndroid/common/Messages/Messages.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/views/github/PacmanAndroid/common/Messages/Messages.cpp > CMakeFiles/PacmanServer.dir/home/views/github/PacmanAndroid/common/Messages/Messages.cpp.i

CMakeFiles/PacmanServer.dir/home/views/github/PacmanAndroid/common/Messages/Messages.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PacmanServer.dir/home/views/github/PacmanAndroid/common/Messages/Messages.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/views/github/PacmanAndroid/common/Messages/Messages.cpp -o CMakeFiles/PacmanServer.dir/home/views/github/PacmanAndroid/common/Messages/Messages.cpp.s

CMakeFiles/PacmanServer.dir/home/views/github/PacmanAndroid/common/Messages/Messages.cpp.o.requires:

.PHONY : CMakeFiles/PacmanServer.dir/home/views/github/PacmanAndroid/common/Messages/Messages.cpp.o.requires

CMakeFiles/PacmanServer.dir/home/views/github/PacmanAndroid/common/Messages/Messages.cpp.o.provides: CMakeFiles/PacmanServer.dir/home/views/github/PacmanAndroid/common/Messages/Messages.cpp.o.requires
	$(MAKE) -f CMakeFiles/PacmanServer.dir/build.make CMakeFiles/PacmanServer.dir/home/views/github/PacmanAndroid/common/Messages/Messages.cpp.o.provides.build
.PHONY : CMakeFiles/PacmanServer.dir/home/views/github/PacmanAndroid/common/Messages/Messages.cpp.o.provides

CMakeFiles/PacmanServer.dir/home/views/github/PacmanAndroid/common/Messages/Messages.cpp.o.provides.build: CMakeFiles/PacmanServer.dir/home/views/github/PacmanAndroid/common/Messages/Messages.cpp.o


CMakeFiles/PacmanServer.dir/home/views/github/PacmanAndroid/common/Messages/Types/Stream.cpp.o: CMakeFiles/PacmanServer.dir/flags.make
CMakeFiles/PacmanServer.dir/home/views/github/PacmanAndroid/common/Messages/Types/Stream.cpp.o: /home/views/github/PacmanAndroid/common/Messages/Types/Stream.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/views/github/PacmanAndroid/server/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/PacmanServer.dir/home/views/github/PacmanAndroid/common/Messages/Types/Stream.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/PacmanServer.dir/home/views/github/PacmanAndroid/common/Messages/Types/Stream.cpp.o -c /home/views/github/PacmanAndroid/common/Messages/Types/Stream.cpp

CMakeFiles/PacmanServer.dir/home/views/github/PacmanAndroid/common/Messages/Types/Stream.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PacmanServer.dir/home/views/github/PacmanAndroid/common/Messages/Types/Stream.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/views/github/PacmanAndroid/common/Messages/Types/Stream.cpp > CMakeFiles/PacmanServer.dir/home/views/github/PacmanAndroid/common/Messages/Types/Stream.cpp.i

CMakeFiles/PacmanServer.dir/home/views/github/PacmanAndroid/common/Messages/Types/Stream.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PacmanServer.dir/home/views/github/PacmanAndroid/common/Messages/Types/Stream.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/views/github/PacmanAndroid/common/Messages/Types/Stream.cpp -o CMakeFiles/PacmanServer.dir/home/views/github/PacmanAndroid/common/Messages/Types/Stream.cpp.s

CMakeFiles/PacmanServer.dir/home/views/github/PacmanAndroid/common/Messages/Types/Stream.cpp.o.requires:

.PHONY : CMakeFiles/PacmanServer.dir/home/views/github/PacmanAndroid/common/Messages/Types/Stream.cpp.o.requires

CMakeFiles/PacmanServer.dir/home/views/github/PacmanAndroid/common/Messages/Types/Stream.cpp.o.provides: CMakeFiles/PacmanServer.dir/home/views/github/PacmanAndroid/common/Messages/Types/Stream.cpp.o.requires
	$(MAKE) -f CMakeFiles/PacmanServer.dir/build.make CMakeFiles/PacmanServer.dir/home/views/github/PacmanAndroid/common/Messages/Types/Stream.cpp.o.provides.build
.PHONY : CMakeFiles/PacmanServer.dir/home/views/github/PacmanAndroid/common/Messages/Types/Stream.cpp.o.provides

CMakeFiles/PacmanServer.dir/home/views/github/PacmanAndroid/common/Messages/Types/Stream.cpp.o.provides.build: CMakeFiles/PacmanServer.dir/home/views/github/PacmanAndroid/common/Messages/Types/Stream.cpp.o


CMakeFiles/PacmanServer.dir/home/views/github/PacmanAndroid/common/Messages/Types/Repeated.cpp.o: CMakeFiles/PacmanServer.dir/flags.make
CMakeFiles/PacmanServer.dir/home/views/github/PacmanAndroid/common/Messages/Types/Repeated.cpp.o: /home/views/github/PacmanAndroid/common/Messages/Types/Repeated.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/views/github/PacmanAndroid/server/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/PacmanServer.dir/home/views/github/PacmanAndroid/common/Messages/Types/Repeated.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/PacmanServer.dir/home/views/github/PacmanAndroid/common/Messages/Types/Repeated.cpp.o -c /home/views/github/PacmanAndroid/common/Messages/Types/Repeated.cpp

CMakeFiles/PacmanServer.dir/home/views/github/PacmanAndroid/common/Messages/Types/Repeated.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PacmanServer.dir/home/views/github/PacmanAndroid/common/Messages/Types/Repeated.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/views/github/PacmanAndroid/common/Messages/Types/Repeated.cpp > CMakeFiles/PacmanServer.dir/home/views/github/PacmanAndroid/common/Messages/Types/Repeated.cpp.i

CMakeFiles/PacmanServer.dir/home/views/github/PacmanAndroid/common/Messages/Types/Repeated.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PacmanServer.dir/home/views/github/PacmanAndroid/common/Messages/Types/Repeated.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/views/github/PacmanAndroid/common/Messages/Types/Repeated.cpp -o CMakeFiles/PacmanServer.dir/home/views/github/PacmanAndroid/common/Messages/Types/Repeated.cpp.s

CMakeFiles/PacmanServer.dir/home/views/github/PacmanAndroid/common/Messages/Types/Repeated.cpp.o.requires:

.PHONY : CMakeFiles/PacmanServer.dir/home/views/github/PacmanAndroid/common/Messages/Types/Repeated.cpp.o.requires

CMakeFiles/PacmanServer.dir/home/views/github/PacmanAndroid/common/Messages/Types/Repeated.cpp.o.provides: CMakeFiles/PacmanServer.dir/home/views/github/PacmanAndroid/common/Messages/Types/Repeated.cpp.o.requires
	$(MAKE) -f CMakeFiles/PacmanServer.dir/build.make CMakeFiles/PacmanServer.dir/home/views/github/PacmanAndroid/common/Messages/Types/Repeated.cpp.o.provides.build
.PHONY : CMakeFiles/PacmanServer.dir/home/views/github/PacmanAndroid/common/Messages/Types/Repeated.cpp.o.provides

CMakeFiles/PacmanServer.dir/home/views/github/PacmanAndroid/common/Messages/Types/Repeated.cpp.o.provides.build: CMakeFiles/PacmanServer.dir/home/views/github/PacmanAndroid/common/Messages/Types/Repeated.cpp.o


CMakeFiles/PacmanServer.dir/main.cpp.o: CMakeFiles/PacmanServer.dir/flags.make
CMakeFiles/PacmanServer.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/views/github/PacmanAndroid/server/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/PacmanServer.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/PacmanServer.dir/main.cpp.o -c /home/views/github/PacmanAndroid/server/main.cpp

CMakeFiles/PacmanServer.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PacmanServer.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/views/github/PacmanAndroid/server/main.cpp > CMakeFiles/PacmanServer.dir/main.cpp.i

CMakeFiles/PacmanServer.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PacmanServer.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/views/github/PacmanAndroid/server/main.cpp -o CMakeFiles/PacmanServer.dir/main.cpp.s

CMakeFiles/PacmanServer.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/PacmanServer.dir/main.cpp.o.requires

CMakeFiles/PacmanServer.dir/main.cpp.o.provides: CMakeFiles/PacmanServer.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/PacmanServer.dir/build.make CMakeFiles/PacmanServer.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/PacmanServer.dir/main.cpp.o.provides

CMakeFiles/PacmanServer.dir/main.cpp.o.provides.build: CMakeFiles/PacmanServer.dir/main.cpp.o


CMakeFiles/PacmanServer.dir/Network.cpp.o: CMakeFiles/PacmanServer.dir/flags.make
CMakeFiles/PacmanServer.dir/Network.cpp.o: ../Network.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/views/github/PacmanAndroid/server/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/PacmanServer.dir/Network.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/PacmanServer.dir/Network.cpp.o -c /home/views/github/PacmanAndroid/server/Network.cpp

CMakeFiles/PacmanServer.dir/Network.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PacmanServer.dir/Network.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/views/github/PacmanAndroid/server/Network.cpp > CMakeFiles/PacmanServer.dir/Network.cpp.i

CMakeFiles/PacmanServer.dir/Network.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PacmanServer.dir/Network.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/views/github/PacmanAndroid/server/Network.cpp -o CMakeFiles/PacmanServer.dir/Network.cpp.s

CMakeFiles/PacmanServer.dir/Network.cpp.o.requires:

.PHONY : CMakeFiles/PacmanServer.dir/Network.cpp.o.requires

CMakeFiles/PacmanServer.dir/Network.cpp.o.provides: CMakeFiles/PacmanServer.dir/Network.cpp.o.requires
	$(MAKE) -f CMakeFiles/PacmanServer.dir/build.make CMakeFiles/PacmanServer.dir/Network.cpp.o.provides.build
.PHONY : CMakeFiles/PacmanServer.dir/Network.cpp.o.provides

CMakeFiles/PacmanServer.dir/Network.cpp.o.provides.build: CMakeFiles/PacmanServer.dir/Network.cpp.o


CMakeFiles/PacmanServer.dir/Service.cpp.o: CMakeFiles/PacmanServer.dir/flags.make
CMakeFiles/PacmanServer.dir/Service.cpp.o: ../Service.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/views/github/PacmanAndroid/server/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/PacmanServer.dir/Service.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/PacmanServer.dir/Service.cpp.o -c /home/views/github/PacmanAndroid/server/Service.cpp

CMakeFiles/PacmanServer.dir/Service.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PacmanServer.dir/Service.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/views/github/PacmanAndroid/server/Service.cpp > CMakeFiles/PacmanServer.dir/Service.cpp.i

CMakeFiles/PacmanServer.dir/Service.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PacmanServer.dir/Service.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/views/github/PacmanAndroid/server/Service.cpp -o CMakeFiles/PacmanServer.dir/Service.cpp.s

CMakeFiles/PacmanServer.dir/Service.cpp.o.requires:

.PHONY : CMakeFiles/PacmanServer.dir/Service.cpp.o.requires

CMakeFiles/PacmanServer.dir/Service.cpp.o.provides: CMakeFiles/PacmanServer.dir/Service.cpp.o.requires
	$(MAKE) -f CMakeFiles/PacmanServer.dir/build.make CMakeFiles/PacmanServer.dir/Service.cpp.o.provides.build
.PHONY : CMakeFiles/PacmanServer.dir/Service.cpp.o.provides

CMakeFiles/PacmanServer.dir/Service.cpp.o.provides.build: CMakeFiles/PacmanServer.dir/Service.cpp.o


CMakeFiles/PacmanServer.dir/GameRoom.cpp.o: CMakeFiles/PacmanServer.dir/flags.make
CMakeFiles/PacmanServer.dir/GameRoom.cpp.o: ../GameRoom.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/views/github/PacmanAndroid/server/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/PacmanServer.dir/GameRoom.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/PacmanServer.dir/GameRoom.cpp.o -c /home/views/github/PacmanAndroid/server/GameRoom.cpp

CMakeFiles/PacmanServer.dir/GameRoom.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PacmanServer.dir/GameRoom.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/views/github/PacmanAndroid/server/GameRoom.cpp > CMakeFiles/PacmanServer.dir/GameRoom.cpp.i

CMakeFiles/PacmanServer.dir/GameRoom.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PacmanServer.dir/GameRoom.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/views/github/PacmanAndroid/server/GameRoom.cpp -o CMakeFiles/PacmanServer.dir/GameRoom.cpp.s

CMakeFiles/PacmanServer.dir/GameRoom.cpp.o.requires:

.PHONY : CMakeFiles/PacmanServer.dir/GameRoom.cpp.o.requires

CMakeFiles/PacmanServer.dir/GameRoom.cpp.o.provides: CMakeFiles/PacmanServer.dir/GameRoom.cpp.o.requires
	$(MAKE) -f CMakeFiles/PacmanServer.dir/build.make CMakeFiles/PacmanServer.dir/GameRoom.cpp.o.provides.build
.PHONY : CMakeFiles/PacmanServer.dir/GameRoom.cpp.o.provides

CMakeFiles/PacmanServer.dir/GameRoom.cpp.o.provides.build: CMakeFiles/PacmanServer.dir/GameRoom.cpp.o


CMakeFiles/PacmanServer.dir/GameMapDefault.cpp.o: CMakeFiles/PacmanServer.dir/flags.make
CMakeFiles/PacmanServer.dir/GameMapDefault.cpp.o: ../GameMapDefault.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/views/github/PacmanAndroid/server/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/PacmanServer.dir/GameMapDefault.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/PacmanServer.dir/GameMapDefault.cpp.o -c /home/views/github/PacmanAndroid/server/GameMapDefault.cpp

CMakeFiles/PacmanServer.dir/GameMapDefault.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PacmanServer.dir/GameMapDefault.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/views/github/PacmanAndroid/server/GameMapDefault.cpp > CMakeFiles/PacmanServer.dir/GameMapDefault.cpp.i

CMakeFiles/PacmanServer.dir/GameMapDefault.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PacmanServer.dir/GameMapDefault.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/views/github/PacmanAndroid/server/GameMapDefault.cpp -o CMakeFiles/PacmanServer.dir/GameMapDefault.cpp.s

CMakeFiles/PacmanServer.dir/GameMapDefault.cpp.o.requires:

.PHONY : CMakeFiles/PacmanServer.dir/GameMapDefault.cpp.o.requires

CMakeFiles/PacmanServer.dir/GameMapDefault.cpp.o.provides: CMakeFiles/PacmanServer.dir/GameMapDefault.cpp.o.requires
	$(MAKE) -f CMakeFiles/PacmanServer.dir/build.make CMakeFiles/PacmanServer.dir/GameMapDefault.cpp.o.provides.build
.PHONY : CMakeFiles/PacmanServer.dir/GameMapDefault.cpp.o.provides

CMakeFiles/PacmanServer.dir/GameMapDefault.cpp.o.provides.build: CMakeFiles/PacmanServer.dir/GameMapDefault.cpp.o


CMakeFiles/PacmanServer.dir/GameMap.cpp.o: CMakeFiles/PacmanServer.dir/flags.make
CMakeFiles/PacmanServer.dir/GameMap.cpp.o: ../GameMap.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/views/github/PacmanAndroid/server/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/PacmanServer.dir/GameMap.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/PacmanServer.dir/GameMap.cpp.o -c /home/views/github/PacmanAndroid/server/GameMap.cpp

CMakeFiles/PacmanServer.dir/GameMap.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PacmanServer.dir/GameMap.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/views/github/PacmanAndroid/server/GameMap.cpp > CMakeFiles/PacmanServer.dir/GameMap.cpp.i

CMakeFiles/PacmanServer.dir/GameMap.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PacmanServer.dir/GameMap.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/views/github/PacmanAndroid/server/GameMap.cpp -o CMakeFiles/PacmanServer.dir/GameMap.cpp.s

CMakeFiles/PacmanServer.dir/GameMap.cpp.o.requires:

.PHONY : CMakeFiles/PacmanServer.dir/GameMap.cpp.o.requires

CMakeFiles/PacmanServer.dir/GameMap.cpp.o.provides: CMakeFiles/PacmanServer.dir/GameMap.cpp.o.requires
	$(MAKE) -f CMakeFiles/PacmanServer.dir/build.make CMakeFiles/PacmanServer.dir/GameMap.cpp.o.provides.build
.PHONY : CMakeFiles/PacmanServer.dir/GameMap.cpp.o.provides

CMakeFiles/PacmanServer.dir/GameMap.cpp.o.provides.build: CMakeFiles/PacmanServer.dir/GameMap.cpp.o


CMakeFiles/PacmanServer.dir/Client.cpp.o: CMakeFiles/PacmanServer.dir/flags.make
CMakeFiles/PacmanServer.dir/Client.cpp.o: ../Client.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/views/github/PacmanAndroid/server/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/PacmanServer.dir/Client.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/PacmanServer.dir/Client.cpp.o -c /home/views/github/PacmanAndroid/server/Client.cpp

CMakeFiles/PacmanServer.dir/Client.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PacmanServer.dir/Client.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/views/github/PacmanAndroid/server/Client.cpp > CMakeFiles/PacmanServer.dir/Client.cpp.i

CMakeFiles/PacmanServer.dir/Client.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PacmanServer.dir/Client.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/views/github/PacmanAndroid/server/Client.cpp -o CMakeFiles/PacmanServer.dir/Client.cpp.s

CMakeFiles/PacmanServer.dir/Client.cpp.o.requires:

.PHONY : CMakeFiles/PacmanServer.dir/Client.cpp.o.requires

CMakeFiles/PacmanServer.dir/Client.cpp.o.provides: CMakeFiles/PacmanServer.dir/Client.cpp.o.requires
	$(MAKE) -f CMakeFiles/PacmanServer.dir/build.make CMakeFiles/PacmanServer.dir/Client.cpp.o.provides.build
.PHONY : CMakeFiles/PacmanServer.dir/Client.cpp.o.provides

CMakeFiles/PacmanServer.dir/Client.cpp.o.provides.build: CMakeFiles/PacmanServer.dir/Client.cpp.o


CMakeFiles/PacmanServer.dir/Socket.cpp.o: CMakeFiles/PacmanServer.dir/flags.make
CMakeFiles/PacmanServer.dir/Socket.cpp.o: ../Socket.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/views/github/PacmanAndroid/server/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/PacmanServer.dir/Socket.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/PacmanServer.dir/Socket.cpp.o -c /home/views/github/PacmanAndroid/server/Socket.cpp

CMakeFiles/PacmanServer.dir/Socket.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PacmanServer.dir/Socket.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/views/github/PacmanAndroid/server/Socket.cpp > CMakeFiles/PacmanServer.dir/Socket.cpp.i

CMakeFiles/PacmanServer.dir/Socket.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PacmanServer.dir/Socket.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/views/github/PacmanAndroid/server/Socket.cpp -o CMakeFiles/PacmanServer.dir/Socket.cpp.s

CMakeFiles/PacmanServer.dir/Socket.cpp.o.requires:

.PHONY : CMakeFiles/PacmanServer.dir/Socket.cpp.o.requires

CMakeFiles/PacmanServer.dir/Socket.cpp.o.provides: CMakeFiles/PacmanServer.dir/Socket.cpp.o.requires
	$(MAKE) -f CMakeFiles/PacmanServer.dir/build.make CMakeFiles/PacmanServer.dir/Socket.cpp.o.provides.build
.PHONY : CMakeFiles/PacmanServer.dir/Socket.cpp.o.provides

CMakeFiles/PacmanServer.dir/Socket.cpp.o.provides.build: CMakeFiles/PacmanServer.dir/Socket.cpp.o


CMakeFiles/PacmanServer.dir/Game.cpp.o: CMakeFiles/PacmanServer.dir/flags.make
CMakeFiles/PacmanServer.dir/Game.cpp.o: ../Game.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/views/github/PacmanAndroid/server/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/PacmanServer.dir/Game.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/PacmanServer.dir/Game.cpp.o -c /home/views/github/PacmanAndroid/server/Game.cpp

CMakeFiles/PacmanServer.dir/Game.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PacmanServer.dir/Game.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/views/github/PacmanAndroid/server/Game.cpp > CMakeFiles/PacmanServer.dir/Game.cpp.i

CMakeFiles/PacmanServer.dir/Game.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PacmanServer.dir/Game.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/views/github/PacmanAndroid/server/Game.cpp -o CMakeFiles/PacmanServer.dir/Game.cpp.s

CMakeFiles/PacmanServer.dir/Game.cpp.o.requires:

.PHONY : CMakeFiles/PacmanServer.dir/Game.cpp.o.requires

CMakeFiles/PacmanServer.dir/Game.cpp.o.provides: CMakeFiles/PacmanServer.dir/Game.cpp.o.requires
	$(MAKE) -f CMakeFiles/PacmanServer.dir/build.make CMakeFiles/PacmanServer.dir/Game.cpp.o.provides.build
.PHONY : CMakeFiles/PacmanServer.dir/Game.cpp.o.provides

CMakeFiles/PacmanServer.dir/Game.cpp.o.provides.build: CMakeFiles/PacmanServer.dir/Game.cpp.o


CMakeFiles/PacmanServer.dir/Player.cpp.o: CMakeFiles/PacmanServer.dir/flags.make
CMakeFiles/PacmanServer.dir/Player.cpp.o: ../Player.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/views/github/PacmanAndroid/server/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building CXX object CMakeFiles/PacmanServer.dir/Player.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/PacmanServer.dir/Player.cpp.o -c /home/views/github/PacmanAndroid/server/Player.cpp

CMakeFiles/PacmanServer.dir/Player.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PacmanServer.dir/Player.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/views/github/PacmanAndroid/server/Player.cpp > CMakeFiles/PacmanServer.dir/Player.cpp.i

CMakeFiles/PacmanServer.dir/Player.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PacmanServer.dir/Player.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/views/github/PacmanAndroid/server/Player.cpp -o CMakeFiles/PacmanServer.dir/Player.cpp.s

CMakeFiles/PacmanServer.dir/Player.cpp.o.requires:

.PHONY : CMakeFiles/PacmanServer.dir/Player.cpp.o.requires

CMakeFiles/PacmanServer.dir/Player.cpp.o.provides: CMakeFiles/PacmanServer.dir/Player.cpp.o.requires
	$(MAKE) -f CMakeFiles/PacmanServer.dir/build.make CMakeFiles/PacmanServer.dir/Player.cpp.o.provides.build
.PHONY : CMakeFiles/PacmanServer.dir/Player.cpp.o.provides

CMakeFiles/PacmanServer.dir/Player.cpp.o.provides.build: CMakeFiles/PacmanServer.dir/Player.cpp.o


# Object files for target PacmanServer
PacmanServer_OBJECTS = \
"CMakeFiles/PacmanServer.dir/home/views/github/PacmanAndroid/common/Messages/Messages.cpp.o" \
"CMakeFiles/PacmanServer.dir/home/views/github/PacmanAndroid/common/Messages/Types/Stream.cpp.o" \
"CMakeFiles/PacmanServer.dir/home/views/github/PacmanAndroid/common/Messages/Types/Repeated.cpp.o" \
"CMakeFiles/PacmanServer.dir/main.cpp.o" \
"CMakeFiles/PacmanServer.dir/Network.cpp.o" \
"CMakeFiles/PacmanServer.dir/Service.cpp.o" \
"CMakeFiles/PacmanServer.dir/GameRoom.cpp.o" \
"CMakeFiles/PacmanServer.dir/GameMapDefault.cpp.o" \
"CMakeFiles/PacmanServer.dir/GameMap.cpp.o" \
"CMakeFiles/PacmanServer.dir/Client.cpp.o" \
"CMakeFiles/PacmanServer.dir/Socket.cpp.o" \
"CMakeFiles/PacmanServer.dir/Game.cpp.o" \
"CMakeFiles/PacmanServer.dir/Player.cpp.o"

# External object files for target PacmanServer
PacmanServer_EXTERNAL_OBJECTS =

PacmanServer: CMakeFiles/PacmanServer.dir/home/views/github/PacmanAndroid/common/Messages/Messages.cpp.o
PacmanServer: CMakeFiles/PacmanServer.dir/home/views/github/PacmanAndroid/common/Messages/Types/Stream.cpp.o
PacmanServer: CMakeFiles/PacmanServer.dir/home/views/github/PacmanAndroid/common/Messages/Types/Repeated.cpp.o
PacmanServer: CMakeFiles/PacmanServer.dir/main.cpp.o
PacmanServer: CMakeFiles/PacmanServer.dir/Network.cpp.o
PacmanServer: CMakeFiles/PacmanServer.dir/Service.cpp.o
PacmanServer: CMakeFiles/PacmanServer.dir/GameRoom.cpp.o
PacmanServer: CMakeFiles/PacmanServer.dir/GameMapDefault.cpp.o
PacmanServer: CMakeFiles/PacmanServer.dir/GameMap.cpp.o
PacmanServer: CMakeFiles/PacmanServer.dir/Client.cpp.o
PacmanServer: CMakeFiles/PacmanServer.dir/Socket.cpp.o
PacmanServer: CMakeFiles/PacmanServer.dir/Game.cpp.o
PacmanServer: CMakeFiles/PacmanServer.dir/Player.cpp.o
PacmanServer: CMakeFiles/PacmanServer.dir/build.make
PacmanServer: /usr/local/lib/libboost_system.so
PacmanServer: /usr/local/lib/libboost_thread.so
PacmanServer: /usr/local/lib/libboost_chrono.so
PacmanServer: /usr/local/lib/libboost_date_time.so
PacmanServer: /usr/local/lib/libboost_atomic.so
PacmanServer: CMakeFiles/PacmanServer.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/views/github/PacmanAndroid/server/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Linking CXX executable PacmanServer"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/PacmanServer.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/PacmanServer.dir/build: PacmanServer

.PHONY : CMakeFiles/PacmanServer.dir/build

CMakeFiles/PacmanServer.dir/requires: CMakeFiles/PacmanServer.dir/home/views/github/PacmanAndroid/common/Messages/Messages.cpp.o.requires
CMakeFiles/PacmanServer.dir/requires: CMakeFiles/PacmanServer.dir/home/views/github/PacmanAndroid/common/Messages/Types/Stream.cpp.o.requires
CMakeFiles/PacmanServer.dir/requires: CMakeFiles/PacmanServer.dir/home/views/github/PacmanAndroid/common/Messages/Types/Repeated.cpp.o.requires
CMakeFiles/PacmanServer.dir/requires: CMakeFiles/PacmanServer.dir/main.cpp.o.requires
CMakeFiles/PacmanServer.dir/requires: CMakeFiles/PacmanServer.dir/Network.cpp.o.requires
CMakeFiles/PacmanServer.dir/requires: CMakeFiles/PacmanServer.dir/Service.cpp.o.requires
CMakeFiles/PacmanServer.dir/requires: CMakeFiles/PacmanServer.dir/GameRoom.cpp.o.requires
CMakeFiles/PacmanServer.dir/requires: CMakeFiles/PacmanServer.dir/GameMapDefault.cpp.o.requires
CMakeFiles/PacmanServer.dir/requires: CMakeFiles/PacmanServer.dir/GameMap.cpp.o.requires
CMakeFiles/PacmanServer.dir/requires: CMakeFiles/PacmanServer.dir/Client.cpp.o.requires
CMakeFiles/PacmanServer.dir/requires: CMakeFiles/PacmanServer.dir/Socket.cpp.o.requires
CMakeFiles/PacmanServer.dir/requires: CMakeFiles/PacmanServer.dir/Game.cpp.o.requires
CMakeFiles/PacmanServer.dir/requires: CMakeFiles/PacmanServer.dir/Player.cpp.o.requires

.PHONY : CMakeFiles/PacmanServer.dir/requires

CMakeFiles/PacmanServer.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/PacmanServer.dir/cmake_clean.cmake
.PHONY : CMakeFiles/PacmanServer.dir/clean

CMakeFiles/PacmanServer.dir/depend:
	cd /home/views/github/PacmanAndroid/server/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/views/github/PacmanAndroid/server /home/views/github/PacmanAndroid/server /home/views/github/PacmanAndroid/server/cmake-build-debug /home/views/github/PacmanAndroid/server/cmake-build-debug /home/views/github/PacmanAndroid/server/cmake-build-debug/CMakeFiles/PacmanServer.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/PacmanServer.dir/depend

