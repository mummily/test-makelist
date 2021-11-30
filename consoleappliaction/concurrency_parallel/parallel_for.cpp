#include <iostream>
#include <vector>
#include <ppl.h>
#include "../common/lock.h"
#include "../common/timer.h"
using namespace std;
using namespace concurrency;
using namespace this_thread;

void demo1()
{
    vector<pair<int, int>> vec;

    {
        timer t;

        shared_mutex mutex;
        parallel_for(0, 10, [&](int i) -> void
                     {
                         sleep_for(std::chrono::seconds(1));

                         WriteLock lock(mutex);
                         vec.push_back({rand() % 100, rand() % 100});
                     });
    }

    for (auto &pi : vec)
        printf("%d - %d\n", pi.first, pi.second);
}

void demo2()
{
    vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(4);
    parallel_for(0, (int)vec.size(), [&](int i) -> void
                 { printf("%d\n", vec.at(i)); });
}

int main(int argc, char **argv)
{
    timer t;
    demo3();
    return 0;
}