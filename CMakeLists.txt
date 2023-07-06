# Based on the SDL2 tutorial
# https://wiki.libsdl.org/SDL2/README/cmake

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

if(WIN32)
    find_package(SDL2 REQUIRED)
    add_compile_definitions(SDL_MAIN_HANDLED)
    target_link_libraries(dum ${SDL2_LIBRARIES})
else()
    # 1. Look for a SDL2 package
    # 2. look for the SDL2 component
    # 3. fail if none can be found
    find_package(SDL2 REQUIRED CONFIG REQUIRED COMPONENTS SDL2 HINTS lib/SDL2)

    # 1. Look for a SDL2 package
    # 2. Look for the SDL2maincomponent
    # 3. DO NOT fail when SDL2main is not available
    find_package(SDL2 REQUIRED CONFIG COMPONENTS SDL2main HINTS lib/SDL2)

    # SDL2::SDL2main may or may not be available. It is e.g. required by Windows GUI applications
    if(TARGET SDL2::SDL2main)
        # It has an implicit dependency on SDL2 functions, so it MUST be added
        # before SDL2::SDL2 (or SDL2::SDL2-static)
        target_link_libraries(dum PRIVATE SDL2::SDL2main)
    endif()

    # Link to the actual SDL2 library:
    #     - SDL2::SDL2 is the shared SDL library,
    #     - SDL2::SDL2-static is the static SDL library.
    target_link_libraries(dum PRIVATE SDL2::SDL2-static)
endif()

include_directories(dum ${SDL2_INCLUDE_DIRS})
