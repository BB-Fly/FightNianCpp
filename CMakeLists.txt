cmake_minimum_required(VERSION 3.10)
project(FightNianGame)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include(cmake/modules/FindlibSDL.cmake)

add_subdirectory(src)
add_subdirectory(main)