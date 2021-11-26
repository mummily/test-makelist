#include <iostream>
#include <ppl.h>
#include <shared_mutex>
#include "../common/timer.h"
using namespace std;

#pragma region 基本操作
/* mutable */ std::shared_mutex mutex_;

void print(int i)
{
    for (int j = i - 10; j < i; j++)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));

        // printf("%d\n", j); // 线程安全

        // cout << j << endl; // 线程不安全
        lock_guard<shared_mutex> lock(mutex_);
        cout << j << endl; // 加锁后线程安全
    }
}

void main_basic()
{
    int i1 = 10;
    int i2 = 20;
    int i3 = 30;
    auto fun1 = std::bind(&print, i1);
    auto fun2 = std::bind(&print, i2);
    auto fun3 = std::bind(&print, i3);

    Concurrency::parallel_invoke(
        fun1,
        fun2,
        fun3);
}
#pragma endregion

#pragma region 性能验证
void sleepfun(int milliseconds)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
}

void main_time()
{
    auto fun1 = std::bind(&sleepfun, 1000);
    auto fun2 = std::bind(&sleepfun, 2000);
    auto fun3 = std::bind(&sleepfun, 3000);

    {
        cout << "并行时间：" << endl;
        timer t;

        Concurrency::parallel_invoke(
            fun1,
            fun2,
            fun3);
    }
    {
        cout << "串行时间：" << endl;
        timer t;

        fun1();
        fun2();
        fun3();
    }
}
#pragma endregion

#pragma region 验证子线程崩溃

void throwexception()
{
    try
    {
        throw std::exception("throw exception");
    }
    catch (const std::exception &e)
    {
        std::cerr << std::this_thread::get_id() << " " << e.what() << '\n';
    }
}

void main_exception()
{
    timer t;

    auto fun1 = std::bind(&sleepfun, 1000);
    auto fun2 = std::bind(&sleepfun, 2000);
    auto fun3 = std::bind(&throwexception);

    Concurrency::parallel_invoke(
        fun1,
        fun2,
        fun3);
}
#pragma endregion

// 并行（Parallelism）：同时做不同事情的能力
int main(int argc, char **argv)
{
    // 基本操作
    // main_basic();
    // 性能验证
    // main_time();
    // 子线程崩溃验证，为避免崩溃对主线程的影响，建议加try-catch
    main_exception();

    return 0;
}