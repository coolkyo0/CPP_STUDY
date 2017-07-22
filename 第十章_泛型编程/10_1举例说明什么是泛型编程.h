/**
* ��ʮ�� ������1 ����˵��ʲô�Ƿ��ͱ��
*
*/
#pragma once
#include <iostream>
using namespace std;

template <typename T>		/** typenameҲ������class���� */
T max(T a, T b)
{
	return a > b ? a : b;
}

void fun10_1genericProgramming()
{
	cout << max(1, 2) << endl;				/** ��ʽ����int���͵�max */
	cout << max(1.1f, 2.2f) << endl;		/** ��ʽ����float���͵�max */
	cout << max(1.11l, 2.22l) << endl;		/** ��ʽ����double���͵�max���������l����1.11��2.22��long double */
	cout << max('A', 'C') << endl;			/** ��ʽ����char���͵�max */
	cout << max<int>(1, (int)2.0) << endl;		/** �����ƶ�int���ͣ�2.0�ᱻǿ��ת��������2 */

	/**
	* @char			: 1
	* @short		: 2
	* @int			: 4
	* @long			: 4
	* @long long	: 4��  ****ע��long long��8���ֽڶ�����4���ֽ�
	* @float		: 4
	* @double		: 8
	* @long double	: 8
	*/
	cout << "sizeof(char) = " << sizeof(char) << endl;
	cout << "sizeof(short) = " << sizeof(short) << endl;
	cout << "sizeof(int) = " << sizeof(int) << endl;
	cout << "sizeof(long) = " << sizeof(long) << endl;
	cout << "sizeof(long long) = " << sizeof(long long) << endl;
	cout << "sizeof(float) = " << sizeof(float) << endl;
	cout << "sizeof(double) = " << sizeof(double) << endl;
	cout << "sizeof(long double) = " << sizeof(long double) << endl;
}