/**
* ѧϰ��7.1��
*
* @Ŀ��1 ��������麯��������ĺ������Ǹ���ĺ����������������� 
* @Ŀ��2 protected�������಻�ܴ��游����ɸ���ӿڶ������Ľӿڡ����಻�ܴ��游����ɸ���ӿ���ʲô��˼��
* @Ŀ��3 protected�����಻���Զ�ת���ɸ���ӿ���ʲô��˼��
* @Ŀ��4 ����protected�̳и���ĳ�Ա��������Ա�����������Ƿ���Ȩ�޷��ʡ�
* @Ŀ��5 ������private��һ��ʵ�ּ̳У�
* @Ŀ��6 ������private�̳У����಻�ܴ��游����ɸ��������Ľӿڣ����಻���Զ�ת���ɸ���Ľӿ���ʲô��˼��
* @Ŀ��7 ��������ܷ���ʸ����˽�С�������Ա��
*/

#pragma once

#include <iostream>

using namespace std;

class Base
{
public:
	void printBasePublic(){ cout << "printBasePublic" << endl; }

	/** Ŀ��1 ��������麯��������ĺ������Ǹ���ĺ����������������� */
	void overrideTest(){ cout << "����" << endl; }

	void baseQ4()
	{
		cout << "baseQ4" << endl;
	}

	virtual void baseQ6()
	{
		cout << "Base baseQ6" << endl;
	}

	/**
	* virtual void grammarTest() = 0;
	* @�﷨ ���������ʵ�ָ���Ĵ��麯���ᱨ�﷨����
	*/



	void ��ð�()
	{
		cout << "��ð�" << endl;
	}


protected:
	void printBaseProtectd(){ cout << "printBaseProtectd" << endl; }

	/**
	* @Ŀ��2 protected�������಻�ܴ��游����ɸ���ӿڶ������Ľӿڡ����಻�ܴ��游����ɸ���ӿ���ʲô��˼��
	*
	*/
	virtual void q2()
	{
		cout << "Base q2" << endl;
	}

private:
	/** @Ŀ��7 �����ܷ���ʸ����˽�С�������Ա�� */
	void subclassAccessSupclassPrivate(){ cout << "subclassAccessSupclassPrivate" << endl; }
	int supclassIntMem;
};

class PublicBase : public Base
{
public:
	void for7_1_Q7()
	{
		/**
		* Q7:��������ܷ���ʸ����˽�С�������Ա��
		*
		* @���� public�̳и���ʱ�����ຯ���޷����ʸ����˽�г�Ա�����Է��ʸ����protected
		* @���� subclassAccessSupclassPrivate();	�������
		* @���� supclassIntMem = 10;				�������
		*/
		printBaseProtectd();
	}
protected:
private:
};

class ProtectedDervied : protected Base
{
public:
	void q7()
	{
		/**
		* Ŀ��7�������ܷ���ʸ����˽�С�������Ա��
		*
		* @Ŀ��7���� ���಻�ܷ��ʸ����˽�к��� subclassAccessSupclassPrivate();
		* @Ŀ��7���� ���಻�ܷ��ʸ����˽�б��� supclassIntMem = 10;
		* @Ŀ��7���� ǿ�з��ʻ�����������
		*/
		
		
	}

	/**
	* �����Ǳ����̳��Ը��࣬�����麯��Ҳû������壬��Ϊ����ָ�벻��ָ�����࣬Ҳ�Ͳ����γɶ�̬��
	*
	*
	*/
	virtual void q2()
	{
		cout << "Derived q2" << endl;
	}

	void derived1Q4()
	{
		baseQ4();
	}

	void derviedForQ7()
	{
		/**
		* Q7:��������ܷ���ʸ����˽�С�������Ա��
		*
		* @���� protected�̳и���ʱ�����ຯ���޷����ʸ����˽�г�Ա�����Է��ʸ����protected
		* @���� subclassAccessSupclassPrivate();	�������
		* @���� supclassIntMem = 10;				�������
		*/
		printBaseProtectd();
	}
};
class PrivateDervied : private Base
{
public:
	/** q5 */
	void print()
	{
		printBasePublic();
		printBaseProtectd();
	}

	/** q6 */
	void baseQ6()
	{
		cout << "PrivateDervied" << endl;
	}
};

class A : public ProtectedDervied
{
public:
	void print()
	{
		printBaseProtectd();
		printBasePublic();
	}

	/**
	* Ŀ��1����������麯��������ĺ������Ǹ���ĺ�����������������
	* 
	* @Ŀ��1���� ��������麯�������ຯ�����Ǹ��ຯ�����ᷢ���������
	*
	*/
	void overrideTest(){ cout << "����" << endl; }


};

