/**
* ��Ҫ���ڲ���һЩͻȻ�뵽���﷨����
*/
#include "���ж�������.h"
#include "���Ը�ֵ������������õĺô�.h"
#include "�̳��Ե�������.h"
#include "TestStaticMem.h"
#include "13_2��ʵ����ͷ�ļ������о�̬��Ա.h"
#include "OverLoad.h"
#include "VarWhenInit.h"
#include "Explicit.h"
#include "ClassWithQuotaMember.h"
#include "TestDtor.h"
#include "���캯����public����private.h"
#include "stdMultiThread.h"
//#include "ClassA_B.h"
#include "�������ض�������ι��췵��ֵ���о�.h"
#include "cppInvokeC.h"
#include "Chain.h"


#include <stdlib.h>
#include <iostream>


// /***************************/
// #include <thread>
// 
// void fun1(unsigned int* cnt)
// {
// 	*cnt++;
// 	cout << "cnt = " << cnt << endl;
// }
// 
// void fun2(unsigned int* cnt)
// {
// 	*cnt++;
// 	cout << "cnt = " << cnt << endl;
// }

/**
* 1 С�ˣ�0 ���
*/
int testEndian()
{
	union Eidian
	{
		unsigned short int arr[2];
		int i;
	};

	Eidian e;
	e.i = 0x1;

	//cout << e.arr[0] << endl;
	//cout << e.arr[1] << endl;

	return (e.arr[0] == 1);
}

class D
{
public:
	void printA()
	{
		cout << "printA" << endl;
	}
	virtual void printB()
	{
		cout << "printB" << endl;
	}
};

void fun_2017_7_1()
{
//	D *d = NULL;
//	d->printA();
//	d->printB();
	D d;
	d.printA();
	d.printB();
}



void main()
{
	//funClassWithQuotaTest();
	//funTestQuotaAdvantage();
	//fun13_1CSingleTTest();

	//TestStaticMem tsm;
	//tsm.printMem();

	//fun13_2classWithStatic();

	//cout << __FILE__ << ", i13_2var = " << i13_2var << endl;

	//FunTestStatic();

	//fun13_3overloadTest();

	//fun13_4whenToInitVar();

	//fun13_4explicitTest();

	//fun13_5classWithQuotaMem();

	//fun13_6systemGenerateDtorCallMemberVarDtor();

	//fun13_7ctor();

	//fun13_8multiThread();

	//fun13_9multiThread2();

	//fun13_9initOrder();

	//fun13_10();

	//cout << testEndian() << endl; 

	//7 =  0x111
	//9 = 0x1001
	//int a = 7 & 9;
	//cout << a << endl;

// #ifdef __cplusplus
// 	cout << "define __cplusplus" << endl;
// #endif

	//fun13_11cppinvokec();

	//fun_13_8_ChainItemChainHeader();

	fun_2017_7_1();
	system("pause");
}