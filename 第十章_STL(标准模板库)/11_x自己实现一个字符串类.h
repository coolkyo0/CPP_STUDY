/**
* 实现一个字符串类

* @学习 顺便在这个类中探索下const用于函数的作用
*/
#pragma once
#include <iostream>
using namespace std;

class MyString
{
public:
	/**
	* 默认构造函数
	*/
	MyString() : m_str(NULL), m_len(0)
	{
		/** 此行下断点也不会被命中 */
	}
	
	/**
	* 拷贝构造函数
	* @深拷贝
	*/
	MyString(const char* str)
	{
		/** 既然是构造，那么m_str肯定是没有被使用过的内存啦，所以不需要判空了 */
		m_len = strlen(str);
		m_str = new char[m_len + 1];

		strcpy_s(m_str, m_len + 1, str);
	}

	/**
	* 拷贝构造
	* 
	* @深拷贝
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
	* 重载赋值操作符
	*
	* @深拷贝
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
	* 重载赋值操作符
	*
	* @深拷贝
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
	int m_len;		/** 字符串m_str的长度，不包含NULL('\0') */
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