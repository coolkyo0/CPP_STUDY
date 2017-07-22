#include "OverLoad.h"

#include <iostream>
using namespace std;

COverLoad::COverLoad()
{
	cout << "默认构造" << endl;
}

COverLoad::COverLoad(const COverLoad& col)
{
	if (this != &col)
	{
		a = col.a;
		b = col.b;
	}

	cout << "拷贝构造" << endl;
}

COverLoad::COverLoad(int i1, int i2)
{
	a = i1;
	b = i2;
	//cout << "整形构造" << a << ", " << b << endl;
	cout << "整形构造" << endl;
}


COverLoad::~COverLoad()
{
	cout << "析构函数" << endl;
}

/**
* 在函数体内重载操作符+
*
* @note 如果返回引用，return会把局部变量rt的引用返回出去，然后rt是局部变量，在栈上，很容易在函数执行过程中把数据给冲掉，所以这里只能返回非引用。
* @note 如果返回非引用，会直接以拷贝构造把值赋给接收的变量
*
*/
COverLoad COverLoad::operator + (const COverLoad& rhs)
{

	/**
	* 方法一
	*
	* @note 相对于方法二多了一次拷贝构造，rt是整形参数构造，而rt返回时要以拷贝构造完成接收对象的拷贝，因为rt是在栈上，函数结束后内存空间不可预知，数据很可能被函数的压栈出栈给冲掉.
	*/

	COverLoad rt(rhs.a + a, rhs.b + b);	/** 构造一次 */

	 cout << "&rt = " << &rt << endl;


	 return rt;							/** 以rt为对象做拷贝构造一次，把值赋给接收变量 */


	/**
	* 方法二
	*
	* @note 相对于方法一，少了一次拷贝构造，因为没有生成局部变量rt;
	*/
/*	return COverLoad(rhs.a + a, rhs.b + b);*/
}

COverLoad& COverLoad::operator = (const COverLoad& rhs)
{
	if (this != &rhs)
	{
		a = rhs.a;
		b = rhs.b;
	}

	cout << "赋值运算符" << endl;

	return *this;
}

COverLoad COverLoad::operator - (const COverLoad& rhs)
{
	return COverLoad(a - rhs.a, b - rhs.b);
}

/**
* 同样的不能返回引用，如果返回引用，下面的调用将会出问题


COverLoad& operator * (COverLoad& c1, COverLoad& c2)
{
	return COverLoad(c1.a * c2.a, c1.b * c2.b);
}



COverLoad o1(1, 2);
COverLoad o2(2, 3);

COverLoad o3 = o1 * o2;

* @运算异常 return COverLoad(c1.a * c2.a, c1.b * c2.b);会构造一个对象，这个对象在return时就被析构了，
*			但是引用仍然返回了，而返回的引用又被o3调用拷贝构造的参数，这个参数是在栈上，值具有不可预知性。

* @因此 我们不许不能返回引用，当返回的类型与接收者类型不同时，接收者会重新构造一个对象！！！！
*/
COverLoad operator * (const COverLoad& c1, const COverLoad& c2)
{
	return COverLoad(c1.a * c2.a, c1.b * c2.b);
}

void fun13_3overloadTest()
{
	COverLoad o1(1, 2);
	COverLoad o2(2, 3);

	//COverLoad o3 = o1 + o2;
	//COverLoad o3 = o1 * o2;
	COverLoad o3;
	o3 = o1 - o2;



	cout << "o3 = (" << o3.a << ", " << o3.b << "), &o3 = " << &o3 << endl;
}