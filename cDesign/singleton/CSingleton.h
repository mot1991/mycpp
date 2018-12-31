#ifndef _C_SINGLETON_H
#define _C_SINGLETON_H

class CSingleton
{
public:
	static CSingleton* getInstance();
	void doSomething(); // test


private:
	CSingleton();
	~CSingleton();

	CSingleton(const CSingleton& other);
	CSingleton& operator=(const CSingleton& other);


private:
	static CSingleton* instance;
	class CGarbo // 只用来调用单例对象的析构函数
	{
	public:
		~CGarbo()
		{
			if(NULL != CSingleton::instance)
			{
				delete CSingleton::instance;
				CSingleton::instance = NULL;
			}
		}
	};
	static CGarbo garbo;
};

#endif /* _C_SINGLETON_H */