/**
* ������ҪΪ�˿���C++�а���const�����ó�Ա����ʱ��copy���캯����ʲô���
*
* @���� ���ó�Ա���������������βν��г�ʼ�����������ó�Ա�ſ���ָ���ʼ���Ķ��������int�ͱ�����ʼ������������ջ���γ��βΣ����βγ�ʼ�����ã�����������ʱ����Ա����ָ��ջ��ַ�������ñ�����ֵ��δ����ġ�
*/

#pragma once
class ClassWithQuotaMember
{
public:
	//ClassWithQuotaMember();
	ClassWithQuotaMember(int i, int c, int& q);
	virtual ~ClassWithQuotaMember();

	
	int m_i;
	const int m_ci = 10;
	//const int& m_qi;	// = m_i;
	int &m_ri;	// = m_i;

	
};

void fun13_5classWithQuotaMem();