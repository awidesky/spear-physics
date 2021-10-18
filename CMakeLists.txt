cmake_minimum_required(VERSION 3.8)
project(spear VERSION 0.1.0)

include(CMakeDependentOption)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(SP_REAL_PRECISION "double_8" CACHE STRING "Choose floating point precision")
set_property(CACHE SP_REAL_PRECISION PROPERTY STRINGS "double_8" "float_4")

option(SP_FPMATH_OPTIMIZATION "use floating point math optimization(might lose some accuracy)" OFF)
cmake_dependent_option(SP_USE_QUAKE_FASTINVSQRT "use inhanced version of Fast inverse square root (aka 0x5F3759DF)" ON "SP_FPMATH_OPTIMIZATION" OFF)



configure_file(spear_config.h.in ${SPEAR_SOURCE_DIR}/src/spear_config.h)


set(SRCFILES
	src/core.hpp

	src/precision.h
	src/spear_config.h

	src/Matrix3.hpp
	src/MatAccumProxy.hpp
	src/MatAccumProxy.cpp
	src/Matrix4.hpp
	src/Vector3.hpp
	src/Vector4.hpp
)

set(HEADERS
	include/spear/spear.hpp
	include/spear/spear_math.h
)

add_library(spear ${SRCFILES} ${HEADERS})

target_include_directories(spear PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_include_directories(spear PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)