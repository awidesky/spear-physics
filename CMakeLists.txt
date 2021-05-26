cmake_minimum_required(VERSION 3.8)
project(spear VERSION 0.1.0)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)


AUX_SOURCE_DIRECTORY(${CMAKE_CURRENT_SOURCE_DIR}/src SRCFILES)

set(HEADERS
	include/temph.h
)

add_library(spear ${SRCFILES} ${HEADERS})

target_include_directories(spear PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
