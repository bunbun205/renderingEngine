file(GLOB_RECURSE MATH ${CMAKE_CURRENT_SOURCE_DIR}/*.*)
file(GLOB_RECURSE MATH_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

add_library(Math ${MATH} ${MATH_SOURCES})

target_include_directories(Math PUBLIC
        ${CMAKE_SOURCE_DIR}/math
        ${CMAKE_SOURCE_DIR}/physics
        ${CMAKE_SOURCE_DIR}/shapes
        ${CMAKE_SOURCE_DIR}/utilities
)