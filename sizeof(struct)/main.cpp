/**
* ���ļ���Ϊ�˼��ṹ������Ĵ�С
* @�������ԭ��
* @1���ṹ���׵�ַ�ܹ�������������������
* @2����Ա��������׵�ַ�����������С����������
* @3���ṹ��Ĵ�С�����������͵���������
*/


#include <iostream>
#include <stdlib.h>


using namespace std;


/*
//sizeof(A) = 16;
struct A
{
	char a;
	long b;
	long long c;
};


A a, b, c, d;

sizeof(a) = 16;
cout << "sizeof(a)" << sizeof(a) << endl;

cout << "int(&a) = " << int(&a) << endl;
cout << "int(&b) = " << int(&b) << endl;
cout << "int(&c) = " << int(&c) << endl;
cout << "int(&d) = " << int(&d) << endl;

*/



#pragma pack(1)

struct Test
{
	char c;
	short s1;
	short s2;
	int i;
};

void main()
{

	Test t;

	cout << sizeof(t) << endl;

	cout << "&t.c = " << int(&t.c) << endl;
	cout << "&t.s1 = " << int(&t.s1) << endl;
	cout << "&t.s2 = " << int(&t.s2) << endl;
	cout << "&t.i = " << int(&t.i) << endl;

	
	system("pause");
}