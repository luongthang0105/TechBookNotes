#include <iostream>

class Test
{
public:
    virtual ~Test() {}
};
Test t;

int main()
{
    std::cout << sizeof(t);
}