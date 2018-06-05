cmake_minimum_required(VERSION 3.5.1)
project(server)


set(CMAKE_CXX_STANDARD 11)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")

include_directories(/usr/local/include)
link_directories(/usr/local/lib)

find_package( Boost 1.6 REQUIRED COMPONENTS system thread)
include_directories( ${Boost_INCLUDE_DIR} )

set(MESSAGES_FILES)

set(SERVER_FILES main.cpp Network.cpp Service.cpp GameRoom.cpp GameMapDefault.cpp GameMap.cpp Client.cpp Socket.cpp Game.cpp Player.cpp Ghost.cpp Ghost.h )

#add_executable(PacmanServer ${SERVER_FILES} ${GENERATED_PROTOBUF_FILES})
add_executable(PacmanServer ${SERVER_FILES} protobuf/message_lite.cc protobuf/service.pb.cc)
target_link_libraries(PacmanServer ${PROTOBUF_LIBRARY} ${Boost_LIBRARIES})
