#include "ClassWithQuotaMember.h"
#include <iostream>
using namespace std;

//m_qi(2)
// ClassWithQuotaMember::ClassWithQuotaMember() : m_i(1), m_ci(2), m_qi(3)
// {
// 
// }

ClassWithQuotaMember::ClassWithQuotaMember(int i, int c, int& q) : m_i(i), m_ci(c), m_ri(q)
{

}


ClassWithQuotaMember::~ClassWithQuotaMember()
{
}

void fun13_5classWithQuotaMem()
{
	int i = 7;
	//int &r = i;
	//ClassWithQuotaMember cwqm1;
	ClassWithQuotaMember cwqm2(4, 5, i);


	//cwqm1 = cwqm2;

	//cout << "cwqm1.m_i = " << cwqm1.m_i << ", cwqm1.m_ci = " << cwqm1.m_ci << ", cwqm1.m_qi = " << cwqm1.m_qi << endl;
	cout << "cwqm2.m_i = " << cwqm2.m_i << ", cwqm2.m_ci = " << cwqm2.m_ci << ", cwqm2.m_ri = " << cwqm2.m_ri << endl;
	/**
	* cwqm1 = cwqm2;
	* 
	* @�������	1	error C2582: ��operator =�������ڡ�ClassWithQuotaMember���в�����
	* @ԭ��			��ΪClassWithQuotaMem�д��ھ�̬��Ա����m_ci1�����Ա����������Զ����ɸ�ֵ�����������û��Լ�����

	* @����취	����һ���Լ�ʵ�� ��ֵ�������������������ø�ֵ������
	*/

}
