/*
* 继承自Singleton，主要是为了探索 T* CSingleT<T>::ms_pObject = NULL; 的作用
*
* @目的 探索类静态成员的初始化
*
* @结论 
*/
#pragma once
#include "Singleton.h"

#include <iostream>
using namespace std;

class A : public CSingleT<A>
{
public:
	A(){}
	~A(){}

private:

};

void fun13_1CSingleTTest()
{
	cout << "A::Get() = " << A::Get() << endl;
	//A* a = A::Instance();

	cout << "A13_1::m_i = " << A13_1::m_csNum << endl;
	//A13_1::m_i = 1;
	cout << "A13_1::m_i = " << A13_1::m_csNum << endl;

	A13_1 a(20);
	cout << "a.m_cNum = " << a.m_cNum << endl;

	A13_1 b;
	cout << "b.m_cNum = " << b.m_cNum << endl;


	cout << "A13_1::m_pcstr = " << A13_1::m_pcstr << endl;
}