#pragma once
#include <iostream>
using namespace std;

class TestStaticMem
{
public:
	TestStaticMem();
	~TestStaticMem();

	void printMem()
	{
		cout << "m_i = " << m_i << endl;
	}

	static int m_i;

protected:
	int m_ip;
};

void FunTestStatic();

/**
* 不能在声明文件中定义，否则会报下面的错误：
错误	2	error LNK1169: 找到一个或多个多重定义的符号	D:\STUDY\CPP_STUDY\Debug\测试知识点用.exe	1	1	测试知识点用
错误	1	error LNK2005: "public: static int TestStaticMem::m_i" (?m_i@TestStaticMem@@2HA) 已经在 main.obj 中定义	D:\STUDY\CPP_STUDY\测试知识点用\TestStaticMem.obj	测试知识点用


*/
//int TestStaticMem::m_i = 0;





/**
* 探索类成员变量为引用时是如何初始化，在什么时候初始化？
*/


/**
* 静态成员函数不可以同时声明为 virtual、const、volatile函数。举例如下: 为什么呢？
*/