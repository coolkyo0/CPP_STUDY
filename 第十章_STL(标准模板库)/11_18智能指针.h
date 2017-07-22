/**
* 第十一章 面试题18 什么是auto_ptr(STL智能指针)？如何使用
*
*/
#pragma once
#include <iostream>
#include <string>
#include <memory>
#include <windows.h>
using namespace std;

class Test
{
public:
	Test(){ name = NULL; }
	Test(const char* strname)
	{
		if (NULL != strname)
		{
			name = new char[strlen(strname) + 1];
			strcpy_s(name, strlen(strname) + 1, strname);
		}
	}
	Test& operator = (const char* namestr)
	{
		if (NULL != name)
		{
			delete name;
		}

		if (NULL != namestr)
		{
			name = new char[strlen(namestr) + 1];
			strcpy_s(name, strlen(namestr) + 1, namestr);
		}

		return *this;
	}

	void showName()
	{
		cout << name << endl;
	}

	~Test()
	{
		if (NULL != name)
		{
			delete name;
		}

		name = NULL;

		cout << "destructor ~Test()" << endl;
		OutputDebugString(L"StructObj construct---------------------------\n");
	}

	char* name;
};

/**
* 有点没看懂为什么下面的代码，delete释放char*数组时会引发异常？   网上搜下答案喽
* @fuck ，fuck, new char[num];   new 数组后面应该是[]中括号而不是()！！！！！！！！！！！！！！
* @所以 char* str = new char(10);  总是出现崩溃现象



//下面的代码是错误范例，正确的应该是  new char[10]
char* str = new char(10);
strcpy_s(str, 10, "123");
delete str;

*/

void fun11_18autoPtr()
{
	auto_ptr<Test> TestPtr(new Test("Terry"));	/** TestPtr智能指针 */
	TestPtr->showName();
	*TestPtr = "David";
	TestPtr->showName();

	int y = 1;			/** 产生异常，TestPtr指向对象的内存仍然能够得到释放 */
	int x = 0;
	y = y / x;
}
