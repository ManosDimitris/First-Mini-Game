cmake_minimum_required(VERSION 3.10)
project(SFMLApp)

set(CMAKE_CXX_STANDARD 17)

find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

add_executable(sfml-app main.cpp game.cpp Enemies.cpp)
target_link_libraries(sfml-app sfml-graphics sfml-window sfml-system)
