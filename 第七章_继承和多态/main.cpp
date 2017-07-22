/**
* 学习继承和多态的特点
*/
#include "C++类继承的三种关系.h"
#include "中文编程娱乐.h"
#include "7_3.h"
#include "7_4privateInherited.h"
#include "7_6重载是多态吗？.h"
#include "7_5pureVirtualFun.h"
#include "7_6_Q1引用在多态里和指针一样吗.h"
#include "7_11虚函数相关.h"
#include "纯虚函数对类大小的影响.h"
#include "析构函数为虚函数的好处.h"
#include "7_15虚拟继承.h"
#include <iostream>
using namespace std;



void calculate()
{
	int iArr[10];	//4
	char cArr[10];	//4
	char* pStr = "Hello World";	//4

	cout << "sizeof(iArr) = " << sizeof(iArr) << endl;
	cout << "sizeof(cArr) = " << sizeof(cArr) << endl;
	cout << "sizeof(pStr) = " << sizeof(pStr) << endl;

}


void main()
{
	//calculate();
	//for7_6();
	//for7_6Q1();
	//for7_7();
	//for7_9Test();
	//for7_11();
	//for7_17PureFunClassAndSubClassSize();
	//forHappy();
	//forVirtualDestructor();

	fun7_15();
	system("pause");
}

