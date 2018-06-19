cmake_minimum_required(VERSION 3.4.1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CPP_LOCAL_PATH ${CMAKE_SOURCE_DIR}/src/main/cpp)
set(PNG_LOCAL_PATH ${CPP_LOCAL_PATH}/libpng)
set(OPENDRAW_LOCAL_PATH ${CPP_LOCAL_PATH}/libodraw)
set(MESSAGE_LOCAL_PATH ${CMAKE_SOURCE_DIR}/../../common/Serialization/)

find_library( z-lib z )
find_library( gles-lib GLESv2 )
find_library( log-lib log )
find_library( android-lib android )
find_library( stdcpp-lib stdc++ )

add_library( libodraw SHARED
            ${OPENDRAW_LOCAL_PATH}/ShaderPrograms.cpp
            ${OPENDRAW_LOCAL_PATH}/Shaders.cpp

            ${OPENDRAW_LOCAL_PATH}/Texture.cpp
            ${OPENDRAW_LOCAL_PATH}/Rectangle.cpp
            ${OPENDRAW_LOCAL_PATH}/Sprite.cpp
            )

target_link_libraries(libodraw ${gles-lib})

include_directories(${MESSAGE_LOCAL_PATH})
add_library( libmessage SHARED
            ${MESSAGE_LOCAL_PATH}/Serialization/src/Stream.cpp
            ${MESSAGE_LOCAL_PATH}/Serialization/src/Serializable.cpp
            ${MESSAGE_LOCAL_PATH}/Samples.cpp
            ${MESSAGE_LOCAL_PATH}/Messages.cpp
            )

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

add_library( game SHARED
             ${CPP_LOCAL_PATH}/GameRendererJNI.cpp
             ${CPP_LOCAL_PATH}/Game.cpp
             ${CPP_LOCAL_PATH}/Background.cpp
             ${CPP_LOCAL_PATH}/platform_asset_utils.cpp
             ${CPP_LOCAL_PATH}/image.cpp
             )

target_link_libraries( game
                       libodraw
                       libmessage
                       libpng
                       ${gles-lib}
                       ${log-lib}
                       ${android-lib}
                       )