cmake_minimum_required(VERSION 3.25.1)
project(
    DumEnxin
    VERSION 1.0
    LANGUAGES C
)

add_compile_options(
    -Wall
    -Wextra
    -Werror
    -Wpedantic
    -Wconversion
    -Wsign-conversion
)

file(GLOB_RECURSE sources src/*.c)
add_executable(dum ${sources})

find_package(SDL2 REQUIRED)
include_directories(dum ${SDL2_INCLUDE_DIRS})

target_link_libraries(dum ${SDL2_LIBRARIES})

