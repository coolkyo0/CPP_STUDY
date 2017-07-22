/**
* 本文件主要是为了实际敲一下第三章第五节的代码研究下正确性
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
	* 对一个临时变量建立引用会发生错误 
	* 
	* @f1返回的变量在函数调用结束时就释放了，对其建立引用势必会引起语法错误
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