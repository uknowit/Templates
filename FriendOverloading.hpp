/*
 * FriendOverloading.hpp
 *
 *  Created on: Jan 18, 2014
 *      Author: shashi
 */
#ifndef _FRIENDLY_OVERLOADING_HPP
#define _FRIENDLY_OVERLOADING_HPP
#include <iostream>

using std::cout;
using std::endl;

template<class T> class FriendOverloading;
template<class T> FriendOverloading<T> operator+(const FriendOverloading<T>&,const FriendOverloading<T> &);
template<class T> std::ostream& operator<<(std::ostream&,const FriendOverloading<T>&);

template<class T> class FriendOverloading {
T t;
public:
	FriendOverloading(const T& theT){t=theT;}
	friend FriendOverloading operator+<>(const FriendOverloading<T>&,const FriendOverloading<T> &);
	friend std::ostream& operator<< <>(std::ostream& ,const FriendOverloading&);
	friend bool operator< (const FriendOverloading& a,const FriendOverloading& b) {return a.t<b.t;}
};

template<class T> FriendOverloading<T> operator+(const FriendOverloading<T>& a ,const FriendOverloading<T>& b)
{
	return FriendOverloading<T>(a.t+b.t);
}

template<class T> std::ostream& operator<<(std::ostream& os, const FriendOverloading<T>& a)
{
	return os<<"["<<a.t<<"]";
}

#endif
