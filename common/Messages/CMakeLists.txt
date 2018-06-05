cmake_minimum_required(VERSION 3.10)
project(serialization)

set(CMAKE_CXX_STANDARD 11)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

#ADD_DEFINITIONS(-DBOOST_TEST_DYN_LINK)
find_package( Boost 1.6 REQUIRED COMPONENTS unit_test_framework)

set(TYPES_FILES Types/Repeated.cpp Types/Stream.cpp)
add_executable(messages_test ${TYPES_FILES} test.cpp Messages.cpp)

target_link_libraries(messages_test ${Boost_LIBRARIES})