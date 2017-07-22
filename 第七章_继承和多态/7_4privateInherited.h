/**
* 全面的了解私有继承，
* 当私有继承某个类时，只是想要基类的函数实现，在软件设计时私有继承的类就毫无作用了，只在实现时才有用！
*/

#pragma once

#include <iostream>
using namespace std;

class InheritBase
{
public:
	InheritBase() : m_base(1){}

	int m_base;

	virtual void printMem()
	{
		cout << "printMem, m_base = " << m_base << endl;
	}
};

class PubDerivedBase : public InheritBase
{
public:
	PubDerivedBase() : m_pub(2){}
	int m_pub;

	void printMem()
	{
		cout << "printMem, m_pub = " << m_pub << endl;
	}
};

class PrtDerivedBase : protected InheritBase
{
public:
	PrtDerivedBase() : m_prt(3){}
	int m_prt;

	void printMem()
	{
		cout << "printMem, m_prt = " << m_prt << endl;
	}
};

class PriDerivedBase : private InheritBase
{
public:
	PriDerivedBase() : m_pri(4){}

	int m_pri;

	const void printMem() const
	{
		cout << "printMem, m_pri = " << m_pri << endl;
	}
};

/**
* 指针才有虚函数的多态特性，对象没有多态特性！！！
*/
void stdudyPriInerited()
{
	InheritBase ib;
	PubDerivedBase pubdb;
	PrtDerivedBase prtdb;
	PriDerivedBase pridb;

	InheritBase* pib = NULL;
	

	/** 
	* printMem, m_base = 1
	* 
	* @结论 把派生类对象转化为基类，虚函数也依然执行基类的！
	**/
	ib = (InheritBase)pubdb;
	ib.printMem();

	/**
	* printMem, m_pub = 2
	*
	* @结论 公有派生类对象的指针不需要转化就可以赋值给基类，虚函数调用基类的！
	**/
	pib = &pubdb;
	pib->printMem();


	/**
	* printMem, m_prt = 3
	*
	* @结论 保护派生类对象的指针不可以赋值给基类！编译器会报错。
	**/
	//pib = &prtdb;

	/**
	* printMem, m_pri = 4
	*
	* @结论 私有派生类对象的指针不可以赋值给基类！编译器会报错
	**/
	//InheritBase* pib = &pridb;



}