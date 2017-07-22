/**
* ��ʮ�� ������7 ʹ�ú���ģ�����ͨ�������з��ͻ�
*
*/
#pragma once
#include <iostream>
using namespace std;

// const int* find1(const int* array, int n, int x)
// {
// 	const int* p = array;
// 	for (int i = 0; i < n; i++)
// 	{
// 		if (*p == x)
// 		{
// 			return p;
// 		}
// 		++p;
// 	}
// 	return 0;
// }

template <class T>
const T* find1(const T* array, int n, T x)
{
	const T* p = array;
	for (int i = 0; i < n; i++)
	{
		if (*p == x)
		{
			return p;
		}
		++p;
	}
	return 0;
}

void fun10_7genericFunction()
{
	int intArr[] = { 1, 2, 3, 4, 5, 6, 7 };
	double doubleArr[] = { 1.1, 2.2, 3.3, 4.4, 5.5, 6.6 };
	const int* p = find1(intArr, 6, 6);		/** ������������в��� */
	cout << *p << endl;

	const double* q = find1(doubleArr, 6, 6.6);	/** �Ը������������в��� */
	cout << *q << endl;
}