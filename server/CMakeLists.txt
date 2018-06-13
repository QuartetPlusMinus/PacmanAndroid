cmake_minimum_required(VERSION 3.5.1)
project(server)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")

include_directories(/usr/local/include)
link_directories(/usr/local/lib)

find_package( Boost 1.6 REQUIRED COMPONENTS system thread)
include_directories( ${Boost_INCLUDE_DIR} )

set(MESSAGES_FILES ../common/Messages/Messages.cpp ../common/Messages/Types/Stream.cpp ../common/Messages/Types/Repeated.cpp)

set(SERVER_FILES main.cpp NetWork/src/Network.cpp NetWork/src/Service.cpp Game/src/GameRoom.cpp Game/src/GameMapDefault.cpp Game/src/GameMap.cpp NetWork/src/Client.cpp NetWork/src/Socket.cpp Game/src/Game.cpp GameObjects/src/Pacman.cpp Game/src/GameRoomsManager.cpp Game/lib/GameRoomsManager.h GameObjects/src/Ghost.cpp GameObjects/lib/Ghost.h ../common/Constants/ConstValues.h)

add_executable(PacmanServer ${MESSAGES_FILES} ${SERVER_FILES})
target_link_libraries(PacmanServer ${PROTOBUF_LIBRARY} ${Boost_LIBRARIES})
