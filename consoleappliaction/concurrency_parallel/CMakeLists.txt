# ==== shared_mutex和mutex的性能对比 ========================
add_executable(shared_mutex_cmp_mutex_test shared_mutex_cmp_mutex.cpp)

# ==== parallel_invoke ==================================
add_executable(parallel_invoke_test parallel_invoke.cpp)

# ==== parallel_for_each ==================================
add_executable(parallel_for_test_each parallel_for_each.cpp)

# ==== parallel_create_task ==================================
add_executable(create_task_test create_task.cpp)

# ==== when_all 或 when_any ==================================
add_executable(when_all_when_any_test when_all_when_any.cpp)

# ==== task_group        ==================================
add_executable(task_group_test task_group.cpp)