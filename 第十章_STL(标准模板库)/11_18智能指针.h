/**
* ��ʮһ�� ������18 ʲô��auto_ptr(STL����ָ��)�����ʹ��
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
* �е�û����Ϊʲô����Ĵ��룬delete�ͷ�char*����ʱ�������쳣��   �������´��
* @fuck ��fuck, new char[num];   new �������Ӧ����[]�����Ŷ�����()����������������������������
* @���� char* str = new char(10);  ���ǳ��ֱ�������



//����Ĵ����Ǵ���������ȷ��Ӧ����  new char[10]
char* str = new char(10);
strcpy_s(str, 10, "123");
delete str;

*/

void fun11_18autoPtr()
{
	auto_ptr<Test> TestPtr(new Test("Terry"));	/** TestPtr����ָ�� */
	TestPtr->showName();
	*TestPtr = "David";
	TestPtr->showName();

	int y = 1;			/** �����쳣��TestPtrָ�������ڴ���Ȼ�ܹ��õ��ͷ� */
	int x = 0;
	y = y / x;
}
