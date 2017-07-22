/**
* ��֤�������Ƿ���ж�̬������
*/

#pragma once
#include <iostream>
using namespace std;


class COverloadA
{
public:
	/**
	* ����
	*/
	void printParVar(int i)
	{
		cout << "u = " << i << endl;
	}

	/**
	* ���أ�virtual�������غ������壬��Ϊֻ�����غ������������ָ����ܵ������غ�����
	*/
	virtual void virPrint()
	{
		cout << "Base nothing" << endl;
	}

	/**
	* ����
	*/
	void override()
	{
		cout << "Base override" << endl;
	}
};

class COverloadB : public COverloadA
{
public:
	/**
	* ����
	*/
	void printParVar(int i, char c)
	{
		cout << "i = " << i << ", c = " << c << endl;
	}

	/**
	* ���أ�virtual��������
	*/
	virtual void virPrint(int a)
	{
		cout << "Dervied a = " << a << endl;
	}

	/**
	* ����
	*/
	void override()
	{
		cout << "Dervied override" << endl;
	}
};

void for7_6()
{
	COverloadA coa;
	COverloadB cob;


	/*
	* @���� �������и�������غ���ʱ������ָ��ָ�����࣬�������غ���ʱ����Ȼֻ�ǰ��պ��������б�����������˭���Ҹ���ָ�벻�ܵ�����������غ���������
	*/
	COverloadA* pcoa = new COverloadB;
	//pcoa->virPrint(1);	//�������
	pcoa->virPrint();

	/**
	* �����������غ���ֻ��������ָ�������ã�����ָ����þͻ��������
	*/
	COverloadB* pcob = new COverloadB;
	pcob->virPrint(1);

	/**
	* ����
	* @���� ����ָ��ָ�����࣬���ø��Ǻ���ʱ��Ȼ���õ��ǻ��ຯ������
	* @���� �������Ķ�̬����ֻ���麯���ž��ж�̬�����ԣ���
	*/
	pcoa->override();
	//pcob->override();


	delete pcoa;
	delete pcob;
}



class JustForHappy
{
public:
	JustForHappy(){ m_mem = 10; }
	JustForHappy(int i) : m_mem(i){}
	~JustForHappy(){}

	/** const������ں���������Ϊ�˷�ֹ�����޸ĳ�Ա��ֵ */
	void print() const
	{
		cout << "m_mem = " << m_mem << endl;
	}

	const int& getMem()
	{
		return m_mem;
	}

	const int getMem1()
	{
		return m_mem;
	}
	int m_mem;
};

void forHappy()
{
	JustForHappy jfh;
	jfh.print();

	const int& jfhrt = jfh.getMem();
	int jfhrt1 = jfh.getMem1();
	jfhrt1 = 20;

	cout << "jfhrt = " << jfhrt << endl;
	cout << "jfhrt = " << jfhrt1 << endl;
}