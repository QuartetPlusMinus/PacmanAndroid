cmake_minimum_required(VERSION 3.10)
project(serialization)

set(CMAKE_CXX_STANDARD 11)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

find_package( Boost 1.6 REQUIRED COMPONENTS unit_test_framework)

set(SZ_FILES Serialization/src/Stream.cpp Serialization/src/Serializable.cpp)
add_executable(messages_test ${SZ_FILES} test.cpp Messages.cpp Samples.cpp TileMap.cpp)

target_link_libraries(messages_test ${Boost_LIBRARIES})