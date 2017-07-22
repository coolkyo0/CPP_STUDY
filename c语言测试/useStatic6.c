#pragma once
#include <stdio.h>

#include "staticDefine.h"
#include "useStatic1.h"

void useStatic6()
{
	printf("%s, &staticInCommDefine = %p, value = %d \n", __FUNCTION__, &staticInCommDefine, staticInCommDefine);
}