class B : public PrivateDervied
{
public:
	void print()
	{
		/**
		* printBaseProtectd();
		* printBasePublic();
		* 
		* @���� �������ĺ������丸���˽�г�Ա���������඼�޷����ʸ���˽�г�Ա�����ܳ�Ա����μ̳С��̳��˶��ٴΡ�
		*/
	}
};

void for7_1Q2Q3()
{
	Base b1;
	ProtectedDervied d1;


	Base* pb1 = (Base*)(new ProtectedDervied);			/** ע��C++��ǿ�������ԣ������������ת�� */
	ProtectedDervied* pd1 = (ProtectedDervied*)(new Base);		/** ע��C++��ǿ�������ԣ������������ת�� */


	/**
	* q2:protectd��һ��ʵ�ּ̳У����಻�ܴ��游����ɸ���ӿ�����������Ϊ����ʱ���಻���Զ�ת���ɸ���Ľӿڡ�
	*
	* @���� pb1->q2(); �﷨����ͨ������
	* @��� ����ͨ��protected��ʽ�̳и��࣬�����û���ָ��ָ����ʱ�޷�����ֱ�ӷ��ʸ���ĳ�Ա������ֻ��ͨ���Լ��ĺ�����ӷ��ʣ���Ȼֻ�ܼ�ӷ��ʣ������麯����������ʵ��Ҳ��ûʲô�����ˣ�
	* @��� ����protected��һ��ʵ�ּ̳У�����ֻ�ǵ��ø����ʵ�֣������޷�ͨ���ӿڼ̳иı亯������Ϊ��ʽ��ͬʱҲ���˱��������Ч����
	*
	* q3:���಻���Զ�ת���ɸ���ӿ���ʲô��˼��
	*
	* @��� ���಻��ֱ�ӵ��ø���ӿڡ�
	*/

	pd1->q2();
}

void for7_1Q4()
{
	Base b1;
	ProtectedDervied d1;

	/**
	* q4:����protected�̳и���ĳ�Ա��������Ա�����������Ƿ���Ȩ�޷��ʡ�
	*
	* @��� d1.baseQ4();���뱨�������޷�ֱ�ӷ��ʸ����protected����������ĳ�Ա�������Է��ʡ�
	*/
	b1.baseQ4();

	d1.derived1Q4();
}

void for7_1Q5()
{
	/**
	* q5:������private�̳���һ��ʵ�ּ̳У�
	*
	* @��� ��protected�е����ƣ���ʹ������˽�м̳и��࣬����ĺ�����Ȼ���Է��ʸ���ĺ�������������Ķ�����޷����ʸ�������к����Ͷ����ˡ�---
	* ------������˽�����������������ֱ�ӷ��� pd.printBasePublic(); �򱨱������
	*/
	PrivateDervied pd;
	pd.print();
}

void for7_1Q6()
{
	/**
	* q6 ������private�̳У����಻�ܴ��游����ɸ��������Ľӿڣ����಻���Զ�ת���ɸ���Ľӿ���ʲô��˼��
	*
	* @code Base* b = (PrivateDervied*)(new PrivateDervied);
	* @code pd.baseQ6();
	* 
	* @��� ����Ĵ���ᱨ��PrivateDervied������Base��Base�����麯��baseQ6���������а�æʵ����baseQ6�����ǵ��ø���ָ��bָ������ʱ�����ܷ��ʳ�Ա����baseQ6
	*/
}


void for7_1Q7()
{
	/**
	* q7:��������ܷ���ʸ����˽�С�������Ա��
	*
	* @���� ����Ķ����ܷ��ʣ���������ĺ���ʵ���ǿ��Է��ʵġ�
	*/
}



/**
* һЩ����
*
*
*/
class TestBase
{
public:
	TestBase(int n1, int n2) : m(n1), n(n2)
	{

	}
protected:
	int m;

private:
	int n;
	int getN()
	{
		return n;
	}
};

class DerviedTestBase : private TestBase
{
public:

	DerviedTestBase(int i1, int i2) : TestBase(i1, i2)
	{

	}

	int getTestBaseProMem()
	{
		return m;
	}

	int getTestBasePriMem()
	{
		/**
		* @���� return n; n��˽�в��ɷ���
		* ------return getN(); getN��˽�в��ɷ���
		* @���� �����ܷ���ʸ���ĳ�Ա��̳������޹أ��͸��������Ա�������йأ�����˵�����private�������ǲ�͸���ġ�
		* @���� �����ܷ��ʸ���ı��������Ǹ���ı�����������˵ֻ�ṩ��ʵ�֣������޷�������ж�̬�����и��죬��Ϊprotected���Ǳ�������˼���������࣡������
		*/
		
		
		return m;
	}
protected:


};

void forTestBase()
{
	DerviedTestBase tb(1, 2);

	int rt1 = tb.getTestBaseProMem();
	int rt2 = tb.getTestBasePriMem();

}


void ��()
{
	Base b;
	b.��ð�();
}