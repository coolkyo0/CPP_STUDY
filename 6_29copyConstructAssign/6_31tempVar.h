#pragma once

/**
* 本例主要探讨临时变量，
* 变量中的临时变量，
* return与临时变量的关系，
* 主要是想探讨程序的效率问题
*/

#include <iostream>

using namespace std;

class Test
{
public:
	Test() : num(0)
	{
		cout << "Test()\t构造函数" << " m = " << num << endl;
	}
	Test(int number) : num(number)
	{
		cout << "Test(int number)\t构造函数" << " m = " << num << endl;
	}
	Test(const Test& t)
	{
		num = t.num;
		cout << "Test(const Test& t)\t构造函数" << " m = " << num << endl;
	}

	Test& operator = (const Test& t)
	{
		if (&t != this)
		{
			num = t.num;
		}
		cout << "Test& operator =\t赋值" << " m = " << num << endl;
		return *this;
	}

	void print()
	{
		cout << "num = " << num << endl;
	}

	~Test()
	{
		cout << "destruct: this = " << this << ", num = " << num << endl;
	}
private:
	int num;
};


void fun1(Test test)
{
	test.print();
}

Test fun2()
{
	Test t(3);		//普通构造
	return t;		//普通构造
}

/**
* 打印的内容
*
* @内容 num = 1
* @内容 destruct: this = , num = 1
* @内容 num = 2
* @内容 destruct: this = , num = 2
* @内容 destruct: this = , num = 3
* @内容 destruct: this = , num = 3
* @内容 destruct: this = , num = 3
*/
void temVarWithFun()
{
	Test t1(1);		//普通构造，等待最后析构

	fun1(t1);		//拷贝构造
	fun1(2);		//普通构造

	t1 = fun2();	//调用赋值操作符
}