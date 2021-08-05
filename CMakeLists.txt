# Class Building Test File for Card Deck Project
# Prof. Frank Emanuel (c) 2021
# CST8219 C++
#
# CMake File for Project

cmake_minimum_required(VERSION 3.20)

# project: deck of playing cards

project ( deckofcards )

add_executable(textdemo deck.cpp deck.h main.cpp)
add_executable(windowdemo deck.cpp deck.h winmain.cpp)

set(CMAKE_CXX_STANDARD 20)

include_directories(CMAKE_CURRENT_SOURCE_DIR C:/SFML/include)

set(SFML_ROOT C:/SFML)
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")

find_package(SFML REQUIRED system window graphics)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(windowdemo ${SFML_LIBRARIES})
endif()

message(STATUS "Checking libraries (SFML_LIBRARIES): ${SFML_LIBRARIES}")

file (GLOB BINARY_DEP_DLLS "${SFML_INCLUDE_DIR}/../bin/*.dll")
file (COPY ${BINARY_DEP_DLLS} DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

