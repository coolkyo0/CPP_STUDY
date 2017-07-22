#include "useStatic1.h"

int inCommDefine = 456;

void useStatic1()
{
	staticInCommDefine = 123;
	printf("%s, &staticInCommDefine = %p, value = %d \n", __FUNCTION__, &staticInCommDefine, staticInCommDefine);
	inCommDefine = 654;
	printf("%s, &inCommDefine = %p, value = %d \n", __FUNCTION__, &inCommDefine, inCommDefine);

	use1 = 11;
	printf("%s, &use1 = %p, value = %d \n", __FUNCTION__, &use1, use1);
}