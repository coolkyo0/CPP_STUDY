/**
* ����ּ��̽��C������struct��class������
* 
* @note <iostream>��C++�еģ�C�����в��ܰ�����
* @note �������ڽṹ��S�ж��幹�캯��ʱ���������ᱨ��˵����C������struct�ǲ����г�Ա�����ģ�ֻ���г�Ա������
* @note C�����ж���ṹ��ĳ�ԱҪ��struct S sa;������typedef��������ʹ��ֱ����S sa;�����壬�������ᱨ��
* @note struct�еĳ�ԱĬ����public
* @note ��C������û��public��protect��private�ؼ��֡�
*
* @note C������û����ĸ�������˱������ᱨ��
*
*
*****/


//#include <iostream>
//using namespace std;


#include <stdlib.h>




struct S
{
	int a;
	// S(){}
	//~S(){}
};


// class C
// {
// public:
// 	C(){}
// 	~C(){}
// 
// private:
// 
// };

void main()
{

	struct S sa;
	sa.a = 10;

}