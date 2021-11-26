#include <iostream>
#include <ppl.h>
#include <ppltasks.h>
#include <vector>
#include <shared_mutex>
#include "../common/timer.h"
using namespace std;
using namespace this_thread;
using namespace concurrency;

int main(int argc, char **argv)
{
    auto t1 = make_task([]
                        {
                            sleep_for(std::chrono::milliseconds(100));
                            cout << "Hello from taskA." << endl;
                        });
    auto t2 = make_task([]
                        {
                            sleep_for(std::chrono::milliseconds(200));
                            cout << "Hello from taskB." << endl;
                        });

    task_group tasks;
    tasks.run(t1);
    tasks.run(t2);

    {
        sleep_for(std::chrono::milliseconds(300));
        cout << "Hello World!";
        timer t;
        tasks.wait();
    }

    return 0;
}