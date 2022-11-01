include_directories(${LIBSDL_INCLUDE_DIR})
link_directories(${LIBSDL_LIBRARIES_DIR})

add_executable(FightNianCpp main.cpp)

target_include_directories(FightNianCpp PUBLIC ../includes)


target_link_libraries(FightNianCpp SDL2)
target_link_libraries(FightNianCpp SDL2_image)
target_link_libraries(FightNianCpp SDL2_mixer)
target_link_libraries(FightNianCpp SDL2main)
target_link_libraries(FightNianCpp Game)