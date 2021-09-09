file(GLOB_RECURSE UTILITIES ${CMAKE_CURRENT_SOURCE_DIR}/*.*)
file(GLOB_RECURSE UTILITIES_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

add_library(Utilities ${UTILITIES} ${UTILITIES_SOURCES})

target_include_directories(Utilities PUBLIC 
        ${CMAKE_SOURCE_DIR}/math
        ${CMAKE_SOURCE_DIR}/physics
        ${CMAKE_SOURCE_DIR}/shapes
        ${CMAKE_SOURCE_DIR}/utilities
)