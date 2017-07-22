#include "A.h"
#include <stdio.h>



A::A()
{
#if STATIC_TEST
	printf("%s stat_param = %d, &stat_param = %p\n", __FILE__, stat_param, &stat_param);
	printf("%s global_param = %d, &global_param = %p\n", __FILE__, global_param, &global_param);
#else
	printf("%s ext_a = %d, &ext_a = %p\n", __FILE__, ext_a, &ext_a);
	printf("%s ext_b = %d, &ext_b = %p\n", __FILE__, ext_b, &ext_b);
#endif
}

A::A(int n, int m)
{
	stat_param = m;
	global_param = n;
}


A::~A()
{
}

void A::_print()
{
	printf("%s stat_param = %d, &stat_param = %p\n", __FILE__, stat_param, &stat_param);
	printf("%s global_param = %d, &global_param = %p\n", __FILE__, global_param, &global_param);
}
