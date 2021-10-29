cmake_minimum_required(VERSION 3.10)

project(hwApp)

include_directories(./hwdll)
add_executable(hwApp ./hwapp/main.cpp)
target_link_libraries(hwApp hwdll)


add_subdirectory(hwdll)