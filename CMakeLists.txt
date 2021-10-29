cmake_minimum_required(VERSION 3.0)
project(zuoye1)

set(CMAKE_BUILD_TYPE "Debug")
set(CMAKE_CXX_FLAGS_DEBUG "-O0 -Wall -ggdb")
# set the directory of executable files
#set(CMAKE_AUTOMOC ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${zuoye1_SOURCE_DIR}/bin)
add_executable(main_cmake 11.cpp)