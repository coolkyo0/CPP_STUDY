#include "OverLoad.h"

#include <iostream>
using namespace std;

COverLoad::COverLoad()
{
	cout << "Ĭ�Ϲ���" << endl;
}

COverLoad::COverLoad(const COverLoad& col)
{
	if (this != &col)
	{
		a = col.a;
		b = col.b;
	}

	cout << "��������" << endl;
}

COverLoad::COverLoad(int i1, int i2)
{
	a = i1;
	b = i2;
	//cout << "���ι���" << a << ", " << b << endl;
	cout << "���ι���" << endl;
}


COverLoad::~COverLoad()
{
	cout << "��������" << endl;
}

/**
* �ں����������ز�����+
*
* @note ����������ã�return��Ѿֲ�����rt�����÷��س�ȥ��Ȼ��rt�Ǿֲ���������ջ�ϣ��������ں���ִ�й����а����ݸ��������������ֻ�ܷ��ط����á�
* @note ������ط����ã���ֱ���Կ��������ֵ�������յı���
*
*/
COverLoad COverLoad::operator + (const COverLoad& rhs)
{

	/**
	* ����һ
	*
	* @note ����ڷ���������һ�ο������죬rt�����β������죬��rt����ʱҪ�Կ���������ɽ��ն���Ŀ�������Ϊrt����ջ�ϣ������������ڴ�ռ䲻��Ԥ֪�����ݺܿ��ܱ�������ѹջ��ջ�����.
	*/

	COverLoad rt(rhs.a + a, rhs.b + b);	/** ����һ�� */

	 cout << "&rt = " << &rt << endl;


	 return rt;							/** ��rtΪ��������������һ�Σ���ֵ�������ձ��� */


	/**
	* ������
	*
	* @note ����ڷ���һ������һ�ο������죬��Ϊû�����ɾֲ�����rt;
	*/
/*	return COverLoad(rhs.a + a, rhs.b + b);*/
}

COverLoad& COverLoad::operator = (const COverLoad& rhs)
{
	if (this != &rhs)
	{
		a = rhs.a;
		b = rhs.b;
	}

	cout << "��ֵ�����" << endl;

	return *this;
}

COverLoad COverLoad::operator - (const COverLoad& rhs)
{
	return COverLoad(a - rhs.a, b - rhs.b);
}

/**
* ͬ���Ĳ��ܷ������ã�����������ã�����ĵ��ý��������


COverLoad& operator * (COverLoad& c1, COverLoad& c2)
{
	return COverLoad(c1.a * c2.a, c1.b * c2.b);
}



COverLoad o1(1, 2);
COverLoad o2(2, 3);

COverLoad o3 = o1 * o2;

* @�����쳣 return COverLoad(c1.a * c2.a, c1.b * c2.b);�ṹ��һ���������������returnʱ�ͱ������ˣ�
*			����������Ȼ�����ˣ������ص������ֱ�o3���ÿ�������Ĳ����������������ջ�ϣ�ֵ���в���Ԥ֪�ԡ�

* @��� ���ǲ����ܷ������ã������ص���������������Ͳ�ͬʱ�������߻����¹���һ�����󣡣�����
*/
COverLoad operator * (const COverLoad& c1, const COverLoad& c2)
{
	return COverLoad(c1.a * c2.a, c1.b * c2.b);
}

void fun13_3overloadTest()
{
	COverLoad o1(1, 2);
	COverLoad o2(2, 3);

	//COverLoad o3 = o1 + o2;
	//COverLoad o3 = o1 * o2;
	COverLoad o3;
	o3 = o1 - o2;



	cout << "o3 = (" << o3.a << ", " << o3.b << "), &o3 = " << &o3 << endl;
}