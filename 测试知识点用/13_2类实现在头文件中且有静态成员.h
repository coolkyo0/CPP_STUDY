#pragma once
#include <iostream>
using namespace std;

static int i13_2var = 123;

class ClassWithStatic13_2
{
public:
	ClassWithStatic13_2();
	~ClassWithStatic13_2();

	void printMem()
	{
		cout << "m_iMem = " << m_iMem << endl;
	}

	static int m_iMem;

private:

};

/**
* �����������ʵ�ֶ���ͷ�ļ���ʱ��static����������������ʵ��Ҳ��ͷ�ļ���
*/
int ClassWithStatic13_2::m_iMem = 0;

ClassWithStatic13_2::ClassWithStatic13_2()
{
}

ClassWithStatic13_2::~ClassWithStatic13_2()
{
}


void fun13_2classWithStatic()
{
	ClassWithStatic13_2 cw;
	cw.printMem();

	cout << __FILE__ << ", i13_2var = " << i13_2var << endl;
}