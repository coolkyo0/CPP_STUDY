/*
*@	��Demoּ��̽�����õĸ����÷���
*@	1�����ý��պ�����Ա�������ı����õ�ֵ������Ա����Ҳ���ű仯��
*/



/*
*@	stdlib ͷ�ļ���standard library��׼��ͷ�ļ���stdlib.h���涨�����������͡�һЩ���ͨ�ù��ߺ����� ��������size_t��wchar_t��div_t��ldiv_t��lldiv_t�� 
*@	������EXIT_FAILURE��EXIT_SUCCESS��RAND_MAX��MB_CUR_MAX�ȵȣ� ���õĺ�����malloc()��calloc()��realloc()��free()��system()��atoi()��atol()��rand()��srand()��exit()�ȵȡ� 
*@	��������ݿ��Դ򿪱�������includeĿ¼�����stdlib.hͷ�ļ��鿴��
*/
#include <stdlib.h>

/*
*@ ��׼������������磺printf��scanf��getc��getchar��puts��gets�ȵȡ�
*/
#include <stdio.h>




/*
*@	1�����ý��պ�����Ա�������ı����õ�ֵ������Ա����Ҳ���ű仯��
*/
class A
{
public:
	A() : m_nMember1(1), m_nMember2(2)
	{

	}

	int& GetMember1(){ return m_nMember1; }
	int& GetMember2(){ return m_nMember2; }

	void SetMember1(int nParam){ m_nMember1 = nParam; }


private:
	int m_nMember1;
	int m_nMember2;
};


class B
{
public:
	B(){}
	~B(){}

	void SetMember(const A& aObj){ m_aObj = aObj; }

private:
	A m_aObj;
};

int main()
{
	/*
	*	1.�����������ã������÷�����m1��m2���շ���ֵ�����ǵ�m1��m2��ֵ�ı�ʱ��aObj�ĳ�Աm_nMember1��m_nMember2�����Ÿı䡣
	*/
	A aObj1, aObj2;

	int m1 = aObj1.GetMember1();
	int m2 = aObj1.GetMember2();

	m1 = 10;
	m2 = 20;

	/*
	*	1.�����������ã�������qm1��qm2���շ���ֵ����m1��m2��ֵ�ı�ʱ��aObj�ĳ�Աm_nMember1��m_nMember2���Ÿı䡣
	*	2.���GetMember1���ط����ã�������qm1ȥ���ջᱨ��
	*/


	/*
	*@	������̫�ã�˽�г�Ա����������Ķ�
	*/
	int& qm1 = aObj2.GetMember1();		
	int& qm2 = aObj2.GetMember2();

	qm1 = 10;							
	qm2 = 20;


	B bObj1, bObj2;

	bObj1.SetMember(aObj1);
	bObj2.SetMember(aObj2);

	system("pause");
	return 1;
}