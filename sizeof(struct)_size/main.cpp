/*
ѧϰĿ�ģ����ݽṹ��������룬����ṹ��Ĵ�С��

����ԭ��
1���ṹ���׵�ַ�����������͵���������
2����Ա����ڽṹ���׵�ַ��ƫ�Ƶ��ڳ�Ա������������������䡣
3���ṹ���ܴ�С�����������͵���������
*/


#include <stdlib.h>
#include <stdio.h>
#include <iostream>

using namespace std;

//4
class A
{
public:
	int i;
};

//1
class B
{ 
public:
	char ch;
};

//8
class C
{
public:
	int i;
	short j;
};

//8
class D
{
public:
	int i;
	short j;
	char ch;
};

//12
class E
{
public:
	int i;
	int ii;
	short j;
	char ch;
	char chr;
};

//16
class F
{
public:
	int i;
	int ii;
	int iii;
	short j;
	char ch;
	char chr;
};



int main()
{
	cout << "sizeof(A) = " << sizeof(A) << endl;	//4
	cout << "sizeof(B) = " << sizeof(B) << endl;	//1
	cout << "sizeof(C) = " << sizeof(C) << endl;	//8
	cout << "sizeof(D) = " << sizeof(D) << endl;	//8
	cout << "sizeof(E) = " << sizeof(E) << endl;	//12
	cout << "sizeof(F) = " << sizeof(F) << endl;	//16

	system("pause");
}