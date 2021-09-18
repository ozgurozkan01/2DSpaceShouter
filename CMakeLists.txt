cmake_minimum_required(VERSION 3.20)
project(SFML)

set(CMAKE_CXX_STANDARD 14)

add_executable(SFML main.cpp Game.cpp Game.h Practice.cpp Practice.h Bullet.cpp Bullet.h Player.cpp Player.h Enemy.cpp Enemy.h)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR C:/SFML/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics audio network REQUIRED)

include_directories(c:/SFML/include)
target_link_libraries(SFML sfml-system sfml-window sfml-graphics sfml-audio)