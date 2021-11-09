project(Test)
set(CMAKE_CXX_STANDARD 17)

# printmain.cpp中调用print.cpp中函数
# add_executable(Test printmain.cpp print.cpp)

# variant的使用
add_executable(Test variantmain.cpp)