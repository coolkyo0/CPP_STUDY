/**
* QQȺ��494052584
*/
#include <stdio.h>
#include <iostream>
using namespace std;

void fun()
{
	float m[10], num, sum = 0, average;
	int i, j;

	for (i = 0; i <= 9; i++)
	{
		//scanf_s("%d", &m[i]);
		scanf_s("%f", &m[i]);
	}
	num = m[0];

	for (i = 0; i <= 9; i++)
	{
		if (num < m[i])
		{
			num = m[i];
			j = i;
		}
	}

	//printf("%f, %c\n", num, j);
	printf("%f, %d\n", num, j);

	for (i = 0; i <= 9; i++)
	{
		sum += m[i];
	}

	average = sum / 10;

	printf("%f\n", average);

	for (i = 0; i <= 9; i++)
	{
		if (m[i] < average)
		{
			//printf("%d\n", m[i]);
			printf("%f\n", m[i]);
		}
	}
}

void printArraySize(int array[])
{
	cout << __FUNCTION__ << " sizeof(array) = " << sizeof(array) << endl;
}

/**
* ̽��sizeof(��������)��sizeof(��������)�Ĵ�С��ϵ
* �²�sizeof(��������) = 4, sizeof(��������) = ��������Ĵ�С������
*
* @���� ����������Ϊ������������ʱ���˻�Ϊָ�룡����
*/
void arraySize()
{
	int a[] = { 1, 2, 3, 4, 5 };
	cout << __FUNCTION__ << " sizeof(a) = " << sizeof(a) << endl;
	printArraySize(a);
}