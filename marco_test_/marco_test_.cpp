// marco_test_.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <stdlib.h>

#undef __cplusplus

int _tmain(int argc, _TCHAR* argv[])
{
#ifdef __cplusplus
	printf("__cplusplus = %d\n", __cplusplus);
#else
	printf("__cplusplus not define");
#endif

	system("pause");
	return 0;
}

