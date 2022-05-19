cmake_minimum_required(VERSION 3.22)
project(libtarcso)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON CACHE INTERNAL "")


include_directories(graphicslib)
add_subdirectory(graphicslib)
link_libraries(
    graphics
)

add_compile_options("-Wall")

file(GLOB sources *.cpp)
list(REMOVE_ITEM sources main.cpp)

add_library(libtarcso ${sources})
add_executable(test_widgets main.cpp)
target_link_libraries(test_widgets libtarcso)
