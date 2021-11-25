project(Test)
set(CMAKE_CXX_STANDARD 17)

# ==== printmain.cpp中调用print.cpp中函数 =================
# add_executable(${PROJECT_NAME} printmain.cpp print/print.cpp)

# ==== variant的使用 =====================================
# add_executable(${PROJECT_NAME} variantmain.cpp)

# ==== fmt的使用 =========================================
# add_executable(${PROJECT_NAME} fmtmain.cpp)
# # 依赖库描述
# target_link_libraries(${PROJECT_NAME} 
#     fmt
# )
# add_subdirectory(
#     ${CMAKE_CURRENT_SOURCE_DIR}/../../3rdparty/fmt
#     fmt
#)

# ==== operator->的使用 =================================
# add_executable(${PROJECT_NAME} operatorptrmain.cpp)

# ==== rttr反射的基本使用 ================================
# add_executable(${PROJECT_NAME} rttrmain.cpp)
# # 依赖库描述
# target_link_libraries(${PROJECT_NAME} 
#     RTTR::Core
# )
# add_subdirectory(
#     ${CMAKE_CURRENT_SOURCE_DIR}/../../3rdparty/rttr
#     rttr
# )

# ==== shared_mutex和mutex的性能对比 ========================
# add_executable(${PROJECT_NAME} concurrency_parallel/shared_mutex_cmp_mutex.cpp)

# ==== 并行parallel：同时做不同事情的能力 ===================
# ==== parallel_invoke ==================================
# add_executable(${PROJECT_NAME} concurrency_parallel/parallel_invoke.cpp)

# ==== parallel_for_each ==================================
add_executable(${PROJECT_NAME} concurrency_parallel/parallel_for_each.cpp)