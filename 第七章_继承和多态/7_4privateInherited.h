/**
* ȫ����˽�˽�м̳У�
* ��˽�м̳�ĳ����ʱ��ֻ����Ҫ����ĺ���ʵ�֣���������ʱ˽�м̳е���ͺ��������ˣ�ֻ��ʵ��ʱ�����ã�
*/

#pragma once

#include <iostream>
using namespace std;

class InheritBase
{
public:
	InheritBase() : m_base(1){}

	int m_base;

	virtual void printMem()
	{
		cout << "printMem, m_base = " << m_base << endl;
	}
};

class PubDerivedBase : public InheritBase
{
public:
	PubDerivedBase() : m_pub(2){}
	int m_pub;

	void printMem()
	{
		cout << "printMem, m_pub = " << m_pub << endl;
	}
};

class PrtDerivedBase : protected InheritBase
{
public:
	PrtDerivedBase() : m_prt(3){}
	int m_prt;

	void printMem()
	{
		cout << "printMem, m_prt = " << m_prt << endl;
	}
};

class PriDerivedBase : private InheritBase
{
public:
	PriDerivedBase() : m_pri(4){}

	int m_pri;

	const void printMem() const
	{
		cout << "printMem, m_pri = " << m_pri << endl;
	}
};

/**
* ָ������麯���Ķ�̬���ԣ�����û�ж�̬���ԣ�����
*/
void stdudyPriInerited()
{
	InheritBase ib;
	PubDerivedBase pubdb;
	PrtDerivedBase prtdb;
	PriDerivedBase pridb;

	InheritBase* pib = NULL;
	

	/** 
	* printMem, m_base = 1
	* 
	* @���� �����������ת��Ϊ���࣬�麯��Ҳ��Ȼִ�л���ģ�
	**/
	ib = (InheritBase)pubdb;
	ib.printMem();

	/**
	* printMem, m_pub = 2
	*
	* @���� ��������������ָ�벻��Ҫת���Ϳ��Ը�ֵ�����࣬�麯�����û���ģ�
	**/
	pib = &pubdb;
	pib->printMem();


	/**
	* printMem, m_prt = 3
	*
	* @���� ��������������ָ�벻���Ը�ֵ�����࣡�������ᱨ��
	**/
	//pib = &prtdb;

	/**
	* printMem, m_pri = 4
	*
	* @���� ˽������������ָ�벻���Ը�ֵ�����࣡�������ᱨ��
	**/
	//InheritBase* pib = &pridb;



}