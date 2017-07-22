/**
* ʵ��һ���ַ�����

* @ѧϰ ˳�����������̽����const���ں���������
*/
#pragma once
#include <iostream>
using namespace std;

class MyString
{
public:
	/**
	* Ĭ�Ϲ��캯��
	*/
	MyString() : m_str(NULL), m_len(0)
	{
		/** �����¶ϵ�Ҳ���ᱻ���� */
	}
	
	/**
	* �������캯��
	* @���
	*/
	MyString(const char* str)
	{
		/** ��Ȼ�ǹ��죬��ôm_str�϶���û�б�ʹ�ù����ڴ��������Բ���Ҫ�п��� */
		m_len = strlen(str);
		m_str = new char[m_len + 1];

		strcpy_s(m_str, m_len + 1, str);
	}

	/**
	* ��������
	* 
	* @���
	*/
	MyString(MyString& mystr)
	{
		if (&mystr != this)
		{
			m_len = mystr.len();
			m_str = new char[m_len + 1];
			strcpy_s(m_str, m_len + 1, mystr.str());
		}
	}

	/**
	* ���ظ�ֵ������
	*
	* @���
	*/
	MyString& operator = (const char* str)
	{
		if (NULL != m_str)
		{
			delete m_str;
		}

		int varStrLen = strlen(str);
		m_str = new char[varStrLen + 1];

		strcpy_s(m_str, varStrLen, str);
		m_len = varStrLen;

		return *this;
	}

	/**
	* ���ظ�ֵ������
	*
	* @���
	*/
	MyString& operator = (MyString& mstr)
	{
		if (&mstr != this)
		{
			if (NULL != m_str)
			{
				delete m_str;
			}

			m_len = mstr.len();
			m_str = new char[m_len + 1];
			strcpy_s(m_str, m_len + 1, mstr.str());
		}

		return *this;
	}

	~MyString()
	{
		if (NULL != m_str)
		{
			delete m_str;
		}
	}

public:
	int len() const
	{
		return m_len;
	}

	const char* str() const
	{
		return m_str;
	}

	void printStr() const
	{
		cout << "(str = " << m_str << ", " << "len = " << m_len << ")" << endl;
	}

private:
	char* m_str;
	int m_len;		/** �ַ���m_str�ĳ��ȣ�������NULL('\0') */
};

void fun11_xTest1()
{
	MyString str1("Hello World");
	MyString str2 = str1;

	str1.printStr();
	str2.printStr();
}

void fun11_xTest2()
{
	MyString str1("Hello World");
	MyString str2;

	str2 = str1;

	str1.printStr();
	str2.printStr();
}