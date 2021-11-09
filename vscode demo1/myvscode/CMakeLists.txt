project(Test)

# printmain.cpp中调用print.cpp中函数
add_executable(Test printmain.cpp print.cpp)