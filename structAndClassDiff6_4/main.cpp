/**
* ��������̽��struct��class������  -----------ע�⣺������ֻ��������C++�е�����
* @note struct�еĳ�Ա�����Լ��̳й�ϵĬ����public����class��Ĭ����private��
* @note struct��class�����Լ̳С�
* @note struct��classһ�������Զ�����˹���/��������ĺ�����
* @note struct��������ģ�塣
*/


/**
* c�����е����������ݲ����ۣ��������ǿ���д�������ǵ�����
* structֻ�Ǹ��ṹ�壬ֻ���б��������г�Ա������
*
*/

#include <iostream>
#include <stdlib.h>
#include <Windows.h>

#include "Singleton.h"
#include "Singleton.cpp"

using namespace std;



struct SA 
{
	int a;
	int b;
public:
	SA()
	{
		OutputDebugString("StructObj construct---------------------------\n");
	}

	virtual ~SA()
	{
		OutputDebugString("StructObj destruct---------------------------\n");
	}

	virtual void _print()
	{
		cout << "SA _print" << endl;
	}

private:

};

struct SB : public SA
{
	SB(){}
	~SB(){}

	virtual void _print()
	{
		cout << "SB _print" << endl;
	}
};

class CA
{

	int a;

public:
	CA(){}
	~CA(){}

	virtual void _print()
	{
		cout << "CA _print" << endl;
	}

private:

};

class CB : public CA
{
public:
	CB(){}
	~CB(){}

	virtual void _print()
	{
		cout << "CB _print" << endl;
	}

private:

};

/**
* struct��class�����Լ̳С�
* struct��classһ�������Զ�����˹���/��������ĺ�����
*
*
*/
void _pointer()
{
	/** struct���Ե��о� */
	SA sa;
	sa.a = 10;

	SB sb;
	sb.a = 10;
	sb.b = 20;


	SA* psa = new SA;
	SB* psb = new SB;

	SA* psat = psb;
	SB* psbt = (SB*)psa;

	cout << "psa - > psb ";
	psat->_print();
	cout << "psb - > psa ";
	psbt->_print();


	/** class���Ե��о� */
	CA* pca = new CA;
	CB* pcb = new CB;

	CA* pcat = pcb;
	CB* pcbt = (CB*)pca;

	cout << "pca - > pcb ";
	pcat->_print();
	cout << "pcb - > pca ";
	pcbt->_print();
}

/** struct�еĳ�Ա����Ĭ����public����class��Ĭ����private */
void memAccessible()
{
	SA sa;
	CA ca;

	sa.a = 10;
	/**
	* sa.a = 10;
	* ���벻����˵��struct�е�aĬ��������ǹ��еġ�
	*/


	/**
	* ca.a = 10;
	* ����������˵��class�е�aĬ���������˽�еġ�
	*
	****/

}

/**
* classģ���ʹ��
* 
* @
*/
void useClassTemplatePrint()
{
	int a = 10;
	int b = 20;

	TC1<int> t;
	t.setValue(a, b);
	t.print();
}

/**
* structģ���ʹ��
* @note C/C++���Դ�ȫ��˵struct����ʹ��ģ�壬��������ʵ���ô������ȷ������ʹ����ģ�尡��������
* @note �����ٴ��Ķ��鼮�����ǵ�֪������˼�ǲ��ܶ���������ģ�壺template<struct T> class TC{}��
*/
void useStructTemplatePrint()
{
	int a = 1;
	int b = 2;

	TS1<int> t;
	t.setValue(a, b);
	t.print();
}




void main()
{



	useClassTemplatePrint();

	useStructTemplatePrint();

	templateFunPrint(1, 2);
	templateFunPrint("123", "456");
	templateFunPrint('A', 'B');
	//_pointer();



	system("pause");
}