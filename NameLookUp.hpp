/*
 * NameLookUp.hpp
 *
 *  Created on: Jan 18, 2014
 *      Author: shashi
 */

#ifndef NAMELOOKUP_HPP_
#define NAMELOOKUP_HPP_
#include <algorithm>
#include <iostream>
#include <typeinfo>

using std::cout;
using std::endl;

void g()
{
	cout<<"global g()"<<endl;
}
/*reference for typeid
 * http://stackoverflow.com/questions/1986418/typeid-versus-typeof-in-c*/
template <class T> class YYY {
public:
		void g() {cout<<"YYY<"<<typeid(T).name()<<">::g()"<<endl;}
		void h() {cout<<"YYY<"<<typeid(T).name()<<">::h()"<<endl;}
		typedef int E;
};

typedef double E;

template<class T> void swap(T& t1,T& t2){
	cout<<"Global swap"<<endl;
	T temp =t1;
	t2=t1;
	t1=temp;
}

template<class T> class XXX:public YYY<T> {
public:
	E f()
	{
		g();
		this->h();
		T t1 = T(10.2),t2=T(1);
		cout<< t1<<endl;
		swap(t1,t2);
		std::swap(t1,t2);
		cout<<"Printing typeid of E::"<<typeid(E).name()<<endl;
		return E(t2);
	}
};
#endif /* NAMELOOKUP_HPP_ */
