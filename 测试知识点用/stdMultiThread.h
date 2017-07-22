/**
* 使用std实现一个简单的多线程
*
* @遗留问题 关于std创建线程的一系列操作。

* @结论 多个线程同事操作vector会使程序崩溃
*/
#pragma once
#include <iostream>
#include <thread>
#include <windows.h>
#include <mutex>
#include <vector>

std::mutex mtx;
using namespace std;

// unsigned int counter = 0;
// std::thread thrd_1;
// std::thread thrd_2;
// 
// std::vector<int> intVec;
// int v[3000] = {0};
// 
// 
// void fun1(unsigned int* cnt)
// {
// 	for (int i = 0; i < 3000; i++)
// 	{
// 		(*cnt)++;
// 		//cout << "fun1 cnt = " << *cnt << std::endl;
// 		mtx.lock();
// 		intVec.push_back(*cnt);
// 		mtx.unlock();
// 	}
// }
// 
// void fun2(unsigned int* cnt)
// {
// 	for (int i = 0; i < 3000; i++)
// 	{
// 		(*cnt)++;
// 		//cout << "fun2 cnt = " << *cnt << std::endl;
// 		//Sleep(10);
// 		mtx.lock();
// 		intVec.push_back(*cnt);
// 		mtx.unlock();
// 	}
// 
// }
// 
// 
// void fun13_8multiThread()
// {
// 	//intVec.resize(300);
// 
// 	thrd_1 = thread(fun1, &counter);
// 	thrd_2 = thread(fun2, &counter);
// 
// 	cout << "线程1 id = " << thrd_1.get_id() << endl;
// 	cout << "线程2 id = " << thrd_2.get_id() << endl;
// 
// 	thrd_1.join();
// 	thrd_2.join();
// 	
// 	//cout << "intVec.size() = " << intVec.size() << endl;
// 	//cout << "intVec.capacity() = " << intVec.capacity() << endl;
// 	//cout << "intVec.max_size() = " << intVec.max_size() << endl;
// 	//cout << "counter = " << counter << endl;
// 
// 	//int vsize = intVec.size();
// 	
// 
// 	for (int i : intVec) 
// 	{
// 		cout << "i = " << i << endl;
// 	}
// 
// 	system("pause");
// 	//A13_7_1 b;
// }

/*****************************************************/
void fun3();
void fun4(int);
unsigned int demo2Int = 0;


// void fun3()
// {
// 	while (1)
// 	{
// 		//demo2Int++;
// 		//Sleep(300);
// 		//cout << "fun3 demo2Int = " << demo2Int << endl;
// 		if (demo2Int == 10)
// 		{
// 			//thrd3.detach();
// 		}
// 	}
// }

void fun4(int i)
{
	while (1)
	{
		demo2Int++;
		Sleep(300);
		cout << "fun4 demo2Int = " << demo2Int << endl;

		if (demo2Int == 10)
		{
		}
	}
}

/**
* join函数作用的新发现
* 
* @结论 如果在函数中初始化线程，当函数调用结束而线程没结束，会出现error6010  thread::~thread错误
*/
void fun13_9multiThread2()
{
	//thread thrd3(fun3);
	thread thrd4(fun4, demo2Int);

	thrd4.join();
	//system("pause");
}