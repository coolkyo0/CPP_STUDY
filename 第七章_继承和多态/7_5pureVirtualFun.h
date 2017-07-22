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
		* 纯虚函数的特性：子类调用父类的函数，函数中调用了纯虚函数，那么该函数的实现由子类来决定，调用函数的对象是谁，就执行谁的函数实现。
		*/
		Base7_7::print();
	}
};

void for7_7()
{
	T t;
	t.useFunc();
}