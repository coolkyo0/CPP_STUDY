/**
* ���й��캯���󣬱������Ͳ���������Ĭ�ϵĹ��캯����
*
* @���� 
*/

#pragma once
#include <iostream>
using namespace std;

class Base7_3
{
public:
	/**
	* ��������һ���������Ĺ��캯���������Ͳ���������Ĭ�ϵĹ��캯���ˣ�
	*/
	Base7_3(int x){ i = x; }

	/**
	* Ϊ�˷�ֹ������û����ʾ���û��๹�캯�������û���Ĭ�Ϲ��캯���Ҳ���ʱ����
	* �������һ��Ĭ�Ϲ��캯������Ϊ��ֻҪ���й��캯��ʱ���������Ͳ���Ĭ�����ɹ��캯���ˡ�
	*/

	Base7_3() : i(0)
	{

	}

	int getI()
	{
		return i;
	}
private:
	int i;
};

class Derived7_3 : public Base7_3
{
public:
	/**
	* ��������һ���������Ĺ��캯���������Ͳ���������Ĭ�ϵĹ��캯���ˣ�
	* ��������û���Ĺ��캯������ô�ͻ���û����Ĭ�Ϲ��캯��������
	* ����û��Ĭ�Ϲ��캯�����������������ͨ����
	*/
	
	Derived7_3(int x, int y)
	{
		i = x;
	}
	

	void printTotal ()
	{
		/**
		* �����i��˽�г�Ա�����������޷����ʵģ���
		* int total = i + Base7_3::i;
		*/
		int total = 0;
		cout << "total = " << total << endl;
	}

	void printI()
	{
		cout << "i = " << getI() << endl;
	}

private:
	/**
	* ���ʣ������Ѿ��иñ������ٴζ��岻�ᱨ����
	* @���� ���ᱨ�����������i�Ḳ�ǻ����i��
	*/
	int i;
};

void for7_3()
{
	//Derived7_3 d;
	//d.printTotal();

	Derived7_3 dd(3, 7);
	dd.printI();
}