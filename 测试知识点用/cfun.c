#include "cfun.h"



/**
* .c��β���ļ���û�к궨��__cplusplus��
*/
void print_hello_world()
{
#ifdef __cplusplus
	cout << "define __cplusplus" << endl;
#endif
	printf("Hello World\n");
}

