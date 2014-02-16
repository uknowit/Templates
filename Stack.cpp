/*
 * Stack.cpp
 *
 *  Created on: Jan 4, 2014
 *      Author: shashi
 */
#include "Stack.hpp"

template<class T,size_t N> void MyStack<T,N>::push(const T& t)
{
	if(count<N)
		data[count++]=t;
	else
		std::cout<<"Stack OverFlow"<<std::endl;
}

template<class T,size_t N> T& MyStack<T,N>::pop()
{
	if(count>0)
		return data[--count];
	else
		std::cout<<"Stack underflow error"<<std::endl;

}




