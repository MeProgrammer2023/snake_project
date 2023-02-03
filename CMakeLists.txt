cmake_minimum_required(VERSION 3.24)
project(patterngui)

set(CMAKE_CXX_STANDARD 20)


add_executable(patterngui headers/level.h headers/player.h headers/savefile.h headers/score.h headers/snake.h code/main.cpp code/ui.cpp headers/ui.h)
include_directories(headers include/SFML/include)

add_compile_options(-static)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML REQUIRED system window graphics)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(patterngui ${SFML_LIBRARIES})
endif()

file(COPY assets DESTINATION ${CMAKE_BINARY_DIR})


if(WIN32)
    file(GLOB BINARY_DEP_DLLS "${SFML_INCLUDE_DIR}/../bin/*.dll")
    file(COPY ${BINARY_DEP_DLLS} DESTINATION ${CMAKE_BINARY_DIR})
endif()