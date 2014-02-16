/*
 * ExpressionTemplate.cpp
 *
 *  Created on: Feb 14, 2014
 *      Author: shashi
 */

#ifndef EXPRESSIONTEMPLATE_HPP_
#define EXPRESSIONTEMPLATE_HPP_

#include <stdlib.h>
#include <iostream>
#include <ctime>
#include <cstddef>
using  std::cout;
using std::endl;


template<class,size_t> class MyVectorSum ;
template<class T,size_t N> class MyVector {
	T data[N];
public:
	MyVector<T,N>& operator=(const MyVector<T,N>& right)
	{
		for(size_t index=0;index<N;index++)
		{
			data[index]=right.data[index];
			return * this;
		}
	}
	MyVector<T,N>& operator=(const MyVectorSum<T,N>& right);
	const T& operator[](size_t index)const {return data[index];}
	T& operator[](size_t index){return data[index];}
};

template<class T,size_t N> class MyVectorSum {
	const MyVector<T,N>& left;
	const MyVector<T,N>& right;
public:
	MyVectorSum(const MyVector<T,N>& lhs,const MyVector<T,N>& rhs):
		left(lhs),right(rhs){}
	T operator[](size_t index)const
	{
		return left[index]+right[index];
	}
};

template<class T,size_t N>  MyVector<T,N>& MyVector<T,N>::operator=(const MyVectorSum<T,N>& right)
{
	for(size_t index=0;index<N;index++)
	{
		data[index]=right[index];
	}
	return *this;
}

template<class T,size_t N> inline MyVectorSum<T,N>
operator+(const MyVector<T,N>& left,const MyVector<T,N>& right)
{
	return MyVectorSum<T,N>(left,right);
}

template<class T,size_t N> void init(MyVector<T,N>& v)
{
	for(size_t index=0;index<N;index++)
	{
		v[index]=rand()%100;
	}
}

template<class T,size_t N> void print(MyVector<T,N>& v)
{
	for(size_t index=0;index<N;index++)
	{
		cout << v[index]<<' '<<endl;
	}
}

#endif /* EXPRESSIONTEMPLATE_CPP_ */
