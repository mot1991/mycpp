#include <iostream>
#include <pthread.h>

#include "CSingleton.h"

static pthread_mutex_t singleton_lock = PTHREAD_MUTEX_INITIALIZER; 

CSingleton* CSingleton::instance = NULL;
CSingleton::CGarbo CSingleton::garbo;

CSingleton::CSingleton()
{

}

CSingleton::~CSingleton()
{

}

CSingleton* CSingleton::getInstance()
{
	pthread_mutex_lock(&singleton_lock);

	if(NULL == instance)
	{
		instance = new CSingleton();
	}

	pthread_mutex_unlock(&singleton_lock);
	return instance;
}

void CSingleton::doSomething()
{
	std::cout << "doSomething" << std::endl;
}