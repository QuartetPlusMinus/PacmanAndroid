# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

# Sets the minimum version of CMake required to build the native library.

cmake_minimum_required(VERSION 3.4.1)

# Creates and names a library, sets it as either STATIC
# or SHARED, and provides the relative paths to its source code.
# You can define multiple libraries, and CMake builds them for you.
# Gradle automatically packages shared libraries with your APK.

set(PNG_LOCAL_PATH src/main/cpp/libpng)

add_library(
             libpng
             STATIC

             ${PNG_LOCAL_PATH}/png.c
             ${PNG_LOCAL_PATH}/pngerror.c
             ${PNG_LOCAL_PATH}/pngget.c
             ${PNG_LOCAL_PATH}/pngmem.c
             ${PNG_LOCAL_PATH}/pngpread.c
             ${PNG_LOCAL_PATH}/pngread.c
             ${PNG_LOCAL_PATH}/pngrio.c
             ${PNG_LOCAL_PATH}/pngrtran.c
             ${PNG_LOCAL_PATH}/pngrutil.c
             ${PNG_LOCAL_PATH}/pngset.c
             ${PNG_LOCAL_PATH}/pngtrans.c
             ${PNG_LOCAL_PATH}/pngwio.c
             ${PNG_LOCAL_PATH}/pngwrite.c
             ${PNG_LOCAL_PATH}/pngwtran.c
             ${PNG_LOCAL_PATH}/pngwutil.c
             )

set(GAME_LOCAL_PATH src/main/cpp)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

add_library( # Sets the name of the library.
             game

             # Sets the library as a shared library.
             SHARED

             # Provides a relative path to your source file(s).
             ${GAME_LOCAL_PATH}/platform_asset_utils.cpp
             ${GAME_LOCAL_PATH}/platform_log.cpp
             ${GAME_LOCAL_PATH}/asset_utils.cpp
             ${GAME_LOCAL_PATH}/buffer.cpp
             ${GAME_LOCAL_PATH}/game.cpp
             ${GAME_LOCAL_PATH}/image.cpp
             ${GAME_LOCAL_PATH}/shader.cpp
             ${GAME_LOCAL_PATH}/texture.cpp
             ${GAME_LOCAL_PATH}/game_objects.cpp
             ${GAME_LOCAL_PATH}/program.cpp
             )


# Searches for a specified prebuilt library and stores the path as a
# variable. Because CMake includes system libraries in the search path by
# default, you only need to specify the name of the public NDK library
# you want to add. CMake verifies that the library exists before
# completing its build.




# Specifies libraries CMake should link to your target library. You
# can link multiple libraries, such as libraries you define in this
# build script, prebuilt third-party libraries, or system libraries.

find_library( z-lib z )

target_link_libraries(
                       libpng

                       ${z-lib}
                       )

find_library( gles-lib GLESv2 )
find_library( log-lib log )
find_library( android-lib android )

target_link_libraries(
                       game

                       libpng
                       ${gles-lib}
                       ${log-lib}
                       ${android-lib}
)