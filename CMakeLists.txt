cmake_minimum_required(VERSION 3.20)

project(moskvin-v-a-23-02)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(prj.codeforces)
add_subdirectory(prj.lab)
add_subdirectory(prj.test)

add_executable(stack stack.cpp)