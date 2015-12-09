/*
 * Stack.hpp
 *
 *  Created on: Jan 3, 2014
 *      Author: shashi
 */

#ifndef STACK_HPP_
#define STACK_HPP_

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <exception>

class StackException: public std::exception
{
    public:
    virtual const char* what() const throw()
    {
        return "StackException happend";
    }
};
template<class T,size_t N=20> class MyStack {
	T data[N];
	size_t count;
public:
	MyStack(){count=0;}
	~MyStack(){}
	void push(const T& t) throw (StackException);
	T& pop() throw (StackException);
    const T& top_of_stack() throw (StackException);
    size_t get_stack_size();
};

#endif /* STACK_HPP_ */
