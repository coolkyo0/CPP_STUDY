// static_var_init_time_test.cpp : �������̨Ӧ�ó������ڵ㡣
//

//static��ʼ��ʱ���һ������


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
���ھ�̬ȫ�ֱ�������������Ҫ��һ��д������֤��

*/

/*
�����
Main.
10
100
200

���ۣ���̬ȫ�ֱ������Ա���γ�ʼ����


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
��̬�ֲ�����ֻ�ڶ���ʱ����ʼ��һ��
*/


/*
���н��Ϊ��
Callee.
Main.
Caller.
Caller.
Caller.

���ۣ�staticȫ�ֱ����ڱ���ʱ�ͳ�ʼ����.

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

���н��Ϊ��
Main.
Callee.
Caller.
Caller.
Caller.

���ۣ�static�ֲ�������ֵ��������ʱ���е�.

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