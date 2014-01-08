/*
 * typeName.hpp
 *
 *  Created on: Jan 4, 2014
 *      Author: shashi
 */

#ifndef TYPENAME_HPP_
#define TYPENAME_HPP_

#include<stdio.h>
#include <stdlib.h>

template<class T> class X {
	typename T::id i;
public:
	void f() {i.g();}
};

class Y {
public:
	class id {
	public:
		void g(){}
	};
};


#endif /* TYPENAME_HPP_ */
