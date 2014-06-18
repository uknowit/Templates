/*
 * FunctionObject.hpp
 *
 *  Created on: Jun 14, 2014
 *      Author: shashi
 */

#ifndef FUNCTIONOBJECT_HPP_
#define FUNCTIONOBJECT_HPP_

#include <stdio.h>
#include <stdlib.h>
#include <list>
#include <iostream>
#include <string>
#include <functional>
bool lessThan7(double value)
{
	return value<7.0;
}

template<class T> class Sum {
	T res;
public:
	Sum(T i=0):res(i){}
	void operator()(T x){res+=x;}
	T result(){return res;}
};

void fDouble(std::list<double>& ld)
{
	Sum<double> s;
	s=std::for_each(ld.begin(),ld.end(),s);
	std::list<double>::iterator doubleIter=find_if(ld.begin(),ld.end(),lessThan7);
	std::cout<<"Less than 7 is "<<*doubleIter<<std::endl;
	std::cout<<"The sum is "<<s.result()<<std::endl;
}

class Person {

};

struct Club {
	std::string clubName;
	std::list<Person*> members;
	std::list<Person*> officers;
	Club(const std::string& name):clubName(name){}
	std::string getName(){std::cout<<clubName<<std::endl;return clubName;}
};

class Club_eq:public std::unary_function<Club,bool> {
	std::string s;
public:
	explicit Club_eq(const std::string& ss):s(ss){}
	bool operator()(const Club& c)const {return c.clubName==s;}
};

class Extract_officers {
	std::list<Person*>& lst;
public:
	explicit Extract_officers(std::list<Person*>& x):lst(x){}
	void operator()(const Club& c) const{std::copy(c.officers.begin(),c.officers.end(),std::back_inserter(lst));}
};

template<class R,class T> class mem_fun_t:public std::unary_function<T*,R> {
	R (T::*pmf)();
public:
	explicit mem_fun_t(R(T::*p)()):pmf(p){}
	R operator()(T* p){return p->*pmf();}
};

template<class R,class T> mem_fun_t<R,T> my_mem_fun(R(T::*f)())
{
	return mem_fun_t<R,T>(f);
}

template<class R,class T> class mem_fun_ref_t:public std::unary_function<T&,R> {
	R(T::*pmf)();
public:
	explicit mem_fun_ref_t(R(T::*p)()):pmf(p){}
	R operator()(T& p){return (p.pmf)();}
};

template<class R,class T> mem_fun_t<R,T> my_mem_fun_ref(R(T::*f)())
{
	return mem_fun_ref_t<R,T>(f);
}

template<class T> class lessThan : public std::unary_function<T,bool> {
	T arg2;
public:
	explicit lessThan(const T& x):arg2(x){}
	bool operator()(const T& x)const {return x<arg2;}
};

template<class BinOp> class binder2nd:public std::unary_function< typename BinOp::first_argument_type,typename BinOp::result_type > {
protected:
	BinOp op;
	typename BinOp::second_argument_type arg2;
public:
	binder2nd(const BinOp& x,const typename BinOp::second_argument_type& v):op(x),arg2(v){}
	typename BinOp::result_type operator()(const typename BinOp::first_argument_type& x)const {return op(x,arg2);}
};

template<class BinOp,class T> binder2nd<BinOp> m_bind2nd(const BinOp& op,const T& v)
{
	return binder2nd<BinOp>(op,v);
}
#endif /* FUNCTIONOBJECT_HPP_ */
