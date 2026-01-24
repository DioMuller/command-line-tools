cmake_minimum_required(VERSION 3.13)
project("ConsoleTools")
set(CMAKE_CXX_STANDARD 17)

# Add executable target with source files listed in SOURCE_FILES variable
add_executable(mediarenamer src/mediarenamer.cpp)