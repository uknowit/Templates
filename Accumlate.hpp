/*
 * Accumlate.hpp
 *
 *  Created on: Feb 8, 2014
 *      Author: shashi
 */

#ifndef ACCUMLATE_HPP_
#define ACCUMLATE_HPP_

template<int n,template<int> class F> struct Accumlate
{
	enum{val=Accumlate<n-1,F>::val+F<n>::val};
};

template<template<int> class F> struct Accumlate<0,F>
{
	enum{val=F<0>::val};
};

template<int n> struct Identity
{
	enum{val=n};
};

template<int n> struct Square
{
	enum{val=n*n};
};

template<int n> struct Cube
{
	enum{val=n*n*n};
};

#endif /* ACCUMLATE_HPP_ */
