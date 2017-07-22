#pragma once

/**
* ������Ҫ̽����ʱ������
* �����е���ʱ������
* return����ʱ�����Ĺ�ϵ��
* ��Ҫ����̽�ֳ����Ч������
*/

#include <iostream>

using namespace std;

class Test
{
public:
	Test() : num(0)
	{
		cout << "Test()\t���캯��" << " m = " << num << endl;
	}
	Test(int number) : num(number)
	{
		cout << "Test(int number)\t���캯��" << " m = " << num << endl;
	}
	Test(const Test& t)
	{
		num = t.num;
		cout << "Test(const Test& t)\t���캯��" << " m = " << num << endl;
	}

	Test& operator = (const Test& t)
	{
		if (&t != this)
		{
			num = t.num;
		}
		cout << "Test& operator =\t��ֵ" << " m = " << num << endl;
		return *this;
	}

	void print()
	{
		cout << "num = " << num << endl;
	}

	~Test()
	{
		cout << "destruct: this = " << this << ", num = " << num << endl;
	}
private:
	int num;
};


void fun1(Test test)
{
	test.print();
}

Test fun2()
{
	Test t(3);		//��ͨ����
	return t;		//��ͨ����
}

/**
* ��ӡ������
*
* @���� num = 1
* @���� destruct: this = , num = 1
* @���� num = 2
* @���� destruct: this = , num = 2
* @���� destruct: this = , num = 3
* @���� destruct: this = , num = 3
* @���� destruct: this = , num = 3
*/
void temVarWithFun()
{
	Test t1(1);		//��ͨ���죬�ȴ��������

	fun1(t1);		//��������
	fun1(2);		//��ͨ����

	t1 = fun2();	//���ø�ֵ������
}