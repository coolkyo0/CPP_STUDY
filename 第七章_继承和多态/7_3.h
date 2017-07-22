/**
* 类有构造函数后，编译器就不会给类添加默认的构造函数。
*
* @结论 
*/

#pragma once
#include <iostream>
using namespace std;

class Base7_3
{
public:
	/**
	* 当给定了一个带参数的构造函数编译器就不会再生成默认的构造函数了，
	*/
	Base7_3(int x){ i = x; }

	/**
	* 为了防止派生类没有显示调用基类构造函数而调用基类默认构造函数找不到时出错，
	* 我们添加一个默认构造函数，因为当只要类有构造函数时，编译器就不会默认生成构造函数了。
	*/

	Base7_3() : i(0)
	{

	}

	int getI()
	{
		return i;
	}
private:
	int i;
};

class Derived7_3 : public Base7_3
{
public:
	/**
	* 当给定了一个带参数的构造函数编译器就不会再生成默认的构造函数了，
	* 如果不调用基类的构造函数，那么就会调用基类的默认构造函数，但是
	* 基类没有默认构造函数，所以派生类编译通不过
	*/
	
	Derived7_3(int x, int y)
	{
		i = x;
	}
	

	void printTotal ()
	{
		/**
		* 基类的i是私有成员，派生类是无法访问的！！
		* int total = i + Base7_3::i;
		*/
		int total = 0;
		cout << "total = " << total << endl;
	}

	void printI()
	{
		cout << "i = " << getI() << endl;
	}

private:
	/**
	* 疑问：基类已经有该变量，再次定义不会报错吗？
	* @解疑 不会报错，但是子类的i会覆盖基类的i。
	*/
	int i;
};

void for7_3()
{
	//Derived7_3 d;
	//d.printTotal();

	Derived7_3 dd(3, 7);
	dd.printI();
}