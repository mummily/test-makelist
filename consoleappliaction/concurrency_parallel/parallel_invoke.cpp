#include <iostream>
#include <ppl.h>
#include <shared_mutex>
using namespace std;

/* mutable */ std::shared_mutex mutex_;
mutex mu;

void fun(int i)
{
    for (int j = i - 10; j < i; j++)
    {
        // cout << j << endl; // 线程不安全
        // printf("%d\n", j); // 线程安全

        std::this_thread::sleep_for(std::chrono::milliseconds(100));

        lock_guard<shared_mutex> lock(mutex_);
        cout << j << endl; // 线程不安全
    }
}

// 并行（Parallelism）：同时做不同事情的能力
int main(int argc, char **argv)
{
    int i1 = 10;
    int i2 = 20;
    int i3 = 30;
    auto fun1 = std::bind(&fun, i1);
    auto fun2 = std::bind(&fun, i2);
    auto fun3 = std::bind(&fun, i3);
    Concurrency::parallel_invoke(
        fun1,
        fun2,
        fun3);

    return 0;
}