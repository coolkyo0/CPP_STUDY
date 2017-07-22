/*
学习目的：根据结构体变量对齐，计算结构体的大小。

对齐原则：
1，结构体首地址是最宽基本类型的整数倍。
2，成员相对于结构体首地址的偏移等于成员的整数倍，否则补齐填充。
3，结构的总大小是最宽基本类型的整数倍。
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