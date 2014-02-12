/*
 * ClassCount.hpp
 *
 *  Created on: Jan 31, 2014
 *      Author: shashi
 */

#ifndef _CLASS_COUNT_HPP
#define _CLASS_COUNT_HPP
#include <iostream>

class Counted {
	static int classCount;
public:
	Counted(){++classCount;}
	Counted(const Counted&){++classCount;}
	~Counted(){--classCount;}
	static int getCount(){return classCount;}
};

int Counted::classCount=0;
class CountedClass:public Counted{};
class CountedClass2:public Counted{};


#endif
