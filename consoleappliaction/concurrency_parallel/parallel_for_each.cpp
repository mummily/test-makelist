#include <iostream>
#include <ppl.h>
#include <shared_mutex>
#include <vector>
#include "../common/timer.h"
using namespace std;

/* mutable */ std::shared_mutex mutex_;
void fun(int i)
{
    for (int j = i - 10; j < i; j++)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));

        // printf("%d\n", j); // 线程安全

        // cout << j << endl; // 线程不安全
        lock_guard<shared_mutex> lock(mutex_);
        cout << std::this_thread::get_id() << "\t" << j << endl; // 加锁后线程安全
    }
}

// 并行（Parallelism）：同时做不同事情的能力
int main(int argc, char **argv)
{
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
                                       { fun(i); });
    }

    return 0;
}