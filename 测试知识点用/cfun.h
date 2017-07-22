#include <stdio.h>

/**
* extern "C" { } 使C++可以调用C接口
*
*/
#ifdef __cplusplus
extern "C" 
{
#endif

void print_hello_world();

#ifdef __cplusplus
}
#endif