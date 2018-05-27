cmake_minimum_required(VERSION 3.5.1)
project(server)


set(CMAKE_CXX_STANDARD 11)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")

include_directories(/usr/local/include)
link_directories(/usr/local/lib)

find_package( Boost 1.6 REQUIRED COMPONENTS system thread)
include_directories( ${Boost_INCLUDE_DIR} )

find_package(Protobuf REQUIRED)

set(PROTO_PATH "${CMAKE_SOURCE_DIR}/../protocol")
set(SERVICE_PROTO "${PROTO_PATH}/service.proto")
set(GENERATED_PROTOBUF_PATH "${CMAKE_BINARY_DIR}/generated")
file(MAKE_DIRECTORY ${GENERATED_PROTOBUF_PATH})

set(SERVICE_PB_CPP_FILE "${GENERATED_PROTOBUF_PATH}/service.pb.cc")
set(SERVICE_PB_H_FILE "${GENERATED_PROTOBUF_PATH}/service.pb.h")

add_custom_command(
        OUTPUT "${SERVICE_PB_H_FILE}"
        "${SERVICE_PB_CPP_FILE}"
        COMMAND ${PROTOBUF_PROTOC_EXECUTABLE}
        ARGS "--proto_path=${PROTO_PATH}"
        "--cpp_out=${GENERATED_PROTOBUF_PATH}"
        "${SERVICE_PROTO}"
)

set(GENERATED_PROTOBUF_FILES ${SERVICE_PB_H_FILE} ${SERVICE_PB_CPP_FILE})
include_directories(${GENERATED_PROTOBUF_PATH})

set(SERVER_FILES main.cpp Network.cpp Service.cpp GameRoom.cpp GameMapDefault.cpp GameMap.cpp Client.cpp Socket.cpp Game.cpp Player.cpp Ghost.cpp Ghost.h )

add_executable(PacmanServer ${SERVER_FILES} ${GENERATED_PROTOBUF_FILES})
target_link_libraries(PacmanServer ${PROTOBUF_LIBRARY} ${Boost_LIBRARIES})
