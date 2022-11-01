add_library(Game STATIC
    # player.cpp
    Game.cpp
    shares.cpp
)
target_include_directories(Game PUBLIC ../includes)
target_include_directories(Game PUBLIC ${LIBSDL_INCLUDE_DIR})
