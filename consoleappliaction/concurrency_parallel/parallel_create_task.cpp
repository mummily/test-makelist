#include <iostream>
#include <ppl.h>
#include <ppltasks.h>
#include <vector>
#include <shared_mutex>
using namespace std;
using namespace concurrency;

std::shared_mutex mutex_;
void print(int i)
{
    for (int j = i - 10; j < i; j++)
    {
        // std::this_thread::sleep_for(std::chrono::milliseconds(100));
        printf("%d\t%d\n", std::this_thread::get_id(), j);
    }
}

void print2(int i)
{
    printf("==============================%d %d\n", std::this_thread::get_id(), i);
    parallel_for(0, 10, [](int idx)
                 {
                     std::this_thread::sleep_for(std::chrono::milliseconds(100));
                     printf("Work thread: %lu\n", std::this_thread::get_id());
                 });
}

void sync()
{
    create_task([]() -> vector<int>
                {
                    vector<int> nums(10);
                    generate(begin(nums), end(nums), []
                             { return rand() % 1000; });
                    return nums;
                })
        .then([](vector<int> vec)
              { Concurrency::parallel_for_each(vec.begin(), vec.end(), [&](int i) -> void
                                               { print(i); }); }

              )
        .then([](task<void> error)
              {
                  try
                  {
                      error.get();
                  }
                  catch (const std::exception &e)
                  {
                      std::cerr << e.what() << '\n';
                  }
              })
        .wait();
}

void async()
{
    int id = 1;

    cout << "start" << endl;
    auto t = create_task([&id]()
                         {
                             print2(id++);
                             return id;
                         })
                 .then([](int id)
                       {
                           print2(id++);
                           return id;
                       })
                 .then([](int id)
                       { print2(id++); });
    cout << "end" << endl;

    // 问题：用户关闭程序时，可能后台线程没有执行完毕，导致后台线程依赖的资源提前释放，程序崩溃
    // 解决：concurrency::task_group，可以管理一系列后台线程，并在程序关闭前wait，保证后台线程结束后再释放资源
    while (!t.is_done())
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
}

// wait会导致阻塞当前线程
int main(int argc, char **argv)
{
    // sync();
    async();

    return 0;
}