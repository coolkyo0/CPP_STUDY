/**
* 本文件是为了检测结构体对齐后的大小
* @遵从三个原则：
* @1，结构体首地址能够被最宽基本类型整除。
* @2，成员的相对于首地址便宜是自身大小的整数倍。
* @3，结构体的大小是最大基本类型的整数倍。
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