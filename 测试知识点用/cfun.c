#include "cfun.h"



/**
* .c结尾的文件是没有宏定义__cplusplus的
*/
void print_hello_world()
{
#ifdef __cplusplus
	cout << "define __cplusplus" << endl;
#endif
	printf("Hello World\n");
}

