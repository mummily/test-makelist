project(Test)
set(CMAKE_CXX_STANDARD 17)

# 说明：printmain.cpp中调用print.cpp中函数
# add_executable(${PROJECT_NAME} printmain.cpp print.cpp)

# 说明：variant的使用
# add_executable(${PROJECT_NAME} variantmain.cpp)

# 说明：fmt的使用
# add_executable(${PROJECT_NAME} fmtmain.cpp)
# # 依赖库描述
# target_link_libraries(${PROJECT_NAME} 
#     fmt
# )
# add_subdirectory(
#     ${CMAKE_CURRENT_SOURCE_DIR}/../../3rdparty/fmt
#     fmt
#)

# 说明：operator->的使用
add_executable(${PROJECT_NAME} operatorptrmain.cpp)