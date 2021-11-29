project(consoleappliaction)
set(CMAKE_CXX_STANDARD 17)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG "${PROJECT_SOURCE_DIR}/lib/debug")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELEASE "${PROJECT_SOURCE_DIR}/lib/release")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG "${PROJECT_SOURCE_DIR}/bin/debug")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE "${PROJECT_SOURCE_DIR}/bin/release")

# c++17 variant的使用
add_executable(cpp17variant variantmain.cpp)

# fmt的使用
add_executable(fmttest fmtmain.cpp)
target_link_libraries(fmttest
    fmt
)

# operator->的使用
add_executable(operatorptr operatorptrmain.cpp)

# rttr反射的基本使用 
add_executable(rttrtest rttrmain.cpp)
target_link_libraries(rttrtest
    RTTR::Core
)

# 并行parallel：同时做不同事情的能力
add_subdirectory(concurrency_parallel)

add_subdirectory(
    ${CMAKE_CURRENT_SOURCE_DIR}/../../3rdparty/fmt
    fmt
)

add_subdirectory(
    ${CMAKE_CURRENT_SOURCE_DIR}/../../3rdparty/rttr
    rttr
)