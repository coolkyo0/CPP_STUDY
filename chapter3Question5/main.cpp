/**
* ���ļ���Ҫ��Ϊ��ʵ����һ�µ����µ���ڵĴ����о�����ȷ��
*/

#include <iostream>
#include <stdlib.h>

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
	float f1(float = 5);
	float& f2(float = 5); 

	float a = f1();

	/**
	* ��һ����ʱ�����������ûᷢ������ 
	* 
	* @f1���صı����ں������ý���ʱ���ͷ��ˣ����佨�������Ʊػ������﷨����
	* @!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	*/
	//float& b = f1();		

	float c = f2();
	float& d = f2();

	d += 1.0f;

	cout << "a = " << a << endl;
	//cout << "b = " << b << endl;
	cout << "c = " << c << endl;
	cout << "d = " << d << endl;
	cout << "f = " << f << endl;
	
	system("pause");
}