#pragma once
#include <iostream>
using namespace std;

class TestStaticMem
{
public:
	TestStaticMem();
	~TestStaticMem();

	void printMem()
	{
		cout << "m_i = " << m_i << endl;
	}

	static int m_i;

protected:
	int m_ip;
};

void FunTestStatic();

/**
* �����������ļ��ж��壬����ᱨ����Ĵ���
����	2	error LNK1169: �ҵ�һ���������ض���ķ���	D:\STUDY\CPP_STUDY\Debug\����֪ʶ����.exe	1	1	����֪ʶ����
����	1	error LNK2005: "public: static int TestStaticMem::m_i" (?m_i@TestStaticMem@@2HA) �Ѿ��� main.obj �ж���	D:\STUDY\CPP_STUDY\����֪ʶ����\TestStaticMem.obj	����֪ʶ����


*/
//int TestStaticMem::m_i = 0;





/**
* ̽�����Ա����Ϊ����ʱ����γ�ʼ������ʲôʱ���ʼ����
*/


/**
* ��̬��Ա����������ͬʱ����Ϊ virtual��const��volatile��������������: Ϊʲô�أ�
*/