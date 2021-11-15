#[[ 说明：
    1. 应用程序hwapp，库文件hwdll
    2. hwapp中调用hwdll中的一个函数
    3. 这个是一个简单的应用程序调用库文件的方法
]]

cmake_minimum_required(VERSION 3.10)

# 设置工程名
project(hwApp2)

# 添加头文件包含目录
include_directories(
    ../hwApp1/hwdll
)

# 头文件描述
set(HEADERS
)

# 源文件描述
set(SOURCES
    ./main.cpp
)

# 生成应用文件
add_executable(${PROJECT_NAME} 
    ${HEADERS}
    ${SOURCES}
)

# 依赖库描述
target_link_libraries(${PROJECT_NAME} 
    hwdll
)