# Class Building Test File for Card Deck Project
# Prof. Frank Emanuel (c) 2021
# CST8219 C++
#
# CMake File for Project

cmake_minimum_required(VERSION 3.20)

# define the project

project ( cardtest )

# add executable or define project scope

add_executable(${PROJECT_NAME} deck.h main.cpp)

# add compiler options

set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 11)
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD_REQUIRED ON)
