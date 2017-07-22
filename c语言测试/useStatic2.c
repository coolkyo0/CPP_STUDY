#include "useStatic1.h"
#include "useStatic2.h"

void useStatic2()
{
	printf("%s, &staticInCommDefine = %p, value = %d\n", __FUNCTION__, &staticInCommDefine, staticInCommDefine);
	printf("%s, &inCommDefine = %p, value = %d\n", __FUNCTION__, &inCommDefine, inCommDefine);

	printf("%s, &use1 = %p, value = %d \n", __FUNCTION__, &use1, use1);
}