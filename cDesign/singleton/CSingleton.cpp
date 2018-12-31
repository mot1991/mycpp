#include <iostream>
#include "CSingleton.h"

CSingleton* CSingleton::instance = NULL;
CSingleton::CGarbo CSingleton::garbo;

CSingleton::CSingleton()
{

}

CSingleton::~CSingleton()
{

}

// 不是线程安全
CSingleton* CSingleton::getInstance()
{
	if(NULL == instance)
	{
		instance = new CSingleton();
	}
	return instance;
}

void CSingleton::doSomething()
{
	std::cout << "doSomething" << std::endl;
}