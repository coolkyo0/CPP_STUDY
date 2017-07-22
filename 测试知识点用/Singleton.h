/**
* ����
*/


////////////////////////////////////////////////
// FileName: singlet.h
// Author: Liulei
// Date: 2011-9-20 15:05
// Description: �����õĵ���ʵ�ֻ���
////////////////////////////////////////////////

#ifndef _SINGLET_H_
#define _SINGLET_H_

#include <memory>

template<class T>
class CSingleT
{
public:

	static T * Instance()
	{
		if (!ms_pObject)
		{
			ms_pObject = new T;
		}
		return ms_pObject;
	}

	static void Create()
	{
		if (!ms_pObject)
		{
			ms_pObject = new T;
		}
	}

	static void Destroy()
	{
		if (ms_pObject)
		{
			delete ms_pObject;
			ms_pObject = NULL;
		}
	}

	static T* Get()
	{
		return ms_pObject;
	}

	static void Reset()
	{
		Destroy();
		Create();
	}

protected:
	static T*	ms_pObject;
};

/**
* @���� ��ʹ����ʼ��ms_pObject���ڱ���ʱҲ���ʼ��λNULL��
*
* @������ Ϊʲô������ ms_pObject�ͻ���ֱ�������أ�
*
*/
template<class T>
T* CSingleT<T>::ms_pObject;// = NULL;



/***************************************************************************/
class A13_1
{
public:
	A13_1()
	{
		/**
		*
		* @���� m_cNum = 10;	
		* @attention ��ĳ�����Ա�����ڹ��캯���г�ʼ����ֵ���������ж���ʱ���߳�ʼ���б����г�ʼ���б�ȶ�����ʼ�������Գ�ʼ���б��е�ֵ�Ḳ�Ƕ���ʱ��ʼ����ֵ��
		*/
	}

	A13_1(int i) : m_cNum(i)			/** const��Ա�����ĳ�ʼ��1����ʼ���б��г�ʼ�����ȶ����ʼ���٣����������ʼ����ֵ�Ḳ�Ƕ���ʱ��ֵ */	
	{

	}

	~A13_1(){}

	static int m_snum;					/** ע�⣺static�������������г�ʼ������Ϊ�ñ����������� */
	const int m_cNum = 2;				/** const��Ա�����ĳ�ʼ��2�������ʱ���ʼ�����ȳ�ʼ���б����� */
	const static int m_csNum = 12;		/** const static��ֵ�����ж���ʱ��ʼ������ʼ��Ч��������С��ı��1��ֻ��ѡ������һ�֣����������ظ���ʼ��������� */
	static const std::string str;
	const static char m_pcstr[m_csNum];	// = "Hello";  ���ܳ�ʼ������������
};

const std::string A13_1::str("123");
/** ���1 *///const int A13_1::m_csNum = 12;				

const char A13_1::m_pcstr[m_csNum] = "Hello World";

/**
* ��̬�ĵ����Ρ�ö�ٳ�Ա����Ҳ���������г�ʼ��
*
*/

/**
* ͨ���ྲ̬��Ա�������������г�ʼ��
*
* @����1 ΪʲôҪ���������г�ʼ����
* @����2 �����������л������������ʼ����
*
* @�ش�1 
* @�ش�2 ����ͷ�ļ���������ʵ���ļ��г�ʼ����  ������ͷ�ļ��г�ʼ����
*/
/*int A13_1::m_i = 0;*/
#endif