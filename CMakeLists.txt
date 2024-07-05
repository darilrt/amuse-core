cmake_minimum_required(VERSION 3.5)

# C++ standard 20
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Project name
project(AmuseCore)

# Add definition for shared library
add_compile_definitions(AMUSE_CORE_EXPORT)

# Add static library
file(GLOB_RECURSE SOURCES 
    src/*.cpp
    src/core/*.cpp
    src/core/gfx/*.cpp
    src/core/components/*.cpp
    src/imgui/*.cpp
    src/imgui/backends/*.cpp)


add_library(AmuseCore SHARED ${SOURCES})


# Add the include directory
target_include_directories(AmuseCore PUBLIC include)
target_include_directories(AmuseCore PUBLIC vendor/SDL/include)

# Add the SDL2 library
option(SDL_STATIC ON)
option(SDL_SHARED OFF)
add_subdirectory(vendor/SDL)

# Link the SDL2 library
target_link_libraries(AmuseCore SDL2main)
target_link_libraries(AmuseCore SDL2-static)