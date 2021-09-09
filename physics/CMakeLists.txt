file(GLOB_RECURSE PHYSICS ${CMAKE_CURRENT_SOURCE_DIR}/*.*)
file(GLOB_RECURSE PHYSICS_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

add_library(Physics ${PHYSICS} ${PHYSICS_SOURCES})

target_include_directories(Physics PUBLIC
        ${CMAKE_SOURCE_DIR}/math
        ${CMAKE_SOURCE_DIR}/physics
        ${CMAKE_SOURCE_DIR}/shapes
        ${CMAKE_SOURCE_DIR}/utilities
)