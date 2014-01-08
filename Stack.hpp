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

template<class T,size_t N=20> class MyStack {
	T data[N];
	size_t count;
public:
	MyStack(){count=0;}
	~MyStack(){}
	void push(const T& t);
	T& pop();
};

#endif /* STACK_HPP_ */
