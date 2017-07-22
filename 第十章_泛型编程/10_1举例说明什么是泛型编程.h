/**
* 第十章 面试题1 举例说明什么是泛型编程
*
*/
#pragma once
#include <iostream>
using namespace std;

template <typename T>		/** typename也可以用class代替 */
T max(T a, T b)
{
	return a > b ? a : b;
}

void fun10_1genericProgramming()
{
	cout << max(1, 2) << endl;				/** 隐式调用int类型的max */
	cout << max(1.1f, 2.2f) << endl;		/** 隐式调用float类型的max */
	cout << max(1.11l, 2.22l) << endl;		/** 隐式调用double类型的max，数后面加l代表1.11、2.22是long double */
	cout << max('A', 'C') << endl;			/** 隐式调用char类型的max */
	cout << max<int>(1, (int)2.0) << endl;		/** 必须制定int类型，2.0会被强制转换成整形2 */

	/**
	* @char			: 1
	* @short		: 2
	* @int			: 4
	* @long			: 4
	* @long long	: 4×  ****注意long long是8个字节而不是4个字节
	* @float		: 4
	* @double		: 8
	* @long double	: 8
	*/
	cout << "sizeof(char) = " << sizeof(char) << endl;
	cout << "sizeof(short) = " << sizeof(short) << endl;
	cout << "sizeof(int) = " << sizeof(int) << endl;
	cout << "sizeof(long) = " << sizeof(long) << endl;
	cout << "sizeof(long long) = " << sizeof(long long) << endl;
	cout << "sizeof(float) = " << sizeof(float) << endl;
	cout << "sizeof(double) = " << sizeof(double) << endl;
	cout << "sizeof(long double) = " << sizeof(long double) << endl;
}