#include <iostream>
#include <ppl.h>
#include <shared_mutex>
#include <vector>
#include "../common/timer.h"
using namespace std;
using namespace concurrency;

void demo1()
{
    /* mutable */ std::shared_mutex mutex_;
    auto print = [&](int i) -> void
    {
        for (int j = i - 10; j < i; j++)
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(100));

            // printf("%d\n", j); // 线程安全

            // cout << j << endl; // 线程不安全
            lock_guard<shared_mutex> lock(mutex_);
            cout << std::this_thread::get_id() << "\t" << j << endl; // 加锁后线程安全
        }
    };

    std::vector<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);
    vec.push_back(40);
    vec.push_back(50);
    vec.push_back(60);
    vec.push_back(70);
    vec.push_back(80);
    vec.push_back(90);
    vec.push_back(100);
    vec.push_back(200);
    vec.push_back(300);
    vec.push_back(400);
    vec.push_back(500);
    vec.push_back(600);
    vec.push_back(700);
    vec.push_back(800);
    vec.push_back(900);

    {
        timer t;
        Concurrency::parallel_for_each(vec.begin(), vec.end(), [&](int i) -> void
                                       { print(i); });
    }
}

// 结论：可以在parallel_for_each中套用parallel_for_each
// 1. for_each中使用for_each，用时约1000ms
// 2. parallel_for_each中使用for_each，用时约400ms
// 3. parallel_for_each中使用parallel_for_each，用时约100ms
// 注：经验证，最大开辟的线程数约10
void demo2()
{
    vector<vector<int>> vec = {{1}, {2, 2}, {3, 3, 3}, {4, 4, 4, 4}};

    parallel_for_each(vec.begin(), vec.end(), [&](vector<int> v) -> void
                      {
                          parallel_for_each(v.begin(), v.end(), [&](int i) -> void
                                            {
                                                std::this_thread::sleep_for(std::chrono::milliseconds(100));
                                                printf("%d\n", i);
                                            });
                      });
}

void demo3()
{
    struct MyStruct
    {
        int i;
        int i1;
    };

    vector<MyStruct> vec = {{1, 0}, {2, 0}, {3, 0}, {4, 0}, {5, 0}, {6, 0}, {7, 0}, {8, 0}, {9, 0}};
    parallel_for_each(vec.begin(), vec.end(), [&](MyStruct &v) -> void
                      { v.i1 = v.i + 1; });
    parallel_for_each(vec.begin(), vec.end(), [&](MyStruct &v) -> void
                      { printf("%d %d\n", v.i, v.i1); });
}

// 并行（Parallelism）：同时做不同事情的能力
int main(int argc, char **argv)
{
    demo3();
    return 0;
}