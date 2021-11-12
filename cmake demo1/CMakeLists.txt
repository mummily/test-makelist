#[[ 说明：
    1. 应用程序hwapp，库文件hwdll
    2. hwapp中调用hwdll中的一个函数
    3. 这个是一个简单的应用程序调用库文件的方法
]]

cmake_minimum_required(VERSION 3.10)

# 设置工程名
project(hwApp)

# 添加子目录
add_subdirectory(hwApp1)
add_subdirectory(hwApp2)