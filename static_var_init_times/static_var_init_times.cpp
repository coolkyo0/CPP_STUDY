// static_var_init_times.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

static int i = 10;


void fun_static_init_1()
{
	i = 1;
}


void fun_static_init_2()
{
	i = 2;
}

int _tmain(int argc, _TCHAR* argv[])
{

	char c = getchar();


	while (true)
	{
		int v;
		scanf_s("%d", &v);

		switch (v)
		{
		case 1:
			printf("you input 1\n");
			break;
		case 2:
			printf("you input 2\n");
			break;
		case 10:

			goto END;

			break;
		default:
			printf("you input %d\n", v);
			break;
		}
	}

END:

	return 0;
}

