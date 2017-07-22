#include <stdio.h>
#include <stdlib.h>
#include "A.h"
#include "B.h"


#if STATIC_TEST

#else
int ext_a = 1;
int ext_b = 2;
#endif

int global = 1;



int callee()
{
	printf("Callee.\n");
	return 1;
}


static int static_int1 = 1;						//在编译时初始化完毕
static int static_int2 = 100 + static_int1;		//在运行时初始化，初始化在Main函数之前

int caller()
{
	
	printf("Caller.\n");
	return 0;
}


void TestFun1()
{
#if STATIC_TEST
	printf("%s stat_param = %d, &stat_param = %p\n", __FILE__, stat_param, &stat_param);
	printf("%s global_param = %d, &global_param = %p\n", __FILE__, global_param, &global_param);
	system("pause");
	stat_param += 1;
	global_param += 1;

	printf("%s stat_param = %d, &stat_param = %p\n", __FILE__, stat_param, &stat_param);
	printf("%s global_param = %d, &global_param = %p\n", __FILE__, global_param, &global_param);

	B b = B(1, 2);
	b._print();
	system("pause");
	A a = A(3, 4);
	a._print();

#else
	printf("%s ext_a = %d, &ext_a = %p\n", __FILE__, ext_a, &ext_a);
	printf("%s ext_b = %d, &ext_b = %p\n", __FILE__, ext_b, &ext_b);
	ext_a += 1;
	ext_b += 2;
	A a;
	B b;


#endif
}

int main()
{

	TestFun1();

	system("pause");
}