/**
* ������������C/C++���Ա���3.5
* 
* @��Ҫ���������������õ�֪ʶ���Ϊ
*
*/
#include <iostream>

using namespace std;


const float pi = 3.14f;
float f;

float f1(float r)
{
	f = r * r * pi;
	return f;
}

float& f2(float r)
{
	f = r * r * pi;
	return f;
}

void main()
{
	/**
	* û��������2����ʲô�﷨��
	* @f1 ����������Ĭ�ϲ������ã�Ĭ�ϲ���ֵΪ5.
	* @f2 ����������Ĭ�ϲ������ã�Ĭ�ϲ���ֵΪ5.
	*/
	float f1(float = 5);
	float& f2(float = 5);

	float a = f1();
	/** 
	* b�����ã��������ص�ֵ��ջ�ϣ��������ý����ͻ�ʧȥ�������ڣ�������b��ǰ�����������ڱ���ͨ���� 
	* @
	*/
	//float& b = f1();

	float c = f2();
	float& d = f2();

	d += 1.0;

	cout << "a = " << a << endl;
	//cout << "b = " << b << endl;
	cout << "c = " << c << endl;
	cout << "d = " << d << endl;
	cout << "f = " << f << endl;

	system("pause");
}