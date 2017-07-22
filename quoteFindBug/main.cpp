/**
* 本程序来自于C/C++面试宝典3.5
* 
* @主要用于熟练掌握引用的知识点而为
*
*/
#include <iostream>

using namespace std;


const float pi = 3.14f;
float f;

float f1(float r)
{
	f = r * r * pi;
	return f;
}

float& f2(float r)
{
	f = r * r * pi;
	return f;
}

void main()
{
	/**
	* 没看懂下面2行是什么语法？
	* @f1 声明函数的默认参数调用，默认参数值为5.
	* @f2 声明函数的默认参数调用，默认参数值为5.
	*/
	float f1(float = 5);
	float& f2(float = 5);

	float a = f1();
	/** 
	* b是引用，函数返回的值在栈上，函数调用结束就会失去生命周期，比引用b提前结束生命周期编译通不过 
	* @
	*/
	//float& b = f1();

	float c = f2();
	float& d = f2();

	d += 1.0;

	cout << "a = " << a << endl;
	//cout << "b = " << b << endl;
	cout << "c = " << c << endl;
	cout << "d = " << d << endl;
	cout << "f = " << f << endl;

	system("pause");
}