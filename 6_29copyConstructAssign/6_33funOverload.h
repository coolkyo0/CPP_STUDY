#pragma once

#include <iostream>
using namespace std;

extern "C" int overloadFun(int n)
{
	return 0;
}


/**
* extern "C"����C��ʽ���б��룬C�в��������ص�Ȼ�������������
*
*/
extern "C" double overloadFun1(double d)
{
	return 0.1;
}

/**
* float��double���ֽ�
*
*/

void printBaseClassSize()
{
	cout << "sizeof(float) = " << sizeof(float) << endl;
	cout << "sizeof(double) = " << sizeof(double) << endl;
	cout << "sizeof(long) = " << sizeof(long) << endl;
	cout << "sizeof(long long) = " << sizeof(long long) << endl;
}