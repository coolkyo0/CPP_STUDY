/**
* ���Ժ������ض�������ε��ù��캯����
*/
#include <iostream>
using namespace std;

class A_13_10
{
public:
	A_13_10();
	A_13_10(const A_13_10& a13)
	{
		cout << "��������" << endl;
	}
	~A_13_10();

private:

};

A_13_10::A_13_10()
{
	cout << "Ĭ�Ϲ��캯��" << endl;
}

A_13_10::~A_13_10()
{
}

A_13_10 getValue(A_13_10 a)
{
	return a;
}

void fun13_10()
{
	A_13_10 a1310;
	/*A_13_10 b = */getValue(a1310);
}