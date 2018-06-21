cmake_minimum_required(VERSION 3.5.1)

project(MapEditor)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_executable(MapEditor main.cpp Button.cpp Tile.cpp Window.cpp)

# Detect and add SFML
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake-modules" ${CMAKE_MODULE_PATH})
find_package(SFML 2 REQUIRED graphics network audio window system )
if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(MapEditor ${SFML_LIBRARIES} ${SFML_DEPENDENCIES} )
endif()
