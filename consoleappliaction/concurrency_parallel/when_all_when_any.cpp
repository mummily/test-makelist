#include <ppltasks.h>
#include <list>
#include <iostream>
using namespace concurrency;
using namespace std;
using namespace this_thread;

int main()
{
    list<task<void>> tasks =
        {
            create_task([]
                        {
                            sleep_for(std::chrono::milliseconds(100));
                            cout << "Hello from taskA." << endl;
                        }),
            create_task([]
                        {
                            sleep_for(std::chrono::milliseconds(200));
                            cout << "Hello from taskB." << endl;
                        }),
            create_task([]
                        {
                            sleep_for(std::chrono::milliseconds(300));
                            cout << "Hello from taskC." << endl;
                        })};

    // 注：joinTask也是一个task
    // auto joinTask = when_any(tasks.begin(), tasks.end());
    auto joinTask = when_all(tasks.begin(), tasks.end());

    cout << "Hello from the joining thread." << endl;
    joinTask.wait();
}
