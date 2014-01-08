/*
 * Container.hpp
 *
 *  Created on: Jan 4, 2014
 *      Author: shashi
 */

#ifndef CONTAINER_HPP_
#define CONTAINER_HPP_
#include<stdio.h>
#include <stdlib.h>
#include "Stack.hpp"
#include <iostream>
template <class T,template<class,size_t=10> class Seq> class Container
{
	Seq<T> stackObj;
	public:
		void append(const T& t){stackObj.push(t);}
		T& pop_back(){return stackObj.pop();}
};





#endif /* CONTAINER_HPP_ */
