/**
* 来源于7_11面试题，为了弄清楚sizeof(类)的大小是如何计算的！
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
	* @结论 类中的函数除了虚函数会占用一个虚函数表指针的大小以外，其它函数一律不占用内存大小！
	* @结论 成员变量属于类对象，会占用内存！
	* @问题 现在有个问题，子类有虚函数，父类也有虚函数，这两个虚函数是在同一个虚函数表中吗？
	* @结论 不管父子类有多少虚函数，父子类均维护一个虚函数表！！！
	*/
	cout << "sizeof(Base7_11) = " << sizeof(Base7_11) << endl;
	cout << "sizeof(Dervied7_11) = " << sizeof(Dervied7_11) << endl;

	
	delete pb;
}