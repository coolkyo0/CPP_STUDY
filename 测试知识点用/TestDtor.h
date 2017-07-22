/**
* 主要是为了检测系统生成的析构函数是否会调用成员变量的析构函数
*
* @结论 即使是系统自动生成的析构函数也会调用类成员的析构函数。
*/
#pragma once
#include <iostream>
using namespace std;

class A13_6
{
public:
	A13_6();
	~A13_6();

private:

};

class TestDtor
{
public:
	TestDtor();

	A13_6 m_a;
};


void fun13_6systemGenerateDtorCallMemberVarDtor();