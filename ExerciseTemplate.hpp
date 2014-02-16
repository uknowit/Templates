/*
 * ExerciseTemplate.hpp
 *
 *  Created on: Feb 16, 2014
 *      Author: shashi
 */

#ifndef EXERCISETEMPLATE_HPP_
#define EXERCISETEMPLATE_HPP_

#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <ctime>

using  std::cout;
using  std::endl;

template<typename T> T calculateSum(T val[],int startIndex,int stopIndex,T initialValue)
{
	T sum;
	int index=startIndex;
	while(index<=stopIndex)
	{
		sum=sum+val[index];
		index++;
	}
	return sum;
}


template<typename T> void initializeExTemp(T val[],size_t size)
{
	for(size_t index=0;index<size;index++)
	{
		val[index]=rand()%100;
	}
}
class Buddy{};

template<class T> class My
{
	int i;
public:
	void play(My<Buddy> s)
	{
		s.i=3;
	}
};

#endif /* EXERCISETEMPLATE_HPP_ */
