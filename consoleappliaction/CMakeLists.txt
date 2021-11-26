project(consoleappliaction)
set(CMAKE_CXX_STANDARD 17)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG "${PROJECT_SOURCE_DIR}/lib/debug")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELEASE "${PROJECT_SOURCE_DIR}/lib/release")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG "${PROJECT_SOURCE_DIR}/bin/debug")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE "${PROJECT_SOURCE_DIR}/bin/release")

# c++17 variant的使用
add_executable(cpp17variant_test variantmain.cpp)

# fmt的使用
add_executable(fmt_test fmtmain.cpp)
target_link_libraries(fmt_test
    fmt
)

# operator->的使用
add_executable(operatorptr_test operatorptrmain.cpp)

# rttr反射的基本使用 
add_executable(rttr_test rttrmain.cpp)
target_link_libraries(rttr_test
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