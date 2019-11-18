#include <iostream>

#include "CSingleton.h"

int main(int argc, char* argv[])
{
    CSingleton* singleton1 = CSingleton::getInstance();
    CSingleton* singleton2 = CSingleton::getInstance();

    std::cout << "Test singleton : " << std::endl;
    std::cout << singleton1 << std::endl;
    std::cout << singleton2 << std::endl;

    return 0;
}