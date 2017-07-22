/**
* 本例在与探讨类的静态成员变量存储在哪
*
*
****/

#include <iostream>
#include <stdlib.h>


using namespace std;


#include "A.h"

int b;

void main()
{

	/**
	* 我们通过下面打印全局变量与类静态成员变量地址发现全局变量的地址为
	* 0x00BF324，而类静态成员变量是存储在0x00BF320，这2个地址紧紧相邻，
	* 说明类静态成员变量也是存储在静态区的。
	*/

	cout << "b的地址 = " << &b << endl;				//0x00BF324

	cout << "CA.m的地址 = " << &(CA::m) << endl;	//0x00BF320

	
		

	system("pause");
}