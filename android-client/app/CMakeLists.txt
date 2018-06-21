cmake_minimum_required(VERSION 3.4.1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CPP_LOCAL_PATH ${CMAKE_SOURCE_DIR}/src/main/cpp)
set(PNG_LOCAL_PATH ${CPP_LOCAL_PATH}/libodraw/libpng)
set(OPENDRAW_LOCAL_PATH ${CPP_LOCAL_PATH}/libodraw/src)
set(COMMON_LOCAL_PATH ${CMAKE_SOURCE_DIR}/../../common/)

find_library( z-lib z )
find_library( gles-lib GLESv2 )
find_library( android-lib android )


add_library( libpng STATIC
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

target_link_libraries(libpng ${z-lib})


add_library( libodraw SHARED
            ${OPENDRAW_LOCAL_PATH}/ShaderPrograms.cpp
            ${OPENDRAW_LOCAL_PATH}/Shaders.cpp
            ${OPENDRAW_LOCAL_PATH}/Texture.cpp
            ${OPENDRAW_LOCAL_PATH}/Sprite.cpp
            ${OPENDRAW_LOCAL_PATH}/RawImage.cpp
            )

target_link_libraries(libodraw
                      libpng
                      ${gles-lib}
                      ${android-lib}
                      )


include_directories(${COMMON_LOCAL_PATH})

add_library( libmessage SHARED
            ${COMMON_LOCAL_PATH}/Serialization/Serialization/src/Stream.cpp
            ${COMMON_LOCAL_PATH}/Serialization/Serialization/src/Serializable.cpp
            ${COMMON_LOCAL_PATH}/Serialization/Samples.cpp
            ${COMMON_LOCAL_PATH}/Serialization/Messages.cpp
            )


add_library( game SHARED
             ${CPP_LOCAL_PATH}/GameRendererJNI.cpp
             ${CPP_LOCAL_PATH}/Game.cpp
             ${CPP_LOCAL_PATH}/Background.cpp
             ${CPP_LOCAL_PATH}/Unit.cpp
             ${CPP_LOCAL_PATH}/Pacman.cpp
             ${CPP_LOCAL_PATH}/Ghost.cpp
             )

target_link_libraries( game
                       libodraw
                       libmessage
                       ${android-lib}
                       )