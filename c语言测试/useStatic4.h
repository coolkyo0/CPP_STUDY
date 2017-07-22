#pragma once
#include <stdio.h>

#include "staticDefine.h"

void useStatic4()
{
	printf("%s, &staticInCommDefine = %p, value = %d \n", __FUNCTION__, &staticInCommDefine, staticInCommDefine);
}