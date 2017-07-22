/**
* ����������̳л��࣬����������˽�г�Ա����ʱ����γ�ʼ�������˽�б���
*
* @note д���Demo��ԭ�������ڶ������еĴ���ֻ���̬��
*/
#include <iostream>

using namespace std;

class Base
{
public:
	Base() : i(0)
	{
		cout << "Base()" << endl;
	}
	Base(int n) : i(n)
	{
		cout << "Base(int)" << endl;
	}
	Base(const Base& b) : i(b.i)
	{
		cout << "Base(Base&)" << endl;
	}
	~Base(){}

private:
	int i;
};

class Dervied : public Base
{
public:
	Dervied() : Base(0), j(0)
	{
		cout << "Dervied()" << endl;
	}

	Dervied(int m, int n) : Base(m), j(n)
	{
		cout << "Dervied(int)" << endl;
	}

	/**
	* ������ô�������ǻ���������������������ʼ������Ŀ������캯����������
	*
	*/
	Dervied(Dervied& obj) : Base(obj), j(obj.j)
	{
		cout << "Dervied(Dervied&)" << endl;
	}

private:
	int j;
};


void main()
{
	Base b(1);
	Dervied obj(2, 3);
	cout << "---------------" << endl;
	/** ��ʵ֤������������������ʼ������Ŷ�������������� */
	Dervied d(obj);
	cout << "---------------" << endl;

	system("pause");
}