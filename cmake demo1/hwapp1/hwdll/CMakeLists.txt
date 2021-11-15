#[[ 说明：
    1. 共享库文件hwdll
    2. 导出一个函数供其它程序调用
]]

set(PROJECT hwdll)

# 头文件描述
file(GLOB HEADERS *.h)

# 源文件描述
file(GLOB SOURCES *.cpp)

# 编译预定义描述
add_compile_definitions(
    DLL_EXPORTS
)

# 生成共享库文件
add_library(${PROJECT} SHARED 
    ${HEADERS}
    ${SOURCES}
)