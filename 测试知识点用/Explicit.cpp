#include "Explicit.h"

#include <iostream>
using namespace std;

Explicit::Explicit()
{
	cout << "Explicit构造" << endl;
}

Explicit::Explicit(int i)
{
	m_i = i;
}


Explicit::~Explicit()
{
}

void fun13_4explicitTest()
{
	/** 因为Explicit(int)是显示构造，所以不能直接把10赋值给Explicit对象。否则会出现编译错误 */
	Explicit e = Explicit(10);

	cout << "e = " << e.m_i << endl;
}
