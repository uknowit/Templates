/*
 * PartialSpecialization.hpp
 *
 *  Created on: Feb 16, 2014
 *      Author: shashi
 */

#ifndef PARTIALSPECIALIZATION_HPP_
#define PARTIALSPECIALIZATION_HPP_

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <ctime>
#include <string>
#include <sstream>
using std::cout;
using std::endl;

template<class T> class Defaultsorter
{
public:
	void getSortedData(T* _data,size_t N)
	{
		for(size_t index=0;index<N;index++)
		{
			for(size_t innerIndex=index+1;innerIndex<N;innerIndex++)
			{
				if(_data[index] > _data[innerIndex])
				{
					T temp=_data[index];
					_data[index] = _data[innerIndex];
					_data[innerIndex] = temp;
				}
			}
		}
	}
};

template <size_t size,class T, template<class> class U> class templatePartial
{
	T* data;
	U<T> localU;
public:
	templatePartial(){data=new T[size];}
	~templatePartial(){delete[] data;}
	void initT(){for(size_t index=0;index<size;index++){data[index]=(rand()%100);}}
	void printTemplateData(){for(size_t index=0;index<size;index++){cout<<data[index]<<endl;}}
	void sort()
	{
		localU.getSortedData(data,size);
		printTemplateData();
	}
};

template <size_t size,template<class> class U> class templatePartial<size,std::string,U>
{
	std::string* data;
	U<std::string> localU;
public:
	templatePartial(){data = new std::string[size];}
	~templatePartial(){delete[] data;}
	void initT()
	{
		for(size_t index=0;index<size;index++)
		{
			std::stringstream ss;
			int val = rand()%100;
			ss << val;
			cout<<"Index:"<<index<<":"<<ss.str()<<endl;
			data[index]=std::string(ss.str());
		}
	}
	void printTemplateData(){for(size_t index=0;index<size;index++){cout<<data[index]<<endl;}}
	void sort()
	{
		localU.getSortedData(data,size);
		printTemplateData();
	}
};
template<> class Defaultsorter<std::string>
{
public:
	void getSortedData(std::string* _data,size_t N)
	{
		for(size_t index=0;index<N;index++)
		{
			for(size_t innerIndex=index+1;innerIndex<N;innerIndex++)
			{
				if(strcmp(_data[index].c_str(),_data[innerIndex].c_str())>0)
				{
					 std::string temp=_data[index];
					_data[index] = _data[innerIndex];
					_data[innerIndex] = temp;
				}
			}
		}
	}
};


#endif /* PARTIALSPECIALIZATION_HPP_ */
