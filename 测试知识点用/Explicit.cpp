#include "Explicit.h"

#include <iostream>
using namespace std;

Explicit::Explicit()
{
	cout << "Explicit����" << endl;
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
	/** ��ΪExplicit(int)����ʾ���죬���Բ���ֱ�Ӱ�10��ֵ��Explicit���󡣷������ֱ������ */
	Explicit e = Explicit(10);

	cout << "e = " << e.m_i << endl;
}
