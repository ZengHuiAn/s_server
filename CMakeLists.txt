cmake_minimum_required(VERSION 3.10)
project(TCPRemote)

set(CMAKE_CXX_STANDARD 17)

include_directories(./include)

#aux_source_directory(./src/ RESOURCE)

include_directories(./src/)


add_executable(TCPRemote src/main.cpp)
target_link_libraries(TCPRemote mysqlclient)