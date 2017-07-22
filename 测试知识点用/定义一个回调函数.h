/**
* 定义一个回调函数
*/
#pragma once

typedef void (__stdcall *CALLBACKFUN)(int a, int b);


/**
* 为什么windows使用stdcall调用约定

你是想问为啥Windows C++中全是stdcall或WINAPI，而不是cdecl的calling convention吧？原因简单直接，生成执行码的大小。
WINAPI就是stdcall的一个宏定义，其实是一回事。stdcall约定是被调用者清栈，返回时指令带一个退栈参数就可以了，被调用者自己一句ret n就完事了。
cdecl约定是调用者清栈，就是每一个调用者在函数调用完成后，要每一个调用者自己去拉esp把栈状况改回来。
stdcall的缺点就是无法支持可变数量的参数，因为被调用者必须确定参数数量才能自己清栈。
我印象中老Win32 API只有一个API支持变长参数，所以只有她是cdel而不是stdcall，来自user32的wsprintf。

作者：旺财
链接：https://www.zhihu.com/question/31453641/answer/52001143
来源：知乎
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/