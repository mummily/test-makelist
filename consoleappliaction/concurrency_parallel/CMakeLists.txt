# shared_mutex和mutex的性能对比
add_executable(shared_mutex_cmp_mutex shared_mutex_cmp_mutex.cpp)

# parallel_invoke
add_executable(parallel_invoke parallel_invoke.cpp)

# parallel_for
add_executable(parallel_for parallel_for.cpp)

# parallel_for_each
add_executable(parallel_for_each parallel_for_each.cpp)

# parallel_create_task
add_executable(create_task create_task.cpp)

# when_all 或 when_any
add_executable(when_all_when_any when_all_when_any.cpp)

# task_group
add_executable(task_group task_group.cpp)