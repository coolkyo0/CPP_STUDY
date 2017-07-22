/**
* �˽⹹�캯����Ĭ�Ϲ��캯���ķ���Ȩ��
*
* @���� ��������˹��캯��ȴû�����public����ô��private����Ȩ�ޣ����û���κι��캯����������ϵͳ���ɵĹ��캯������Ȩ����public
*
*/
#pragma once
#include <iostream>
using namespace std;

#include <thread>
#include <mutex>

class A13_7
{
	A13_7(){}
	~A13_7(){}
};

class A13_7_1
{

};

/**
* ��������λprivate�Ƿ����delete obj
* 
* 
*/

class Singleton13_7
{
public:
	/**
	* һ���򵥵��̰߳�ȫ������ʹ��double check��Ҫ�ǳ���Ч�ʿ��ǣ���Ϊ�������Ƚ��˷�cpu
	* 
	* 
	*/
	static Singleton13_7* getInstance()
	{
		if (m_obj == NULL)
		{
			m_mtx.lock();
			if (m_obj == NULL)
			{
				m_obj = new Singleton13_7();
			}
			m_mtx.unlock();
		}

		return m_obj;
	}

	static void destory()
	{
		if (m_obj != NULL)
		{
			m_mtx.lock();
			if (m_obj != NULL)
			{
				delete m_obj;
				m_obj = NULL;
			}
			m_mtx.unlock();
		}
	}


private:
	Singleton13_7(){}
	~Singleton13_7(){}

	static Singleton13_7* m_obj;
	static mutex m_mtx;
};

Singleton13_7* Singleton13_7::m_obj = NULL;
mutex Singleton13_7::m_mtx;



void fun13_7ctor()
{
	Singleton13_7* s = Singleton13_7::getInstance();
	Singleton13_7::destory();

	//delete s;



	system("pause");
}