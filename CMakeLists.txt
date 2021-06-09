cmake_minimum_required(VERSION 3.8)
project(spear VERSION 0.1.0)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

option(SP_SINGLE_PRECISION "use single-precision floating point. If OFF, use double-precision floating point" OFF)

message("options starting with SP_EXPERIMENTAL is for experiment or testing, not for practice use!")
option(SP_EXPERIMENTAL_QUAKE_FASTINVSQRT "use inhanced version of Fast inverse square root (aka 0x5F3759DF)" OFF)

configure_file(spear_config.h.in ${SPEAR_SOURCE_DIR}/src/spear_config.h)


set(SRCFILES
	src/core.hpp

	src/precision.h
	src/spear_config.h

	src/experimentMath.hpp
	src/experimentMath.cpp
 
	src/Matrix3.hpp
	src/Matrix4.hpp
	src/Vector3.hpp
	src/Vector4.hpp

	src/particle.hpp
	src/particle.cpp
)

set(HEADERS
	include/spear/spear.hpp
	include/spear/spear_math.hpp
)

add_library(spear ${SRCFILES} ${HEADERS})

target_include_directories(spear PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_include_directories(spear PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)