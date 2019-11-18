/******************************************
 *
 * 单例模式的简单实现
 * 单例模式，是一种常用的软件设计模式。在它的核心结构中只包含一个被称为单例的特殊类。
 * 通过单例模式可以保证系统中，应用该模式的类一个类只有一个实例。
 * 即一个类只有一个对象实例。
 *
 * @file        CSingleton.h
 * @brief       单例模式(模板实现)
 *
 ********************************************/
#ifndef _C_SINGLETON_HPP_
#define _C_SINGLETON_HPP_

#include <pthread.h>

template <class T>
class CSingleton
{
public:
    static T* getInstance()
    {
        pthread_mutex_lock(&m_singleton_lock);

        if (NULL == m_instance)
        {
            m_instance = new T();
        }

        pthread_mutex_unlock(&m_singleton_lock);
        return m_instance;
    };

protected:
    CSingleton() {};
    virtual ~CSingleton() {};
    CSingleton(const CSingleton&);
    CSingleton& operator=(const CSingleton&);

protected:
    static T* m_instance;
    class CGarbo
    {
    public:
        ~CGarbo()
        {
            if(NULL != T::m_instance)
            {
                delete T::m_instance;
                T::m_instance = NULL;
            }
        }
    };
    static CGarbo m_garbo;
    static pthread_mutex_t m_singleton_lock;
};

template <class T> T *CSingleton<T>::m_instance = NULL;
template <class T> typename CSingleton<T>::CGarbo CSingleton<T>::m_garbo;
template <class T> pthread_mutex_t CSingleton<T>::m_singleton_lock = PTHREAD_MUTEX_INITIALIZER;

#endif /* _C_SINGLETON_HPP_ */