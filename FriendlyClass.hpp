/*
 * FriendlyClass.hpp
 *
 *  Created on: Jan 18, 2014
 *      Author: shashi
 */

#ifndef FRIENDLYCLASS_HPP_
#define FRIENDLYCLASS_HPP_

#include <iostream>
using std::cout;
using std::endl;
class Friendly {
	int i;
public:
	explicit Friendly(int theInt){i=theInt;}
	friend void f(const Friendly&) ;//
	void g();
};

void hf()
{
	f(Friendly(1));
	/* uses ADL --argument-dependent lookup
	 * In this case Friendly class is searched for f()...
	 * f(1) in this will result in failure
	 * since there is no hint for compiler to search for definition of  f().
	 * Implicit conversion of f(1) to f(Friendly(1)) is avoided by using explicit keyword in constructor
	 */
}

void Friendly::g()
{
	f(*this);
}

void f(const Friendly& fo)
{
	cout<<"Friendly::"<<fo.i<<endl;
}

#endif /* FRIENDLYCLASS_HPP_ */
