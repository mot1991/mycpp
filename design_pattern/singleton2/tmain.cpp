#include <iostream>

#include "CTestA.h"

int main(int argc, char* argv[])
{
    CTestA* singleton1 = CTestA::getInstance();
    CTestA* singleton2 = CTestA::getInstance();

    std::cout << "Test singleton2 : " << std::endl;
    std::cout << singleton1 << std::endl;
    std::cout << singleton2 << std::endl;

    return 0;
}