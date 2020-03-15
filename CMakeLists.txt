cmake_minimum_required(VERSION 3.0)
project(Labyrinth VERSION 1.0.0)

file(GLOB_RECURSE sources      src/*.cpp src/*.h)
file(GLOB_RECURSE includes      includes/*.h)

configure_file(LabyrinthConfig.h.in LabyrinthConfig.h)
add_executable(labyrinth ${sources} )
target_include_directories(labyrinth PUBLIC
    "${PROJECT_BINARY_DIR}")

set(CPACK_PACKAGE_NAME "Labyrinth")
set(CPACK_PACKAGE_VERSION "1.0.0")
set(CPACK_MONOLITHIC_INSTALL 1)

include(CPack)

set(CMAKE_CXX_STANDARD 11)
