#include <iostream>
#include <string>
using namespace std;

class A
{
public:
    void display() { cout << "A" << endl; }
};

class B
{
public:
    B(A &ra) : ptr(&ra) {}
    A *operator->() { return ptr; }
    
    void display() { cout << "B" << endl; }

private:
    A *ptr;
};

// 结论：->重载根据栈对象，若为堆对象，只能是自己的->
int main()
{
    A a;
    B b(a);
    b->display(); // A

    B *pB = new B(a);
    pB->display();    // B
    (*pB)->display(); // A

    return 0;
}