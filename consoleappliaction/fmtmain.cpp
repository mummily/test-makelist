#include <iostream>
#include "fmt\format.h"
#include <string>
using namespace std;

int main(int argc, char **argv)
{
    std::string str1 = fmt::format("Hello, {}!", "world");
    std::cout << str1 << std::endl;

    fmt::print("Hello, {}!\n", "world");

    int i = 2147483647;
    printf("value=0x%lx\n", i);
    fmt::print("value=0x{:x}", i);
}