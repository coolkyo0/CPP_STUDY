/**
* ���ؼ̳��е�����̳У�����̳еĶ�����
*
* @���� B��C����̳���A��D�̳���B��C��D��һ��ʵ������������A����D����̳�B��C��û�����Ч����
* @���� ֻ�ж������ͬʱ�̳���ͬһ����ʱ����������ͬʱҲ�̳��Զ����ʱ�Ż���Ч����
*/
#pragma once
#include <iostream>
using namespace std;

class A7_15
{
public:
	A7_15()
	{
		cout << "A" << endl;
	}
	~A7_15()
	{

	}
};

class B7_15 : public virtual A7_15
{
public:
	B7_15()
	{
		cout << "B" << endl;
	}
	~B7_15()
	{

	}
};

class C7_15 : virtual public A7_15
{
public:
	C7_15()
	{
		cout << "C" << endl;
	}
	~C7_15()
	{

	}
};

class D7_15 : public B7_15, public C7_15
{
public:
	D7_15() : B7_15(), C7_15()
	{
		cout << "D" << endl;
	}
	~D7_15()
	{

	}
};

void fun7_15()
{
	D7_15 d;
}