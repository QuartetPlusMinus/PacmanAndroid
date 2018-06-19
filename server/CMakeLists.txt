cmake_minimum_required(VERSION 3.5.1)
project(server)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")

include_directories(/usr/local/include)
link_directories(/usr/local/lib)

find_package( Boost 1.6 REQUIRED COMPONENTS system thread)
include_directories( ${Boost_INCLUDE_DIR} )

set(SERIALIZATION_FILES
        ../common/Serialization/Serialization/src/Serializable.cpp
        ../common/Serialization/Serialization/src/Stream.cpp
        )
set(TILEMAP_AND_MESSAGES_FILES
        ../common/Serialization/Messages.cpp
        ../common/Serialization/Samples.cpp
        ../common/Serialization/TileMap.cpp
        )

set(SERVER_FILES main.cpp NetWork/Network.cpp NetWork/Service.cpp Game/GameRoom.cpp NetWork/Client.cpp NetWork/Socket.cpp Game/Game.cpp GameObjects/Pacman.cpp Game/GameRoomsManager.cpp Game/GameRoomsManager.h Game/MapManager.cpp GameObjects/Ghost.cpp GameObjects/Ghost.h ../common/Constants/ConstValues.h)

set(GRAPH_FILES Graph/SetGraph.cpp Graph/setUpGraph.cpp Graph/setUpGraph.h)

add_executable(PacmanServer ${SERIALIZATION_FILES} ${TILEMAP_AND_MESSAGES_FILES} ${GRAPH_FILES} ${SERVER_FILES})
target_link_libraries(PacmanServer ${PROTOBUF_LIBRARY} ${Boost_LIBRARIES})
