#pragma once

#include <iostream>
using namespace std;

extern "C" int overloadFun(int n)
{
	return 0;
}


/**
* extern "C"是以C方式进行编译，C中不存在重载当然会出错啦！！！
*
*/
extern "C" double overloadFun1(double d)
{
	return 0.1;
}

/**
* float、double的字节
*
*/

void printBaseClassSize()
{
	cout << "sizeof(float) = " << sizeof(float) << endl;
	cout << "sizeof(double) = " << sizeof(double) << endl;
	cout << "sizeof(long) = " << sizeof(long) << endl;
	cout << "sizeof(long long) = " << sizeof(long long) << endl;
}