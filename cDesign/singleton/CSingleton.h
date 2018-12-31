/******************************************
 *
 * 单例模式的简单实现
 * 单例模式，是一种常用的软件设计模式。在它的核心结构中只包含一个被称为单例的特殊类。
 * 通过单例模式可以保证系统中，应用该模式的类一个类只有一个实例。
 * 即一个类只有一个对象实例。
 *
 * @file		CSingleton.h
 * @brief		单例模式
 *
 ********************************************/
#ifndef _C_SINGLETON_H
#define _C_SINGLETON_H

/**
 * @brief 单例类
 */
class CSingleton
{
public:

	/**
	* @brief Get singleton instance
	* @return CSingleton pointer
	*/
	static CSingleton* getInstance();
	/**
	* @brief test
	*/
	void doSomething();

private:
	CSingleton();
	~CSingleton();

	CSingleton(const CSingleton& other);
	CSingleton& operator=(const CSingleton& other);

private:
	static CSingleton* instance;
	/**
	* @brief 内嵌类
	* 用来调用单例对象的析构函数
	*/
	class CGarbo
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