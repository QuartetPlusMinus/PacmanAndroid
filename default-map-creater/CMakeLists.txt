cmake_minimum_required(VERSION 3.5.1)

project(MapEditor)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SERIALIZATION_FILES
        ../../common/Serialization/Serialization/src/Serializable.cpp
        ../../common/Serialization/Serialization/src/Stream.cpp)

set(TILEMAP_FILES
        ../../common/Serialization/TileMap.cpp
        ../../common/Serialization/Samples.cpp)

add_executable(DefaultMapCreater main.cpp ${SERIALIZATION_FILES} ${TILEMAP_FILES})
