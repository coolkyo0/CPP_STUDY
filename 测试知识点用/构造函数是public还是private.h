/**
* 了解构造函数、默认构造函数的访问权限
*
* @结论 如果声明了构造函数却没有添加public，那么是private访问权限，如果没有任何构造函数的声明，系统生成的构造函数访问权限是public
*
*/
#pragma once
#include <iostream>
using namespace std;

#include <thread>
#include <mutex>

class A13_7
{
	A13_7(){}
	~A13_7(){}
};

class A13_7_1
{

};

/**
* 析构函数位private是否可以delete obj
* 
* 
*/

class Singleton13_7
{
public:
	/**
	* 一个简单的线程安全单例，使用double check主要是出于效率考虑，因为互斥锁比较浪费cpu
	* 
	* 
	*/
	static Singleton13_7* getInstance()
	{
		if (m_obj == NULL)
		{
			m_mtx.lock();
			if (m_obj == NULL)
			{
				m_obj = new Singleton13_7();
			}
			m_mtx.unlock();
		}

		return m_obj;
	}

	static void destory()
	{
		if (m_obj != NULL)
		{
			m_mtx.lock();
			if (m_obj != NULL)
			{
				delete m_obj;
				m_obj = NULL;
			}
			m_mtx.unlock();
		}
	}


private:
	Singleton13_7(){}
	~Singleton13_7(){}

	static Singleton13_7* m_obj;
	static mutex m_mtx;
};

Singleton13_7* Singleton13_7::m_obj = NULL;
mutex Singleton13_7::m_mtx;



void fun13_7ctor()
{
	Singleton13_7* s = Singleton13_7::getInstance();
	Singleton13_7::destory();

	//delete s;



	system("pause");
}