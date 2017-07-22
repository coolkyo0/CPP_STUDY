// static_var_init_time_test.cpp : 定义控制台应用程序的入口点。
//

//static初始化时间的一场测试


#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>



static int i = 10;



int _tmain(int argc, _TCHAR* argv[])
{
	printf("Main.\n");
	printf("%d\n", i);
	i = 100;
	printf("%d\n", i);
	i = 200;
	printf("%d\n", i);
	system("pause");
	return 0;
}

/*
关于静态全局变量的作用于需要进一步写代码验证下

*/

/*
输出：
Main.
10
100
200

结论：静态全局变量可以被多次初始化。


static int i = 10;



int _tmain(int argc, _TCHAR* argv[])
{
printf("Main.\n");
printf("%d\n", i);
i = 100;
printf("%d\n", i);
i = 200;
printf("%d\n", i);
system("pause");
return 0;
}

*/

/*
静态局部变量只在定义时被初始化一次
*/


/*
运行结果为：
Callee.
Main.
Caller.
Caller.
Caller.

结论：static全局变量在编译时就初始化了.

int callee()
{
	printf("Callee.\n");
	return 0;
}

static int i = (callee(), 1);

int caller()
{
	printf("Caller.\n");
	return 0;
}


int _tmain(int argc, _TCHAR* argv[])
{
	printf("Main.\n");
	caller();
	caller();
	caller();

	system("pause");
	return 0;
}

*/


/*

运行结果为：
Main.
Callee.
Caller.
Caller.
Caller.

结论：static局部变量赋值是在运行时进行的.

int callee()
{
	printf("Callee.\n");
	return 0;
}

int caller()
{
	static int i = (callee(), 1);
	printf("Caller.\n");
	return 0;
}


int _tmain(int argc, _TCHAR* argv[])
{
	printf("Main.\n");
	caller();
	caller();
	caller();

	system("pause");
	return 0;
}
*/