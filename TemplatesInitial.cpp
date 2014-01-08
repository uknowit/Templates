//============================================================================
// Name        : TemplatesInitial.cpp
// Author      : Shashikumar HN
// Version     :
// Copyright   : Dream big
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "Stack.hpp"
#include "Container.hpp"
#include "typeName.hpp"
using namespace std;
string strTolower(string);

template<typename T> void  displayMessage(T message)
{
}

template<typename T> const T& min(const T& a,const T& b)
{
	return (a<b)?a:b;
}

template<> const char* const& min<const char* >(const char* const & a,const char* const& b)
{
	return (strcmp(a,b)<0)?a:b;
}

int main()
{
	cout<<"==============="<<endl;
	string msg = "Welcome to 2014 ....";
	displayMessage(msg);
	MyStack<int,10> stackTest;
	int i=10;
	int j=20;
	stackTest.push(i);
	stackTest.push(j);
	stackTest.pop();
	stackTest.pop();
	Container<int,MyStack> container;
	container.append(1);
	container.pop_back();
	X<Y> xy;
	xy.f();
	cout<<strTolower(msg)<<endl;
	const char* s2="Say \"Hi!\" ",*s1="knights who" ;
	cout<<min(s1,s2)<<endl;
	cout<<min<>(s1,s2)<<endl;

}
