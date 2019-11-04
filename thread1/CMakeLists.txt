cmake_minimum_required(VERSION 3.14)
project(thread1)

set(CMAKE_CXX_STANDARD 11)

find_package(Threads REQUIRED)


add_executable(thread1 main.cpp)

target_link_libraries(thread1 Threads::Threads)
