/**
* ������Ҫ��Ϊ�����׺����з���һ������ʱ�Ƿ�ṹ��һ������
*
*/
#include <iostream>
#include <Windows.h>

#include "6_30staticMemAndTemVar.h"
#include "6_31tempVar.h"
#include "6_33funOverload.h"

using namespace std;




class A
{
public:
	A() : m(0)
	{
		print_s("��ͨ���� A() : m(0)");
		cout << "��ͨ���� A() : m(0)" << endl;
	}

	A(const A& a)
	{
		print_s("�������� A(const A& a)");
		cout << "�������� A(const A& a)" << endl;
		m = a.m;
	}



#define TEST

#ifdef TEST

	/**
	* �������ÿ�����һ�ι��캯����ֱ�Ӱ�*this���أ���ô����ֵ�ĺͽ��յĵ�ַ�Ƿ�һ����
	* @�� ����������ã���ô�����ߺ�this��ͬһ������
	*/
	A& operator = (const A& a)
	{
		cout << "��ֵ A& operator = (const A& a)" << endl;
		m = a.m;

		print_s("��ֵ A& operator = (const A& a)");

		//cout << "\t\t\t\t\tthis = " << this << endl;
		return *this;
	}

	void print_s(const int n)
	{
		char ch[100];
		sprintf_s(ch, "m = %d\n", n);
		OutputDebugString(ch);
	}

	void print_s(const char* pcstr)
	{
		char ch[100];
		sprintf_s(ch, "%s\n", pcstr);
		OutputDebugString(ch);
	}

#else
	A& operator = (const A a)
	{
		cout << "A& operator = (const A& a)" << endl;
		m = a.m;

		return *this;
	}
#endif // 1

	~A()
	{
		cout << "���� ~A()" << " m = " << m << endl;
		print_s(m);
		
// 		if (m == 10)
// 		{
// 			int *p = NULL;
// 			*p = 10;
// 		}
	}

	int m;

private:

};

A fun()
{
	A b;		//������ͨ����
	return b;	//���ÿ������췵�أ���aΪ����
}

A& funRtQuote()
{
	A b;		//������ͨ����
	return b;	//���ÿ������췵�أ���aΪ����
}

void fun1()
{
	A a;
}

/**
* ���Է������ú�ɷ�ı䱻���õ�ֵ
*
*/

// #define TEST_1 0
// 
// #if TEST_1
// 	A *gpa = new A;
// 	A fun1()
// 	{
// 		cout << "fun1 ga = " << gpa << endl;
// 		/** ֱ�ӷ���*ga���󣬲�������*ga��Ϊ������һ�����أ������м� */
// 		return *gpa;	//ֻ������һ������
// 	}
// #else
// 	A gpa;
// 	A fun1()
// 	{
// 		return gpa;
// 	}
// #endif






/**
* ���Ժ�������ʱ�Ƿ�ṹ��һ��������з��أ�
* @�� �������������ṹ�췵��һ��������з��ء�
*/
// void Test()
// {
// 	/** ֱ����*ga��Ϊ�������ÿ������캯��������ga��&rtga�ĵ�ַ�ǲ�ͬ�� */
// 	A rtga = fun1();
// 	cout << "&rtga = " << &rtga << endl;
// 
// #if TEST_1
// 	gpa->m = 10;
// #else
// 	gpa.m = 10;
// #endif
// 
// 	cout << "Hello" << endl;
// }



void main()
{
// 	{
// 		A a;
// 		a = fun();
// 
// 		cout << "\t\t\t\t\t&a = " << &a << endl;
// 	}


	/**
	* @note fun�з���ֵ������ֵ�������ã���ô���ܷ���ֵ��û�б������գ�����returnʱ������ÿ������캯��
	*/
	//A a = fun();		
	//a.m = 10;


	/**
	* @note  funRtQuote �з���ֵ�����ص������ã���������ý��գ�return�ǲ�����ÿ������캯����
	*/
	//A& b = funRtQuote();


	/**
	* @note  fun �з���ֵ�����صĲ������ã���������ý��գ�return�����һ���������캯��
	* @note �������ǵĲ�ͣ̽�����Ƿ���return��һ������ù��캯����ָ����ǽ��ձ����Լ���������ֵ��������ʱ�Ų�����ÿ������죡������
	*
	*
	*/
	//A& c = fun();


	//fun1();

	//fun();
	
	//Test();

	

	
	//staticVarAndCopyConstruct(); //6_30

	//temVarWithFun();	//6_31


	//��Ȼ��float��double�Ĵ�С��ģ����
	printBaseClassSize();
	system("pause");
}