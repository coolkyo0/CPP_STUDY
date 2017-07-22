/**
* ��ʮ�� ������5 ����ʲô��ģ����ػ�
* 
* @���� ��ʵ����ģ��ʱ�����ض����͵�ʵ�ν������⴦����ʵ����һ�������ʵ���汾��
* @���� �����ػ�����ʱ���β�ʹ��ģ��ʱ���������ػ��汾��ģ���ػ���Ϊȫ�ػ���ƫ�ػ�
*/
#pragma once
#include <iostream>
using namespace std;

/**
* �������ػ���ʾ
*
*/
template <class T>
bool isEqual(T t1, T t2)
{
	return t1 == t2;
}

/**
* �����������ģ������棬�����������ᷢ��һϵ�еĴ���
*/
template<>
bool isEqual<char*>(char* t1, char* t2)	/** ����ģ����ػ� */
{
	return strcmp(t1, t2);
}

void fun10_5errorSample()
{
	char str1[] = "Hello1";
	char str2[] = "Hello";
	cout << isEqual(1, 1) << endl;
	cout << isEqual(str1, str2) << endl;	/** ���0 */
}