/*
Ŀ�ģ������麯�������С��Ӱ�죬���������С��Ӱ�죬��Ա���������С��Ӱ�죬û���κζ����������μ����С�ġ�

���ɣ�
1����ά��һ���麯���������ж���麯��ʱ����Ĵ�Сֻ����4���ֽڡ�
2������û���κγ�Ա����ʱ��ϵͳ���Զ����һ��char�ֽ����Ա������ÿһ������
3�����е���ͨ��Ա��������������Ĵ�С��
4����Ա���������������Ĵ�С��
*/


#include <iostream>

using namespace std;

//sizeof(Base) = 4
class Base
{
public:
	Base(int x) : a(x)
	{

	}

	void print()
	{
		cout << "base" << endl;
	}

private:
	int a;
};

//sizeof(Derived) = 8
class Derived : public Base
{
public:
	Derived(int x) : Base(x - 1), b(x)
	{

	}

	void print()
	{
		cout << "derived" << endl;
	}

private:
	int b;
};

//sizeof(A) = 8
class A
{
public:
	A(int x) : a(x)
	{

	}

	virtual void print()
	{
		cout << "A" << endl;
	}
private:
	int a;
};

//sizeof(B) = 12
class B : public A 
{
public:
	B(int x) : A(x - 1), b(x)
	{

	}
	virtual void print()
	{
		cout << "B" << endl;
	}

private:
	int b;
};




int main()
{
	Base obj1(1);
	cout << "size of Base obj is " << sizeof(obj1) << endl;		//4

	Derived obj2(2);
	cout << "size of Derived obj is " << sizeof(obj2) << endl;	//8

	A a(1);
	cout << "size of A obj is " << sizeof(a) << endl;			//8

	B b(2);
	cout << "size of B obj is " << sizeof(b) << endl;			//12

	system("pause");
}