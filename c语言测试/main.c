/**
* ̽��static�ѱ����������ڿ�����ģ���ڣ���ôʲô����ģ���أ� ����.c��.cpp��β���ļ�����ģ�顣
*
*
*
*/

#pragma once
#include <stdlib.h>
#include "useStatic1.h"
#include "useStatic2.h"
#include "useStatic3.h"
#include "useStatic4.h"

void main()
{

	useStatic1();
	useStatic2();

	/**
	* .h������ģ�飬��������ͬһ��ͷ�ļ��е�static��������ַ��һ����
	*/
	useStatic3();
	useStatic4();

	/**
	* .c��.cpp������һ��ģ��
	*/
	useStatic5();
	useStatic6();

	system("pause");
}