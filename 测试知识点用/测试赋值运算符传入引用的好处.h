/**
* Ū�����ֵ����������뷵�ز������õĺô���
*
* @���� 
*/
#pragma once

#include <iostream>
using namespace std;

#define RT_QUOTA_PAR_NOTQUOTA


class CAssignQuota
{
public:
	int m_test;
	static int ci;
	int temp;
public:
	CAssignQuota()
	{
		ci += 1;
		temp = ci;
		//cout << "Ĭ�Ϲ���, num = " << ci << endl;
		cout << "Ĭ�Ϲ���, num = " << ci << endl;
		m_test = 0;
	}
	CAssignQuota(int par) : m_test(par)
	{
		ci += 1;
		temp = ci;
		m_test = par;
		//cout << "���ι���, num = " << ci << endl;
		cout << "���ι���, num = " << ci << endl;
	}
	CAssignQuota(CAssignQuota& par)
	{
		ci += 1;
		temp = ci;
		if (&par != this)
		{
			m_test = par.m_test;
		}

		//cout << "��ֵ����, this = " << this << ", num = " << ci << endl;
		cout << "��ֵ���죬 num = " << ci << endl;
	}

	~CAssignQuota()
	{
		//cout << "��������, this = " << this << ", num = " << temp << endl;
		cout << "~~~��������, num = " << temp << endl;
	}

	/**
	* 
	* @����ֵ��Ϊ����ʱ��return����*this��Ϊ�������¹���һ������
	*
	*/
	CAssignQuota& operator = (CAssignQuota& par)
	{
		if (&par != this)
		{
			m_test = par.m_test;
		}

		//cout << "����'=', this = " << this << endl;
		return *this;
	}
};
int CAssignQuota::ci = 0;


CAssignQuota printMemberRt(CAssignQuota cqa)
{
	//cout << "cqa = " << &cqa << endl;
	//cout << "m_test = " << cqa.m_test << endl;
	return cqa;
}

void printMember(CAssignQuota& cqa)
{
	//cout << "m_test = " << cqa.m_test << endl;
}

