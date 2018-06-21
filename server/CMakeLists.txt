cmake_minimum_required(VERSION 3.5.1)
project(server)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")

#include_directories(/usr/local/include)
#link_directories(/usr/local/lib)

find_package( Boost 1.6 REQUIRED COMPONENTS system thread)
include_directories( ${Boost_INCLUDE_DIR} )

set(COMMON_LOCAL_PATH ${CMAKE_SOURCE_DIR}/../common/)

include_directories(${COMMON_LOCAL_PATH})

set(SERIALIZATION_FILES
        ${COMMON_LOCAL_PATH}/Serialization/Serialization/src/Serializable.cpp
        ${COMMON_LOCAL_PATH}/Serialization/Serialization/src/Stream.cpp
        )
set(TILEMAP_AND_MESSAGES_FILES
        ${COMMON_LOCAL_PATH}/Serialization/Messages.cpp
        ${COMMON_LOCAL_PATH}/Serialization/Samples.cpp
        ${COMMON_LOCAL_PATH}/Serialization/TileMap.cpp
        )

set(SERVER_FILES main.cpp NetWork/Network.cpp NetWork/Service.cpp Game/GameRoom.cpp NetWork/Client.cpp NetWork/Socket.cpp Game/Game.cpp GameObjects/Pacman.cpp Game/GameRoomsManager.cpp Game/GameRoomsManager.h Game/MapManager.cpp GameObjects/Ghost.cpp GameObjects/Ghost.h ../common/Constants/ConstValues.h)

set(GRAPH_FILES Graph/SetGraph.cpp GameObjects/GameObject.cpp GameObjects/GameObject.h)

add_executable(PacmanServer ${SERIALIZATION_FILES} ${TILEMAP_AND_MESSAGES_FILES} ${GRAPH_FILES} ${SERVER_FILES})
target_link_libraries(PacmanServer ${PROTOBUF_LIBRARY} ${Boost_LIBRARIES})

make_directory(${CMAKE_BINARY_DIR}/src/)
make_directory(${CMAKE_BINARY_DIR}/src/maps)
file(COPY src/maps/default-map-one-pacman.map DESTINATION ${CMAKE_BINARY_DIR}/src/maps/)