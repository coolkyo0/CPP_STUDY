#include "TestStaticMem.h"

/**
* Ϊʲô��̬��Ա��ʼ��һ��Ҫ�����ʵ���ļ��У����ұ��붨�壬�����������Ӵ���

* @���� ���쿴��һ����˵���еľ�̬��Ա��������������仰������ǰһ������Ϊ������ʵ���ļ�����������壬��ô�ͻ����error LINK2001:�޷��������ⲿ���ţ�?mi@TestStaticMem::m_i���ܼ򵥣���������ԭ���������ֻ���������Ҳ���ʵ����ɵġ�
*
*
*
*/
int TestStaticMem::m_i = 0;

TestStaticMem::TestStaticMem()
{
}


TestStaticMem::~TestStaticMem()
{
}



void FunTestStatic()
{
	TestStaticMem ts;
	ts.printMem();
}
