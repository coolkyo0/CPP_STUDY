/**
* 第十章 面试题5 解释什么是模板的特化
* 
* @定义 在实例化模板时，对特定类型的实参进行特殊处理，即实例化一个特殊的实例版本，
* @定义 当以特化定义时的形参使用模板时，将调用特化版本，模板特化分为全特化和偏特化
*/
#pragma once
#include <iostream>
using namespace std;

/**
* 函数的特化演示
*
*/
template <class T>
bool isEqual(T t1, T t2)
{
	return t1 == t2;
}

/**
* 必须放在上面模板的下面，如果放在上面会发生一系列的错误
*/
template<>
bool isEqual<char*>(char* t1, char* t2)	/** 函数模板的特化 */
{
	return strcmp(t1, t2);
}

void fun10_5errorSample()
{
	char str1[] = "Hello1";
	char str2[] = "Hello";
	cout << isEqual(1, 1) << endl;
	cout << isEqual(str1, str2) << endl;	/** 输出0 */
}