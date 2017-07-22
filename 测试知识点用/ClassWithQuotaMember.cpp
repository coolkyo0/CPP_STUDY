#include "ClassWithQuotaMember.h"
#include <iostream>
using namespace std;

//m_qi(2)
// ClassWithQuotaMember::ClassWithQuotaMember() : m_i(1), m_ci(2), m_qi(3)
// {
// 
// }

ClassWithQuotaMember::ClassWithQuotaMember(int i, int c, int& q) : m_i(i), m_ci(c), m_ri(q)
{

}


ClassWithQuotaMember::~ClassWithQuotaMember()
{
}

void fun13_5classWithQuotaMem()
{
	int i = 7;
	//int &r = i;
	//ClassWithQuotaMember cwqm1;
	ClassWithQuotaMember cwqm2(4, 5, i);


	//cwqm1 = cwqm2;

	//cout << "cwqm1.m_i = " << cwqm1.m_i << ", cwqm1.m_ci = " << cwqm1.m_ci << ", cwqm1.m_qi = " << cwqm1.m_qi << endl;
	cout << "cwqm2.m_i = " << cwqm2.m_i << ", cwqm2.m_ci = " << cwqm2.m_ci << ", cwqm2.m_ri = " << cwqm2.m_ri << endl;
	/**
	* cwqm1 = cwqm2;
	* 
	* @编译错误	1	error C2582: “operator =”函数在“ClassWithQuotaMember”中不可用
	* @原因			因为ClassWithQuotaMem中存在静态成员变量m_ci1，所以编译器不会自动生成赋值操作符，让用户自己处理。

	* @解决办法	方法一：自己实现 赋值操作符。方法二：不用赋值操作符
	*/

}
