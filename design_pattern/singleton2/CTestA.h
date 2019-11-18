#ifndef _C_TEST_A_H_
#define _C_TEST_A_H_

#include "CSingleton.hpp"

class CTestA : public CSingleton<CTestA>
{
public:
    /**
    * @brief test
    */
    void doSomething();

private:
    CTestA();
    virtual ~CTestA();
    CTestA(const CTestA&);
    CTestA& operator=(const CTestA&);

    // 创建友元，需要在模板类访问构造函数
    friend class CSingleton<CTestA>;
};

#endif /* _C_TEST_A_H_ */