void funTestQuotaAdvantage()
{
	/**
	* CAssignQuota& operator = (CAssignQuota& par)
	* 
	* @����1 ����κͷ���ֵ��Ϊ����ʱ������Ĵ���ִ��2�ι��죺���ι��졢��ֵ����
	* @����2 �����Ϊ���ã�����ֵ��Ϊ����ʱ������Ĵ���ִ��2�ι��죺���ι��졢��ֵ����
	* @����3 ����Ĵ��벻�ᴥ�����صĸ�ֵ��������ֻ�ᴥ�����캯����
	*/
	
//  	CAssignQuota cq1(1);
//  	CAssignQuota cq2 = cq1;
	

	/**
	* CAssignQuota& operator = (CAssignQuota& par)
	*
	* @����1 ����κͷ���ֵ��Ϊ����ʱ������Ĵ���ִֻ��2�ι������ι��졢Ĭ�Ϲ��졢����'='
	* @����2 �����Ϊ���ã�����ֵ��Ϊ����ʱ������Ĵ���ִ��2�ι��죺���ι��졢Ĭ�Ϲ��졢����'='
	* @����3 ��ֵ�ķ���ֵ�Ƿ�Ϊ���þ����ᴥ�����캯����
	* @����4 ����β�Ϊ����ʱ����������ݲ�������"��ֵ����"����һ��һģһ������ʱ����

	* @����1 
	*/

// 	CAssignQuota cq1(1);
// 	CAssignQuota cq2;
// 	cq2 = cq1;

	/**
	* printMember����ʱ������Ƿ�Ϊ���õĺô��о�
	*
	* @���� printMember��β�Ϊ����ʱ������cq1Ϊ������ø�ֵ���캯������һ����ʱ����
	* @���� printMember���Ϊ����ʱ������൱�ڴ���cq1��ָ�롣
	* @
	*/
	
// 	CAssignQuota cq1(1);
// 	printMember(cq1);

	/**
	* printMemberRt����ʱ������뷵��ֵ�Ƿ�Ϊ���õĺô��о�
	*
	* @���� �����Ϊ���á�����ֵ��Ϊ����ʱ������2�ι��캯����1��cq1�Ĺ��졣2����������ֵʱ��cq1����Ϊ������ø�ֵ���졣
	* @���� �����Ϊ���á�����ֵΪ����ʱ������1�ι��캯����1��cq1�Ĺ��졣 ע�����ʹ�õ���cq1�����ã�����ֵҲ��cq1�����á�
	* @���� ����β�Ϊ���á�����ֵΪ����ʱ������2�ι��캯����1��cq1�Ĺ��졣 2����cq1Ϊ������ø�ֵ���캯����Ϊ��Ρ� ע������ֵ�������β���Ϊ���÷��صġ�
	* @���� ����β�Ϊ���á�����ֵ��Ϊ����ʱ������3�ι��캯����1��cq1�Ĺ��졣2����cq1Ϊ������ø�ֵ���캯����Ϊ��Ρ�3�����β�Ϊ������ø�ֵ���캯�����ء�
	*/
// 	CAssignQuota cq1(1);
// 	cout << "cq1 = " << &cq1 << endl;
// 	printMemberRt(cq1);



	/**
	* printMemberRt����ʱ������뷵��ֵ�Ƿ�Ϊ���õĺô��о�
	*
	* @���� ����β�Ϊ���á�����ֵ��Ϊ����ʱ������3�ι��캯����1��cq1�Ĺ��졣2����������ֵʱ��cq1����Ϊ������ø�ֵ���졣3��cq2�Ĺ��졣
	* @���� ����Ρ�����ֵ����Ϊ����ʱ�����۷���ֵ��û�б������գ�����ʱ������ø�ֵ���캯������һ�����󣬲�����������Ƿ��ж�����գ�����ж�����գ������������ľ��ǵ��ø�ֵ������ա�

// 	* @���� �����Ϊ���á�����ֵΪ����ʱ������1�ι��캯����1��cq1�Ĺ��졣 ע�����ʹ�õ���cq1�����ã�����ֵҲ��cq1�����á�
// 	* @���� ����β�Ϊ���á�����ֵΪ����ʱ������2�ι��캯����1��cq1�Ĺ��졣 2����cq1Ϊ������ø�ֵ���캯����Ϊ��Ρ� ע������ֵ�������β���Ϊ���÷��صġ�
// 	* @���� ����β�Ϊ���á�����ֵ��Ϊ����ʱ������3�ι��캯����1��cq1�Ĺ��졣2����cq1Ϊ������ø�ֵ���캯����Ϊ��Ρ�3�����β�Ϊ������ø�ֵ���캯�����ء�
	*/
// 	CAssignQuota cq1(1);
// 	CAssignQuota cq2 = printMemberRt(cq1);



	/**
	* printMemberRt
	* @���� ��η���ֵ����Ϊ����ʱ��ϵͳ��������ι��죬����ι���ֱ���
	* @1��	cq1 ���ι���	CAssignQuota cq1(1);
	* @2��	cq2 Ĭ�Ϲ���	CAssignQuota cq2;
	* @3��	��cq1���ø�ֵ��������һ��������Ϊ��� printMemberRt(cq1);
	* @4��	returnʱ�Ե����ι���Ķ���Ϊ�������ø�ֵ�������ɶ��󷵻�
	* @5��	��ֵ�����������ģ��ܹ��찡�������صĸ�ֵ�����û�з������ã�����ʱ�ṹ��һ������
	*/
	CAssignQuota cq1(1);
	//CAssignQuota cq2;
	printMemberRt(cq1);



// 	CAssignQuota cq1(1);
// 	CAssignQuota cq2 = printMemberRt(cq1);









// 	CAssignQuota cq1;
// 	CAssignQuota cq2;
// 	cq2 = printMemberRt(cq1);








	//cout << "&cq1 = " << &cq1 << endl;
	//cout << "&cq2 = " << &cq2 << endl;
}