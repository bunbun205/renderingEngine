file(GLOB_RECURSE SHAPES ${CMAKE_CURRENT_SOURCE_DIR}/*.*)
file(GLOB_RECURSE SHAPES_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

add_library(Shapes ${SHAPES} ${SHAPES_SOURCES})

target_include_directories(Shapes PUBLIC 
        ${CMAKE_SOURCE_DIR}/math
        ${CMAKE_SOURCE_DIR}/physics
        ${CMAKE_SOURCE_DIR}/shapes
        ${CMAKE_SOURCE_DIR}/utilities
)