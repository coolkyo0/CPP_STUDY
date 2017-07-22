/**
* ��Դ��7_11�����⣬Ϊ��Ū���sizeof(��)�Ĵ�С����μ���ģ�
*
*/
#include <complex>
#include <iostream>
using namespace std;

class Base7_11
{
public:
	Base7_11(){ cout << "Base7_11-ctor" << endl; }
	~Base7_11(){ cout << "Base7_11-dtor" << endl; }
	virtual void f(int){ cout << "Base7_11::f(int)" << endl; }
	virtual void f(double){ cout << "Base7_11::f(double)" << endl; }
	virtual void g(int i = 10){ cout << "Base7_11::g()" << i << endl; }
protected:
private:
};

class Dervied7_11 : public Base7_11
{
public:
	Dervied7_11(){ cout << "Dervied7_11-ctor" << endl; }
	~Dervied7_11(){ cout << "Dervied7_11-dtor" << endl; }
	void f(complex<double> c){ cout << "Dervied7_11::f(complex)" << endl; }

	virtual void g(int i = 20){ cout << "Dervied7_11::g()" << i << endl; }
};

void for7_11()
{

	Base7_11 b;
	Dervied7_11 d;

	Base7_11* pb = new Dervied7_11;

	/**
	* @���� ���еĺ��������麯����ռ��һ���麯����ָ��Ĵ�С���⣬��������һ�ɲ�ռ���ڴ��С��
	* @���� ��Ա������������󣬻�ռ���ڴ棡
	* @���� �����и����⣬�������麯��������Ҳ���麯�����������麯������ͬһ���麯��������
	* @���� ���ܸ������ж����麯�����������ά��һ���麯��������
	*/
	cout << "sizeof(Base7_11) = " << sizeof(Base7_11) << endl;
	cout << "sizeof(Dervied7_11) = " << sizeof(Dervied7_11) << endl;

	
	delete pb;
}