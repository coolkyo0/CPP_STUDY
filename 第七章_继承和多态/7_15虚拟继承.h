/**
* 多重继承中的虚拟继承，解决继承的二义性
*
* @结论 B、C虚拟继承自A，D继承自B、C，D的一个实例不会包含多个A，而D虚拟继承B、C则没有这个效果，
* @结论 只有多个基类同时继承自同一个类时，当派生类同时也继承自多个类时才会起效果。
*/
#pragma once
#include <iostream>
using namespace std;

class A7_15
{
public:
	A7_15()
	{
		cout << "A" << endl;
	}
	~A7_15()
	{

	}
};

class B7_15 : public virtual A7_15
{
public:
	B7_15()
	{
		cout << "B" << endl;
	}
	~B7_15()
	{

	}
};

class C7_15 : virtual public A7_15
{
public:
	C7_15()
	{
		cout << "C" << endl;
	}
	~C7_15()
	{

	}
};

class D7_15 : public B7_15, public C7_15
{
public:
	D7_15() : B7_15(), C7_15()
	{
		cout << "D" << endl;
	}
	~D7_15()
	{

	}
};

void fun7_15()
{
	D7_15 d;
}