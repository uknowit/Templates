/*
 * Stack.cpp
 *
 *  Created on: Jan 4, 2014
 *      Author: shashi
 */
#include "Stack.hpp"

StackException my_stack_exp;
template<class T,size_t N> void MyStack<T,N>::push(const T& t) throw (StackException)
{
	if(count<N)
    {
		data[count++]=t;
    }
    else
    {
		std::cout<<"Stack OverFlow"<<std::endl;
        throw my_stack_exp;
    }
}

template<class T,size_t N> T& MyStack<T,N>::pop() throw (StackException)
{
	if(count>0)
    {
		return data[--count];
    }
    else
    {
		std::cout<<"Stack underflow error"<<std::endl;
        throw my_stack_exp;
    }
}

template<class T, size_t N> const T& MyStack<T,N>::top_of_stack() throw (StackException)
{
    if(count>0)
    {
        return data[count-1];
    }
    else
    {
        std::cout<<"Stack underflow error"<<std::endl;
        throw my_stack_exp;
    }
}



