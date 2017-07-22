/**
* 验证下重载是否具有多态的特性
*/

#pragma once
#include <iostream>
using namespace std;


class COverloadA
{
public:
	/**
	* 重载
	*/
	void printParVar(int i)
	{
		cout << "u = " << i << endl;
	}

	/**
	* 重载，virtual对于重载毫无意义，因为只有重载函数所属对象的指针才能调用重载函数！
	*/
	virtual void virPrint()
	{
		cout << "Base nothing" << endl;
	}

	/**
	* 覆盖
	*/
	void override()
	{
		cout << "Base override" << endl;
	}
};

class COverloadB : public COverloadA
{
public:
	/**
	* 重载
	*/
	void printParVar(int i, char c)
	{
		cout << "i = " << i << ", c = " << c << endl;
	}

	/**
	* 重载，virtual毫无意义
	*/
	virtual void virPrint(int a)
	{
		cout << "Dervied a = " << a << endl;
	}

	/**
	* 覆盖
	*/
	void override()
	{
		cout << "Dervied override" << endl;
	}
};

void for7_6()
{
	COverloadA coa;
	COverloadB cob;


	/*
	* @结论 当子类有父类的重载函数时，父类指针指向子类，调用重载函数时，依然只是按照函数参数列表来决定调用谁，且父类指针不能调用子类的重载函数！！！
	*/
	COverloadA* pcoa = new COverloadB;
	//pcoa->virPrint(1);	//编译出错
	pcoa->virPrint();

	/**
	* 子类对象的重载函数只能由子类指针来调用，父类指针调用就会出错！！！
	*/
	COverloadB* pcob = new COverloadB;
	pcob->virPrint(1);

	/**
	* 覆盖
	* @结论 基类指针指向子类，调用覆盖函数时竟然调用的是基类函数！！
	* @结论 从狭隘的多态讲，只有虚函数才具有多态的特性！！
	*/
	pcoa->override();
	//pcob->override();


	delete pcoa;
	delete pcob;
}



class JustForHappy
{
public:
	JustForHappy(){ m_mem = 10; }
	JustForHappy(int i) : m_mem(i){}
	~JustForHappy(){}

	/** const对象放在函数后面是为了防止函数修改成员的值 */
	void print() const
	{
		cout << "m_mem = " << m_mem << endl;
	}

	const int& getMem()
	{
		return m_mem;
	}

	const int getMem1()
	{
		return m_mem;
	}
	int m_mem;
};

void forHappy()
{
	JustForHappy jfh;
	jfh.print();

	const int& jfhrt = jfh.getMem();
	int jfhrt1 = jfh.getMem1();
	jfhrt1 = 20;

	cout << "jfhrt = " << jfhrt << endl;
	cout << "jfhrt = " << jfhrt1 << endl;
}