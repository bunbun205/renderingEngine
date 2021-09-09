cmake_minimum_required(VERSION 3.21.0)

project(RayTracer VERSION 1.0)

add_subdirectory(math)
# add_subdirectory(physics)
add_subdirectory(utilities)
add_subdirectory(shapes)

add_executable(RayTracer main.cpp)

target_link_libraries(RayTracer PRIVATE Math Shapes Utilities)

target_include_directories(RayTracer PUBLIC
        ${CMAKE_SOURCE_DIR}/math
        ${CMAKE_SOURCE_DIR}/physics
        ${CMAKE_SOURCE_DIR}/shapes
        ${CMAKE_SOURCE_DIR}/utilities
)

set_property(TARGET RayTracer PROPERTY CXX_STANDARD 17)
set_property(TARGET RayTracer PROPERTY CXX_STANDARD_REQUIRED ON)