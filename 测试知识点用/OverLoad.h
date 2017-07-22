/**
* 学习要点
*
* @要点一 在函数体内实现操作符的加法
* @要点二 在函数体外实现操作符的加法是否与函数体内效果一样呢？
* @see http://www.cnblogs.com/cutepig/archive/2009/01/14/1375930.html
* @answer1 类内重载需要1个参数就可以了，因为类本身也参与运算，也相当于一个参数。
* @answer2 赋值运算符"="是不能在类外重载的。
* @answer3 操作符重载千万别返回引用，因为引用的地址在运算符函数内大多数是栈上的局部变量，值具有不可预知性，所以运算符重载要返回类的对象。
*/

#pragma once
#include <iostream>
using namespace std;

class COverLoad
{
public:
	COverLoad();
	COverLoad(int i1, int i2);
	COverLoad(const COverLoad& col);

	virtual ~COverLoad();

	/**
	* 在函数体内重载操作符+
	*
	*/
	COverLoad operator + (const COverLoad& rhs);

	/**
	* 在函数体内重载赋值操作符 = 
	*/
	COverLoad& operator = (const COverLoad& rhs);

	/**
	* 在函数体内重载赋值操作符 -

	* @note 不管在类内还是在类外重载操作符都不能返回引用啊！！！！！！
	*
	*/
	COverLoad operator - (const COverLoad& rhs);

	int a;
	int b;
};

/**
* 在函数体外重载操作符 =，以实现COverLoad的赋值运算
*
* @note 我们发现，在类外重载赋值操作符时会出现错误提示：必须是成员函数

* @question 在类外可以重载赋值操作符吗？
*/



/**
* 在函数体外重载操作符 *，以实现COverLoad的乘法运算
*
* @NOTE 在类内实现乘法运算符的重载只需要一个参数，而在类外实现乘法运算符的重载需要2个参数
*/
COverLoad operator * (const COverLoad& c1, const COverLoad& c2);

void fun13_3overloadTest();