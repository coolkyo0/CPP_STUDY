/**
* ��Demo��ҪĿ��
*
* @Ŀ��1 �˽�ʲô�п������죬ʲô�и�ֵ�����������븳ֵ������
* @Ŀ��2 �˽���Ĭ�ϵĸ�ֵ���������ǳ��������������ָ��ʱ�ȽϺñȽϡ�
*/

#include <iostream>

using namespace std;

class Test
{
	int a;
public:
	Test(){}
	Test(int n) : a(n){}
	/**
	* ΪʲôTest(const Test&t)���ǿ������캯���أ�
	* ��ΪTest a1; Test a2 = a1;�൱��Test a2(a1);
	*
	*/
 	Test(const Test& t)
 	{
		cout << "copy construct" << endl;
 		a = t.a;
 	}

	/**
	* ���ز���������ζ���ģ�
	* @note ����Ϊ���ؿ������캯��Ӧ�������ѽ��
	* @note ����Ӧ�������ظ�ֵ�������ɣ��������캯������ֵ֮���������ʲô��
	* @note �������캯���ǹ��죬���ڹ���һ�������Ժ�Ż�ִ�еĶ�����
	* @note ��ֵ����������ڹ���ʱ�Ķ��������Ƕ����Ѿ�������������и�ֵ�Ĳ�����
	*/
	Test& operator = (const Test& t)			//a = b = c = d;
	{
		cout << "operator =" << endl;
		if (&t != this)
		{
			a = t.a;
		}
		
		return *this;
	}

// 	void operator = (const Test& t)				//a = b = c; ���Ȼ����
// 	{
// 		
// 		if (&t != this)
// 		{
// 			a = t.a;
// 		}
// 	}

	~Test(){}

private:

};

void fun1(Test test)
{
	cout << "fun1..." << endl;
}

Test fun2()
{

	Test t2;
	cout << "fun2..." << endl;
	return t2;
}

/**
* д��������ӡ����ʲô��
* @����1 ʶ���ʲôʱ����ÿ������죬ʲôʱ����ø�ֵ��
* @����2 ����ʲô�п������죬ʲô�и�ֵ��
*
*/
void printIsWhat()
{
	Test t1(1);
	Test t2 = t1;	//���ÿ�������
/*	Test t5(t2);	//���ÿ�������*/

// 	Test t4;
// 	t4 = t2;

	cout << "before fun1()..." << endl;
	fun1(t1);

	Test t3 = fun2();
	cout << "after fun2()..." << endl;
}


/**
* �����к���ָ���Ա����ʱ��Ĭ�ϵĿ������캯���Ƿ��������
* @note C++��Ĭ�ϻ��й��졢�������������졢��ֵ�����ȡ��ַ������Ҳ�̫���ף�Ҳ����int a;int *p = &a;��
*/
class CHavePointer
{
public:
	CHavePointer()
	{
		m_str = NULL;
		m_strLen = 0;
	}
	CHavePointer(const char* str)
	{
		if (str != NULL)
		{
			m_strLen = strlen(str);
			m_str = new char(m_strLen + 1);
			strncpy_s(m_str, m_strLen + 1, str, m_strLen + 1);

			m_use++;
		}
	}

	CHavePointer(CHavePointer& ch)
	{
		m_use++;
		m_str = ch.m_str;
		m_strLen = ch.m_strLen;
	}

	CHavePointer& operator = (CHavePointer& ch)
	{
		m_use++;
		m_str = ch.m_str;
		m_strLen = ch.m_strLen;

		return *this;
	}

	~CHavePointer()
	{
		if (m_use > 0)
		{
			m_use--;
		}
		else
		{
			/** ɾ������ʱ[]������������ǰ�� */
			delete []m_str;
			m_str = NULL;
		}
	}

public:
	char* m_str;
	unsigned int m_strLen;
	static int m_use;
};

int CHavePointer::m_use = 0;

/**
* ��������Ϊ��̽�������д���ָ��ʱ��ϵͳĬ�ϵĿ������캯���븳ֵ�������������ǳ������
*
*/
void deepOrShadowCopy()
{
	CHavePointer var1("Hello World");
	CHavePointer var2 = var1;

	if (var1.m_str == var2.m_str)
	{
		cout << "system default copy construct is shadow copy" << endl;
	}
	else
	{
		cout << "system default copy construct is deep copy" << endl;
	}

	CHavePointer var3;
	var3 = var2;

	if (var3.m_str == var2.m_str)
	{
		cout << "system default assignment is shadow assign" << endl;
	}
	else
	{
		cout << "system default assign is deep assign" << endl;
	}
}


/**
* ����ϵͳĬ�ϵĺ������û��������Ժ�Ͳ����������ˡ�
* @note ��ô�������ˣ� ��Щ���캯����ʹ�ú�Ż����ɻ����ඨ��ʱ��Ĭ�������أ�
*/
class ClassTest
{
public:
	ClassTest(){}
	~ClassTest(){}

private:

};

void printClassSize()
{
	ClassTest t1;
	cout << "sizeof(ClassTest) = " << sizeof(ClassTest) << endl;

	ClassTest t2 = t1;
	cout << "after use default copy construct, sizeof(ClassTest) = " << sizeof(ClassTest) << endl;


	/**
	* �������û�����ݳ�ԱҲû�г�Ա����ʱ����Ĵ�СΪ1��Ϊʲô�أ���Ϊϵͳ����һ���ֽڷ��㶨λ������
	*
	*/
}



int main()
{

	//deepOrShadowCopy();
	
	
	
	//printIsWhat();


	printClassSize();

	system("pause");
	return 0;
}