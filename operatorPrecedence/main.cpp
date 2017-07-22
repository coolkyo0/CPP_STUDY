/**
* @用于检测运算符*和+的优先级
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
* 指针的运算
* @note ++ > *
* @本例子主要考察一维数组指针，str就是个一维数组，不要搞错了
*/
void poniterOperation()
{
	/**
	* str is pointer to array，that is to say: the element of str is char *.
	*/
	char* str[] = { "welcome", "to", "Fortemedia", "China" };

	

	char **p = str + 1;					//p == &str[1]
	str[0] = (*p++) + 2;				//当前行运算结束后p = &str[2]，在本行时参与运算的p = &str[1]， str[0] == &str[1][2] == ""
	COM_PONTER(str[0], &str[1][2])		//判断str[0]余&str[1][2]是否相等
	str[1] = *(p + 1);					//p == &str[2],  p + 1 == &str[3], *(p + 1) == str[3] , str[1] == str[2] == str[3] == "china"
	str[2] = p[1] + 3;					//p[1] == str[3], str[3] + 3 == "na"
	str[3] = p[0] + (str[2] - str[1]);	//p[0] == str[2], str[2] + str[3] + 3 - str[3] = str[2] + 3 = "";

	cout << str[0] << endl << str[1] << endl << str[2] << endl << str[3] << endl;
}

/**
* poniterOperation简化成下面的函数就非常好理解了
*/
void poniterOperationInt()
{
	int iArr[4] = { 1, 2, 3, 4 };
	int* pInt = iArr;
	cout << *pInt << " " << *(pInt + 1) << " " << *(pInt + 2) << " " << *(pInt + 3) << endl;
}


/**
* 主要用于检测运算符'+'和'*'的优先级，但是下面的函数无法检测优先级，
* 因为'++'在变量后面时，只有当前行的计算结束才会生效
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
* 二维指针++的验证
* @note char** str;只是定义了个二位指针，没有指向任何空间也没有分配任何内存， char* str[] = {"hello", "world"};定义了一个容量为2的指针数组。
*/
void twopointer_plusplus()
{
	char* str[] = { "how", "are", "you" };

	cout << "&str[0] = " << &str[0] << endl << "&str[1] = " << &str[1] << endl << "&str[2] = " << &str[2] << endl;

	char** p = str;		//二维数组p++时指向的字符串会一次由"how"->"are"->"you"

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