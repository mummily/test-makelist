#include <mutex>
#include <shared_mutex>
#include <thread>
#include <list>
#include <iostream>
#include <vector>
#include "../common/timer.h"

#define READ_THREAD_COUNT 8
#define LOOP_COUNT 5000000

typedef std::shared_lock<std::shared_mutex> ReadLock;
typedef std::lock_guard<std::shared_mutex> WriteLock;
typedef std::lock_guard<std::mutex> NormalLock;

class shared_mutex_counter
{
public:
    shared_mutex_counter() = default;

    unsigned int get() const
    {
        ReadLock lock(mutex);
        return value;
    }

    void increment()
    {
        WriteLock lock(mutex);
        value++;
    }

private:
    mutable std::shared_mutex mutex;
    unsigned int value = 0;
};

class mutex_counter
{
public:
    mutex_counter() = default;

    unsigned int get() const
    {
        NormalLock lock(mutex);
        return value;
    }

    void increment()
    {
        NormalLock lock(mutex);
        value++;
    }

private:
    mutable std::mutex mutex;
    unsigned int value = 0;
};

void test_shared_mutex()
{
    shared_mutex_counter counter;
    unsigned int temp;

    auto writer = [&counter]()
    {
        for (unsigned int i = 0; i < LOOP_COUNT; i++)
        {
            counter.increment();
        }
    };

    auto reader = [&counter, &temp]()
    {
        for (unsigned int i = 0; i < LOOP_COUNT; i++)
        {
            temp = counter.get();
        }
    };

    std::cout << "----- shared mutex test ------" << std::endl;
    std::list<std::shared_ptr<std::thread>> threadlist;
    {
        timer t;

        for (int i = 0; i < READ_THREAD_COUNT; i++)
        {
            threadlist.push_back(std::make_shared<std::thread>(reader));
        }
        std::shared_ptr<std::thread> pw = std::make_shared<std::thread>(writer);

        for (auto &it : threadlist)
        {
            it->join();
        }
        pw->join();
    }
    std::cout << "count:" << counter.get() << ", temp:" << temp << std::endl;
}

void test_mutex()
{
    mutex_counter counter;
    unsigned int temp;

    auto writer = [&counter]()
    {
        for (unsigned int i = 0; i < LOOP_COUNT; i++)
        {
            counter.increment();
        }
    };

    auto reader = [&counter, &temp]()
    {
        for (unsigned int i = 0; i < LOOP_COUNT; i++)
        {
            temp = counter.get();
        }
    };

    std::cout << "----- mutex test ------" << std::endl;
    std::list<std::shared_ptr<std::thread>> threadlist;
    {
        timer t;

        for (int i = 0; i < READ_THREAD_COUNT; i++)
        {
            threadlist.push_back(std::make_shared<std::thread>(reader));
        }

        std::shared_ptr<std::thread> pw = std::make_shared<std::thread>(writer);

        for (auto &it : threadlist)
        {
            it->join();
        }
        pw->join();
    }
    std::cout << "count:" << counter.get() << ", temp:" << temp << std::endl;
}

// 结论：用shared_mutex，区分读写锁
int main()
{
    test_shared_mutex();
    test_mutex();
    return 0;
}
