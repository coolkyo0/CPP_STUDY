/**
* @���ڼ�������*��+�����ȼ�
*/

#include <cstdlib>
#include <iostream>


using namespace std;


#define COM_PONTER(p1, p2) if(p1 == p2)	\
{	\
cout << #p1 << " == " <<  #p2;	\
}	\
else \
{	\
	cout << #p1 << " != " << #p2;	\
}	

/*
int arr[4];
int (*parr)[4] = &arr;




(*parr)[0] = 1;
(*parr)[1] = 2;
(*parr)[2] = 3;
(*parr)[3] = 4;


cout << "*parr++ = " << (*parr++)[0] << endl;
cout << "*parr++ = " << (*parr)[1] << endl;

*/

/**
* ָ�������
* @note ++ > *
* @��������Ҫ����һά����ָ�룬str���Ǹ�һά���飬��Ҫ�����
*/
void poniterOperation()
{
	/**
	* str is pointer to array��that is to say: the element of str is char *.
	*/
	char* str[] = { "welcome", "to", "Fortemedia", "China" };

	

	char **p = str + 1;					//p == &str[1]
	str[0] = (*p++) + 2;				//��ǰ�����������p = &str[2]���ڱ���ʱ���������p = &str[1]�� str[0] == &str[1][2] == ""
	COM_PONTER(str[0], &str[1][2])		//�ж�str[0]��&str[1][2]�Ƿ����
	str[1] = *(p + 1);					//p == &str[2],  p + 1 == &str[3], *(p + 1) == str[3] , str[1] == str[2] == str[3] == "china"
	str[2] = p[1] + 3;					//p[1] == str[3], str[3] + 3 == "na"
	str[3] = p[0] + (str[2] - str[1]);	//p[0] == str[2], str[2] + str[3] + 3 - str[3] = str[2] + 3 = "";

	cout << str[0] << endl << str[1] << endl << str[2] << endl << str[3] << endl;
}

/**
* poniterOperation�򻯳�����ĺ����ͷǳ��������
*/
void poniterOperationInt()
{
	int iArr[4] = { 1, 2, 3, 4 };
	int* pInt = iArr;
	cout << *pInt << " " << *(pInt + 1) << " " << *(pInt + 2) << " " << *(pInt + 3) << endl;
}


/**
* ��Ҫ���ڼ�������'+'��'*'�����ȼ�����������ĺ����޷�������ȼ���
* ��Ϊ'++'�ڱ�������ʱ��ֻ�е�ǰ�еļ�������Ż���Ч
*/
void operPrecedence()
{
	char str[] = "Hello World";

	char *p1 = str;
	char *p2 = str;

	char c1 = *p1++;
	char c2 = *(p2++);
}


/**
* ��άָ��++����֤
* @note char** str;ֻ�Ƕ����˸���λָ�룬û��ָ���κοռ�Ҳû�з����κ��ڴ棬 char* str[] = {"hello", "world"};������һ������Ϊ2��ָ�����顣
*/
void twopointer_plusplus()
{
	char* str[] = { "how", "are", "you" };

	cout << "&str[0] = " << &str[0] << endl << "&str[1] = " << &str[1] << endl << "&str[2] = " << &str[2] << endl;

	char** p = str;		//��ά����p++ʱָ����ַ�����һ����"how"->"are"->"you"

	char** p1 = p++;

	cout << "p1 = " << p1 << endl << "p = " << p << endl;

	char* p2 = *p++;

	cout << "&p2 = " << &p2 << endl;
}

int main()
{
	poniterOperationInt();


	//twopointer_plusplus();

	//poniterOperation();

	//operPrecedence();

	system("pause");

	return 0;
}