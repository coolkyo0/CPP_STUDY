#pragma once
#include <iostream>

using namespace std;

struct Base7_7
{
public:
	virtual void fun1() = 0;
	virtual void fun2() = 0;
	void print()
	{
		fun1();
		fun2();
	}
};

struct T : private Base7_7
{
public:
	virtual void fun1(){ cout << "T fun1" << endl; }
	virtual void fun2(){ cout << "T fun2" << endl; }

	void useFunc()
	{
		/**
		* ���麯�������ԣ�������ø���ĺ����������е����˴��麯������ô�ú�����ʵ�������������������ú����Ķ�����˭����ִ��˭�ĺ���ʵ�֡�
		*/
		Base7_7::print();
	}
};

void for7_7()
{
	T t;
	t.useFunc();
}