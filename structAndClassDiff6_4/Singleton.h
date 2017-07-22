#pragma once

#include <iostream>
using namespace std;

/**
* ���������ﳢ�Զ���class��ģ���࣬ΪʲôҪ�����ﶨ��ģ�����أ���Ϊ����˵struct������ģ����������
* @define template<class T> or template<typename T>
***/
template<typename T> class TC1
{
public:
	TC1();
	TC1(T t1);
	~TC1<T>();

	T m1;
	T m2;

	void setValue(T var1, T var2);
	T getMax();

	void print();
private:

};

template<typename T>
void TC1<T>::print()
{
	cout << "class template:" << "m1 = " << m1 << endl;
	cout << "class template:" << "m2 = " << m2 << endl;
}

/**
* Ϊʲôģ���ʵ��Ҫ��template<class T> TC1<T>::TC1() �أ�
* template<class T> TC1::TC1()Ҳ������?
* @note ģ���������ʵ��Ӧ�÷���ͬһ���ļ���������������Ӵ�����Ϊģ����ʹ��ʱ�Ų�������ʵ����
* @note ����	1	error LNK2019: �޷��������ⲿ���� "public: __thiscall TC1<int>::TC1<int>(void)" (??0?$TC1@H@@QAE@XZ)���÷����ں��� "void __cdecl useTemplatePrintMax(void)" (?useTemplatePrintMax@@YAXXZ) �б�����
* @note ģ�庯����ʵ��ʱӦ�ö���Ϊ����ĸ�ʽ��template<class T> TC1<T>::TC(){}  ע�⣬���ܶ���ΪTC1::TC()���������ֱ������error C2955: ��TC1��: ʹ�� �� ģ�� ��Ҫ ģ�� �����б�error C2244: ��TC1<T>::{ctor}��: �޷����������������е�����ƥ��	
*
*/
template<typename T>
TC1<T>::TC1()
{

}

template<class T> TC1<T>::TC1(T t1)
{

}

template<class T> TC1<T>::~TC1()
{

}

template<typename T>
void TC1<T>::setValue(T var1, T var2)
{
	m1 = var1;
	m2 = var2;
}


template<typename T>
T TC1<T>::getMax()
{
	return m1 > m2 ? m1 : m2;
}






/**
* ���������ﳢ�Զ���struct��ģ����
*
***/
template<class T> struct TS1
{
public:
	TS1();
	TS1(T t1);
	~TS1<T>();

	T m1;
	T m2;

	void setValue(T var1, T var2);
	T getMax();

	void print();
private:

};

template<class T>
void TS1<T>::setValue(T var1, T var2)
{
	m1 = var1;
	m2 = var2;
}

template<class T>
void TS1<T>::print()
{
	cout << "struct template:" << "m1 = " << m1 << endl;
	cout << "struct template:" << "m2 = " << m2 << endl;
}

template<class T>
TS1<T>::TS1()
{

}

template<class T> TS1<T>::TS1(T t1)
{

}

template<class T> TS1<T>::~TS1()
{

}


/**
* �������Ƕ���ģ�庯��
*
*
*
*/
template<class T>
void templateFunPrint(T var1, T var2)
{
	cout << "templateFunPrint: var1 = " << var1 << "\tvar2 = " << var2 << endl;
}