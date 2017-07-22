/**
* 全部模板特例化
*
*
*/
#pragma once

template <class T1, class T2, class T3>
class A10_6{};

template<>
class A10_6<int, float, long>{};



/**
* 部分模板特例化
*/
template <class A, class B>
class Z {};

template <typename A>
class Z<A&, int> {};


template <typename T>
class Y{};

template <class T>
class Y<T*> {};
