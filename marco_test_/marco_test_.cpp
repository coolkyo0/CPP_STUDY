// marco_test_.cpp : 定义控制台应用程序的入口点。
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

