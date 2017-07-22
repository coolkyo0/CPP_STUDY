/**
* �����������Ϊ�麯���ĺô���
*
* @�ô� ������������������麯��������ָ��ָ������ʱ������ָ�룬�������������������ࡣ
* @�ջ� ֻҪ���������������麯���Ϳ����ˣ����������������Ϊ�����������������Ϊ�飬��ô�������ͨ��������ʱ������
* @�ô� ��������������������麯������ô����ָ��ָ�����࣬����ʱֻ��������������������࣬����ںܴ���ڴ�й©���ա�
* @�ջ� �������ָ��ָ�����࣬��ʹ����������Ϊ�飬��ôҲ�������͸��඼�������ˡ�
* @�ջ� ֻ�е�����ָ����Ҫ�ͷ�������Դʱ�Ŷ���������������ֻ��Ҫ�����������������Ϳ����ˣ�����Ҫ������������Ϊ�顣�麯���ή�����ܣ�����Ҫ�þͱ����ˡ�
*/

#pragma once
#include <iostream>
using namespace std;

class DestructorA
{
public:
	DestructorA(){}
	~DestructorA()
	{
		cout << "~DestructorA()" << endl;
	}
};

class DestructorB : public DestructorA
{
public:
	DestructorB(){}
	~DestructorB()
	{
		cout << "~DestructorB()" << endl;
	}
};

class VirtualDestructorA
{
public:
	VirtualDestructorA(){}
	virtual ~VirtualDestructorA()
	{
		cout << "virtual ~VirtualDestructorA()" << endl;
	}
};

class VirtualDestructorB : public VirtualDestructorA
{
public:
	VirtualDestructorB(){}
	virtual ~VirtualDestructorB()
	{
		cout << "virtual ~VirtualDestructorB()" << endl;
	}
};

void forVirtualDestructor()
{
	DestructorA* pda = new DestructorB;
	delete pda;
	pda = NULL;

	VirtualDestructorA* pvda = new VirtualDestructorB;
	delete pvda;
	pvda = NULL;
}