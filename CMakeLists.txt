cmake_minimum_required(VERSION 3.21.0)

project("RayTracer")

set_property( GLOBAL PROPERTY USE_FOLDERS ON )

if( CMAKE_BUILD_TYPE STREQUAL "" )
        set( CMAKE_BUILD_TYPE "debug")
endif()

if( CMAKE_BUILD_TYPE STREQUAL "debug" )
        add_definitions(-D_DEBUG)
endif()

include_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}/include/math 
        ${CMAKE_CURRENT_SOURCE_DIR}/include/physics 
        ${CMAKE_CURRENT_SOURCE_DIR}/include/utilities 
        ${CMAKE_CURRENT_SOURCE_DIR}/include/shapes
)



file(GLOB_RECURSE MATH ${CMAKE_CURRENT_SOURCE_DIR}/include/math/*.*)
file(GLOB_RECURSE PHYSICS ${CMAKE_CURRENT_SOURCE_DIR}/include/physics/*.*)
file(GLOB_RECURSE UTILITIES ${CMAKE_CURRENT_SOURCE_DIR}/include/utilities/*.*)
file(GLOB_RECURSE SHAPES ${CMAKE_CURRENT_SOURCE_DIR}/include/shapes/*.*)

file(GLOB_RECURSE MATH_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/source/math/*.cpp)
file(GLOB_RECURSE PHYSICS_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/source/physics/*.cpp)
file(GLOB_RECURSE UTILITIES_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/source/utilities/*.cpp)
file(GLOB_RECURSE SHAPES_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/source/shapes/*.cpp)

add_library(math      SHARED ${MATH}      ${MATH_SOURCES})


add_executable(RayTracer main.cpp)

target_link_libraries(RayTracer math)

set_property(TARGET RayTracer PROPERTY CXX_STANDARD 17)
set_property(TARGET RayTracer PROPERTY CXX_STANDARD_REQUIRED ON)