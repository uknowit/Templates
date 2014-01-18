/*
 * DelayedInstatiation.hpp
 *
 *  Created on: Jan 16, 2014
 *      Author: shashi
 */

#ifndef DELAYEDINSTATIATION_HPP_
#define DELAYEDINSTATIATION_HPP_

class XX {
public:
	void f() {}
};

class YY {
public:
	void g(){}
};

template<typename T> class Z {
	T t;
public:
	void a() {t.f();}
	void b() {t.g();}
};



#endif /* DELAYEDINSTATIATION_HPP_ */
