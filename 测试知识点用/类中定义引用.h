/**
* ���������Ƿ���Զ�������
*
* @���� ���ж������û�const���ͱ��������ڳ�ʼ���б��г�ʼ�������������֮ǰ���г�ʼ����
*/
#pragma  once

class ClassWithQuota
{
public:
	ClassWithQuota() : m_q(m_i)
	{

	}
	~ClassWithQuota()
	{

	}

private:
	int m_i;
	int& m_q;
};

void funClassWithQuotaTest()
{
	ClassWithQuota cwq;
}