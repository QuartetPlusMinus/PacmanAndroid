cmake_minimum_required(VERSION 3.4.1)



set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CPP_LOCAL_PATH /home/viewsharp/GitHub/PacmanAndroid/android-client/app/src/main/cpp)
set(PNG_LOCAL_PATH ${CPP_LOCAL_PATH}/libpng)
set(BOOST_LOCAL_PATH ${CPP_LOCAL_PATH}/boost)



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

find_library( z-lib z )

target_link_libraries(libpng ${z-lib})



include_directories(${BOOST_LOCAL_PATH}/include/boost-1_66)

add_library(boost_system STATIC IMPORTED)
set_target_properties( boost_system PROPERTIES IMPORTED_LOCATION
                      ${BOOST_LOCAL_PATH}/lib/libboost_system-clang-mt-a32-1_66.a
                      )


# add_library(boost_thread STATIC IMPORTED)
# set_target_properties( boost_thread PROPERTIES IMPORTED_LOCATION
#                        ${BOOST_LOCAL_PATH}/lib/libboost_thread-clang-mt-x64-1_66.a
#                        )



add_library( game SHARED
             ${CPP_LOCAL_PATH}/platform_asset_utils.cpp
             ${CPP_LOCAL_PATH}/platform_log.cpp
             ${CPP_LOCAL_PATH}/asset_utils.cpp
             ${CPP_LOCAL_PATH}/buffer.cpp
             ${CPP_LOCAL_PATH}/program.cpp
             ${CPP_LOCAL_PATH}/game.cpp
             ${CPP_LOCAL_PATH}/image.cpp
             ${CPP_LOCAL_PATH}/shader.cpp
             ${CPP_LOCAL_PATH}/texture.cpp
             ${CPP_LOCAL_PATH}/game_objects.cpp
             ${CPP_LOCAL_PATH}/client-udp.cpp
             )

find_library( gles-lib GLESv2 )
find_library( log-lib log )
find_library( android-lib android )
find_library( stdcpp-lib stdc++ )

target_link_libraries( game

                       libpng
                       boost_system
                       # boost_thread
                       ${gles-lib}
                       ${log-lib}
                       ${android-lib}
                     )