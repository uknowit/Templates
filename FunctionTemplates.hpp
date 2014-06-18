/*
 * FunctionTemplates.hpp
 *
 *  Created on: May 3, 2014
 *      Author: shashi
 */

#ifndef FUNCTIONTEMPLATES_HPP_
#define FUNCTIONTEMPLATES_HPP_

class Top {};
class Middle:public Top {};
class Bottom:public Middle{};

template<typename T> class SmartPtr
{
public:
	explicit SmartPtr(T* realPtr){};
	template<typename U> SmartPtr(const SmartPtr<U>& other):heldPtr(other.get()){};
	T* get()const{return heldPtr;}
private:
	T* heldPtr;
};



#endif /* FUNCTIONTEMPLATES_HPP_ */
