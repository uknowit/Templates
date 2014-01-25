/*
 * Traits.hpp
 *
 *  Created on: Jan 24, 2014
 *      Author: shashi
 */
#ifndef _TRAITS_HPP
#define _TRAITS_HPP

template <class T> class C {
public:
	C(){}
	~C(){
		T*(T::*test)()const = &T::size();
	}

};

#endif

