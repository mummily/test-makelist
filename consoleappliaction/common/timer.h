#pragma once
#include <chrono>
#include <iostream>

class timers
{
public:
    timers()
    {
        m_begin = std::chrono::high_resolution_clock::now();
    }

    ~timers()
    {
        m_end = std::chrono::high_resolution_clock::now();
        Consuming();
    }

    void Consuming()
    {
        std::cout << "Time-consuming:" << std::chrono::duration_cast<std::chrono::duration<float, std::milli>>(m_end - m_begin).count() << std::endl;
    }

private:
    std::chrono::high_resolution_clock::time_point m_begin;
    std::chrono::high_resolution_clock::time_point m_end;
};