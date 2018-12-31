#include <iostream>
#include "CSingleton.h"

int main(int argc, char* argv[])
{
	CSingleton* singleton = CSingleton::getInstance();
	singleton->doSomething();

	return 0;
}